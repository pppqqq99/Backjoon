#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int t,m;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    while(t--){
        cin>>m;
        vector <int> v;
        cout<<(m+1)/2<<endl;
        for(int i=0; i<m; i++){
            int k, h;
            cin>>k;
            int idx = lower_bound(v.begin(), v.end(), k) - v.begin();
            v.insert(v.begin() + idx, k);
            if((h = i%2) == 0){
                h = i/2;
                cout<<v[h]<<" ";
            }
        }
        cout<<'\n';
    }
    
}