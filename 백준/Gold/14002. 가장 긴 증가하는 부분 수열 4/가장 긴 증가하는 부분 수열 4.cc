#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int DP[1001];



int main(){
    
    int n;
    int *arr;
    int *LCS;
    int max = 0,maxIndex=0, temp = 1, t;
    int c;
    
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int)*n+1);

    fill(DP+1,DP+n+1,1);
  

    for(int i=1;i<n+1;i++){ // i 번째 정수
        scanf("%d",&arr[i]);
        if(arr[i] > arr[maxIndex]){ // 입력 받은 값이 입력 받기 전 배열의 최댓 값보다 큰 경우
            max++;
            maxIndex = i;
            DP[i] = max;
        }else{ // 입력 받은 값이 배열의 최댓 값보다 작은 경우
            temp = 0; // 작은 것들 중 DP의 최댓 값
            for(int j=i;j>0;j--){ // 배열의 이전 값들을 역순으로 순회하며
                if(arr[i] > arr[j]){ // 입력받은 값이 이전 값보다 크고
                    if(temp < DP[j]){ // 작은 값들 중 DP의 최댓 값 발견 시
                        temp = DP[j]; // temp에 저장한다.
                        DP[i] = temp ; // 그리고 DP[i]를 최신화
                    }
                }
            }
           // printf("temp : %d, DP[%d] : %d\n",temp, i, DP[i]);
            if(temp>=max){
                maxIndex = i;
                max = temp;
            }
            if(temp == DP[i]){
                DP[i] = temp+1;
            }
            if(DP[i] == max){
                if(arr[maxIndex] > arr[i])
                    maxIndex = i;
                
            }
        }
        //printf("max : %d, maxIndex : %d , arr[maxIndex] = %d\n", max, maxIndex, arr[maxIndex]);

    }

//    for(int i=1;i<n+1;i++){
//        printf("%d ", DP[i]);
//    }
    printf("%d\n",max);

    c = max - 1;
    t = max;
    LCS = (int *)malloc(sizeof(int)*max);
    
    for(int i=n;i>0;i--){
        if(DP[i] == t){
            LCS[c] = arr[i];
            t--;
            c--;
        }
    }
   
    for(int i=0;i<max;i++){
        printf("%d ",LCS[i]);
    }

    
   
    
    
}
