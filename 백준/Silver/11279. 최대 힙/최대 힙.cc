#include <iostream>
#include <queue>

using namespace std;

priority_queue <int, vector<int>> pq;

int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;i++){
        int x, k;
        cin>>x;
        if(x==0){
            if(pq.empty()){
                k = 0;
            }else{
                k = pq.top();
                pq.pop();
            }
            cout<<k<<'\n';
        }else{
            pq.push(x);
        }
    }

}