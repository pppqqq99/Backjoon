#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[500001];

int n,m;

int getParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);

    // 둘이 같을 경우 - 사이클이 됨
    if(a == b) return true;
    else if(a > b) parent[a] = b;
    else parent[b] = a;
    return false;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans=0, cnt=1;

    cin>>n>>m;
    for(int i=0; i<=n; i++) parent[i] = i;

    for(int i=0; i<m; i++){
        int t1, t2;
        cin>>t1>>t2;
        if(unionParent(t1, t2) && !ans){
            ans = cnt;
            
        }
        cnt++;
    }

    cout<<ans<<endl;
}