//
//  boj1415.cpp
//  backjoon
//
//  Created by 임형준 on 2022/03/16.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



void prime(bool primeNum[500001]){
    for(int i=2;i<500000;i++){
        if(primeNum[i]==false)
            for(int j=2;j*i<500000;j++){
                primeNum[i*j]=true;
            }
    }
}


// v에 담긴 숫자 집합으로 primeNum[i]를 만들 수 있는지 판별하는 함수


int main(){
    long long *DP;
    bool primeNum[500001]={false};
    int *buf; // 입력받은 수 저장할 배열
    int *numCount; // 입력받은 수와 갯수를 체크하는 배열
    int n, candy, numOfInput = 0, c = 0, i, max;
    long long total = 0;
    scanf("%d",&n);
    
    prime(primeNum);
    

    max = n*10000+1;
    numCount = new int[max](); // 입력받은 수들의 총 합의 최댓 값 크기 배열 생성
    for(i = 0;i<max;i++){
        numCount[i] = 0;
    }
    for(i=0;i<n;i++){
        scanf("%d",&candy);
        if(numCount[candy]==0){ // 입력 받은 candy가 처음 입력 받는 수라면
            numOfInput++;
        }
        numCount[candy]++; // numCount에 입력 받은 수의 개수 저장
        
    }
    
    
    buf = new int[numOfInput]();
    for(i=0; i<max; i++){ // buf에 입력 받은 수들을 중복되지 않게 하나씩만 저장
        if(numCount[i]!=0)
            buf[c++] = i;
        //printf("numCount[%d] = %d\n",i,numCount[i]);
    }
    
    for(i=0; i<c; i++){ // buf에 입력 받은 수들을 중복되지 않게 하나씩만 저장
     
        //printf("buf[%d] = %d\n",i,buf[i]);
    }
    // DP[n]은 입력 받은 수들의 집합으로 n을 만드는 조합의 수
    DP = new long long[max]();
    DP[0] = 1; // 0은 아무것도 없는 조합 한 개로 만들 수 있음
    
    for(i=0;i<c;i++){ // buf[i]
        for(int j=max;j>0;j--){ // DP 큰 문제부터 작은 문제로 접근
            for(int k=1;k<=numCount[buf[i]];k++){ // 갯수만큼 반복
                if(j - (buf[i]*k) < 0) //
                   break;
                DP[j] += DP[j - (buf[i]*k)]; // buf[i]*j 는 buf[i]의 갯수
                 //printf("DP[%d] = %lld\n",j,DP[j]);
            }
    
        }
    }
    
//        printf("DP[%d] = %lld\n",2,DP[2]);
//        printf("DP[%d] = %lld\n",1,DP[1]);
//        printf("DP[%d] = %lld\n",0,DP[0]);
        for(i=2;i<max;i++){
            if(primeNum[i] == false){
                total += DP[i];
            }
        }
    
        if(buf[0]==0)
            total *= (numCount[0]+1);
        
        printf("%lld\n",total);
                    
    
   
}

