#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <regex>


using namespace std;

int main(void){
	string s;
	cin>>s;
    if(regex_match(s, regex("(100+1+|01)+"))){
        cout<<"SUBMARINE"<<endl;
    }else{
        cout<<"NOISE"<<endl;
    }
}
