#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
long long cost[10005][21]; // 해당 도시까지 j개의 포장 도로를 썼을 때 최솟 값
vector<pair<int, int>> way[10005]; //pos, cost
priority_queue<pair<long long, pair<int, int>>> pq; //cost,pos,포장

// 도로를 포장하는 경우, 포장하지 않는 경우
// -> cost[도시 번호][포장 도로 수]의 배열에 출발 도시부터 현재 번호 도시 까지 포장 도로를 사용했을 때 최소 비용
long long dijkstra(int start){
    int now, des, num;
    long long mcheck, pcost, minV = -1000000;

    // cost를 -1로 초기화
    for(int j=1; j<=n; j++){
        for (int i=0; i<21; i++)
            cost[j][i] = -1;
    }
    
    // 초기화
    cost[start][0] = 0;
    pq.push(make_pair(0, make_pair(start, 0))); // 우선순위 큐에 삽입
    
    while(!pq.empty()){ // pq에 요소가 있으면 반복
        now = pq.top().second.first;
        num = pq.top().second.second;
        mcheck = -pq.top().first; // pq의 top을 저장
        
        pq.pop(); // pq top 추출
        
        if(mcheck> cost[now][num]) // 0이면 -1보다 크므로
            continue;
        
        for(int j=0; j < way[now].size(); j++){ // way[here]에 존재하는 도로 확인
            des = way[now][j].first; // way[here]에 존재하는 도로의 도착 점 저장
            pcost = mcheck + way[now][j].second; // here->j 까지 가는 비용 저장
            
            if (num < k) // 포장 가능한 경우 -> 비용 0추가
            {
                if(cost[des][num+1] == -1) { // there에서 출발하여 cnt+1
                    cost[des][num+1] = mcheck;
                    pq.push(make_pair(-mcheck, make_pair(des, num+1)));
                }
                if (cost[des][num+1] > mcheck) {
                    cost[des][num+1] = mcheck;
                    pq.push(make_pair(-mcheck, make_pair(des, num+1)));
                }
            }
            if (cost[des][num]>pcost || cost[des][num] == -1) // 포장이 불가능한 경우 -> 비용 발생
            {
                cost[des][num] = pcost;
                pq.push(make_pair(-pcost, make_pair(des, num)));
            }
            
        }
    }
    minV = cost[n][0];
    
    for(int i=1; i<=k; i++){
        if(minV > cost[n][i] && cost[n][i] != -1)
            minV = cost[n][i];
    }
    return minV;
}




int main (void){

    int a, b, cost;
    cin>>n>>m>>k;
  
    // 포장 도로 입력 받으며 2차원 벡터에 저장
    for (int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &cost);
        way[a].push_back(make_pair(b, cost)); // (a, b, cost) 삽입
        way[b].push_back(make_pair(a, cost));
    }
    
    // 다익스트라 알고리즘을 이용해 최소 거리 찾기
    cout<<dijkstra(1)<<endl;;
    
}
