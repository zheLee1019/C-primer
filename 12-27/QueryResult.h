//
// Created by lizhe on 17-12-19.
//

#ifndef LEARNCPP_QUERYRESULT_H
#define LEARNCPP_QUERYRESULT_H
#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include <set>
#include <map>
#include<sstream>

class TextQuery;
class QueryResult{
    friend void print_12(std::ostream&,const QueryResult&);
public:
    QueryResult(std::shared_ptr<std::vector<std::string>> vec,std::shared_ptr<std::map<std::string,std::set<int>>> mp,const std::string& wd)
            :ptr2map(mp),ptr2vec(vec),word(wd){}
private:
    std::shared_ptr<std::vector<std::string>> ptr2vec;
    std::shared_ptr<std::map<std::string,std::set<int>>> ptr2map;
    std::string word;
};



#endif //LEARNCPP_QUERYRESULT_H
