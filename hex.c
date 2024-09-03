#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char string_data[256];

    while (1) {
        printf("> ");
        fgets(string_data, sizeof(string_data), stdin);

        string_data[strcspn(string_data, "\n")] = '\0';

        if (strcmp(string_data, "/input") == 0) {
            printf("%s\n", string_data);
        } else if (strcmp(string_data, "/help") == 0) {
            printf("사용 가능한 명령어\n");
            printf("/input : 문자열 입력\n");
            printf("/exit : 프로그램 종료\n");
        } else if (strcmp(string_data, "/exit") == 0) {
            break;
        } else {
            printf("다시 입력하세요. 도움말 : /help");
        }
    }

    return 0;
}
