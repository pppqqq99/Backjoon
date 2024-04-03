#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());


    int start=0, end=n-1, cnt=0;
    while(start<end){

        long long sum = v[start] + v[end];
        if(sum==m){
            cnt++;
            end--;
        }else if(sum<m){
            start++;
        }else{
            end--;
        }
    }

    cout<<cnt<<"\n";
}