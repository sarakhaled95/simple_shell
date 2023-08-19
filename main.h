#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: number field
 * @str: string
 * @next: pointer to next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_st;

/**
 * struct passinfo - contain pseudo-arguments to pass into a function
 * allowing uniform prototype function pointer struct
 * @arg: a string generated from getline containing arguments
 * @argv: an array of string
 * @path: a string path for the current command
 * @argc: argument count
 * @line_count: error count
 * @err_num: error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: program file name
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from ll env
 * @history: history node
 * @alias: alias node
 * @env_changed: on if environ changed
 * @status: return status of the last executed command
 * @cmd_buf: address of pointer to cmd_buf, on if chain
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: fd from which to read the line input
 * @histcount: history line count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_st *env;
	list_st *history;
	list_st *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_st;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - have built in string and related functions
 * @type: the builting command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_st *);
} builtin_table;

void exe_cmd(char **argv); /*exec_cmd.c*/
void get_location(info_st *info); /*get_locat.c*/

/* string.c */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *starts_with(const char *haystack, const char *needle);

/*string_1.c*/
int _putchar(char c);
void _puts(char *str);

/*enviroment_var.c*/
char *_getenv(info_st *info, const char *name);
int _current_env(info_st *info);
char **get_environ(info_st *info);

/*list_string.c*/
size_t print_liststr(const list_st *h);

/*path.c*/
char *dup_chars(char *pathstr, int start, int stop);
char *get_path(info_st *info, char *pathstr, char *cmd);
int is_cmd(info_st *info, char *path);

/*function1.c*/
void print_error(info_st *info, char *estr);
int print_d(int input, int fd);
int is_delim(char c, char *delim);
int interactive(info_st *info);

/*errstr_func.c*/
int _eputchar(char c);
void _eputs(char *str);

/*fork.c*/
void fork_cmd(info_st *info);

/* info_st.c*/
void free_info(info_st *info, int all);

/* memory_func.c*/
int bfree(void **ptr);
void ffree(char **pp);
void free_list(list_st **head_ptr);
#endif
