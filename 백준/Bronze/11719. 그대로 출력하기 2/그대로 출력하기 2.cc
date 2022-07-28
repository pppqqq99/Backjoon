#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
char str[102];
int main(){
    while(fgets(str, 101, stdin) != NULL) cout<<str;
}