#include "main.h"
/**
 * compare - Compare two strings lexicographically.
 * This function is designed to be used as a comparison function for qsort to
 * compare two strings lexicographically.
 * @a: Pointer to the first string to compare.
 * @b: Pointer to the second string to compare.
 * Return: 0 
 */
int compare(const void *a, const void *b) {
    return _strcmp(*(char **)a, *(char **)b);
}



void _env(DataShell *datash) {
	char **env = environ;
    	int num_vars = 0;
    	int i;
    if (env == NULL) {
        perror("Error accessing environment variables");
        datash->status = 1;
        return;
    }


    while (env[num_vars] != NULL) {
        num_vars++;
    }

qsort(env, num_vars, sizeof(char *), compare);


    for (i = 0; env[i] != NULL; i++) {
        printf("%s\n", env[i]);
    }

    datash->status = 0;
	
}
