#include <iostream>
#include <algorithm>

using namespace std;
long long arr[31];

int sum(int s){
    int ss = 0;
    for(int i=s; i>=2; i-=2){
        ss += arr[i]*2;
    }
    return ss;
}
int main(){
    int n;
    cin>>n;

    if(n%2==1){ cout<<0<<endl; exit(0);}
    arr[2] = 3;
    
    for(int i=4;i<=n;i+=2){
        arr[i] = arr[i-2]*3 + sum(i-4) + 2;
    }
    cout<<arr[n]<<endl;
}