#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n;
typedef pair<int, int> pii;
stack<pii> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    int cnt=1;
    while(n--){
        int input, flag=0;
        cin>>input;
        
        // 같은 경우 안됨
        while(!st.empty()){
            if(st.top().second >= input){
                cout<<st.top().first<<" ";
                flag=1;
                st.push({cnt, input});
                break;
            }else{
                st.pop();
            }
        }

        if(flag == 0){
            st.push({cnt, input});
            cout<<"0 ";
        }

        cnt++;
    }
}