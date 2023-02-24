#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map <string, int> set;

int n,m;
string str;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    while(n--){
        cin>>str;
        set[str] = 1;
    }

    int cnt=0;
    while(m--){
        cin>>str;
        if(set.count(str)){
            cnt++;
        }
    }

    cout<<cnt<<endl;

}