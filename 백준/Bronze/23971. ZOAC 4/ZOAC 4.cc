#include <iostream>
#include <algorithm>

using namespace std;

int h,w,n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>h>>w>>n>>m;
    int r = h/(n+1);
    int rr = h%(n+1);
    if(rr == 0) rr = 0;
    else rr = 1;
    int l = w/(m+1);
    int lr = w%(m+1);
    if(lr == 0) lr =0;
    else lr = 1;
    cout<<(r+rr)*(l+lr)<<endl;

}