#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t, n, m, input;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    while(t--){
        vector <int> A;
        vector <int> B;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>input;
            A.push_back(input);
        }
        for(int i=0;i<m;i++){
            cin>>input;
            B.push_back(input);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int cnt=0, l=n-1, r=m-1;

        while(r>=0){
            
            if(A[l] > B[r]){
                l--;
                cnt++;
            }else{
                if(r==0) break;
                r--;
                cnt += n-1-l;
            }
            //cout<<cnt<<endl;
        }

        cout<<cnt<<endl;
    }
}