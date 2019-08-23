#include <bits/stdc++.h>

using namespace std;

int main(){

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w",stdout);

    int n, t;
    while(cin>>n && n != 0){
        queue<int> q;
        vector<int> ds;
        for(int i=1; i<=n; i++) q.push(i);

        while(q.size() > 1){

            ds.push_back(q.front());
            q.pop();

            t = q.front(); q.pop();
            q.push(t);
        }
        
        cout<<"Discarded cards:";
        if(ds.size() > 0){
            cout<<" "<<ds[0];
            for(int i=1; i<ds.size(); i++) cout<<", "<<ds[i];
        }
        cout<<endl;
        cout<<"Remaining card: "<<q.front()<<endl;
    }
}
