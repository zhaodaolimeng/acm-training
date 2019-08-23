#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> mta;

vector<string> split_by(string line, char c){
    stringstream ss(line);
    vector<string> ans;
    while(ss.good()){
        string substr;
        getline(ss, substr, c);
        ans.push_back(substr);
    }
    return ans;
}


void build_connection(string sender, vector<string> recipients, vector<string> mdata){

    string from_addr = split_by(sender, '@')[1];
    string to_addr = split_by(recipients[0], '@')[1];

    printf("Connection between %s and %s\n", from_addr, to_addr);
    printf("HELO %s\n250", from_addr);
    printf("MAIL FROM:<%s>\n250", sender);

    int cnt = 0;
    for(string rcpt : recipients){
        string rcpt_name = split_by(rcpt, '@')[0];
        printf("RCPT TO:<%s>\n", rcpt);

        if(mta[to_addr].find(rcpt) == mta[to_addr].end()){
            printf("550\n");
        }else{
            cnt++;
            printf("250\n");
        }
    }
    if(cnt > 0){
        printf("DATA\n354\n");
        for(string s : mdata) cout<<s<<endl;
        cout<<".\n250"<<endl;
    }
    printf("QUIT\n221\n");
}

int main(){

    string cmd, agent, name;
    int t;

    while(cin>>cmd && cmd[0] != '*'){
        cin>>agent>>t;
        set<string> names;
        for(int i=0; i<t; i++) {
            cin>>name;
            names.insert(name);
        }
        mta[agent] = names;
    }

    while(cin>>cmd && cmd[0] != '*'){
        string line;
        vector<string> addr_vs, mdata;

        cin.ignore();
        getline(cin, line);
        addr_vs = split_by(line, ' ');

        cin>>line; // *
        while(cin>>line && line[0] != '*') mdata.push_back(line);
        
        vector<bool> sent(addr_vs.size(), false);
        string from_addr = split_by(addr_vs[0], '@')[1];

        for(int i=1; i<addr_vs.size(); i++){
            if(sent[i]) continue;
            string to_addr = split_by(addr_vs[i], '@')[1];
            vector<string> recipient_vs;

            for(int j=i; j<addr_vs.size(); j++){
                string ts = split_by(addr_vs[j], '@')[1];
                if(ts != to_addr) continue;
                recipient_vs.push_back(addr_vs[j]);
                sent[j] = true;
            }
            build_connection(addr_vs[0], recipient_vs, mdata);
        }
    }
}

/*
MTA London 4 Fiona Paul Heather Nevil
MTA SanFrancisco 3 Mario Luigi Shariff
MTA Paris 3 Jacque Suzanne Maurice
MTA HongKong 3 Chen Jeng Hee
MTA MexicoCity 4 Conrado Estella Eva Raul
MTA Cairo 3 Hamdy Tarik Misa
*
Hamdy@Cairo Conrado@MexicoCity Shariff@SanFrancisco Lisa@MexicoCity
*
Congratulations on your efforts !!
--Hamdy
*
Fiona@London Chen@HongKong Natasha@Paris
*
Thanks for the report! --Fiona
*
*

Connection between Cairo and MexicoCity
HELO Cairo
250
MAIL FROM:<Hamdy@Cairo>
250
RCPT TO:<Conrado@MexicoCity>
250
RCPT TO:<Lisa@MexicoCity>
550
DATA
354
Congratulations on your efforts !!
--Hamdy
.
250
QUIT
221
Connection between Cairo and SanFrancisco
HELO Cairo
250
MAIL FROM:<Hamdy@Cairo>
250
RCPT TO:<Shariff@SanFrancisco>
250
DATA
354
Congratulations on your efforts !!
--Hamdy
.
250
QUIT
221
Connection between London and HongKong
HELO London
250
MAIL FROM:<Fiona@London>
250
RCPT TO:<Chen@HongKong>
250
DATA
354
Thanks for the report! --Fiona
.
250
QUIT
221
Connection between London and Paris
HELO London
250
MAIL FROM:<Fiona@London>
250
RCPT TO:<Natasha@Paris>
550
QUIT
221

*/