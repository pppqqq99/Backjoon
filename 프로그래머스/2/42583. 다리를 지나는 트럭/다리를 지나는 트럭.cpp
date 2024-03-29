#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cnt = 0;
    int sum = 0;
    
    // 큐 초기화
    queue <int> q;
    for(int i=0; i<bridge_length; i++){ q.push(0); }
    
    // truck을 모두 다리 위로 올리고 트럭이 다리 위를 다 건너가기 전까지 반복
    while(cnt < truck_weights.size()){
        
        sum -= q.front();
        q.pop();
        answer++;
        
        // 트럭이 다리 위에 올라갈 수 있으면 다리에 올리기
        if(truck_weights[cnt] + sum <= weight){
            q.push(truck_weights[cnt]);
            sum += truck_weights[cnt];
            cnt++;
            // cout<<cnt<<", "<<sum<<", "<<answer<<","<<q.size()<<endl;
        }else{
            q.push(0);
        }
        

        
    }
    answer += bridge_length;
    
    return answer;
}