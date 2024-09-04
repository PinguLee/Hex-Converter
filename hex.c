#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char command[256] = {0};
    char string_data[256] = {0};

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "/input") == 0) {
            printf(" -> ");
            fgets(string_data, sizeof(string_data), stdin);
            string_data[strcspn(string_data, "\n")] = 0;
            printf("%s\n", string_data);

            memset(string_data, 0, sizeof(string_data));
        } else if (strcmp(command, "/help") == 0) {
            printf("command\n");
            printf("/input : input\n");
            printf("/exit : exit\n");
        } else if (strcmp(command, "/exit") == 0) {
            break;
        } else {
            printf("help? : /help\n");
        }

        memset(command, 0, sizeof(command));
    }

    return 0;
}
