// 10:20 - 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define INF 1200000000

using namespace std;

typedef pair<int, int> pii;

int n,m;
int DP[1001];

vector <pii> W[1001];
bool checked[1001] = {false};

priority_queue <pii, vector<pii>, greater<pii>> pq;

void dijkstra(int s, int e){

    int opt_node[1001];
    int opt_dis=0, cnt=0;
    

    // DP 배열 초기화
    for(int i=1; i<=n; i++){
        DP[i] = INF;
        opt_node[i] = -1;
    }
    DP[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        
        // pq에서 꺼냄
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(checked[node]) continue;
        checked[node] = true;
        

        // pq에서 꺼낸 도착 노드를 꺼내어 DP 배열 갱신
        // DP[i] == s->i
        // s->node->i
        for(int i=0; i<W[node].size(); i++){
            int target = W[node][i].first;
            int dis = W[node][i].second;

            if(DP[target] > DP[node] + dis){
                DP[target] = DP[node] + dis;
                pq.push({DP[target], target});
                opt_node[target] = node;
            }
        }
    }

    cout<<DP[e]<<endl;
    
    int par=e;
    stack <int> st;
    while(par != -1){
        cnt++;
        st.push(par);
        par = opt_node[par];
    }
    cout<<cnt<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sp, ep;

    fill(DP, DP+1001, INF);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int s,e,l;
        cin>>s>>e>>l;
        W[s].push_back({e, l});
    }
    cin>>sp>>ep;
    dijkstra(sp, ep);
}