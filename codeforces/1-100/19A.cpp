/*
模拟足球小组赛
*/

#include<bits/stdc++.h>

using namespace std;

class Team {
public:
    string teamname;
    int standing;
    int goaldiff;
    int scored;

    Team(){}
    Team(string t,int st,int g, int sc):teamname(t),standing(st),goaldiff(g),scored(sc){}
};

bool cmp(Team const& a, Team const& b){
    if(a.standing>b.standing) return true;
    if(a.standing == b.standing){
        if(a.goaldiff>b.goaldiff) return true;
        if(a.goaldiff==b.goaldiff){
            if(a.scored>b.scored) return true;
        }
    }
    return false;
}


int main(){
    int n,t,g1,g2;
    string s,t1,t2;
    cin>>n;
    map<string,Team> teams;

    for(int i=0;i<n;i++){
        cin>>s;
        teams.insert(make_pair(s,Team(s,0,0,0)));
    }

    for(int i=0;i<(n*(n-1)/2);i++){

        cin>>s;
        t = s.find("-");
        t1 = s.substr(0, t);
        t2 = s.substr(t+1);

        cin>>s;
        t = s.find(":");
        g1 = stoi(s.substr(0,t));
        g2 = stoi(s.substr(t+1));

        // cout<<t1<<"\t"<<t2<<"\t"<<g1<<"\t"<<g2<<endl;

        if(g1>g2){
            teams[t1].standing += 3;
            teams[t2].standing += 0;
        } else if(g1<g2){
            teams[t1].standing += 0;
            teams[t2].standing += 3;
        } else {
            teams[t1].standing += 1;
            teams[t2].standing += 1;
        }
        teams[t1].goaldiff += (g1-g2);
        teams[t2].goaldiff += (g2-g1);
        teams[t1].scored += g1;
        teams[t2].scored += g2;
    }

    vector<Team> vec;
    vector<string> ans;

    for(auto const& entry : teams) vec.push_back(entry.second);
    sort(vec.begin(), vec.end(), cmp);
    
    for(int i=0;i<(n/2);i++) ans.push_back(vec[i].teamname);
    sort(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
    return 0;
}