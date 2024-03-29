#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str = strdup("   ");
	const char *delim = " ";
	char *token;

	token = strtok(str, delim);
	printf("%s", token);

	while (token)
	{
		token = strtok('\0', delim);
		if (token)
			printf(" %s", token);
	}
	free(str);
	printf("\n");
	return (0);
}
