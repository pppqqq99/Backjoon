#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int n;
int arr[1001][4];
int DP[1001][4];
vector <int> v;

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>arr[i][j];

    

for(int k=0;k<3;k++){
    memset(DP, 0, sizeof(DP));
    DP[0][0] = arr[0][k];
    DP[0][1] = arr[0][k];
    DP[0][2] = arr[0][k];

    for(int i=1;i<n-1;i++){
        for(int j=0;j<3;j++){
            if(j==k && i==1) {DP[i][j] = 2000;continue;}
            if(j==0)
                DP[i][j] = min(DP[i-1][1]+arr[i][j], DP[i-1][2]+arr[i][j]);
            else if(j==1)
                DP[i][j] = min(DP[i-1][0] +arr[i][j], DP[i-1][2]+arr[i][j]);
            else 
                DP[i][j] = min(DP[i-1][0]+arr[i][j], DP[i-1][1]+arr[i][j]);
        }
    }

if(k==0){
    v.push_back(min(DP[n-2][0]+arr[n-1][1], DP[n-2][0]+arr[n-1][2]));
    v.push_back(DP[n-2][1]+arr[n-1][2]);
    v.push_back(DP[n-2][2]+arr[n-1][1]);
}else if(k==1){
    v.push_back(min(DP[n-2][1]+arr[n-1][0], DP[n-2][1]+arr[n-1][2]));
    v.push_back(DP[n-2][0]+arr[n-1][2]);
    v.push_back(DP[n-2][2]+arr[n-1][0]);
}else{
    v.push_back(min(DP[n-2][2]+arr[n-1][0], DP[n-2][2]+arr[n-1][1]));
    v.push_back(DP[n-2][0]+arr[n-1][1]);
    v.push_back(DP[n-2][1]+arr[n-1][0]);
}

}
    sort(v.begin(), v.end());
    cout<<v[0]<<endl;
}