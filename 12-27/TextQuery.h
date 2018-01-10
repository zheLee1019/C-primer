//
// Created by lizhe on 17-12-19.
//

#ifndef LEARNCPP_TEXTQUERY_H
#define LEARNCPP_TEXTQUERY_H
#include<vector>
#include<map>
#include<string>
#include<memory>
#include <set>
class QueryResult;
class TextQuery{
public:
    TextQuery(const std::string& fn):mp(std::make_shared<std::map<std::string,std::set<int>>>()),
    content(std::make_shared<std::vector<std::string>>()){
        Read(fn);
    }
    QueryResult Query(const std::string&);
private:
    void Read(const std::string&);
    void ConstructMap(const std::string&,int);
    std::shared_ptr<std::map<std::string,std::set<int>>> mp;
    std::shared_ptr<std::vector<std::string>> content;
};
#endif //LEARNCPP_TEXTQUERY_H
