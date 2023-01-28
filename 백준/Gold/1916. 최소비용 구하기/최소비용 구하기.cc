#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 100000000
#define MAX_N 1001

typedef pair<int, int> pii;

vector <pii> v[MAX_N];
int dist[MAX_N];
bool checked[MAX_N] = {false, };
priority_queue <pii, vector<pii>, greater<pii>> pq;

int n,m;

int dijkstra(int src, int dst){
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){

        int u = pq.top().second;
        pq.pop();
        
        if(dst == u) return dist[dst];
        if(checked[u]) continue;
        checked[u] = true;

        for(int i=0; i<v[u].size(); i++){
            int node = v[u][i].first;
            int cost = v[u][i].second;

            if(dist[node] > dist[u] + cost){
                dist[node] = dist[u] + cost;
                pq.push({dist[node], node});
            }
        }


    }
    return -1;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int s,d,l;
        scanf("%d %d %d", &s, &d, &l);
        v[s].push_back({d, l});
    }
    int src, dst;
    cin>>src>>dst;
    
    cout<<dijkstra(src, dst)<<endl;
}