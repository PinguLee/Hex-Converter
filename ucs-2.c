#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/*
wchar_t 를 사용하는 순간 UCS-2 또는 UTF-16 방식으로 문자열 처리

*/
int main(void) {
    wchar_t string_data[256];
    wscanf(L"%ls", string_data);
        
    for (int i = 0; string_data[i] != L'\0'; i++) {
        wprintf(L"%04x ", string_data[i]);
    }
    wprintf(L"\n");
    return 0;
}