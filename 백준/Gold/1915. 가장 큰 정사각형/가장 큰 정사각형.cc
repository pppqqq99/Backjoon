#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int arr[1001][1001];
int DP[1001][1001];
int n,m;

// 위, 왼쪽, 대각선
int dx[3] = {0,-1,-1};
int dy[3] = {-1,0,-1};


int main(){
    int maxV=0;
    cin>>n>>m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf("%1d", &arr[i][j]);
            if(arr[i][j] == 1) maxV = 1;
        }

    
    fill(&DP[0][0], &DP[0][0] + n*n, 0);
    for(int i=0; i<n; i++)
        DP[i][0] = arr[i][0];
    for(int i=0; i<m; i++)
        DP[0][i] = arr[0][i];
    
    
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){

            int minV = 1000003, flag = 1;
            if(arr[i][j]==0)
                DP[i][j] = 0;
            else{
                for(int k=0;k<3;k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(DP[ny][nx] == 0){
                        DP[i][j] = 1;
                        flag = 0;
                        break;
                    }else{
                        if(minV > DP[ny][nx])
                            minV = DP[ny][nx];
                    }
                }
                if(flag == 1)
                    DP[i][j] = minV + 1;
            }
            if(maxV < DP[i][j]) maxV = DP[i][j];
        }
    }

    cout<<maxV*maxV<<endl;


}