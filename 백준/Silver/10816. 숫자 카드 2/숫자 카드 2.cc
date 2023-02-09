#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n,m;

unordered_map <int, int> checked;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        if(checked.count(t) > 0){
            checked[t]++;
        }else{
            checked.insert({t, 1});
        }
    }

    cin>>m;
    for(int i=0; i<m; i++){
        cin>>t;
        cout<<checked[t]<<" ";
    }

}