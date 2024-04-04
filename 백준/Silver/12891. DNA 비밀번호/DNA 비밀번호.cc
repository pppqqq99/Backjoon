#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 문자를 받아 문자에 해당하는 인덱스 리턴하는 함수
int checkCh(char ch){
    if(ch == 'A') return 0;
    else if(ch == 'C') return 1;
    else if(ch == 'G') return 2;
    else return 3;
}

// 두 배열을 인자로 받아 두 배열의 값이 일치하는지 확인하는 함수
bool checkPass(int* passArr, int* checkArr){
    for(int i=0; i<4; i++){
        if(passArr[i] < checkArr[i]) return false;
    }
    return true;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, p, cnt=0;
    string str;
    int checkArr[4] = {0,0,0,0};
    int passArr[4] = {0,0,0,0};

    // 0. 입력
    cin>>s>>p;
    cin>>str;
    for(int i=0; i<4; i++){
        cin>>checkArr[i];
    }


    // 1. 첫번째 비밀번호 세팅, 비밀번호 조건 확인하여 cnt에 반영
    for(int i=0; i<p; i++){
        // str[i]의 비밀번호 추가
        passArr[checkCh(str[i])]++;
    }


    // 2. 슬라이딩 알고리즘을 사용하여 비밀번호 조건 확인하며 cnt에 반영
    for(int i=0; i+p-1<s; i++){


        // 2-1. passArr와 checkArr의 개수가 같을 시 true 리턴
        if(checkPass(passArr, checkArr)){ cnt++; } 
        
        // 2-2. start 커서 옮기며 passArr에 반영
        passArr[checkCh(str[i])]--;

        // 2-3. end 커서 옮기며 passArr에 반영
        passArr[checkCh(str[i+p])]++;
    }

    cout<<cnt<<endl;
}