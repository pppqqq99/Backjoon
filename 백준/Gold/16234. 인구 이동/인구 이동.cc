#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, l, r;
int arr[51][51];
int checked[51][51];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int num=0;
int sum=0;

typedef pair<int, int> pii;
queue <pii> q;
vector <pii> v;

void bfs(int sy, int sx, int cnt){

    v.push_back({sy, sx});
    checked[sy][sx] = cnt;
    q.push({sy, sx});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            int diff = abs(arr[y][x] - arr[ny][nx]);
            
            if(ny<0 || ny>=n || nx<0 || nx>=n || checked[ny][nx] || diff < l || diff > r) continue;
            num++;
            sum += arr[ny][nx];
            checked[ny][nx] = cnt;
            q.push({ny, nx});
            v.push_back({ny, nx});
        }
    }

    
}

void trans(){
    for(int i=0; i<v.size(); i++){
        int y = v[i].first;
        int x = v[i].second;
        arr[y][x] = sum/num;
    }
}
void day_count(){
    int day=0;
    while(true){
        int cnt=0;
        memset(checked, 0, sizeof(checked));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!checked[i][j]){
                    cnt++;
                    num++; sum += arr[i][j];
                    bfs(i, j, cnt);
                    trans();
                    v.clear();
                    num=0; sum=0;
                }
            }
        }
        if(cnt == n*n){
            cout<<day<<endl;
            break;
        }
        day++;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    day_count();


}