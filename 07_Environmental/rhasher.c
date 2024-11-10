#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "rhash.h"
#include "config.h"

#ifdef HAVE_LIBREADLINE
#include <readline/readline.h>
#endif

int main(int argc, char **argv) {
    char* line;
    char* msg;
    char* hash_type;
    char digest[64];
    char output[130];
    size_t len = 0;
    int nread;

    rhash_library_init();

    while (1) {
        #ifndef HAVE_LIBREADLINE
        printf("> ");
        nread = getline(&line, &len, stdin);
        #else
        line = readline("> ");
        nread = line ? 0 : -1;
        #endif

        if (nread == -1)
            break;
        
        hash_type = strtok(line, " ");
        if (!hash_type) {
            printf("Bad line\n");
            continue;
        }
        else if (!(msg = strtok(NULL, " "))) {
            printf("Missing second parameter: %s\n", hash_type);
            continue;
        }
        unsigned PRINT_FLAG = islower(hash_type[0]) ? RHPR_BASE64 : RHPR_HEX;
        for (int i = 0; i < strlen(hash_type); i++) {
            hash_type[i] = (char) toupper(hash_type[i]);
        }
        
        int msg_len = strlen(msg);
        if (msg[msg_len - 1] == '\n') {
            msg[msg_len - 1] = '\0';
        }

        unsigned int hash_id;
        if (!strcmp(hash_type, "MD5")) {
            hash_id = RHASH_MD5;
        } else if (!strcmp(hash_type, "SHA1")) {
            hash_id = RHASH_SHA1;
        } else if (!strcmp(hash_type, "TTH")) {
            hash_id = RHASH_TTH;
        } else {
            printf("Undefined command: %s\n", hash_type);
            continue;
        }

        int res;
        if (msg[0] == '"') {
            msg = (char*)(msg + 1);
            res = rhash_msg(hash_id, msg, strlen(msg), digest);
        }
        else
            res = rhash_file(hash_id, msg, digest);
        if (res < 0) {
            fprintf(stderr, "Digest calculation error: %s\n", strerror(errno));
            continue;
        }
        rhash_print_bytes(output, digest, rhash_get_digest_size(hash_id), PRINT_FLAG);
        printf("%s\n", output);
    }
    return 0;
}