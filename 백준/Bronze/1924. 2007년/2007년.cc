#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int mon, date, total=0;


    // 1. 월 일 입력
    cin>>mon>>date;

    // 2. 월에 따라 총일 수 계산
    for(int i=1; i<mon; i++){
        total += arr[i];
    }

    // 3. 일 추가
    total += date;

    // 4. 나머지에 따른 출력
    int op = total%7;
    string str;
    switch(op)
    {
        case 0 : 
            str = "SUN";
            break;
        case 1 :
            str = "MON";
            break;
        case 2 :
            str = "TUE";
            break;
        case 3 :
            str = "WED";
            break;
        case 4 :
            str = "THU";
            break;
        case 5 :
            str = "FRI";
            break;
        case 6 :
            str = "SAT";
            break;
    }
    cout<<str<<endl;
    return 0;

}