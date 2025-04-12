#include<bits/stdc++.h>
using namespace std;

bool res(const string &w1,const string &w2){
    if(w1.size()!=w2.size()+1)return false;

    int i=0,j=0;
    while(i<w1.size()&&j<w2.size()){
        if(w1[i]==w2[j])i++;
        j++;
    }
    return i==w1.size();
}



pair<int,vector<string>> func(vector<string>a){
    sort(a.begin(),a.end(),[](const string &x,const string &y){
        return x.size()<y.size();
    });
    unordered_map<string,pair<int,string>>mp;
    int ans=0;
    string prevWord;


    for(const string &word:a){
        mp[word]={1,""};
        for(int i=0;i<word.size();i++){
            string last=word.substr(0,i)+word.substr(i+1);
            if(mp.find(last)!=mp.end()){
                if(mp[last].first+1>mp[word].first){
                    mp[word]={mp[last].first+1,last};
                }
            }
        }
        if(mp[word].first>ans){
        ans=mp[word].first;
        prevWord=word;
        }
    }
    
    
    vector<string>ch;
    while(!prevWord.empty()){
        ch.push_back(prevWord);
        prevWord=mp[prevWord].second;
    }
    reverse(ch.begin(),ch.end());
    return {ans,ch};
    
}
int main(){
  vector<string>a={"a","b","ba","bd","bdc","bca","bda","bdca"};
  cout<<func(a)<<endl;
}
