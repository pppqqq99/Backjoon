#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int n,m;

unordered_map <int, int> map;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        map.insert({t, 1});
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>t;
        if(map.count(t) >= 1){
            cout<<"1 ";
        }else{
            cout<<"0 ";
        }
    }
}