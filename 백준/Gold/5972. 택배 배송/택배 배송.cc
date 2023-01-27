#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 50001
#define INF 100000000

typedef pair<int, int> pii;
vector <pii> v[MAX_N];
int dist[MAX_N];
bool checked[MAX_N] = {false};
priority_queue <pii, vector<pii>, greater<pii>> pq;

int n, m;

void dijkstra(int src){
    // dist 배열 초기화
    for(int i=1; i<=n; i++){
        dist[i] =INF;
    }
    dist[src] = 0;

    // pq에 시작점 삽입
    pq.push({0, src});

    // pq가 빌 때 까지
    while(!pq.empty()){

        // 현재 pq에 존재하는 노드 중 0과 가장 가까운 노드 추출
        int u = pq.top().second;
        pq.pop();

        // 이전에 방문했다면 continue;
        if(checked[u]) continue;
        //pq.pop();
        checked[u] = true;

        for(int i=0; i<v[u].size(); i++){
            int targetNode = v[u][i].first;
            int cost = v[u][i].second;
            if(dist[targetNode] > dist[u] + cost){
                dist[targetNode] = dist[u] + cost;
                pq.push({dist[targetNode], targetNode});
            }
        }

        
    }
}

int main(){

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int s,d,l;
        scanf("%d %d %d", &s, &d, &l);

        v[s].push_back({d, l});
        v[d].push_back({s, l});

    }

    dijkstra(1);

    cout<<dist[n]<<endl;

}
