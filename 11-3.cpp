#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

int main()
{
    string word;
    map<string,size_t> mp;
    while(cin>>word){
        ++mp[word];
    }
    for(const auto &i:mp){
        cout<<i.first<<" "
                     <<i.second<<endl;
    }
    return 0;
}

