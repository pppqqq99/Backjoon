#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

stack <char> st;
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

    int cx=xs, cy=ys;
    while(cx > 0 && cy > 0){
        if(DP[cx][cy] == DP[cx][cy-1]) cy--;
        else if(DP[cx][cy] == DP[cx-1][cy]) cx--;
        else{
            st.push(x[cx]); cx--; cy--;
        }
    }
    cout<<DP[xs][ys]<<endl;

    while(!st.empty()){ cout<<st.top(); st.pop();}
}