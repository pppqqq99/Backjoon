#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
double W[29][29] = {0,};
bool checked[29][29] = {false,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
double pro[4];
double result = 0;

bool promising(int y, int x){
    if(y>=0 && y<29 &&x>=0 && x<29 && !checked[y][x]) return true;
    else return false;
}

void btk(int y, int x, int cnt){
    if(cnt == n) { result += W[y][x]; return;}
    int ny, nx;
    for(int i=0;i<4;i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(promising(ny, nx)){
            checked[ny][nx] = true;
            W[ny][nx] = W[y][x]*pro[i];
            btk(ny, nx, cnt+1);
            checked[ny][nx] =false;
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<4;i++) { cin>>pro[i]; pro[i] /= 100; }
    checked[14][14] = true;
    W[14][14] = 1;
    btk(14,14,0);
    printf("%.15f\n",result);
}