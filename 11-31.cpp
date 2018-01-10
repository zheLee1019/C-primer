#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
void print(multimap<string,string>& mp)
{
    for(auto i:mp){
        cout<<"Author:"<<i.first<<" Composition:"<<i.second<<endl;
    }
}
int main()
{
    multimap<string,string> author{
            {"David","haha"},
            {"Peter","hehe"},
            {"David","heihei"},
            {"Lucy","haohao"}
    };
    print(author);
    string ar="Lily";
    auto findres=author.equal_range(ar);
    if(findres.first!=findres.second){
        while(findres.first!=findres.second){
            multimap<string,string> pp;
//            pp[findres.first->first]=findres.first->second;
            pp.insert(pair<string,string>(findres.first->first,findres.first->second));
            cout<<endl<<"find"<<endl;
            print(pp);
            ++findres.first;
        }
    }else{
        cout<<"cannot find"<<endl;
    }
    return 0;
}

