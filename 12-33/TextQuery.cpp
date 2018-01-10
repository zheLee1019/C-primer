//
// Created by lizhe on 17-12-19.
//

#include"TextQuery.h"
#include"QueryResult.h"
//#include<sstream>
#include<fstream>
using namespace std;

void TextQuery::ConstructMap(const string& str,int linenum)
{
    istringstream iss(str);
    string temp;
    while(iss>>temp){
        const auto& findres=mp.find(temp);
        if(findres==mp.end())
        {
            mp[temp]=make_shared<set<int>>(set<int>{linenum});
        }
        else
        {
            findres->second->insert(linenum);
        }
    }
}
void TextQuery::Read(const std::string& fn)
{
    ifstream fin(fn);
    if(!fin)
        throw runtime_error("cannot open file");
    string temp;
    int cnt=1;
    while(getline(fin,temp)){
        content->push_back(temp);
        ConstructMap(temp,cnt);
        ++cnt;
    }
    fin.close();
}
QueryResult TextQuery::Query(const std::string& word)
{
    const auto & item=mp.find(word);
    if(item==mp.end())
    {
        return QueryResult();
    }
    else
    {
        return QueryResult(content,item->second,word);
    }
}

