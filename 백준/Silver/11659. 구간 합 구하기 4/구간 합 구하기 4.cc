#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int arr[100001] = {0, };
vector <int> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=1; i<n+1; i++){
        int t;
        cin>>t;
        v.push_back(t);
        arr[i] = arr[i-1] + t;
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        cout<<arr[b] - arr[a-1]<<"\n";
    }

}