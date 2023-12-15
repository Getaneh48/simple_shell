#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0

size_t total_tokens(char *str, char delim);
void _strcpy(char *dest, char *src, int sindex, int eindex);
char **tokenize(char *str, char delim);
void free_memory(char **mem);
size_t _getline(char *buffer, size_t size, FILE *stream);
int _strcmp(char *s1, char *s2);
int _exitt(char *, char **);
int _env(char *, char **);
int _setenv(char *, char **);
int _unsetenv(char *, char **);
int _cd(char *, char **);
int _alias(char *, char **);
int count_tokens(char **tokens);
int is_number(char *num);
int _strlen(char *);
int _strlen_rec(char *, int);
int _pow(int, int);
char **_strtoken(char *string);
int word_count(char *string);
char *copy_str(char *source, unsigned int st_index,
		unsigned int end_index);
int strtoint(char *num);
char *_getenv(char *name);
char *_strcat(char *dest, char *src);
char *locate(char *cmd);
int execute_external_command(char *filepath, char **tokens);
char **duplicate_environ(char **tokens);
int new_env(char **tokens);
int replace_env(char **tokens);
int remove_env(char **tokens);
int substr(char *src, char *dest, size_t sp, size_t ep);
int change_dir(char *path);
void update_oldpwd(char *path);
int handle_cd_hyphen(void);
void show_current_path(void);
int handle_cd_tilder(void);
int get_length(char **str);
int handle_alias(char **tokens);
char *remove_quote(char *token);
void replace_homepath(char *home, char *cwd, int home_len,
		int cwd_len, int i, char *symbol);
int check_alias_exists(char *name);
int add_new_alias(char **al);
char *create_alias_string(char **alias_cmd);
char *stripe_quote(char *str, int *stoken, int *etoken,
		int *sq, int *eq, int i);
char **allocate_mem(char **buffer, char *str, int *j);
char **parse_string(char *str, char delim);
int update_alias(char **new_al);
void list_alias(void);
int is_setting_alias(char *al);
void show_alias_by_name(char *name);
char **move_envto_heapmem();
int get_arrptr_length(char **arr);
void init_app(void);
char **getenv_list();
char *expand_variable(char *str);
char *replace_variable(char *src_str, char *r_str, int sind, int i);
int handle_dollar_symbol(char *path, char *str);
char *perform_variable_replacement(char *str, char *env_name, char *env_val);
void handle_alias_process(char **tokens);
int read_command_file(char *filename, char *appname);
int handleCommand(char *appname, char **tokens);
int runCommand(char *appname, char **tokens);
int execute_external_command(char *filepath, char **tokens);
int checkBuiltinCmd(char *cmd);

extern char **environ;
extern int environ_on_stack;
extern char **temp_environ;
extern char **alias;
#endif
