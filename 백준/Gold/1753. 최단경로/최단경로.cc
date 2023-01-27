#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 100000000
#define MAX_N 20001

typedef pair<int, int> pii;
vector <pii> v[MAX_N];
priority_queue<pii, vector<pii>, greater<pii>>pq;
bool visited[MAX_N] = {false};

int n, e, s;
int dist[MAX_N];

void dijkstra(int src){

    // dist 배열 초기화
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    } 
    dist[src] = 0;

    // pq에 시작점 삽입
    pq.push({0, src});

    // pq가 빌 때까지
    while(!pq.empty()){

        // pq에 삽입된 노드 중 src와 가장 가까운 노드 뽑기
        int u = pq.top().second;
        pq.pop();

        // 방문한 적이 있는 노드라면 스킵 
        if(visited[u]) continue;

        // 방문 체크 - u노드는 0-u 까지의 최단경로임이 보장됨
        visited[u] = true;

        // dist 배열 갱신 및 pq 삽입
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

    // 입력
    cin>>n>>e;
    cin>>s;
    for(int i=0; i<e; i++){
        int start, end, value;
        scanf("%d %d %d", &start, &end, &value);
        v[start].push_back({end, value});
    }

    // dijkstra 알고리즘 수행
    dijkstra(s);

    // 출력
    for(int i=1; i<=n; i++){
        if(dist[i] == INF) cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }

    return 0;
}