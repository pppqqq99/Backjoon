#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int, int>> v;
queue <pair<int, int>> q;
int checked[101] = {false, };

int t, n;

bool arrive(int sy, int sx){
    if(abs(v[n+1].first - sy) + abs(v[n+1].second - sx) <= 1000)
        return true;
    else 
        return false;
}

void bfs(){
    int flag = 0;
    checked[0] = true;
    q.push(make_pair(v[0].first, v[0].second));

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        if(arrive(y, x)){
            flag = 1;
            break;
        }else{
            // printf("-1\n");
            for(int i=1; i<=n; i++){
                if(!checked[i]){
                    if(abs(v[i].first - y) + abs(v[i].second - x) <= 1000){
                        checked[i] = true;
                        q.push(make_pair(v[i].first, v[i].second));
                        // printf("%d\n", i);
                    }
                }
            }
        }
        q.pop();
    }

    if(flag == 0) printf("sad\n");
    else printf("happy\n");
   
    
}

int main(){
    cin>>t;
    while(t-- > 0){
        cin>>n;
        v = vector <pair<int, int>>();
        q = queue <pair<int, int>>();
        memset(checked, 0, sizeof(checked));

        for(int i=0; i<n+2; i++){
            int x, y;
            scanf("%d %d", &y, &x);
            v.push_back(make_pair(y, x));
        }
        
        bfs();
       
    }
}
