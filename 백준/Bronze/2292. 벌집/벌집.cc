#include <iostream>
#include <math.h>

using namespace std;
long long n;

int main(){
    cin>>n;
    long long r=1, sum=1;

    while(n > sum){
        sum += 6*r++;
    }
    cout<<r<<endl;
}