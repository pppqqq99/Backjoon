#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    char arr[101];
    int a;
    cin>>a;
    cin>>arr;
    int n=0;
    for(int i=0;i<a;i++)
        n += (arr[i]-'0');
    cout<<n<<endl;
}