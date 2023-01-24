#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef struct node{
    int y;
    int x;
    int l;
    char ch;
}node;

int r,c;

char w[1002][1002];

vector <pair<int, int>> f;
queue <node> n;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool promising(int y, int x, char ch){

    if(ch == 'F' && (w[y][x] == '.' || w[y][x] == 'J')){
        w[y][x] = 'F';
        return true;
    }else if(ch == 'J' && w[y][x] == '.'){
        w[y][x] = 'J';
        //cout<<y<<", "<<x<<endl;
        return true;
    }else if(ch == 'J' && (y < 0 || y >= r || x < 0 || x >= c)){
        return true;
    }{
        return false;
    }

}

void bfs(){

    while(!n.empty()){

        int y = n.front().y;
        int x = n.front().x;
        int l = n.front().l;
        char ch = n.front().ch;

        if(ch == 'J' && w[y][x] == 'F'){
            ;
        }else{

            // 뽑은 것이 J이고 가장자리에 닿아있다면 탈출
            if(y < 0 || y >= r || x < 0 || x >= c){
                //cout<<"ans : "<< y<< ", "<<x<<endl; 
                printf("%d\n", l);
                return;
            }

            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                int nl = l + 1;
                
                if(promising(ny, nx, ch)){
                    n.push({ny, nx, nl, ch});
                }
            }
        }

        n.pop();
    }

    printf("IMPOSSIBLE\n");
}

int main(){
    int jy, jx;
    string str;
    cin>>r>>c;

    for(int i=0; i<r; i++){
        cin>>str;
        for(int j=0; j<c; j++){
            w[i][j] = str[j];
            if(w[i][j] == 'J'){
                jy = i;
                jx = j;
            }else if(w[i][j] == 'F'){
                f.push_back({i, j});
            }
        }
    }

    n.push({jy, jx, 0, 'J'});
    for(int i=0; i<f.size(); i++){
        n.push({f[i].first, f[i].second, 0, 'F'});
    }

    bfs();

}