#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n,k;
int arr[1001];
bool checked[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    for(int i=0; i<2*n; i++) cin>>arr[i];

    int f=0, l=n-1, z=0, round=1;

    while(true){
        // 1. 단계
        if(f == 0) f=2*n-1;
        else f--;
        if(l == 0) l=2*n-1;
        else l--;

        // 로봇이 이동한 위치가 n이라면 로봇 내리기
        if(checked[l]){
            checked[l] = false;
        }

        // 2. 단계 l -> f까지
        int tl;
        if(l == 0){
            tl =2*n-1;
        }else tl = l-1;

        while(tl != f){

            int nt;
            // t1에 로봇이 존재할 경우
            if(checked[tl]){
                // t1==2*n-1 -> 0
                if(tl == 2*n-1){
                    nt = 0;
                }else{
                    nt = tl+1;
                }
                if(!checked[nt] && arr[nt] >= 1){ // 로봇 이동
                    checked[nt] = true;
                    checked[tl] = false;
                    arr[nt]--;
                    if(arr[nt] == 0) z++;
                }

                // 로봇이 이동한 위치가 n이라면 로봇 내리기
                if(nt == l){ checked[nt] = false; }
            }

            if(tl == 0) tl = 2*n-1;
            else tl--;
        }

        // 3. 단계
        if(arr[f] >= 1){
            checked[f] = true;
            arr[f]--;
            if(arr[f] == 0) z++;
        }


        // 4. 단계
        if(z >= k){
            cout<<round<<endl;
            break;
        }else{
            round++;
        }

    }
}