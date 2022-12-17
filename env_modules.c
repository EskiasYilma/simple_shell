#include "main.h"

/**
 * print_env - print variable global envirionment
 * @env: envirionment variable
 **/

void print_env(char **env)
{
	int itr = 0;

	for (itr = 0; env[itr] != NULL; itr++)
	{
		write(STDOUT_FILENO, env[itr], _strlen(env[itr]));
		write(STDOUT_FILENO, "\n", 1);
	}
}


/**
 * _getenv - get variable enviriomment
 * @key: key of envirionment variable eg. PATH, HOME
 * @env: envirionment variable
 * Return: char value envirionment
 **/
char *_getenv(char *key, char **env)
{
	char *tmp = NULL, *token = NULL, *envir = NULL, *current_env = NULL;
	int itr = 0;

	envir = _strdup(key);
	while (env[itr] && env)
	{
		current_env = NULL;
		token = NULL;
		current_env = _strdup(env[itr]);
		tmp = strtok(current_env, "=");
		token = _strdup(strtok(NULL, "="));
		if (_strcmp(envir, tmp) == 0)
		{
			break;
		}
		free(current_env);
		free(token);
		itr++;
	}
	free(current_env);
	current_env = NULL;
	free(envir);
	return (token);
}

/**
 * file_exists - check if a filename or executable exist in directory.
 * @exec_path: Full 'PATH' variable
 * @cmd: command name
 * Return: full path name of cmd
 **/
char *file_exists(char *exec_path, char *cmd)
{
	struct stat st;
	char *path_name, *token;
	int itr = 0;

	token = strtok(exec_path, ":");
	while (token != NULL)
	{
		path_name = malloc((_strlen(token) + _strlen(cmd) + 2) * sizeof(char));
		if (path_name == NULL)
		{
			free(path_name);
			return (NULL);
		}
		_strcpy(path_name, token);
		_strcat(path_name, "/");
		_strcat(path_name, cmd);
		if (stat(path_name, &st) == 0)
		{
			return (path_name);
		}
		free(path_name);
		token = strtok(NULL, ":");
		itr++;
	}
	return (NULL);
}
