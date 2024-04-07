#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;

bool isPrime(int num){
    // 소수 구하기
    for(int i=2; i<=num/2; i++){
        if(num%i == 0) return false;
    }

    return true;
}

void dfs(int num){

    string num_str = to_string(num);

    // 1. 인자로 받은 수가 n자리 수일 경우 출력
    if(num_str.length() == n){
        cout<<num_str<<"\n";
        return ;
    }

    // 2. <인자로 받은 수 + 다음 자리 수>가 소수일 경우 dfs()진입
    for(int i=1;i<10;i++){
        int post_num = num*10+i;

        // 2-1. post_num이 소수인지 판별하기
        if(isPrime(post_num)){
            dfs(post_num);
        }
    }

}


int main(){

    // 0. n 입력
    cin>>n;

    // 1. dfs를 통한 n자리 신기한 소수 찾기
    for(int i=2;i<10;i++){
        if(isPrime(i)) dfs(i);
    }


}