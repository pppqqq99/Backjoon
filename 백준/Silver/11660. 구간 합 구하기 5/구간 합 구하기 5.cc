#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum[1025][1025] = {0, };
int arr[1025][1025] = {0, };

int subsum(int x1, int y1, int x2, int y2){
    return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 0. 입력 및 구간 합 구해서 저장

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t;
            cin>>t;
            arr[i][j] = t;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }

    // 1. 구간 합 입력 받고 구하기
    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<subsum(x1,y1,x2,y2)<<"\n";
    }
}