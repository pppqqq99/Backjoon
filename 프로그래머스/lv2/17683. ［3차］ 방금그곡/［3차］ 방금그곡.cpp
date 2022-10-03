#include <string>
#include <vector>
#include <iostream>

using namespace std;

string now(string m, vector<pair<string, string>> play, vector <int> tv){
    string answer = "(None)";
    int size=0, k=0, cur=0;
    
    for(int i=0; i<play.size();i++){
        //m이 play[i].second에 포함되어 있다면
        cur = 0;
        k = 0;
        while((k = play[i].second.find(m, cur)) != string::npos){
             if(play[i].second[k+m.length()] == '#') {
                 cur = k+m.length();
                 continue;
             }
            // play[i].second.length()가 size보다 길다면
            int t_size = tv[i];
            if(t_size > size){
                size = t_size;
                answer = play[i].first;
            }
            break;
        }
    }
    return answer;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string seperate = ",";
    int position, cur_position, cnt, len;
    vector<pair<string, string>> play;
    vector <int> tv;
    string start, end, name, melody;
    
    // musicinfos를 쪼개서 <제목, 노래 길이>를 play에 넣기
    for(int i=0;i<musicinfos.size();i++){
        cur_position = 0, cnt = 0;
        while((position = musicinfos[i].find(seperate, cur_position)) != string::npos){
            len = position - cur_position;
            string result = musicinfos[i].substr(cur_position, len);
            cur_position = position + 1;
            if(cnt == 0){
                start = result;
            }else if(cnt == 1){
                end = result;
            }else if(cnt == 2){
                name = result;
            }
            cnt++;
        }
        melody = musicinfos[i].substr(cur_position);
        
        // play에 노래 제목, 멜로디 삽입
        int hour = stoi(end.substr(0,2)) - stoi(start.substr(0,2));
        int minute = stoi(end.substr(3,2)) - stoi(start.substr(3,2));
        int time = hour*60 + minute;
        string put="";
        int c=0;
        for(int i=0;i<time;i++){
            if(c == melody.length()) c = 0;
            if(c < melody.length()-1 && melody[c+1] == '#') {put += melody[c]; c++;}
            put += melody[c];
            c++;
        }
        play.push_back(make_pair(name, put));
        tv.push_back(time);
        //cout<<name<<", "<<put<<endl;
    }
    
    answer = now(m, play, tv);
    return answer;
}