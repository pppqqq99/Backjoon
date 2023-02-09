#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
int n,m;

unordered_map <int, int> map;
vector <int> v;

int find_num(int t){
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(t == v[mid]){
            return 1;
        }

        if(v[mid] < t){
            l = mid+1;
        }else if(v[mid] > t){
            r = mid-1;
        }
    }

    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    cin>>m;
    for(int i=0; i<m; i++){
        cin>>t;
        cout<<find_num(t)<<" ";
    }
}