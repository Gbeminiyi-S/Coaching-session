#include "main.h"


void sigintHandler(int sig)
{
	(void) sig;
	free(lineptr), lineptr = NULL;
	exit(0);
}

void mygetline(void)
{
	size_t n = 0;
	ssize_t nread;

	nread = getline(&lineptr, &n, stdin);
	if (nread == -1)
	{
		free(lineptr);
		lineptr = NULL;
		exit(1);
	}

	lineptr[nread - 1] = '\0';
}

char **mystrtok(const char *delim)
{
	char *token = NULL, *line = strdup(lineptr);
	char **tokens = malloc(sizeof(char *) * 10);
	int i = 0;

	if (!tokens)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, delim);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tokens), tokens = NULL;
		return (NULL);
	}

	while (token)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	free(line), line = NULL;
	return (tokens);
}

void myfork(char **argv, char **av, char **environ)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
		return;
	else if (child_pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror(av[0]);
	}
	else
		wait(&status);
}

int main(int ac, char **av, char **environ)
{
	char *prompt = "#simple_shell$ ";
	int i;
	char **argv = NULL;
	bool interactive = isatty(fileno(stdin));

	(void) ac;

	signal(SIGINT, sigintHandler);

	while(1)
	{
		if (interactive)
		{
			i = 0;
			while (prompt[i])
				_putchar(prompt[i++]);
		}

		mygetline();
		argv = mystrtok(" ");

		if (argv)
		{
			myfork(argv, av, environ);
			for (i = 0; argv[i]; i++)
			{
				free(argv[i]);
				argv[i] = NULL;
			}
			free(argv), argv = NULL;
		}
		free(lineptr), lineptr = NULL;
	}
	free(lineptr), lineptr = NULL;

	return (0);
}
