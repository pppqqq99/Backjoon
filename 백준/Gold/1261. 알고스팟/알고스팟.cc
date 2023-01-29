#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX_N 101

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;

priority_queue <ipii, vector<ipii>, greater<ipii>> pq;
int arr[MAX_N][MAX_N];
bool checked[MAX_N][MAX_N] = {false};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n,m;

bool promising(int y, int x){
    if(y<=0 || y>n || x<=0 || x>m || checked[y][x]) return false;
    return true;
}

int bfs(){
    int cnt=0;
    pq.push({0,{1, 1}});
    checked[1][1] = true;

    while(!pq.empty()){
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int c = pq.top().first;
        pq.pop();
        //cout<<y<<", "<<x<<endl;
        if(y==n && x==m){
            cnt = c;
            break;
        }

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(promising(ny, nx)){
                if(arr[ny][nx])
                    pq.push({c+1, {ny, nx}});
                else
                    pq.push({c, {ny, nx}});
                checked[ny][nx] = true;

            }
        }
    }

    return cnt;
}

int main(){
    cin>>m>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    cout<<bfs()<<endl;

}