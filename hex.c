#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
// hex로 변환 old
void hxd(const char * data) {
    while(*data) {
        printf("%02x", (unsigned char)*data);
        data++;
    }
}
*/

void hxd(const char *data) {
    int count = 0;
    while (*data) {
        printf("%x", (unsigned char)*data);
        count++;
        if (count % 2 == 0) {
            printf(" ");
        }
        data++;
    }
    printf("\n");
}

int main(void) {
    char command[256];
    wchar_t string_data[256];

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "/input") == 0) {
            printf(" -> ");
            wscanf(L"%s", string_data);
            // printf("%s\n", string_data);
            hxd(string_data);
        
        } else if (strstr(command, "/save ") == command) {
            char *filename = command + 6;
            FILE *file = fopen(filename, "w");
            if (file != NULL) {
                fprintf(file, "%s", string_data);
                fclose(file);
                printf("save success\n");
            } else {
                printf("error\n");
            }

        } else if (strcmp(command, "/exit") == 0) {
            break;
        } else {
            printf("retry");
        }

    }

    return 0;
}
