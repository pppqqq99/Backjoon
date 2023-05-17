#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = -1;
    int last_index_d = 0, last_index_p = 0; // 처리할 업무가 남아있는 마지막 집
    
    for(int i=0; i<n; i++){
        if(deliveries[i] > 0) last_index_d = i;
        if(pickups[i] > 0) last_index_p = i;
    }
    
    // answer구하기
    answer=0;
    // 더 이상 처리할 업무가 남아있지 않는 경우 - 
    while(!(last_index_d==0 && deliveries[0] == 0 && last_index_p==0 && pickups[0] == 0)){
        
        answer += (max(last_index_d, last_index_p)+1)*2;
        //cout<<answer<<",idx_d : "<<last_index_d<<" ,idx_p : "<<last_index_p<<endl;
        
            
        int box = cap; // 배송할 수 있는 박스 수
        // deliveries 처리
        for(int i=last_index_d; i>=0; i--){
            
            // 배송할 수 있는 박스 수가 현재 위치하는 집의 처리 박스 수 보다 작으면
            if(box < deliveries[i]){
                deliveries[i] -= box;
                box = 0;
                last_index_d = i;
                if(deliveries[i] > 0) break;
            }else{
                box -= deliveries[i];
                deliveries[i] = 0;
                if(i==0) last_index_d = 0;
            }
        } // 결과 : deliveries 처리, last_index
        
        box=cap;
        for(int i=last_index_p; i>=0; i--){
            
            // 배송할 수 있는 박스 수가 현재 위치하는 집의 처리 박스 수 보다 작으면
            if(box < pickups[i]){
                pickups[i] -= box;
                box = 0;
                last_index_p = i;
                if(pickups[i] > 0) break;
            }else{
                box -= pickups[i];
                pickups[i] = 0;
                if(i==0) last_index_p = 0;
            }
        }
    }
    return answer;
}