#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
deque <pii> snake; // 뱀
queue <int> dir; // 방향
int n, k, l;
int arr[101][101] ={0,};

// 0상, 1우, 2하, 3좌
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int direction(char ch, int d){
    int nd=d;

    if(ch=='D'){
        nd++;
    }else{
        nd--;
    }

    if(nd<0) nd=3;
    if(nd>3) nd=0;
    
    return nd;
}

bool promising(int y, int x){
    if(y>n || y<=0 || x>n || x<=0 || arr[y][x] == 1) return false;
    else return true;
}

int counting_sec(){
    int cnt=0;
    // 시작점 (1, 1)에서 출발 -> snake에 넣기
    snake.push_back({1, 1});
    arr[1][1] = 1;

    while(true){
        // 방향을 뽑아서 확인하고 뱀이라면 snake.push 아니라면 snake.push, snake.pop
        int dd = dir.front();
        int y = snake.front().first;
        int x = snake.front().second;
        int ny = y + dy[dd];
        int nx = x + dx[dd];
        dir.pop();
        
        // arr[ny][nx]가 벽이거나 자기 몸이 아니라면
        if(promising(ny, nx)){
            
            // 사과라면
            if(arr[ny][nx] == 0){
                int ty = snake.back().first;
                int tx = snake.back().second;
                snake.pop_back();
                arr[ty][tx] = 0;
            }
            snake.push_front({ny, nx});
            arr[ny][nx] = 1;
            cnt++;

        }else{
            cnt++;
            break;
        }
        
        if(dir.empty()){ dir.push(dd); }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    memset(arr, 0, sizeof(arr));

    cin>>n;
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b]=2; // 사과
    }

    int b=0, c, t, d=1;
    cin>>l;
    for(int i=0;i<l;i++){
        char ch;
        cin>>c>>ch;
        for(int i=b; i<c; i++){
            dir.push(d);
        }
        d = direction(ch, d);
        b = c;
    }
    dir.push(d);

    cout<<counting_sec()<<endl;

}