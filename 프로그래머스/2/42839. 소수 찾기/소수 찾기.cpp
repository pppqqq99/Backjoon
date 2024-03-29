#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 10000000
bool checked[10000000] = {0, };
bool used[7] = {0, };
int cnt=0;

void era(int n){
    checked[0] = true;
    checked[1] = true;
    
    for(int i=2;i<=n/2;i++){
        for(int j=2;i*j<=n;j++){
            checked[i*j] = true;
        }   
    }
    
}

void prime_check(string str, string numbers){
    string orin = str;
    for(int i=0;i<numbers.length();i++){
        if(!used[i]){
            used[i] = true;
            str += numbers[i];
            //cout<<stoi(str)<<endl;
            
            // str을 문자열로 바꾸기
            int int_str = stoi(str);
            if(!checked[int_str]) { 
                cnt++; 
                checked[int_str] = true; 
                //cout<<int_str<<endl;
            }
            
            prime_check(str, numbers);
            used[i] = false;
            str = orin;
        }
    }
}

int solution(string numbers) {
    int answer = 0;

    // 문자열로 모든 숫자 조합 만들기
    // backtracking으로 만들기
        
        era(10000000);

    for(int i=0;i<numbers.length();i++){
        used[i] = false;
    } 
        //era(10000000);

    //for(int i=0;i<30; i++) cout<<checked[i]<<endl;
    prime_check("", numbers);
    
    //cout<<cnt<<endl;
    answer = cnt;
    return answer;
}