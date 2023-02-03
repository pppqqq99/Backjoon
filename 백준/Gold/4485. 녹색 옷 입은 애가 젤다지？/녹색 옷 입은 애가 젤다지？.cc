#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 130
#define INF 100000000

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;

int n;
int arr[MAX_N][MAX_N];
int DP[MAX_N][MAX_N];
int checked[MAX_N][MAX_N];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

priority_queue <ipii, vector<ipii>, greater<ipii>> q;

void dijkstra(){

    DP[0][0] = arr[0][0];
    q.push({DP[0][0], {0, 0}});


    while(!q.empty()){
        int y = q.top().second.first;
        int x = q.top().second.second;
        int l = q.top().first;
        
        q.pop();

        if(checked[y][x]) continue;
        checked[y][x] = true;

        for(int i=0; i<4; i++){
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if(ny < 0 || ny >= n || nx < 0 || nx >= n || checked[ny][nx]) continue;

            if(DP[ny][nx] > l + arr[ny][nx]){
                DP[ny][nx] = l + arr[ny][nx];
                //cout<<ny<<", "<<nx<<" : "<<l<<endl;
                q.push({DP[ny][nx], {ny, nx}});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt=1;
    while(true){
        cin>>n;
        if(n == 0) break;
        memset(arr, 0, sizeof(arr));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                DP[i][j] = INF;
            }
        }// INF로 채우기
        memset(checked, 0, sizeof(checked));
        q = priority_queue<ipii, vector<ipii>, greater<ipii>>();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }

        dijkstra();
        cout<<"Problem "<<cnt++<<": "<<DP[n-1][n-1]<<endl;
    }
}