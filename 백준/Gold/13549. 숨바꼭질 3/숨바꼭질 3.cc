#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,k;

typedef pair<int, int> pii;
priority_queue <pii, vector<pii>, greater<pii>> q;

bool checked[200003] = {false};

int dijkstra(int start, int end){
    int ret=-1;
    q.push({0, start});

    while(!q.empty()){
        int t = q.top().first;
        int p = q.top().second;
        q.pop();

        if(checked[p]) continue;
        checked[p] = true;

        if(p == end){
            ret = t;
            break;
        }

        if(p <= end && !checked[2*p]){
            q.push({t, 2*p});
        }
        if(p-1 >= 0 && !checked[p-1]){
            q.push({t+1, p-1});
        }
        if(p+1 <= end && !checked[p+1]){
            q.push({t+1, p+1});
        }
    }

    return ret;

}

int 
main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    cout<<dijkstra(n, k)<<endl;

}