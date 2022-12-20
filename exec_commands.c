#include "main.h"

/**
 * eval_commands - evaluate and execute external commands
 * @args: token array to pass to execve
 * @env: environment variables
 * @cmd_cnt: command counter
 * Return: exit status
 */

int eval_commands(char *args[], char **env, int cmd_cnt)
{
	char *path = NULL, *ex_name = NULL;
	int status = 0, found = 0, mem_c = 0, exit_stat = 0;
	pid_t child_pid;
	struct stat st;

	if (stat(args[1], &st) == 0)
		found = 1, ex_name = args[1];
	else
	{
		path = _getenv("PATH", env);
		ex_name = file_exists(path, args[1]);
		if (ex_name != NULL)
			found = 1, mem_c = 1;
		free(path);
	}
	if (found)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if ((execve(ex_name, (args + 1), env)) == -1)
			{
				_sprintf(args, cmd_cnt, "not found");
				(mem_c == 1) ? free(ex_name) : (void) mem_c;
			}
		}
			waitpid(child_pid, &status, 0), (mem_c == 1) ? free(ex_name) : (void) mem_c;
		if (WIFEXITED(status))
		{
			exit_stat = WEXITSTATUS(status);
			return (exit_stat);
		}
	} else
	{
		_sprintf(args, cmd_cnt, "not found");
		return (127);
	}
	return (0);
}
