#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

char *lineptr = NULL;
int _putchar(char c);
void mygetline(void);
char **mystrtok(const char *delim);

#endif 
