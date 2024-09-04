#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/*
// hex�� ��ȯ old
void hxd(const char * data) {
    while(*data) {
        printf("%02x", (unsigned char)*data);
        data++;
    }
}
*/

void hxd(const wchar_t *string_data) {
    int count = 0;
    int offset = 0;

    for (int i = 0; string_data[i] != L'\0'; i++) {
        unsigned char *bytes = (unsigned char *)&string_data[i];
        printf("%02x %02x ", bytes[1], bytes[0]); // ��Ʋ �����ó�� ���̰� ���
        count++;

        if (count % 8 == 0) {
            printf("\n");
            offset += 16;
            printf("%08x | ", offset);
        }
    }

    // ������ �ٹٲ� ó��
    if (count % 8 != 0) {
        printf("\n");
    }
}

int main(void) {
    char command[7];
    wchar_t string_data[256];

    while (1) {
        printf("> ");
        
        // BOF ����
        if (scanf("%6s", command) != 1) {
            printf("�ִ� 6���� �Է�\n");
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
            printf("�ٽ� �Է��ϼ���.\n");
        }

    }

    return 0;
}
