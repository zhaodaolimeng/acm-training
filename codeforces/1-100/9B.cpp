#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

int main(){
    int n,vb,vs,t,xu,yu;
    vector<int> stop;
    cin>>n>>vb>>vs;

    for(int i=0; i<n;i++){
        cin>>t;
        stop.push_back(t);
    }
    cin>>xu>>yu;

    double maxd = 1e12,d;

    for(int i=1;i<n;i++){
        d = 1.0*stop[i]/vb + sqrt(1.0*(xu-stop[i])*(xu-stop[i])+yu*yu)/vs;
        if(d<maxd || (abs(maxd-d)<eps && abs(stop[t]-xu) > abs(stop[i]-xu))){
            maxd = d;
            t = i;
        }
    }

    cout<<t+1<<endl;
    return 0;
}