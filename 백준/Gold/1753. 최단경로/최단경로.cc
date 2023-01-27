#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 100000000
#define MAX_N 20001

typedef pair<int, int> pii;
vector <pii> v[MAX_N];

int n, e, s;
int dist[MAX_N];

void dijkstra(int src){
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    bool visited[MAX_N] = {false};

    for(int i=1; i<=n; i++){
        dist[i] = INF;
    } 
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int u = pq.top().second;
        //if(u == dst) return pq.top().first;
        pq.pop();
        if(visited[u]) continue;

        visited[u] = true;

        for(int i=0; i<v[u].size(); i++){
            if(dist[v[u][i].second] > dist[u] + v[u][i].first){
                dist[v[u][i].second] = dist[u] + v[u][i].first;
                pq.push({dist[v[u][i].second], v[u][i].second});
            }
        }
    }
    // return INF;

}

int main(){
    cin>>n>>e;
    cin>>s;
    
    for(int i=0; i<e; i++){
        int start, end, value;
        scanf("%d %d %d", &start, &end, &value);

        v[start].push_back({value, end});
    }

    dijkstra(s);
    for(int i=1; i<=n; i++){
        if(dist[i] == INF) cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }

    return 0;
}