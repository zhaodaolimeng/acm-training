#include <bits/stdc++.h>

using namespace std;

map<string, vector<pair<int, int>>> reverse_index; 
vector<vector<string>> docs;

string tokenize(string term){
    for(int i=0; i<term.size(); i++){
        if(term[i]<='Z' && term[i] >='A')
            term[i] = term[i] - 'A' + 'a';
    }
    return term;
}

vector<string> split_by_space(string line){
    vector<string> ans;
    string s;
    int p = -1;
    for(int i=0; i<=line.size(); i++){
        if(!isalpha(line[i]) || i == line.size()){
            s = line.substr(p+1, i-p-1);
            if(p+1 != i) ans.push_back(s);
            p = i;
        }
    }
    return ans;
}

void build_rindex(){
    for(int i=0; i<docs.size(); i++){
        for(int j=0; j<docs[i].size(); j++){
            vector<string> terms = split_by_space(tokenize(docs[i][j]));
            for(int ti=0; ti<terms.size(); ti++){
                if(reverse_index.find(terms[ti]) == reverse_index.end()){
                    vector<pair<int, int>> vp;
                    reverse_index[terms[ti]] = vp;
                }
                reverse_index[terms[ti]].push_back(make_pair(i, j));
            }
        }
    }
}

vector<vector<string>> index_to_string(map<int, vector<int>> ans_idx){
    vector<vector<string>> ans;
    for(int i=0; i<docs.size(); i++){
        if(ans_idx.find(i) == ans_idx.end())
            continue;
        vector<string> vs;
        for(int j=0; j<ans_idx[i].size(); j++)
            vs.push_back(docs[i][ans_idx[i][j]]);
        ans.push_back(vs);
    }
    return ans;
}

vector<vector<string>> handle_query(string q_str){
    vector<string> raw_qterms = split_by_space(q_str);
    vector<string> qterms;
    string condition;
    vector<vector<string>> ans;
    vector<pair<int, int>> vp;

    for(int qi=0; qi<raw_qterms.size(); qi++){
        if(raw_qterms[qi] == "NOT" || 
            raw_qterms[qi] == "AND" ||
            raw_qterms[qi] == "OR")
            condition = raw_qterms[qi];
        else
            qterms.push_back(tokenize(raw_qterms[qi]));
    }

    if(condition == "NOT"){
        vp = reverse_index[qterms[0]];
        set<int> not_doc_set;
        for(int i=0; i<vp.size(); i++)
            not_doc_set.insert(vp[i].first);
        for(int i=0; i<docs.size(); i++)
            if(not_doc_set.find(i) == not_doc_set.end())
                ans.push_back(docs[i]);
    }else if(condition == "AND"){
        set<int> ds1, ds0;
        vp = reverse_index[qterms[0]];
        for(int i=0; i<vp.size(); i++) ds1.insert(vp[i].first);
        vp = reverse_index[qterms[1]];
        for(int i=0; i<vp.size(); i++)
            if(ds1.find(vp[i].first) != ds1.end())
                ds0.insert(vp[i].first);
        
        map<int, vector<int>> ans_idx;
        set<pair<int,int>> sp;
        vp = reverse_index[qterms[0]];
        for(int i=0; i<vp.size(); i++) sp.insert(vp[i]);
        vp = reverse_index[qterms[1]];
        for(int i=0; i<vp.size(); i++) sp.insert(vp[i]);
        
        for(pair<int,int> p : sp){
            if(ds0.find(p.first) == ds0.end()) continue;
            if(ans_idx.find(p.first) == ans_idx.end()){
                vector<int> vi;
                vi.push_back(p.second);
                ans_idx[p.first] = vi;
            }else
                ans_idx[p.first].push_back(p.second);
        }
        ans = index_to_string(ans_idx);
    }else if(condition == "OR"){
        set<pair<int,int>> s0;
        vp = reverse_index[qterms[0]];
        for(int i=0; i<vp.size(); i++) s0.insert(vp[i]);
        vp = reverse_index[qterms[1]];
        for(int i=0; i<vp.size(); i++) s0.insert(vp[i]);

        map<int, vector<int>> ans_idx;
        for(pair<int,int> p1 : s0){
            if(ans_idx.find(p1.first) == ans_idx.end()){
                vector<int> vi;
                vi.push_back(p1.second);
                ans_idx[p1.first] = vi;
            }else
                ans_idx[p1.first].push_back(p1.second);
        }
        ans = index_to_string(ans_idx);
    }else{
        set<pair<int,int>> s0;
        vp = reverse_index[qterms[0]];
        for(int i=0; i<vp.size(); i++) s0.insert(vp[i]);
        map<int, vector<int>> ans_idx;
        for(pair<int,int> p1 : s0){
            if(ans_idx.find(p1.first) == ans_idx.end()){
                vector<int> vi;
                vi.push_back(p1.second);
                ans_idx[p1.first] = vi;
            }else
                ans_idx[p1.first].push_back(p1.second);
        }
        ans = index_to_string(ans_idx);
    }
    return ans;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n_docs, n_queries;
    string line;

    cin>>n_docs;
    cin.ignore();
    for(int i=0; i<n_docs; i++){
        vector<string> doc;
        while(getline(cin, line) && line != "**********")
            doc.push_back(line);
        docs.push_back(doc);
    }
    build_rindex();

    // cout<<"+++++"<<endl;
    // cout<<"Documents"<<endl;
    // cout<<"+++++"<<endl;
    // for(int i=0; i<docs.size(); i++){
    //     for(int j=0; j<docs[i].size(); j++)
    //         cout<<docs[i][j]<<endl;
    //     cout<<endl;
    // }

    // cout<<"+++++"<<endl;
    // cout<<"Reverse Index"<<endl;
    // cout<<"+++++"<<endl;
    // for(auto const & term : reverse_index){
    //     cout<<term.first<<endl;
    //     vector<pair<int,int>> vp = term.second;
    //     for(int i=0; i<vp.size(); i++)
    //         cout<<"\t"<<vp[i].first<<"\t"<<vp[i].second<<endl;
    // }
    // cout<<"+++++"<<endl;

    cin>>n_queries;
    cin.ignore();
    for(int i=0; i<n_queries; i++){
        string raw_q;
        getline(cin, raw_q);
        vector<vector<string>> ans = handle_query(raw_q);
        if(ans.size() == 0){
            cout<<"Sorry, I found nothing."<<endl;
        }else{
            for(int di=0; di<ans.size(); di++){
                for(int j=0; j<ans[di].size(); j++)
                    cout<<ans[di][j]<<endl;
                if(di != ans.size()-1)
                    cout<<"----------"<<endl;
            }
        }
        cout<<"=========="<<endl;
    }
    return 0;
}