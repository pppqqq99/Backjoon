#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int l, c;
char arr[16];
bool checked[16];
char output[16];

bool condition(){
    int m=0,z=0;
    for(int i=0;i<strlen(output);i++){
        if(output[i]=='a'||output[i]=='e'||output[i]=='i'||output[i]=='o'||output[i]=='u')
            m++;
        else
            z++;
    }
    
    if(m>=1&&z>=2)
        return true;
    else
        return false;
}
void dfs(int length, int pos, int k) {
	
	// length가 l과 같으면 출력
	if (length == l) {
        if(condition())
		    printf("%s\n", output);
		return ;
	}

	for (int i = pos; i <= c; i++) {
		checked[i] = true;
		output[k] = arr[i];
		dfs(length + 1, i + 1, k + 1);
		checked[i] = false;
	}
	
}

int main() {
	cin >> l >> c;

	for (int i = 1; i <= c; i++)
		cin >> arr[i];

	sort(arr + 1, arr + c + 1);
	output[l] = '\0';
	// ASCII 코드 순으로 sort
	dfs(0, 1, 0);
}