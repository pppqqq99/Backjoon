#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <map>

using namespace std;
int n,m;
int W[1001][1001][2] = {0, };
int d[1001][1001];

typedef struct t{
    int x;
    int y;
    int l;
}t;

queue <t> q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(){
    t temp;
    int x,y,l, nx,ny;
    W[0][0][0] = 1;
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        l = q.front().l;
       // printf("%d %d %d, %d\n", y,x,l,W[y][x][l]);
        if(x == m-1 && y == n-1)
            return W[y][x][l];
        
        for(int i=0;i<4;i++){
            
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(W[ny][nx][l]) continue;
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            
            if(d[ny][nx] == 0){
              //  printf("%d\n",i);
                W[ny][nx][l] = W[y][x][l] + 1;
                temp.x = nx;
                temp.y = ny;
                temp.l = l;
                
                q.push(temp);
            }
            
            if(d[ny][nx] == 1 && l == 0){
               // printf("%d\n",i);
                W[ny][nx][l+1] = W[y][x][l] + 1;
                temp.x = nx;
                temp.y = ny;
                temp.l = l+1;
                
                q.push(temp);
            }
        }
        q.pop();
    }
    
    return -1;
}

int main(){
    cin>>n>>m;
    t s;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &d[i][j]);
    
   
    s.x = 0;
    s.y = 0;
    s.l = 0;
    
    q.push(s);
    printf("%d\n", bfs());
    
}
