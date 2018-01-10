//
// Created by lizhe on 17-12-4.
//

#ifndef LEARNCPP_STRBLOB_H
#define LEARNCPP_STRBLOB_H
#include<vector>
#include<string>
#include<memory>
#include<exception>
//#include"StrBlobPtr.h"
class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type st;
    StrBlob():data(std::make_shared<std::vector<std::string>>()){}
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
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(st i,const std::string& msg)const{
        if(i>=data->size()){
            throw std::out_of_range(msg);
        }
    }
};



class StrBlobPtr{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob & a,size_t sz=0):wptr(a.data),curr(sz){}
    std::string& deref()const{
        auto p=check(curr,"dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr(){
        check(curr,"increment past end of StrBLobPtr");
        ++curr;
        return *this;
    }
    bool isequal(StrBlobPtr& sb){
        return curr==sb.curr;
    }
private:
    std::shared_ptr<std::vector<std::string>> check(size_t sz,const std::string& str)const
    {
        auto ret=wptr.lock();
        if(!ret){
            throw std::runtime_error("unbound StrBlobPtr");
        }
        if(sz>=ret->size()){
            throw std::out_of_range(str);
        }
        return ret;
    }
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};


StrBlobPtr StrBlob::end(){
    auto ret=StrBlobPtr(*this,data->size());
    return ret;
}
StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}

#endif //LEARNCPP_STRBLOB_H
