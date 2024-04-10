#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n,m;
int W[101][101];
bool checked[101][101] = { false, };

typedef struct t{
    int y;
    int x;
    int length;
}t;

queue <t> q;
vector <t> v;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
// 1이 존재하는 좌표를 현재까지의 이동거리와 함께 queue에 삽입

// queue에서 꺼낸 것의 좌표 m,n이라면 vector에 삽입

bool valid(int x, int y){
    if(x<0 || x>=m || y<0 || y>=n || !W[y][x] || checked[y][x])
        return false;
    return true;
}

void bfs(){
    int x, y, l;
    t input;
    
    while(!q.empty()){
        
        for(int i=0;i<4;i++){
            x = q.front().x + dx[i];
            y = q.front().y + dy[i];
            l = q.front().length;
            
            if(valid(x,y)){
                checked[y][x] = true;
                input.x = x;
                input.y = y;
                input.length = l + 1;
                
                if(x == m-1 && y == n-1)
                    v.push_back(input);
                else
                    q.push(input);
            }
        }
        q.pop();
    }
}

bool compare(t t1, t t2){
    return t2.length < t1.length;
}

int main(){
    t temp;
    cin>>n>>m; // n - y, m - x
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%1d", &W[i][j]);
      
    temp.y = 0;
    temp.x = 0;
    temp.length = 1;
    q.push(temp);
    checked[0][0] = true;
    
    bfs();
    sort(v.begin(), v.end(), compare);
   
        printf("%d\n", v[v.size()-1].length);
}
