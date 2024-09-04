#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main(void) {
    wchar_t string_data[256];
    wscanf(L"%ls", string_data);
    wprintf(L"%ls\n", string_data);
    return 0;
}