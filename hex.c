#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buffer[256];
    printf("fgets 입력 : ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("%s\n", buffer);
    return 0;
}