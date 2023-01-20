#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;
unordered_map <string, int> name;
// vector <string> name;
vector <int> parent, cnt;

int getParent(int a){
    if(a == parent[a]) return a;
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b){
    int p1 = getParent(a);
    int p2 = getParent(b);


    if(p1 < p2){
        parent[p2] = p1;
        cnt[p1] += cnt[p2];
    }else if(p1 > p2){
        parent[p1] = p2;
        cnt[p2] += cnt[p1];
    }
}

// int findParent(int a, int b){
//     int p1 = getParent(a);
//     int p2 = getParent(b);

//     if(p1 == p2) return 1;
//     else return 0;
// }



int t,f;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>t;

    while(t--){
        cin>>f;

        name.clear();
        parent.assign(f*2+1, 0);
        cnt.assign(f*2+1, 1);

        for(int i=0; i<=f*2+1; i++){
            parent[i] = i;
        }

        int idx=0;

        for(int i=1; i<=f; i++){
            string str1, str2;
            cin>>str1>>str2;
            
            int f1 = 0, f2 = 0;
            
            // 문자열이 해쉬맵에 존재한다면 해당 key의 value값 리턴
            //iter = name.find(str1);
            if(name.count(str1) != 0){
                f1 = name[str1];
            }else{
                name[str1] = ++idx;
                f1 = idx;
            }

            // iter = name.find(str2);
            if(name.count(str2) != 0){
                f2 = name[str2];
            }else{
                name[str2] = ++idx;
                f2 = idx;
            }
 
            unionParent(f1, f2);
            int target = getParent(f1);
            cout<<cnt[target]<<"\n";
        }

    }
}