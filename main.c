#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

void hxd(const wchar_t *string_data, FILE *output) {
    int count = 0;
    int offset = 0;
    int ascii_count = 0;
    char ascii[999];

    fprintf(output, "%08x | ", offset);

    for (int i = 0; string_data[i] != L'\0'; i++) {
        unsigned char *bytes = (unsigned char *)&string_data[i];
        
        if (bytes[0] >= 0x20 && bytes[0] <= 0x7E) {
            ascii[ascii_count++] = bytes[0];
        } else {
            ascii[ascii_count++] = '.';
        }

        if (bytes[1] >= 0x20 && bytes[1] <= 0x7E) {
            ascii[ascii_count++] = bytes[1];
        } else {
            ascii[ascii_count++] = '.';
        }

        fprintf(output, "%02x %02x ", bytes[1], bytes[0]);
        count++;

        if (count % 8 == 0) {
            fprintf(output, "| %s\n", ascii);
            offset += 16;
            fprintf(output, "%08x | ", offset);
            memset(ascii, 0, sizeof(ascii));
            ascii_count = 0;
        }
    }

    if (count % 8 != 0) {
        fprintf(output, "\n");
    }
}

int main(void) {
    char command[256];
    wchar_t string_data[256];

    while (1) {
        printf("> ");
        
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("명령어 입력 오류\n");
            continue;
        }

        command[strcspn(command, "\n")] = '\0'; // 개행 문자 제거

        if (strcmp(command, "/input") == 0) {
            printf(" -> ");
            wscanf(L"%ls", string_data);
            hxd(string_data, stdout);
        
        } else if (strstr(command, "/save ") == command) {
            char *filename = strtok(command + 6, " ");
            char *input_string = strtok(NULL, "");

            if (filename != NULL && input_string != NULL) {
                FILE *file = fopen(filename, "w");
                if (file != NULL) {
                    mbstowcs(string_data, input_string, strlen(input_string) + 1);
                    hxd(string_data, file);
                    fclose(file);
                    printf("save success\n");
                } else {
                    printf("파일 저장 중 오류 발생\n");
                }
            } else {
                printf("명령어 오류\n");
            }

        } else if (strcmp(command, "/exit") == 0) {
            break;
        } else {
            printf("명령어 오류\n");
        }
    }

    return 0;
}
