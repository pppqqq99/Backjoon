#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
// 20 -> 3진법 = 1112
// 100 -> 8진법 = 

string notation(int num, int n){
    char code[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string tmp = "";
    while(num/n != 0){
        tmp = code[num%n] + tmp;
        num = num/n;
    }
    tmp = code[num%n]+tmp;
    return tmp;
}

string solve(int n, int t, int m, int p){
    string ans = "";
    int cnt=0;
    int num=0, f=0, talk=0;
    // t를 n진법으로 m 명이 말한다.
    // t/n>0일 경우 계속 반복하여 말한다.
    // n 진법 구하기 -> cnt/=n;
    for(int i=0; i<100000; i++){
        if(talk == t) break;
        string str = notation(num, n);
        num++;
        //cout<<str<<endl;
        // num을 n진수로 변환한 후 문자열로 저장
        // 문자열을 순서대로 읽으며 if(cnt/p == 0)일 때 ans에 추가
        for(int j=0;j<str.size();j++){
            if(cnt%m == p-1) {
                ans += str[j];
                talk++;
                if(talk==t) break;
            }
            cnt++;
        }
        
    }
    return ans;
    
}

// n 진법, t 말해야 하는 숫자의 개수, 참가하는 인원 m, 튜브의 순서 p
string solution(int n, int t, int m, int p) {
    
    string answer = "";
    answer = solve(n, t, m, p);
    return answer;
}