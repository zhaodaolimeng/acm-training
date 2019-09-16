#include <bits/stdc++.h>

#include <chrono>
#include <thread>

using namespace std;
// using namespace std::this_thread;
// using namespace std::chrono;

deque<int> deck;
vector<deque<int>> piles;
unordered_set<string> game_states;

string get_state(){
    string ans;
    for(auto it=deck.begin(); it!=deck.end(); it++) ans += to_string((int)(*it))+",";
    ans += "||";
    for(auto it=piles.begin(); it!=piles.end(); it++){
        for(auto iit=(*it).begin(); iit!=(*it).end(); iit++) ans += to_string((int)(*iit))+",";
        ans += "|";
    }
    return ans;
}

bool check_sum(int i1, int i2, int i3){
    int n = i1 + i2 + i3;
    if(n == 10 || n == 20 || n == 30) return true;
    return false;
}

void play_loop(){
    game_states.insert(get_state());

    for(int step=7; ;){
        // sleep_until(system_clock::now() + milliseconds(10));

        for(auto it=piles.begin(); it!=piles.end(); it++){
            deque<int> &dq = (*it);

            if(dq.size() == 0) continue;
            int played = deck.front(); deck.pop_front();
            dq.push_back(played);

            // for(auto dit=dq.begin(); dit!=dq.end(); dit++) cout<<(*dit)<<" ";
            // cout<<endl;

            bool changed = false;
            while(dq.size() >= 3){
                int first1 = dq.front(); dq.pop_front();
                int first2 = dq.front();
                dq.push_front(first1);
                int last1 = dq.back(); dq.pop_back();
                int last2 = dq.back(); dq.pop_back();
                int last3 = dq.back();
                dq.push_back(last2);
                dq.push_back(last1);
                if(check_sum(first1, first2, last1)){
                    changed = true;
                    deck.push_back(first1);
                    deck.push_back(first2);
                    deck.push_back(last1);
                    dq.pop_front(); dq.pop_front(); dq.pop_back();
                }else if(check_sum(first1, last1, last2)){
                    changed = true;
                    deck.push_back(first1);
                    deck.push_back(last2);
                    deck.push_back(last1);
                    dq.pop_front(); dq.pop_back(); dq.pop_back();
                }else if(check_sum(last1, last2, last3)){
                    changed = true;
                    deck.push_back(last3);
                    deck.push_back(last2);
                    deck.push_back(last1);
                    dq.pop_back(); dq.pop_back(); dq.pop_back();
                }else break;
            }
            if(!changed && deck.size() == 0) {
                cout<<"Loss: "<<step+1<<endl;
                return ;
            }
            string gs = get_state();

            // cout<<gs<<endl;

            if(game_states.find(gs) != game_states.end()){
                cout<<"Draw: "<<step+1<<endl;
                return ;
            }
            game_states.insert(gs);
            step ++;
        }

        if(deck.size() == 52){
            cout<<"Win : "<<step<<endl;
            return ;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    while(cin>>t && t != 0){
        deck.clear();
        deck.push_back(t);
        for(int i=0; i<51; i++){
            cin>>t;
            deck.push_back(t);
        }

        piles.clear();
        for(int i=0; i<7; i++){
            int head = deck.front(); deck.pop_front();
            deque<int> dq;
            dq.push_back(head);
            piles.push_back(dq);
        }
        play_loop();
    }
}
