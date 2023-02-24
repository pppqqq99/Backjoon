#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
int n;

unordered_map <string, int> m;
vector <int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int cnt=1, t=n;
    string str;

    while(t--){
        cin>>str;
        m[str] = cnt++;
    }

    t=n;
    cnt=0;
    while(t--){
        int c=0;
        cin>>str;
        v.push_back(m[str]);
        for(int i=0;i<v.size();i++){
            if(m[str] > v[i]) c++;
        }
        if(m[str]-1 != c) cnt++;
    }
    

    cout<<cnt<<endl;
}