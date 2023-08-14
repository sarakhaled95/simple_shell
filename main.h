#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void exe_cmd(char **argv); /*exec_cmd.c*/
char *get_locat(char *cmd); /*get_locat.c*/
/* string.c */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);

#endif
