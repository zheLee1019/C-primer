//
// Created by lizhe on 17-12-4.
//

#ifndef LEARNCPP_STRBLOB_H
#define LEARNCPP_STRBLOB_H
#include<vector>
#include<string>
#include<memory>
#include<exception>
class StrBlob{
public:
    typedef std::vector<std::string>::size_type st;
    StrBlob()=default;
    StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}
    st size()const{return data->size();}
    bool empty() const{return data->empty();}
    void push_back(const std::string& s){data->push_back(s);}
    void pop_back(){
        check(0,"pop back on empty strblob");
        data->pop_back();
    }
    std::string& front(){
        return const_cast<const StrBlob*>(this)->front();
    }
    std::string& front()const{
        check(0,"front on empty strblob");
        return data->front();
    }
    std::string& back(){
        return const_cast<const StrBlob*>(this)->back();
    }
    std::string& back()const{
        check(0,"back on empty strblob");
        return data->back();
    }
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(st i,const std::string& msg)const{
        if(i>=data->size()){
            throw std::out_of_range(msg);
        }
    }
};
#endif //LEARNCPP_STRBLOB_H
