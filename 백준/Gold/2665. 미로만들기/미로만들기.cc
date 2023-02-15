#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 100000000

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;

priority_queue <ipii, vector<ipii>, greater<ipii>> pq;
int n;
int arr[51][51] = {0, };
int checked[51][51] = {0, };
int dist[51][51] = {0, };


int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int dijkstra(){
    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    while(!pq.empty()){
        int l = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if(checked[y][x]) continue;
        //cout<<y<<", "<<x<<", "<<l<<endl;
        checked[y][x] = true;

        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];

            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;

            if(arr[ny][nx]){
                dist[ny][nx] = min(dist[ny][nx], l);
            }else{
                dist[ny][nx] = min(dist[ny][nx], l+1);
            }
            pq.push({dist[ny][nx], {ny, nx}});
        }
        
    }

    return dist[n-1][n-1];

}
int main(){
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = INF;
        }
    }
    memset(checked, false, sizeof(checked));
    cout<<dijkstra()<<endl;

}