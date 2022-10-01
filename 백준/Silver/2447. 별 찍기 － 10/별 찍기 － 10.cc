#include <iostream>
#include <algorithm>

using namespace std;

char arr[6600][6600];
void empty(int n, int y, int x){
    for(int i=y;i<y+n;i++)
        for(int j=x;j<x+n;j++)
            arr[i][j] = ' ';
}
void divide(int n, int y, int x){
    if(n==3){
        for(int i=y;i<y+3;i++)
            for(int j=x;j<x+3;j++){
                if(i%3==2 && j%3==2)
                    arr[i][j] = ' ';
                else
                    arr[i][j] = '*';
            }
        return ;
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1 && j==1)
                empty(n/3, y+n/3, x+n/3);
            else
                divide(n/3, y+(n/3)*i, x+(n/3)*j);
        }
    }
    
    
}


int main(){
    int n;
    cin>>n;
    
    divide(n, 1, 1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<arr[i][j];
        cout<< endl;
    }
    
}
