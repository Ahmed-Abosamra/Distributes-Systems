#include "substring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring_prog_1(char *host)
{
    CLIENT *clnt;
    int *result_1;
    substring_data check_substring_1_arg;

    #ifndef DEBUG
    clnt = clnt_create(host, SUBSTRING_PROG, SUBSTRING_VERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }
    #endif /* DEBUG */

    check_substring_1_arg.str1 = (char*) malloc(256 * sizeof(char));
    check_substring_1_arg.str2 = (char*) malloc(256 * sizeof(char));

    printf("Enter the first string: ");
    fgets(check_substring_1_arg.str1, 256, stdin);
    check_substring_1_arg.str1[strcspn(check_substring_1_arg.str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(check_substring_1_arg.str2, 256, stdin);
    check_substring_1_arg.str2[strcspn(check_substring_1_arg.str2, "\n")] = '\0';

    result_1 = check_substring_1(&check_substring_1_arg, clnt);

    if (result_1 == NULL) {
        clnt_perror(clnt, "Failed to connect to the server");
        exit(1);
    } else {
        if (*result_1 == 1) {
            printf("%s is a substring of %s\n", check_substring_1_arg.str2, check_substring_1_arg.str1);
        } else {
            printf("%s is NOT a substring of %s\n", check_substring_1_arg.str2, check_substring_1_arg.str1);
        }
    }

    free(check_substring_1_arg.str1);
    free(check_substring_1_arg.str2);

    #ifndef DEBUG
    clnt_destroy(clnt);
    #endif /* DEBUG */
}

int main(int argc, char *argv[])
{
    char *host;

    if (argc < 2) {
        printf("Usage: %s server_host\n", argv[0]);
        exit(1);
    }
    host = argv[1];
    substring_prog_1(host);
    exit(0);
}

