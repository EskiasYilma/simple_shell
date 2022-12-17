#include "main.h"

/**
 * free_me - Frees buffer pointer and writes to stdout
 * @lineptr: pointer to be freed
 * @out: string to be written to stdout
 * Return: 0
 */

int free_me(char *lineptr, char *out)
{
	if (!out)
	{
		free(lineptr);
		return (0);
	}
	free(lineptr);
	write(STDIN_FILENO, out, 1);
	return (0);
}

/**
 * read_token_loop - Read stdin and Tokenize line and Create main prompt Loop
 * @argv: arguement vector passed from main
 * @cmd_cnt: passed commands counter
 * @env: environment variables
 * Return: exit status
 */

int read_token_loop(char **argv, int cmd_cnt, char **env)
{
	char *lineptr = NULL, *token = NULL, *tokens[64];
	int i = 0, active = 1, exec_stat = 0, bytes_read = 0;
	size_t n = 0;

	isatty(STDIN_FILENO) == 0 ? active = 0 : active;
	while (1)
	{
		active == 1 ? write(STDOUT_FILENO, "(Eshell) $ ", 11) : active;
		bytes_read = getline(&lineptr, &n, stdin);
		if (bytes_read == EOF)
			return (free_me(lineptr, "\n"));
		if (_strncmp(lineptr, "exit\n", 4) == 0)
			return (free_me(lineptr, NULL));
		if (bytes_read > 1)
		{
			token = strtok(lineptr, DELIM), tokens[0] = argv[0];
			for (i = 1; i < 32 && token != NULL; i++)
			{
				tokens[i] = token;
				token = strtok(NULL, DELIM);
			}
			tokens[i] = NULL;
			if (tokens[1])
			{
				if (check_builtins(tokens, env, cmd_cnt) == 1)
				{
					cmd_cnt++;
					continue;
				}
				exec_stat = eval_commands(tokens, env, cmd_cnt);
			}
		}
		cmd_cnt++;
	}
	return (exec_stat);
}
