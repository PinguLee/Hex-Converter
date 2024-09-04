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
        
        } else if (strcmp(command, "/save") == 0) {
            FILE *file = fopen("output.txt", "w");
            if (file != NULL) {
                fprintf(file, "%s\n", string_data);
                fclose(file);
                printf("save success\n");
            } else {
                printf("error\n");
            }

        } else if (strcmp(command, "/help") == 0) {
            printf("command\n");
            printf("/input : input\n");
            printf("/exit : exit\n");
        } else if (strcmp(command, "/exit") == 0) {
            break;
        } else {
            printf("help? : /help\n");
        }

    }

    return 0;
}
