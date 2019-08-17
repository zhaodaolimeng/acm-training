#include <bits/stdc++.h>
using namespace std;


// const bool DEBUG = false;
const bool DEBUG = true;


priority_queue<int> buy_pq;  // p, (q, id)
priority_queue<int, vector<int>, greater<int>> sell_pq;

// set<int> buy_pq_deleted;
// set<int> sell_pq_deleted;

// CAN BE IMPROVED
// map<int, set<int>> buy_trans_deleted;
// map<int, set<int>> sell_trans_deleted;

map<int,queue<pair<int,int>>> buy_trans;
map<int,queue<pair<int,int>>> sell_trans;

map<int,int> buy_id_p;
map<int,int> sell_id_p;

map<int,int> buy_trans_cnt;  // quota
map<int,int> sell_trans_cnt;

//////////

void print_buy_trans(){
    cout<<"buy"<<endl;
    for(auto const & e : buy_trans){
        cout<<"p="<<e.first<<": ";
        queue<pair<int,int>> qp = e.second;
        int q_size = qp.size();
        for(int i=0; i<q_size; i++){
            pair<int,int> p = qp.front();
            cout<<"(q="<<p.first<<",i="<<p.second<<"),";
            qp.pop();
            qp.push(p);
        }
        cout<<endl;
    }
    cout<<"-----"<<endl;
}

void print_sell_trans(){
    cout<<"sell"<<endl;
    for(auto const & e : sell_trans){
        cout<<"p="<<e.first<<": ";
        queue<pair<int,int>> qp = e.second;
        int q_size = qp.size();
        for(int i=0; i<q_size; i++){
            pair<int,int> p = qp.front();
            cout<<"(q="<<p.first<<",i="<<p.second<<"),";
            qp.pop();
            qp.push(p);
        }
        cout<<endl;
    }
    cout<<"-----"<<endl;
}

void print_buy_trans_cnt(){
    cout<<"buy_trans_cnt: ";
    for(auto const & e : buy_trans_cnt)
        cout<<"("<<e.first<<","<<e.second<<"),";
    cout<<endl;
}

void print_sell_trans_cnt(){
    cout<<"sell_trans_cnt: ";
    for(auto const & e : sell_trans_cnt)
        cout<<"("<<e.first<<","<<e.second<<"),";
    cout<<endl;
}

/////////


void update_pq(
    map<int,queue<pair<int,int>>>& trans,
    map<int,int>& trans_cnt,
    int price, int quant, int id, string trans_type){
    if(trans.find(price) == trans.end()){
        queue<pair<int,int>> price_q;
        price_q.push(make_pair(quant, id));
        trans[price] = price_q;
        if(trans_type == "BUY") buy_pq.push(price);
        else sell_pq.push(price);
        trans_cnt[price] = quant;
    }else{
        queue<pair<int,int>>& price_q = trans[price];
        price_q.push(make_pair(quant, id));
        trans_cnt[price] += quant;
    }
}

void clean_sell_pq(){
    while(!sell_pq.empty()){
        int deleted_ele = sell_pq.top();
        if(sell_trans.find(deleted_ele) == sell_trans.end()){
            sell_pq.pop();
            sell_trans_cnt.erase(deleted_ele);
        }else break;
    }
}

void clean_buy_pq(){
    while(!buy_pq.empty()){
        int deleted_ele = buy_pq.top();
        if(buy_trans.find(deleted_ele) == buy_trans.end()){
            buy_pq.pop();
            buy_trans_cnt.erase(deleted_ele);
        }else break;
    }
}

void process_buy(int price, int quant, int index){
    bool done = false;
    while(!done){
        clean_sell_pq();
        if(sell_pq.empty()) break;
        int min_sell_price = sell_pq.top();
        // if(DEBUG) print_sell_trans_cnt();
        if(min_sell_price > price) break;
        queue<pair<int,int>> &qp = sell_trans[min_sell_price];

        while(!qp.empty() && !done){
            pair<int,int> &sell_p = qp.front(); // (q,id)
            if(sell_p.first >= quant){
                sell_p.first -= quant;
                sell_trans_cnt[min_sell_price] -= quant;
                printf("TRADE %d %d\n", quant, min_sell_price);
                if(sell_p.first == 0) qp.pop();
                quant = 0;
                done = true;
            }else{
                qp.pop();
                sell_id_p.erase(sell_p.second);
                sell_trans_cnt[min_sell_price] -= sell_p.first;
                quant -= sell_p.first;
                printf("TRADE %d %d\n", sell_p.first, min_sell_price);
            }
        }
        if(qp.empty()) {
            sell_pq.pop();
            sell_trans.erase(min_sell_price);
            sell_trans_cnt.erase(min_sell_price);
        }
    }
    if(quant > 0){
        update_pq(buy_trans, buy_trans_cnt, price, quant, index, "BUY");
        buy_id_p[index] = price;
    }
}

