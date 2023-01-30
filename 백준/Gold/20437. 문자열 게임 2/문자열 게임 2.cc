#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, k, n;
    cin>>t;

    while(t--){
        vector <int> alpha[27];
        string str;
        cin>>str;
        cin>>k;
        
        for(int i=0; i<str.length(); i++){
            alpha[str[i] - 'a'].push_back(i);
        }


        // 3번
        int minLen = 10005, maxLen = 0;
        for(int i=0; i<27; i++){
            int left=0, right=k-1, len=0;
            while(right < alpha[i].size()){
                len = alpha[i][right] - alpha[i][left]+1;
                if(minLen > len){
                    minLen = len;
                    //cout<<i<<", "<<alpha[i][right]<<", "<<alpha[i][left]<<endl;
                }
                if(maxLen < len){
                    maxLen = len;
                }
                left++;
                right++;
            }
        }
        if(minLen > 10000){
            cout<<-1<<endl;
        }else{
            cout<<minLen<<" "<<maxLen<<endl;
        }
        
    }
    
}