#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
using Family=map<string,vector<string>>;
void addnewfamily(string & firstname,Family& family)
{
    family[firstname]={};
}
void addnewmember(string& firstname,string& name,Family& family)
{
    auto item=family.find(firstname);
    (item->second).push_back(name);
}
void print(Family& fam)
{
    for(auto &i :fam)
    {
        cout<<"firstname:"<<i.first<<endl;
        for(auto &j:i.second)
        {
            cout<<"child:"<<j<<endl;
        }
    }
}
int main()
{
    string firstname("lee");
    Family fam;
    addnewfamily(firstname,fam);
    string name("haha");
    addnewmember(firstname,name,fam);
    name="hehe";
    addnewmember(firstname,name,fam);
    firstname="David";
    addnewfamily(firstname,fam);
    name="haha";
    addnewmember(firstname,name,fam);
    name="hehe";
    addnewmember(firstname,name,fam);
    print(fam);
    return 0;
}

