#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n,k;

vector <long long> v;

int decision(long long mid){
    int num=0;
    for(int i=0; i<v.size(); i++){
        long long tmp = v[i];
        if(mid > tmp){
            continue;
        }
        num += tmp/mid;
    }
    return num;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>k>>n;
    for(int i=0; i<k; i++){
        long long t;
        cin>>t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    long long l=1, r=v[k-1], ret=0;
    while(l <= r){
        // cout<<l<<", "<<r<<endl;
        long long mid = (l+r)/2;
        int cnt = decision(mid);

        if(n <= cnt){
            l=mid+1;
            ret = mid; // 참인 경우
        }else{
            r=mid-1;
        }
    }

    cout<<ret<<endl;
}