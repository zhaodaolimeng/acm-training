#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){

    int n, v, c, last;
    string s;
    int arr[] = {'a', 'e', 'i', 'o', 'u'};
    set<char> vowels(begin(arr), end(arr));
    vector<string> words;
    vector<int> vowel_cnt;

    map<int, vector<int> > cnt_vec[26]; // group by vowel count
    vector<pair<int, int> > word_first, word_second;
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>s;
        words.push_back(s);
        v = 0;
        for(int j=0; j<s.size(); j++)
            if(vowels.find(s[j]) != vowels.end())
                v ++, c = s[j];
        vowel_cnt.push_back(v);
        if(cnt_vec[c-'a'][v].empty())
            cnt_vec[c-'a'][v].push_back(i);
        else{
            word_second.push_back(make_pair(cnt_vec[c-'a'][v].back(), i));
            cnt_vec[c-'a'][v].pop_back();
        }
    }

    // cout<<"======"<<endl;
    // for(int i=0; i<26; i++){
    //     for(const auto& e : cnt_vec[i]){
    //         cout<<e.first<<"= ";
    //         for(int j=0; j<e.second.size(); j++) cout<<words[e.second[j]]<<" ";
    //         cout<<endl;
    //     }
    // }

    // cout<<"======"<<endl;
    // for(int i=0; i<word_second.size(); i++)
    //     cout<<words[word_second[i].first]<<" "<<words[word_second[i].second]<<endl;
    

    for(int i=0; i<n; i++){
        v = vowel_cnt[i];
        last = -1;
        for(int j=0; j<26; j++){
            while(!cnt_vec[j][v].empty()){
                if(last != -1){
                    word_first.push_back(make_pair(cnt_vec[j][v].back(), last));
                    last = -1;
                }else{
                    last = cnt_vec[j][v].back();
                }
                cnt_vec[j][v].pop_back();
            }
        }
    }

    // cout<<"======"<<endl;
    // for(int i=0; i<word_first.size(); i++)
    //     cout<<words[word_first[i].first]<<" "<<words[word_first[i].second]<<endl;
    // cout<<"======"<<endl;

    while(word_second.size() > word_first.size()){
        word_first.push_back(word_second.back());
        word_second.pop_back();
    }
    cout<<word_second.size()<<endl;
    while(!word_second.empty()){
        cout<<words[word_first.back().first]<<" "<<words[word_second.back().first]<<endl;
        cout<<words[word_first.back().second]<<" "<<words[word_second.back().second]<<endl;
        word_first.pop_back();
        word_second.pop_back();
    }
    return 0;
}
