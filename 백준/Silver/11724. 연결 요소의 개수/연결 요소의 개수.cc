#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v[1001];
bool checked[1001] = {false,};


void dfs(int start){

    if(checked[start]) return ;
    checked[start] = true;

    for(int i=0;i<v[start].size();i++){
        if(!checked[v[start][i]]) dfs(v[start][i]);
    }

    return ;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, cnt=0;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int start, end;
        cin>>start>>end;
        v[start].push_back(end);
        v[end].push_back(start);
    }

    for(int i=1;i<=n;i++){
        if(!checked[i]){
            cnt++;
            dfs(i);
        }
    }

    cout<<cnt<<endl;

}