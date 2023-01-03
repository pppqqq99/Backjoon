#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int arr[9][9];

vector <pair <int, int>> wall;
vector <pair <int, int>> virus;
vector <pair <int, int>> e;
vector <int> ans;
queue <pair <int, int>> q;

int vchecked[65] = {false, };
int checked[9][9] = {0, };

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

bool promising(int y, int x){
    if(y >=0 && y<n && x>=0 && x<m && !checked[y][x] && arr[y][x] == 0)
        return true;
    else 
        return false;
}

void bfs(){

    q = queue <pair <int, int>>();
    memset(checked, 0, sizeof(checked));

    for(int i=0;i<virus.size();i++){
        checked[virus[i].first][virus[i].second] = true;
        q.push(make_pair(virus[i].first, virus[i].second));
    }

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(promising(ny, nx)){
                checked[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
        q.pop();

    }
}

void cnt(){
    int c=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0 && !checked[i][j])
                c++;
        }
    }
    ans.push_back(c);
}

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                wall.push_back(make_pair(i, j));
            }else if(arr[i][j] == 2){
                virus.push_back(make_pair(i, j));
            }else{
                e.push_back(make_pair(i, j));
            }
        }
    }

    // 1. empty중 벽이 될 좌표 3개 고르기
    for(int i=0; i<e.size(); i++){
        if(!vchecked[i]){
            vchecked[i] = true;
            arr[e[i].first][e[i].second] = 1;

            for(int j=i+1; j<e.size(); j++){
                if(!vchecked[j]){
                    vchecked[j] = true;
                    arr[e[j].first][e[j].second] = 1;

                    for(int k=j+1; k<e.size(); k++){
                        if(!vchecked[k]){
                            vchecked[k] = true;
                            arr[e[k].first][e[k].second] = 1;
                            // 2. 바이러스 퍼트리기
                            bfs();
                            cnt();
                            arr[e[k].first][e[k].second] = 0;
                            vchecked[k] = false;
                        }
                    }
                    arr[e[j].first][e[j].second] = 0;
                    vchecked[j] = false;

                }
            }
            arr[e[i].first][e[i].second] = 0;
            vchecked[i] = false;
        }
    }

    sort(ans.begin(), ans.end());
    
    printf("%d\n", ans[ans.size()-1]);
    
    


}