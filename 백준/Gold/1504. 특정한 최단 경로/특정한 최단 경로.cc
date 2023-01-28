#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX_N 8001
#define INF 100000000

typedef pair<int, int> pii;

int n,e;

vector <pii> v[MAX_N];

int dijkstra(int src, int dst){
    int dist[MAX_N];
    bool checked[MAX_N] = {false};
    priority_queue <pii, vector<pii>, greater<pii>> pq;

    for(int i=0; i<=n; i++){
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
            int weight = v[u][i].second;

            if(dist[node] > dist[u] + weight){
                dist[node] = dist[u] + weight;
                pq.push({dist[node], node});
            }
        }
    }

    return -1;
}

int root_path(int v1, int v2){
    int sum=0, tmp;
    if((tmp = dijkstra(1, v1)) < 0) return -1;
    sum += tmp;
    if((tmp = dijkstra(v1, v2)) < 0) return -1;
    sum += tmp;
    if((tmp = dijkstra(v2, n)) < 0) return -1;
    sum += tmp;
    return sum;
}

int main(){
    int s1, s2, root1=0, root2=0;

    cin>>n>>e;
    for(int i=0; i<e; i++){
        int s,e,l;
        scanf("%d %d %d", &s, &e, &l);
        v[s].push_back({e, l});
        v[e].push_back({s, l});
    }
    
    cin>>s1>>s2;
    // 1->s1->s2->n
    root1 = root_path(s1, s2);
    // 1->s2->s1->n
    root2 = root_path(s2, s1);

    if(root1 < 0){
        cout<<root2<<endl;
    }else if(root2 < 0){
        cout<<root1<<endl;
    }else{
        cout<<min(root1, root2)<<endl;
    }

}