### char *strstr(const char *haystack, const char *needle);

- haystack : 검색 대상 문자열
- needle : 검색 하고자 하는 문자열

일치하면 일치하는 곳부터 끝까지 출력

#### 예제 1
```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char *string1 = "a test";
    char *string2 = "test";
    char *result;

    result = strstr(string1, string2);
    printf("%s\n", result);
    return 0;
}

> test
```
#### 예제 2
```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char *string1 = "test a";
    char *string2 = "test";
    char *result;

    result = strstr(string1, string2);
    printf("%s\n", result);
    return 0;
}

> test a
```
