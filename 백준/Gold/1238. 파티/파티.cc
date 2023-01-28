#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 1001
#define INF 100000000

typedef pair<int, int> pii;
int n, m, x;

vector <pii> back[MAX_N];
vector <pii> come[MAX_N];

void dijkstra(int src, int* dist, vector <pii> *v){
    bool checked[MAX_N] = {false};
    priority_queue <pii, vector<pii>, greater<pii>> pq;

    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(checked[u]) continue;
        checked[u] = true;

        for(int i=0; i<v[u].size(); i++){
            int node = v[u][i].first;
            int weight = v[u][i].second;
            if(dist[node] > dist[u] + weight){
                dist[node] = dist[u] + weight;
                pq.push({dist[node], node});
            }
        }
    }
}
int main(){

    cin>>n>>m>>x;
    for(int i=0; i<m; i++){
        int s,e,l;
        scanf("%d %d %d", &s, &e, &l);
        back[s].push_back({e, l});
        come[e].push_back({s, l});
    }

    int dist_come[MAX_N];
    dijkstra(x, dist_come, come);
    int dist_back[MAX_N];
    dijkstra(x, dist_back, back);
    int sum = 0;
    
    for(int i=1; i<=n; i++){
        if(sum < dist_come[i] + dist_back[i]){
            sum = dist_come[i] + dist_back[i];
        }
    }

    cout<<sum<<endl;

}