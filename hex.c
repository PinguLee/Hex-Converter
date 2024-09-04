#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char command[256];
    char string_data[256];

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "/input") == 0) {
            printf(" -> ");
            fgets(string_data, sizeof(string_data), stdin);
            string_data[strcspn(string_data, "\n")] = 0;
            printf("%s\n", string_data);
        
        } else if (strncmp(command, "/save ", 6) == 0) {
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
