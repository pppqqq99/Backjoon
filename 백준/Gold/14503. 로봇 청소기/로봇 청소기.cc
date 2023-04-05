// 10:24
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 방 : N*M, 청소기 바라보는 방향 - 동,서,남,북, 0은 청소되지 않은 빈 칸, 1은 벽
// 청소 로직
// 1. 현재 칸이 청소되지 않은 경우, 현재 칸을 청소함
// 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우 
// 2-1. 바라보는 방향으로 한 칸 후진
// 2-2. 바라보는 방향의 반대가 벽인 경우 - 작동 종료
// 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸 존재할 시 왼쪽으로 90도 회전 - 바라보는 방향 기준으로 앞컨이 청소되어 있지 않은 경우 한 칸 전진
int n, m, cnt=0;

// d - 0 - 상, 1 - 우, 2 - 하, 3- 좌
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int **arr, **checked;
void dfs(int sy, int sx, int d, int ret){
    // cout<<sy<<", "<<sx<<", "<<checked[sy][sx]<<", "<<ret<<endl;
    // 현재 칸이 벽인 경우
    if(arr[sy][sx] == 1){
        cout<<cnt<<endl;
        exit(0);
    }

    // 현재 칸이 청소되었는지 확인
    // if(!checked[sy][sx]){
    //     checked[sy][sx] = true;
    //     cnt++;
    // }

    // 바라보는 방향 기준 반시계 방향으로 탐색하며 청소 안된 칸 찾고 이동
    for(int i=d+3; i>=d; i--){
        int ny = sy + dy[i%4];
        int nx = sx + dx[i%4];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(!arr[ny][nx] && !checked[ny][nx]){
            checked[ny][nx] = true;
            cnt++;
            dfs(ny, nx, i%4, 0);
        }
    }

    // 더 이상 청소 안된 칸이 존재하지 않을 경우 뒤로 한 칸 이동
    if(!(sy+dy[(d+2)%4] < 0 || sy+dy[(d+2)%4] >= n || sx+dx[(d+2)%4] < 0 || sx+dx[(d+2)%4] >= m))
        dfs(sy+dy[(d+2)%4], sx+dx[(d+2)%4], d, 0);

    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sy, sx, d; // 로봇 청소기 시작 좌표와 방향
    // 입력
    cin>>n>>m;
    cin>>sy>>sx>>d;

    checked = (int **)malloc(sizeof(int *) * n);
    arr = (int **)malloc(sizeof(int *) * n);
    for(int i=0; i<n; i++){
        arr[i] = (int *)malloc(sizeof(int) * m);
        checked[i] = (int *)malloc(sizeof(int) * m);
    
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j]; 
            checked[i][j] = false;
        }
    }

    // 탐색
    checked[sy][sx] = true;
    cnt++;
    dfs(sy, sx, d, 0);
    cout<<cnt<<endl;


}