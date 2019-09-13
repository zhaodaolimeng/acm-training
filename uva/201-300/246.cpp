#include <bits/stdc++.h>

using namespace std;

deque<int> deck;
list<deque<int>> piles;
unordered_set<string> game_state;

string get_state(){
    string ans;
    for(auto it=deck.begin(); it!=deck.end(); it++) ans += (*it)+",";
    ans += "|";
    for(auto it=piles.begin(); it!=piles.end(); it++){
        for(auto iit=(*it).begin(); iit!=(*it).end(); iit++) ans += (*iit)+",";
        ans += "|";
    }
    return ans;
}

void play_loop(){
    while(true){
        bool changed = false;
        int pile_size = piles.size();
        for(auto it=piles.begin(); it!=piles.end(); it++){
            deque<int> dq = (*it);
            while(dq.size() >= 3){
                int first1 = dq.front();
                dq.pop_front();
                int first2 = dq.front();
                dq.push_front(first1);
                int last1 = dq.back(); dq.pop_back();
                int last2 = dq.back(); dq.pop_back();
                int last3 = dq.back();
                dq.push_back(last3);
                dq.push_back(last2);
                dq.push_back(last1);
            }
        }
        if(deck.size() == 52){
            cout<<""<<endl;
            return ;
        }
        if(!changed){
            
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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
            int head = deck.front();
            deque<int> dq;
            dq.push_back(head);
            piles.push_back(dq);
        }
        game_state.insert(get_state());
        play_loop();
    }
}
