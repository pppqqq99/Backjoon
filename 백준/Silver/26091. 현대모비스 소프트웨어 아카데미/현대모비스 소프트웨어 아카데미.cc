#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <long long> v;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt=0;
    long long m;

    cin>>n>>m;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int start=0, end=n-1;

    while(start<end){

        // 각 커서가 가리키는 수의 합이 m을 넘을 시 cnt++
        if(v[start] + v[end] >= m){
            start++;
            end--;
            cnt++;
        }else{
            start++;
        }
    }

    cout<<cnt<<endl;


}