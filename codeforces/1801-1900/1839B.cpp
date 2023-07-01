#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,long long>&pa, const pair<int,long long>&pb){
    if(pa.first < pb.first)
        return 1;
    else if(pa.first > pb.first){
        return 0;   
    }else{
        if(pa.second > pb.second) return 1;
        else return 0;
    }
}

int main(){

    int T,n;
    int a;
    long long b;
    std::cin>>T;
    while(T--){
        std::cin>>n;

        vector<pair<int,long long> > vp(n);
        queue<int> light;

        for(int i=0;i<n;i++){
            std::cin>>a>>b;
            vp[i] = make_pair(a,b);
        }
        sort(vp.begin(),vp.end(),cmp);

        long long ret=0;
        int p;
        for(int i=0; i<n; i++){
            ret += vp[i].second;
            light.push(i);
            int light_cnt = light.size();

            while(!light.empty() && vp[light.front()].first <= light_cnt){
                light.pop();
            }
            if(light_cnt == vp[i].first){
                for(p=i; p<n && vp[p].first == light_cnt;) p++;
                i = p-1;
            }
        }
        std::cout<<ret<<endl;
    }
    return 0;
}