#include "main.h"

/**
	* sighandler - handles signals from keyboard interrupts
	* @sig: the signal caught
	*/
static void sighandler(int sig)
{
	unsigned char sig_flag = 0;

	if (sig == SIGINT && sig_flag == 0)
		xprint("\n(Eshell) $ ");
	else if (sig_flag != 0)
		xprint("\n");
}

/**
 * main - entry point
 * @argc: arguement count
 * @argv: arguement vector
 * @env: environment variable
 * Return: Exit status
 */

int main(int argc, char *argv[], char *env[])
{
		int exec_stat = 0;
		int cmd_cnt = 1;

		(void)argc;

		if (signal(SIGINT, sighandler) == SIG_ERR)
			perror(argv[0]);

		if (argc > 1)
		{
			_sprintf(argv, 0, "Can't open");
			return (127);
		}

		exec_stat = read_token_loop(argv, cmd_cnt, env);
		return (exec_stat);

}
