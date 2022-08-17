#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

typedef struct st{
    int y;
    int x;
    int d;
}st;

char W[6][6];
int ld=0;
vector <pair<int, int>> ydy;
vector <pair<int, int>> lds;
bool checked[6][6] = {false, };
bool visited[6][6] = {false, };
vector <pair<int, int>> seven;
vector <int> answer;
queue <st> q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int num=0;
int ans=0;

bool promising(int y, int x){
    if(y>0 && y<=5 && x>0 && x<=5 && checked[y][x] && !visited[y][x]) return true;
    else return false;
}

void bfs(int y, int x, int d){
//cout<<y<<", "<<x<<endl;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(promising(ny, nx)){
            visited[ny][nx] = true;
            q.push({ny, nx, d+1});
            seven.push_back({ny,nx});
            num++;
            //cout<<"ny : "<<ny<<", nx : "<<nx<<endl;
        }
    }
}

void calc(int y, int x){
    memset(visited,0,sizeof(visited));
    num = 1;
    q.push({y,x,1});
    visited[y][x] = true;
    while(!q.empty()){
        int ky = q.front().y;
        int kx = q.front().x;
        int d = q.front().d;
        q.pop();
        if(num == 7) { ans++; break;}
        bfs(ky, kx, d);
    }
    q = queue<st>();
    seven = vector<pair<int, int>>();
}

void btk(int y, int x, int cnt){

    if(cnt == 7 && ld >= 4) { calc(y, x); return;}
    if(cnt == 7 && ld < 4) return;

    for(int i=y;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(y==i && j < x)continue;
            else if(!checked[i][j]){
                if(W[i][j] == 'S') ld++;
                checked[i][j] = true;
                btk(i,j,cnt+1);
                checked[i][j] = false;
                if(W[i][j] == 'S') ld--;
            }
        }
    }
}

int main(){
    
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            cin>>W[i][j];
        

    memset(checked, 0, sizeof(checked));
    btk(0, 0, 0);

    cout<<ans<<endl;
    
}