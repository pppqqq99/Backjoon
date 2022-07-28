# [Bronze II] 그대로 출력하기 2 - 11719 

[문제 링크](https://www.acmicpc.net/problem/11719) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현(implementation), 문자열(string)


### 사용 함수
#### fgets

'''cpp
#include <stdio.h> -> <cstdio>
char* fgets(char* str, int num, FILE* stream)
'''
  
stream에서 char문자를 num-1 개 만큼 읽은 후 뒤에 '\0'을 붙혀 str에 저장
num-1 개 만큼 읽지 않았을 때 '\n'이나 EOF를 만날 경우 현재까지 읽은 문자열만큼 str에 저장 후 리턴, 개행 문자를 읽었을 때는 개행 문자까지 str에 저장
읽어들인 문자열의 첫 번째 문자 주소를 리턴


'''cpp
char str[10];
fgets(str, 10, stdin);
cout<<str<<" : "<<strlen(str)<<endl;
'''
* num-1 만큼 읽은 후 strlen(str) == num-1
<img width="101" alt="스크린샷 2022-07-28 10 32 17" src="https://user-images.githubusercontent.com/64363668/181401120-dd16b310-47f3-4a26-8673-dcf6b875944e.png">

* num-1 만큼 읽기 전 개행 문자를 만났을 경우 strlen(str) == (개행 문자 포함까지의 길이)
<img width="45" alt="스크린샷 2022-07-28 10 32 24" src="https://user-images.githubusercontent.com/64363668/181401137-89961898-6302-4f8e-a307-02b456f73a8f.png">
