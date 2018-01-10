#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main()
{
    vector<pair<string,size_t>> res;
    string word;
    while(cin>>word){
        pair<string,size_t> temp{word,word.size()};
        res.push_back(temp);
    }
    for(auto i:res){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}

