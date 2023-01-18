#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
bool checked[201] = {false, };
queue <int> q;
vector <int> v;
vector <int> arr[201];

void bfs(int cnt){

    if(cnt == m){
        cout<<"YES"<<endl;
        return ;
    }
    // queue와 checked 배열 초기화
    q = queue <int>();
    memset(checked, 0 ,sizeof(checked));

    // queue에 시작점 삽입3
    q.push(v[cnt]);
    checked[v[cnt]] = true;
    
    if(v[cnt] == v[cnt+1]){
        bfs(cnt+1);
        return ;
    }
    while(!q.empty()){
        int now = q.front();
        for(int i=0; i<arr[now].size(); i++){
            if(arr[now][i] == v[cnt+1]){
                bfs(cnt+1);
                return ;
            }else if(!checked[arr[now][i]]){
                q.push(arr[now][i]);
                checked[arr[now][i]] = true;
            }else{
                ;
            }
        }
        q.pop();
    }
    cout<<"NO"<<endl;

}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int tmp;
            scanf("%d", &tmp);
            if(tmp == 1){
                arr[i].push_back(j);
            }
        }
    }


    v.push_back(0);
    for(int i=0; i<m; i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }

    if(m==2 && v[1] == v[2]){
        cout<<"YES"<<endl;
    }else{
        bfs(1);
    }

}