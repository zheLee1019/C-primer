#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<sstream>
using namespace std;
void constuctmap(const string& str,map<string,set<int>>& mp,int linenum)
{
    istringstream is(str);
    string temp;
    while(is>>temp)
    {
        mp[temp].insert(linenum);
    }
}
void read(const string& str,vector<string>& vec,map<string,set<int>>&mp)
{
    ifstream fin(str);
    if(!fin)
    {
        throw runtime_error("cannot open file");
    }
    int cnt=1;
    string temp;
    while(getline(fin,temp))
    {
        vec.push_back(temp);
        constuctmap(temp,mp,cnt);
        ++cnt;
    }
}
void queryandprint(const string& str,vector<string>&vec,map<string,set<int>>&mp)
{
    const auto queryres=mp.find(str);
    if(queryres==mp.end())
    {
        cout<<"cannot find"<<endl;
    }
    else
    {
        cout<<str<<" occurs "<<(*queryres).second.size()<<" times"<<endl;
        for(const auto& item:(*queryres).second)
        {
            cout<<"(line "<<item<<") "<<vec[item-1]<<endl;
        }
    }
}

int main()
{
    string path("/home/lizhe/CLionProjects/learncpp/txt");
    vector<string> vec;
    map<string,set<int>> mp;
    read(path,vec,mp);
    string word;
    do{
        cout<<"please enter a word, press q to quit"<<endl;
        if(cin>>word&&word!="q"){
            queryandprint(word,vec,mp);
        }
        else
            break;
    }while(true);
    return 0;
}