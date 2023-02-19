#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

// queue에 삽입하는 단위
typedef struct node{
    int y;
    int x;
    int l;
    char ch;
}node;

int r,c;

char w[1002][1002];

vector <pair<int, int>> f;
queue <node> n;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// queue에 삽입할 수 있는 노드인지 검사하는 함수
bool promising(int y, int x, char ch){

    // 이전 노드가 F이고 탐색 좌표가 .이거나 J일 때 -> 불이 옮겨갈 수 있는 상황
    if(ch == 'F' && (w[y][x] == '.' || w[y][x] == 'J')){
        w[y][x] = 'F';
        return true;
    }else if(ch == 'J' && w[y][x] == '.'){ // 이전 노드가 J이고 탐색 노드가 .일 때 -> J가 이동할 수 있는 상황
        w[y][x] = 'J';
        return true;
    }else if(ch == 'J' && (y < 0 || y >= r || x < 0 || x >= c)){ // 이전 노드가 J이고 탐색 노드가 .은 아니지만 탈출할 수 있는 상황일 때
        return true;
    }else{
        return false;
    }

}

// 그래프 탐색
void bfs(){

    // queue가 빌 때까지 반복
    while(!n.empty()){

        // queue의 front값 추출
        int y = n.front().y;
        int x = n.front().x;
        int l = n.front().l;
        char ch = n.front().ch;

        // queue에서 추출한 좌표의 값이 원래 J였으나, BFS 탐색 과정에서 F로 바뀐 경우 탐색하지 않음
        if(ch == 'J' && w[y][x] == 'F'){
            ;
        }else{

            // 뽑은 것이 J이고 가장자리에 닿아있다면 탈출
            if(y < 0 || y >= r || x < 0 || x >= c){
                printf("%d\n", l);
                return;
            }

            // queue에서 추출한 값의 상하좌우 탐색
            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                int nl = l + 1;
                
                // 조건에 부합할 경우 queue에 삽입
                if(promising(ny, nx, ch)){
                    n.push({ny, nx, nl, ch});
                }
            }
        }

        // 확인한 요소 queue에서 추출
        n.pop();
    }

    // queue가 빌 때까지 탈출하지 못했다면 
    printf("IMPOSSIBLE\n");
}


int main(){
    int jy, jx;
    string str;
    cin>>r>>c;

    // 입력부
    for(int i=0; i<r; i++){

        // 한 문장씩 입력 받기
        cin>>str;

        // 입력 받은 문자열을 검사하며 w 배열에 저장
        for(int j=0; j<c; j++){
            w[i][j] = str[j];

            // 입력 받은 문자 중 J가 존재하면 초기 위치 좌표로 저장
            if(w[i][j] == 'J'){
                jy = i;
                jx = j;
            }else if(w[i][j] == 'F'){ // 입력 받은 문자 중 F가 존재하면 불의 좌표를 저장하는 벡터에 저장
                f.push_back({i, j});
            }
        }
    }

    // queue에 초기 위치 부터 삽입한 후, 불의 위치를 삽입
    n.push({jy, jx, 0, 'J'});
    for(int i=0; i<f.size(); i++){
        n.push({f[i].first, f[i].second, 0, 'F'});
    }

    // J위치 부터 탈출 최단 경로 탐색
    bfs();

}