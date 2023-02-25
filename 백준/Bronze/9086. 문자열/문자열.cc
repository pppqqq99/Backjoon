#include <iostream>
#include <string>

using namespace std;

int t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<str[0]<<str[str.size()-1]<<endl;
    }
}