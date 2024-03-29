#include<vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

typedef struct st{
    int y;
    int x;
    int d;
}st;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool checked[101][101] = {false, };

queue <st> q;

int bfs(vector<vector<int> > maps, int n, int m){
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int d = q.front().d;
        q.pop();
        
        if(y==n-1 && x==m-1) {return d;}
        
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || checked[ny][nx] || maps[ny][nx] == 0) continue;
            
            checked[ny][nx] = true;
            q.push({ny,nx,d+1});
            //cout<<ny<<", "<<nx<<", "<<d+1<<endl;
            
        }
        
    }
    
    return -1;
}

// bfs 알고리즘을 통해 사방을 탐색

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    q.push({0,0,1});
    
    
    checked[0][0] = true;
    
   // cout<<maps.size()<<", "<<maps[0].size()<<endl;
    answer = bfs(maps, maps.size(), maps[0].size());
    return answer;
}