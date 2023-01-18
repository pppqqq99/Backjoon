#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
int parent[201] = {0, };
vector <int> v;

int getParent(int a){
    if(parent[a] == a) return parent[a];
    else return getParent(parent[a]);
}

// 두 개의 노드의 부모를 합치는 함수
void unionParent(int a, int b){
    int p1 = getParent(a);
    int p2 = getParent(b);

    if(p1 < p2) parent[p2] = p1;
    else parent[p1] = p2;
}
// 두 개의 노드가 같은 부모인지 확인하는 함수
int findParent(int a, int b){
    int t1 = getParent(a);
    int t2 = getParent(b);

    if(t1 != t2) return 0;
    else return 1;
}

int main(){
    int tmp;

    for(int i=1; i<sizeof(parent)/sizeof(int); i++){
        parent[i] = i;
    }

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &tmp);
            if(tmp == 1){
                unionParent(i, j);
            }
        }
    }

    for(int i=0; i<m; i++){
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    for(int i=0; i<m-1; i++){
        if(!findParent(v[i], v[i+1])){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}