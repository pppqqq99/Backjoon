#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;
int n,m;
int checked[9] = {false};

deque <int> de;

void dfs(int cnt){

    if(cnt == m){
        for(long unsigned int i=0;i<de.size();i++){
            cout<<de[i]<<" ";
        }
        cout<<'\n';
        return ;
    }

    for(int i=1;i<=n;i++){
        if(!checked[i]){
            checked[i] = true;
            de.push_back(i);
            dfs(cnt+1);
            de.pop_back();
            checked[i] = false;
        }
    }

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    memset(checked, 0, sizeof(checked));
    dfs(0);

}