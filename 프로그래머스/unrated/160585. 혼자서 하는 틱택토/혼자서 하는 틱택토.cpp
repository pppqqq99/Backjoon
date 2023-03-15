#include <string>
#include <vector>

using namespace std;

// 나올 수 없는 상황
// 1. 순서가 바뀐 경우
// 1-1. X가 O보다 많은 경우
// 1-2. O가 X보다 2개 이상 많을 경우
// 2. 게임이 종료되어야 하는데 진행되는 경우
// 2-1. 3개 짜리가 나왔는데 진행한 경우

bool check(char ch, int s, char shape, vector<string> board){
    int t=0;
    if(board[0][0] == shape && board[1][1] == shape && board[2][2] == shape) return true;
    if(board[2][0] == shape && board[1][1] == shape && board[0][2] == shape) return true;
    if(ch == 'y'){
        for(int i=0; i<3; i++){
            if(board[i][s] == shape) t++;
        }
    }else if(ch == 'x'){
        for(int i=0; i<3; i++){
            if(board[s][i] == shape) t++;
        }
    }
    
    if(t==3) return true;
    return false;
}
int solution(vector<string> board) {
    int answer = -1;
    
    int x_cnt=0, o_cnt=0, x_three=0, o_three=0;
    // 벡터를 탐색하며 X와 O의 개수를 파악한다.
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == 'O'){
                o_cnt++;
                if(i==0 && check('y', j, 'O', board)) o_three++;
                if(j==0 && check('x', i, 'O', board)) o_three++;
          
            }else if(board[i][j] == 'X'){
                x_cnt++;
                if(i==0 && check('y', j, 'X', board)) x_three++;
                if(j==0 && check('x', i, 'X', board)) x_three++;
            }
        }
    }
    
    // X나 O가 발견될 시 가로 세로 3개가 되어 있는지 확인하고 체크한다.
    // 탐색이 끝난 후 리턴 값을 결정한다.
    if(x_three >= 1 && o_cnt > x_cnt){
        answer = 0;
    }else if(o_three >= 1 && o_cnt == x_cnt){
        answer = 0;
    }else if((o_cnt - x_cnt) < 0 || (o_cnt - x_cnt) >= 2){
        answer = 0;
    }else{
        answer = 1;
    }
    
    
    return answer;
}