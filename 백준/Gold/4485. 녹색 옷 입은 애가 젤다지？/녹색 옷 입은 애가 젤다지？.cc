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

    // 출발 지점 값 삽입
    DP[0][0] = arr[0][0];
    q.push({DP[0][0], {0, 0}});

    while(!q.empty()){
        // q에 들어간 요소 중 출발지점과 가장 가까운 요소 뽑기
        int y = q.top().second.first;
        int x = q.top().second.second;
        int l = q.top().first;
        q.pop();

        // 이전에 뽑았다면 이전까지 최소이므로
        if(DP[y][x] < l) continue;
        //checked[y][x] = true;

        // 사방향 탐색
        for(int i=0; i<4; i++){
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            // 기존의 ny, nx로 가는 비용 보다 x, y를 거친 후 ny, nx로 가는 길이 더 작은 비용이라면
            if(DP[ny][nx] > l + arr[ny][nx]){
                DP[ny][nx] = l + arr[ny][nx];
                q.push({DP[ny][nx], {ny, nx}});
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt=1; // Problem #.

    while(true){
        // n 입력
        cin>>n;
        if(n == 0) break;

        // 테스트 케이스 별 메모리 초기화
        memset(arr, 0, sizeof(arr));
        for(int i=0; i<n; i++){ // INF로 채우기 - fill 함수 대체 가능
            for(int j=0; j<n; j++){
                DP[i][j] = INF;
            }
        }
        memset(checked, 0, sizeof(checked));
        q = priority_queue<ipii, vector<ipii>, greater<ipii>>();

        // 도둑 루피 입력
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }
        
        // 최소 비용 - 다익스트라
        dijkstra();
        // 정답 출력
        cout<<"Problem "<<cnt++<<": "<<DP[n-1][n-1]<<endl;
    }
}