#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAXGR 10
#define ERRLEN 100

int is_digit(char c){
    return (c >= '0' && c <= '9');
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <pattern> <replacement> <input>\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];
    const char *replacement = argv[2];
    const char *input = argv[3];

    regex_t regex;
    size_t input_len = strlen(input);
    size_t replacement_len = strlen(replacement);
    regmatch_t bags[MAXGR];
    char comp_error[ERRLEN], exec_error[ERRLEN];
    
    int bags_count = 0;

    int comp_code = regcomp(&regex, pattern, REG_EXTENDED);
    if (comp_code){
        regerror(comp_code, &regex, comp_error, ERRLEN);
        fprintf(stderr, "%.*s\n", ERRLEN - 1, comp_error);
        return 1;
    }

    int exec_code = regexec(&regex, input, MAXGR, bags, 0);
    if (exec_code){
        regerror(exec_code, &regex, exec_error, ERRLEN);
        fprintf(stderr, "%.*s\n", ERRLEN - 1, exec_error);
        return 1;
    }

    for (int i = 1; bags[i].rm_so != -1; i++)
        bags_count++;

    size_t k = 0;
    while (k != replacement_len){
        if (replacement[k] == '\\' && is_digit(replacement[k+1])){
            int num = replacement[k+1] - '0';
            if (num > bags_count){
                fprintf(stderr, "Недопустимая ссылка на \\%c\n", replacement[k+1]);
                return 1;
            }
            k = k + 2;
        }
        else
            k++;
    }

    for (int i = 0; i < bags[0].rm_so; i++) {
        printf("%c", input[i]);
    }
    k = 0;
    while (k != replacement_len){
        if (replacement[k] == '\\' && is_digit(replacement[k+1])){
            int num = replacement[k+1] - '0';
            int b = bags[num].rm_so, e = bags[num].rm_eo;
            for (int j = b; j < e; j++)
                printf("%c", input[j]);
            k = k + 2;
        }
        else {
            printf("%c", replacement[k]);
            k++;
        }
    }
    for (size_t i = bags[0].rm_eo; i < input_len; i++) {
        printf("%c", input[i]);
    }
    printf("\n");
    
    regfree(&regex);

    return 0;
}
