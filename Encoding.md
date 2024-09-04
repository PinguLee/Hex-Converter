## 인코딩 (데이터를 특정 형식으로 변환)

ASCII: 7비트로 128개의 문자와 기호를 표현

UTF-8: 가변 길이 인코딩 방식으로, 1~4바이트로 유니코드 문자를 표현

UTF-16: 2바이트 또는 4바이트로 유니코드 문자를 표현

UCS-2: 2바이트로 BMP(기본 다국어 평면) 문자만을 표현

UCS-4: 4바이트로 모든 유니코드 문자를 표현


## 문자 인코딩 예시
문자: 'A'

ASCII 인코딩: 65 (0x41)

UTF-8 인코딩: 0x41 (1바이트)

UTF-16 인코딩: 0x0041 (2바이트)

UCS-4 인코딩: 0x00000041 (4바이트)


## 예제
```c
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
        wprintf(L"%x ", string_data[i]);
    }
    wprintf(L"\n");
    return 0;
}

> ㅁ
a4 b1
```