#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
priority_queue <int, vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            pq.push(t);
            if(pq.size() > n) pq.pop();
        }
    }

    cout<<pq.top()<<endl;
}