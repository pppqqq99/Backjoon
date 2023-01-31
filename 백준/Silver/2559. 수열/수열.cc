#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector <int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        v.push_back(t);
    }

    int left=0, right=k-1, maxT = -1000000000, sum=0;
    for(int i=0; i<=right; i++){
        sum+=v[i];
    }
    // sum += v[0];

    while(right<n){
        if(maxT < sum){
            maxT = sum;
        }
        sum -= v[left];
        left++;
        right++;
        sum += v[right];
    }
    cout<<maxT<<endl;
}