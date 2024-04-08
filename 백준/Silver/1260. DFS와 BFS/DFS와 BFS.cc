#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector <int> v[1001];
queue <int> q;
bool checked[1001] = {false, };

// dfs 결과 출력 함수
void dfs(int s){
    
    // 탐색 시작 노드 출력
    checked[s] = true;
    cout<<s<<" ";

    for(int i=0; i<v[s].size(); i++){
        if(!checked[v[s][i]]) dfs(v[s][i]);
    }
}

// bfs 결과 출력 함수
void bfs(int s){

    // 탐색 시작 노드 삽입
    q.push(s);
    checked[s] = true;
    
    while(!q.empty()){

        // q에 삽입
        int tmp = q.front();
        q.pop();
        cout<<tmp<<" ";

        // 
        for(int i=0; i<v[tmp].size(); i++){
            if(!checked[v[tmp][i]]){
                checked[v[tmp][i]] = true;
                q.push(v[tmp][i]);
            }
        }
    }

}

// AB : DFS와 BFS로 탐색한 결과를 추력하는 프로그램
// 시간 복잡도 : 
// 공간 복잡도 : 10000*4*2
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 0. 입력
    int n,m,s;
    cin>>n>>m>>s;
    // 양방향 그래프 저장
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(v[i].begin(), v[i].end());
    }

    // 1. dfs 탐색 결과 출력
    memset(checked, 0, sizeof(checked));
    dfs(s);
    cout<<endl;

    // 2. bfs 탐색 결과 출력
    memset(checked, 0, sizeof(checked));
    bfs(s);
    cout<<endl;
}