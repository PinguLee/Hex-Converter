#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void) {
    // SetConsoleOutputCP(65001);  // 출력 코드 페이지를 UTF-8로 설정
    // SetConsoleCP(65001);  // 입력 코드 페이지를 UTF-8로 설정

    char buffer[256];
    printf("입력 : ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("%s", buffer);
    return 0;
}