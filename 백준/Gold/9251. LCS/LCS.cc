#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int DP[1001][1001];

char x[1001],y[1001],input[1001];

int main(){
    int xs=0, ys=0;
    scanf("%s", input);
    xs = strlen(input);
    strcpy(x+1, input);
    scanf("%s", input);
    ys = strlen(input);
    strcpy(y+1, input);
    
    memset(DP,0, sizeof(DP));

    for(int i=1;i<=xs;i++){
        int k=0;
        for(int j=1;j<=ys;j++){
            if(k>0){ DP[i][j] = k; continue;}
            if(x[i] == y[j]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }

    cout<<DP[xs][ys]<<endl;
}