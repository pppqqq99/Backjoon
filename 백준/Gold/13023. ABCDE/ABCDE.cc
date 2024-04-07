#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector <int> v[2001];
bool checked[2001] = {false, };

int dfs(int start, int depth){
    if(depth == 4){
        return 1;
    }

    checked[start] = true;
    int ret=0;

    for(int i=0; i<v[start].size(); i++){
        if(!checked[v[start][i]]){
            ret += dfs(v[start][i], depth+1);
        }
    }

    checked[start] = false;

    return ret;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 0. 입력
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int s, e;
        cin>>s>>e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    
    int flag=0;
    // 1. dfs를 통해 depth가 4인 관계가 존재한다면 1 출력, 없으면 0 출력
    for(int i=0;i<n;i++){
        memset(checked, 0, sizeof(checked));
        if(dfs(i, 0)){
            flag=1;
            break;
        }
    }
    
    if(flag) cout<<"1"<<endl;
    else cout<<"0"<<endl;

}