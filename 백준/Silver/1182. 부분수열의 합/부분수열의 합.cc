#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
int n,s, cnt=0;

void dfs(int start, int sum){

    if(start == n) return;

    if(sum + v[start] == s) cnt++;

    dfs(start+1, sum);
    dfs(start+1, sum + v[start]);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin>>n>>s;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    dfs(0, 0);

    cout<<cnt<<endl;
}