void process_sell(int price, int quant, int index){
    bool done = false;
    while(!done){
        clean_buy_pq();
        if(buy_pq.empty()) break;
        int max_buy_price = buy_pq.top();
        // if(DEBUG) print_buy_trans_cnt();
        if(max_buy_price < price) break;
        queue<pair<int,int>> &qp = buy_trans[max_buy_price];
        while(!qp.empty() && !done){
            pair<int,int> &buy_p = qp.front();  // (q,id)
            if(buy_p.first >= quant){
                buy_p.first -= quant;
                buy_trans_cnt[max_buy_price] -= quant;
                printf("TRADE %d %d\n", quant, max_buy_price);
                if(buy_p.first == 0) qp.pop();
                quant = 0;
                done = true;
            }else{
                qp.pop();
                buy_id_p.erase(buy_p.second);
                buy_trans_cnt[max_buy_price] -= buy_p.first;
                quant -= buy_p.first;
                printf("TRADE %d %d\n", buy_p.first, max_buy_price);
            }
        }
        if(qp.empty()) {
            buy_pq.pop();
            buy_trans.erase(max_buy_price);
            buy_trans_cnt.erase(max_buy_price);
        }
    }
    if(quant > 0){
        update_pq(sell_trans, sell_trans_cnt, price, quant, index, "SELL");
        sell_id_p[index] = price;
    }
}

void process_cancel(int index){
    if(buy_id_p.find(index) != buy_id_p.end()) {
        int price = buy_id_p[index];
        queue<pair<int,int>> &qp = buy_trans[price];
        int queue_size = qp.size();
        if(queue_size == 1){
            int buy_id = qp.front().second;
            buy_id_p.erase(buy_id);
            buy_trans.erase(price);
            buy_trans_cnt.erase(price);
        }else{
            for(int qi=0; qi<queue_size; qi++){
                pair<int,int> buy_p = qp.front();
                qp.pop();
                if(buy_p.second == index){
                    buy_id_p.erase(buy_p.second);
                    buy_trans_cnt[price] -= buy_p.first;
                }else qp.push(buy_p);
            }
        }
    } else if(sell_id_p.find(index) != sell_id_p.end()){
        int price = sell_id_p[index];
        queue<pair<int,int>> &qp = sell_trans[price];
        int queue_size = qp.size();
        if(queue_size == 1){
            int sell_id = qp.front().second;
            sell_id_p.erase(sell_id);
            sell_trans.erase(price);
            sell_trans_cnt.erase(price);
        }else{
            for(int qi=0; qi<queue_size; qi++){
                pair<int,int> sell_p = qp.front();
                qp.pop();
                if(sell_p.second == index){
                    sell_id_p.erase(sell_p.second);
                    sell_trans_cnt[price] -= sell_p.first;
                }else qp.push(sell_p);
            }
        }
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q, p, t;
    string cmd;

    while(cin>>n){
        buy_pq = priority_queue <int>();
        sell_pq = priority_queue<int, vector<int>, greater<int>>();

        buy_trans.clear();
        sell_trans.clear();

        buy_id_p.clear();
        sell_id_p.clear();

        buy_trans_cnt.clear();  // quota
        sell_trans_cnt.clear();

        for(int i=1; i<=n; i++){
            cin>>cmd;
            if(cmd == "BUY"){
                cin>>q>>p;
                // printf("BUY %d %d ", q, p);
                if(DEBUG) printf("BUY %d %d\n", q, p);
                process_buy(p, q, i);
            }else if(cmd == "SELL"){
                cin>>q>>p;
                // printf("SELL %d %d ", q, p);
                if(DEBUG) printf("SELL %d %d\n", q, p);
                process_sell(p, q, i);
            }else{
                cin>>t;
                // printf("CANCEL %d", t);
                if(DEBUG) printf("CANCEL %d\n", t);
                process_cancel(t);
            }
            int buy_price = 0, buy_quant = 0;
            int sell_price = 99999, sell_quant = 0;
            clean_buy_pq();
            if(!buy_pq.empty()){
                buy_price = buy_pq.top();
                buy_quant = buy_trans_cnt[buy_price];
            }
            clean_sell_pq();
            if(!sell_pq.empty()){
                sell_price = sell_pq.top();
                sell_quant = sell_trans_cnt[sell_price];
            }
            // cout<<n<<" ";
            printf("QUOTE %d %d - %d %d\n", buy_quant, buy_price, sell_quant, sell_price);
        }
        if(DEBUG) print_buy_trans();
        if(DEBUG) print_sell_trans();

        if(DEBUG) print_buy_trans_cnt();
        if(DEBUG) print_sell_trans_cnt();
        cout<<endl;
    }
}