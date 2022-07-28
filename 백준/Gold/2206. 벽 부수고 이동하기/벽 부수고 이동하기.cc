#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef struct s{
    int y;
    int x;
    int f;
}s;

int n,m;
char arr[1001][1001];
int W[1001][1001][2];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue <s> q;

bool promising(int y, int x, int f){
    if(y>=0 && x>=0 && y<n && x<m && W[y][x][f] == 0) return true;
    else return false;
}

void bfs(int y, int x, int f){
    int ny, nx;
    
    for(int i=0;i<4;i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(promising(ny, nx, f)){
            if(arr[ny][nx] == '0'){
                W[ny][nx][f] = W[y][x][f] + 1;
                q.push({ny, nx, f});
            }
            if(arr[ny][nx] == '1' && f == 0){
                W[ny][nx][f+1] = W[y][x][f] + 1;
                q.push({ny, nx, f+1});
            }
        }

    }
}
int main(){
    cin>>n>>m;
    memset(W, 0, sizeof(W));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    
    q.push({0,0,0});
    W[0][0][0] = 1;
    while(!q.empty()){
        int x,y,f;
        y = q.front().y;
        x = q.front().x;
        f = q.front().f;
        q.pop();
        if(y == n-1 && x == m-1){
            cout<<W[y][x][f]<<endl;
            exit(0);
        }
        bfs(y,x,f);
    }

    cout<<-1<<endl;
    
}
