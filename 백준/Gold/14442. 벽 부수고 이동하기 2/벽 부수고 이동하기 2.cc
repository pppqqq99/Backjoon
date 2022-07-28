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

int n,m,k;
queue <s> q;
int arr[1001][1001];
int W[1001][1001][11];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

bool promising(int y, int x, int f){
    if(y>=0 && x>=0 && y<n && x<m && f<=k && W[y][x][f] == 0) return true;
    else return false;
}

void bfs(int y, int x, int f){
    int ny, nx;

    for(int i=0;i<4;i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(promising(ny, nx, f)){
            if(arr[ny][nx] == 0){
                W[ny][nx][f] = W[y][x][f] + 1;
                q.push({ny, nx, f});
            }
            if(arr[ny][nx] == 1 && f<k && W[ny][nx][f+1]==0){
                W[ny][nx][f+1] = W[y][x][f] + 1;
                q.push({ny, nx, f+1});
            }
        }
    }
}
int main(){
    cin>>n>>m>>k;
    char ch;
    fflush(stdin);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%1d", &arr[i][j]);
    
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)
    //         cout<<arr[i][j];
    //     cout<<endl;
    // }
    
    memset(W, 0, sizeof(W));

    q.push({0,0,0});
    W[0][0][0] = 1; // 시작 점 포함이므로 

    while(!q.empty()){
        int y,x,f;
        y = q.front().y;
        x = q.front().x;
        f = q.front().f;
        q.pop();
        if(y == n-1 && x == m-1){
            printf("%d\n", W[y][x][f]);
            exit(0);
        }
        bfs(y,x,f);
    }

    printf("-1\n");
    
}