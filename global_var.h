#ifndef GLOBAL_VAR
#define GLOBAL_VAR
int environ_on_stack = TRUE;
char **temp_environ = NULL;
char **alias = {NULL};
static int (*builtin_func[]) (char *, char **) = {&_exitt, &_env,
	&_setenv, &_unsetenv, &_cd, &_alias};
static char *builtins[] = {"exit", "env", "setenv",
	"unsetenv", "cd", "alias", NULL};
#endif
