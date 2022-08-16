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

int n,m;
int W[51][51];
vector <pair<int, int>> home;
vector <pair<int, int>> chick;
bool checked[14] = {false, };
vector <int> answer;
queue <st> q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[51][51] = {false,};
int num=0;
int ans=0;

bool promising(int y, int x){
    if(y>0 && y<=n && x>0 && x<=n && !visited[y][x]) return true;
    else return false;
}

void bfs(int y, int x, int d){

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(promising(ny, nx)){
            if(W[ny][nx] == 1) { num++; ans += (d+1); }
            visited[ny][nx] = true;
            q.push({ny, nx, d+1});
        }
        
    }
}

void calc(){
    ans = 0;
    num = 0;
    memset(visited, 0, sizeof(visited));

    for(int i=0;i<chick.size();i++){
        if(checked[i]) {q.push({chick[i].first, chick[i].second, 0}); visited[chick[i].first][chick[i].second] = true; }
    }

    
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int d = q.front().d;
        q.pop();
        bfs(y, x, d);
        if(num == home.size()) break;
    }
    q = queue<st>();
    answer.push_back(ans);
}

void btk(int idx, int cnt){
if(cnt == m) { calc(); return;}// for(int i=0;i<chick.size();i++) if(checked[i])cout<<i<<endl; cout<<endl;}
    for(int i=idx;i<chick.size();i++){
        if(!checked[i]){
            checked[i] = true;
            btk(i+1, cnt+1);
            checked[i] = false;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>W[i][j];
            if(W[i][j] == 1) home.push_back(make_pair(i, j));
            else if(W[i][j] == 2) chick.push_back(make_pair(i, j));
        }
    }
    // }
    // cout<<chick.size()<<endl;
    memset(checked, 0, sizeof(checked));
    btk(0, 0);
    sort(answer.begin(), answer.end());
    cout<<answer[0]<<endl;
    
}