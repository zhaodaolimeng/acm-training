#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<string> braceExpansionII(string expression) {

        vector<char> st;
        vector<set<string> > values;
        char c,cc;
        
        for(int i=expression.size(); i>=0 || st.size()>0; i--) {
            c = st.back(); st.pop_back();

            if(c == '{'){
                set<string> vts; vts.insert("");
                set<string> left;
                string st = "";

                while(st.back() != '}'){
                    cc = st.back(); st.pop_back();
                    if(cc == '#' || cc == ','){
                        set<string> nset;
                        for(auto& ele : vts) nset.insert(ele + st);
                        vts = nset;
                        st = "";

                        if(cc == '#'){
                            set<string> ss = values.back();
                            values.pop_back();
                            set<string> nset;
                            for(auto l : vts) 
                                for(auto r : ss)
                                    nset.insert(l + r);
                            vts = nset;
                        }else{
                            left = vts;
                            vts.clear();
                        }   
                    }else{
                        st += cc;
                    }
                }
                if(st.size()>0){
                    set<string> nset;
                    for(auto& ele : vts) nset.insert(ele + st);
                    vts = nset;
                }

                if(!left.empty()){
                    set<string> nset;
                    for(auto l : left) 
                        for(auto r : vts)
                            nset.insert(l + r);
                    vts = nset;
                }
                st.push_back('#');
                values.push_back(vts);
            }
            st.push_back(expression[i]);
        }
        vector<string> ret(values[0].begin(),values[0].end());
        return ret;
    }
};


int main(){
    Solution sl;
    vector<int> input;

    sl.braceExpansionII("{a,b}{c,{d,e}}");

}
