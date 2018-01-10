//
// Created by lizhe on 17-12-19.
//

#include"TextQuery.h"
#include"QueryResult.h"
#include<sstream>
#include<fstream>
using namespace std;

void TextQuery::ConstructMap(const string& str,int linenum)
{
    istringstream iss(str);
    string temp;
    while(iss>>temp){
        ((*mp)[temp]).insert(linenum);
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
    return QueryResult(content,mp,word);
}

