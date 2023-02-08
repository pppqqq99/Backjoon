#include <iostream>
#include <algorithm>

using namespace std;

void triangle(int a, int b, int c){
    if(a+b <= c || a+c <= b || b+c <= a){
        cout<<"Invalid"<<endl;
    }else if(a==b && b==c && a==c){
        cout<<"Equilateral"<<endl;
    }else if(a!=b && b!=c && c!=a){
        cout<<"Scalene"<<endl;
    }else{
        cout<<"Isosceles"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==0 && b==0 && c==0) break;
        triangle(a,b,c);
    }
}