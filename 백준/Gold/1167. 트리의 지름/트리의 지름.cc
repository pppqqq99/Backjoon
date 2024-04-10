#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n;

vector <pii> v[100001];
int dp[100001] = {0,};
int maxNode=0, maxValue=0;

queue <int> q;

void bfs(int start){

    maxNode =0, maxValue=0;

    dp[start] = 0;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0;i<v[node].size();i++){
            // 현재 노드와 인접한 노드
            int next = v[node][i].first; 
            int len = v[node][i].second;
            //cout<<"node : "<<node<<", next : "<<next<<", len : "<<len<<endl;
            
            if(dp[next] > 0 || next == start) continue;

            dp[next] = dp[node] + len;

            if(maxValue < dp[next]){
                maxNode = next;
                maxValue = dp[next];
                //cout<<"maxValue : "<<maxNode<<", maxNode : "<<maxValue<<endl;
            }

            q.push(next);

        }
    }
    
}

int main(){

    // 0. 입력
    cin>>n;
    for(int i=0;i<n;i++){
        int len=0, st, node=0, cnt=0;
        cin>>st;
        while(node != -1){
            // 시작 노드를 입력 받기 -> 입력이 문제
            if(cnt%2 == 0){
                cin>>node;
            } 
            else{
                cin>>len;
                v[st].push_back({node, len});
            }
            cnt++;
        }
    }



    // 1. 임의의 점을 선택하여 가장 거리가 먼 노드 찾기
    // 인접 노드로 이동하여 현재 노드 부터 해당 노드까지의 거리를 dp 테이블에 채움
    bfs(1);
    memset(dp, 0, sizeof(dp));

    // 2. 가장 거리가 먼 노드에서 출발하여 해당 노드와 가장 먼 노드의 거리 구하기
    bfs(maxNode);
    cout<<maxValue<<endl;
}
