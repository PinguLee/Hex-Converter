### size_t mbstowcs(wchar_t *dest, const char *src, size_t n);

#### 파라미터
- wchar_t *dest: 변환된 와이드 문자열을 저장할 버퍼
- const char *src: 변환할 멀티바이트 문자열
- size_t n: 변환할 최대 문자 수를 지정

#### 리턴
- 변환된 와이드 문자열의 길이(문자 수)를 반환합니다.
- 유효하지 않은 멀티바이트 문자를 만나면 (size_t)-1 리턴
- 변환 오류 발생 시 errno는 ECONVERT

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
