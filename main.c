#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/*
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
*/

void hxd(const wchar_t *string_data) {
    int count = 0;
    int offset = 0;
    int ascii_count = 0;
    char ascii[999];

    printf("%08x | ", offset);

    for (int i = 0; string_data[i] != L'\0'; i++) {
        unsigned char *bytes = (unsigned char *)&string_data[i];
        
        // �ƽ�Ű �ڵ�� 0x20~0x7E�� ǥ���� (�������� . ���� ǥ��)
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

        printf("%02x %02x ", bytes[1], bytes[0]); // ��Ʋ �����ó�� ���̰� ���
        count++;

        if (count % 8 == 0) {
            ascii[ascii_count] = '\0';  // Null-terminator �߰�
            printf("| %s\n", ascii);    // ASCII ���� ���
            offset += 16;
            printf("%08x | ", offset);
            memset(ascii, ' ', sizeof(ascii) - 1);  // ASCII �迭�� �������� �ʱ�ȭ
            ascii_count = 0;
        }
    }

    if (count % 8 != 0) {
        ascii[ascii_count] = '\0';
        int padding = (8 - (count % 8)) * 5;
        printf("%*s| %s\n", padding, "", ascii);
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
