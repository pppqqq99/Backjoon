#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int arr[1001];

int main(){
    int n;
    cin>>n;
    int sum=0;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++) {
        arr[i] = (arr[i-2] + arr[i-1])%10007;
    }
    cout<<arr[n]<<endl;
}