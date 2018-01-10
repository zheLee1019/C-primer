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
    using ResultIter=std::set<int>::iterator;
    friend void print_12(std::ostream&,const QueryResult&);
public:
    QueryResult()=default;
    QueryResult(std::shared_ptr<std::vector<std::string>> vec,std::shared_ptr<std::set<int>> mp,const std::string& wd)
            :ptr2set(mp),ptr2vec(vec),word(wd){}
    std::shared_ptr<std::vector<std::string>> get_file() const{
        return ptr2vec;
    }
    ResultIter begin()const{
        return ptr2set->begin();
    }
    ResultIter end()const{
        return ptr2set->end();
    }
private:
    std::shared_ptr<std::vector<std::string>> ptr2vec;
    std::shared_ptr<std::set<int>> ptr2set;
    std::string word;
};

void print_12(std::ostream& ot,const QueryResult& qr);

#endif //LEARNCPP_QUERYRESULT_H
