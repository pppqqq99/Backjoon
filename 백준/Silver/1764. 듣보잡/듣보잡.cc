#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map <string, int> mymap;
vector <string> v;
int n,m;


int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    string str;

    cin>>n>>m;
    while(n--){
        cin>>str;
        mymap[str] = 1;
    }
    while(m--){
        cin>>str;
        if(mymap.count(str)) v.push_back(str);
    }

    sort(v.begin(), v.end());
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }

}