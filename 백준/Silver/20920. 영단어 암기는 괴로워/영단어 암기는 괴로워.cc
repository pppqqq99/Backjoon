#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map <string, int> mymap;
vector <string> v;


bool comp2(string a, string b){
    if(mymap[a] == mymap[b]){
        if(a.size() == b.size()){
            return a<b;
        }else{
            return a.size()>b.size();
        }
    }else{
        return mymap[a] > mymap[b];
    }
}


void dict(){
    // 1. 자주 나오는 단어
    // 2. 단어의 길이가 길수록
    // 3. 알파벳 사준 순
    sort(v.begin(), v.end(), comp2);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }

}

int n,m;

int main(){

// 길이가 m이상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin>>n>>m;
    while(n--){
        cin>>str;
        if(str.size() >= m){
            // 해쉬 맵에 저장
            if(mymap.count(str)){
                mymap[str]++;
            }else{
                mymap[str] = 1;
                v.push_back(str);
            }
            
        }
    }
    
    dict();

}

