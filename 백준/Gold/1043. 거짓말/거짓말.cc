#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m; // n - 사람 수, m - 파티 수
int numOfTrue;
int parent[52] = {0, };
vector <int> v[52];

int getParent(int a){
    if(parent[a] < 0) return parent[a]; 
    if(a == parent[a]) return a;
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b){
    int p1 = getParent(a);
    int p2 = getParent(b);

    if(p1 == p2) return;
    if(p1 < 0) parent[p2] = p1;
    else if(p2 < 0) parent[p1] = p2;
    else if(p1 < p2) parent[p2] = parent[p1];
    else parent[p1] = parent[p2];
}

int main(){
    cin>>n>>m;
    cin>>numOfTrue;

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    // 진실을 아는 사람은 -1로 초기화
    for(int i=0; i<numOfTrue; i++){
        int tmp;
        scanf("%d", &tmp);
        parent[tmp] = -1;
    }

    for(int i=1; i<=m; i++){
        int t;
        scanf("%d", &t);

        // t = 0 이면 통과, 1 이면 unionParent(0, tmp)
        int bef = 51;
        parent[bef] = 51;
        while(t--){
            int tmp;
            scanf("%d", &tmp);
            v[i].push_back(tmp);
        //   printf("par[%d] : %d\n", tmp, parent[tmp]);
            unionParent(bef, tmp);
            bef = tmp;
        }
    }

    for(int i=1; i<=n; i++){
        getParent(i);
       // printf("par[%d] : %d\n", i, parent[i]);
    }
    // 부모 노드 공유하는
    int cnt=0;
    for(int i=1; i<=m; i++){
        int flag=0;
        for(int j=0; j<v[i].size(); j++){
            if(parent[v[i][j]] == -1) flag=1;
        }

        if(!flag) cnt++;
        // printf("par[%d] : %d\n", i, parent[i]);
        //int p = getParent(i);
    }

    cout<<cnt<<endl;
   
}