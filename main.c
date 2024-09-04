#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/*
// hex로 변환 old
void hxd(const char * data) {
    while(*data) {
        printf("%02x", (unsigned char)*data);
        data++;
    }
}
*/

void hxd(const wchar_t *string_data) {
    for (int i = 0; string_data[i] != L'\0'; i++) {
        unsigned char *bytes = (unsigned char *)&string_data[i];
        printf("%02x %02x ", bytes[1], bytes[0]); // 리틀 엔디언 처럼 보이게 출력
    }
    printf("\n");
}

int main(void) {
    char command[6];
    wchar_t string_data[256];

    while (1) {
        printf("> ");
        
        // BOF 보완
        if (scanf("%6s", command) != 1) {
            printf("최대 6글자 입력\n");
            continue;
        }

        if (strcmp(command, "/input") == 0) {
            printf(" -> ");
            wscanf(L"%ls", string_data);
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
            printf("다시 입력하세요.");
        }

    }

    return 0;
}
