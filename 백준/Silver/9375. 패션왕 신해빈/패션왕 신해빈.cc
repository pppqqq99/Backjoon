#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int t, n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    string str1, str2;
    cin>>t;
    while(t--){
        unordered_map <string, int> mymap;
        int ret=1;
        cin>>n;
        while(n--){
            cin>>str1>>str2;
            if(mymap.count(str2)){
                mymap[str2]++;
            }else{
                mymap[str2] = 1;
            }
        }
        for(auto& x : mymap){
            ret *= (x.second+1);
        }
        ret -= 1;
        cout<<ret<<endl;
    }
}