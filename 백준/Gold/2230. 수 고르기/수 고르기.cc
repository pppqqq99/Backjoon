#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long m;

vector <int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    int l=0,r=0;
    long long ans=2000000000;
    while(l < n && r < n){
        long long diff = v[r]-v[l];
        if(diff < m){
            r++;
        }else{
            l++;
            ans = min(ans, diff);
        }
    }
    cout<<ans<<endl;
}