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
int func(vector<string>a){
    sort(a.begin(),a.end(),[](const string &x,const string &y){
        return x.size()<y.size();
    });
    unordered_map<string,int>mp;
    int ans=0;
    for(const string &word:a){
        mp[word]=1;
        for(int i=0;i<word.size();i++){
            string last=word.substr(0,i)+word.substr(i+1);
            if(mp.find(last)!=mp.end()){
                mp[word]=max(mp[word],mp[last]+1);
            }
        }
        ans=max(ans,mp[word]);
    }
    return ans;
    
}
int main(){
  vector<string>a={"a","b","ba",”bd”,”bdc”,"bca","bda","bdca"}
  cout<<func(a)<<endl;
}
