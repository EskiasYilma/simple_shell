#include "main.h"

/**
 * e_num_builtins - number of builtins
 * Return: number of builtins
 */

int e_num_builtins(void)
{
	char *bi_cmd[] = {
		"cd",
		"help",
		"exit"
	};

	return (sizeof(bi_cmd) / sizeof(char *));
}

/**
 * e_cd - Change Directory Bi command
 * @args: cd args
 * @env: environment variables
 * @cmd_cnt: Command counter
 * Return: (1)
 */

int e_cd(char **args, char **env, int cmd_cnt)
{
	char *home = NULL;

	if (args[2] == NULL)
	{
		home = _getenv("HOME", env);
		if (chdir(home) != 0)
		{
			_sprintf(args, cmd_cnt, "can't cd to ");
		}
		free(home);
	}
	else
	{
		if (chdir(args[2]) != 0)
		{
			_sprintf(args, cmd_cnt, "can't cd to ");
		}
	}
	return (1);
}

/**
 * e_help - Help Bi command
 * @args: help args
 * @env: environment variables
 * @cmd_cnt: Command counter
 * Return: (1)
 */

int e_help(char **args, char **env, int __attribute__((__unused__)) cmd_cnt)
{
	if (args || env)
	{
		;
	}
	xprint("\n##################\n");
	xprint("## Simple Shell ##\n");
	xprint("##################\n\n");
	xprint("## Authors: Eskias Yilma & Rahel Tesfaye\n");
	xprint("## Type 'help' to see this list of builtin commands.\n");
	xprint("  > cd [dir]\n");
	xprint("  > env\n");
	xprint("  > help name\n");
	xprint("  > exit [n]\n");

	printf("Use the man [command_name] for help on external commands.\n\n");
	return (1);
}

/**
 * e_exit - Exit Bi command
 * @args: exit statuses
 * @env: environment variables
 * @cmd_cnt: Command counter
 * Return: exit status
 */

int e_exit(char **args, char **env, int __attribute__((__unused__)) cmd_cnt)
{
		int exit_stat = 0;

		if (env)
		{
			;
		}
		if (args[2])
		{
			exit_stat = _atoi(args[2]);
		}
		write(STDIN_FILENO, "exit\n", 5);
		exit(exit_stat);
}

/**
 * check_builtins - Checks for builtin commands
 * @args: arguement vectors
 * @env: environment variables
 * @cmd_cnt: Command counter
 * Return: exit status
 */

int check_builtins(char *args[], char **env, int cmd_cnt)
{
	int i, exec_stat = 0;
	char *bi_cmd[] = {
		"cd",
		"help",
		"exit"
	};

	int (*bi_func[]) (char **, char **, int n) = {
		&e_cd,
		&e_help,
		&e_exit
	};
	for (i = 0; i < e_num_builtins(); i++)
	{
		if (strcmp(args[1], bi_cmd[i]) == 0)
		{
			exec_stat = (*bi_func[i])(args, env, cmd_cnt);
		}
	}
	return (exec_stat);
}
