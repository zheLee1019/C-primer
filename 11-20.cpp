#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main()
{
    map<string,size_t> res;
    string word;
    while(cin>>word){
        auto iter=res.insert({word,1});
        if(!iter.second){
            ++res[word];
        }
    }

    for(auto i:res){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}

