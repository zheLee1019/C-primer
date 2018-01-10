//
// Created by lizhe on 17-11-20.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef unsigned long mytp;
vector<mytp>& findnum_1(string& input,vector<mytp>& result)
{
    string mark("0123456789");
    decltype(input.size()) pos=0;
    while((pos=input.find_first_of(mark,pos))!=input.npos){
        result.push_back(pos);
        ++pos;
    }
    return result;
}
vector<mytp>& findstr_1(string& input,vector<mytp>& result)
{
    string mark("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    decltype(input.size()) pos=0;
    while((pos=input.find_first_of(mark,pos))!=input.npos){
        result.push_back(pos);
        ++pos;
    }
    return result;
}
vector<mytp>& findnum_2(string& input,vector<mytp>&result)
{
    string mark("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    decltype(input.size()) pos=0;
    while((pos=input.find_first_not_of(mark,pos))!=input.npos){
        result.push_back(pos);
        ++pos;
    }
    return result;
}
vector<mytp>& findstr_2(string& input,vector<mytp>&result)
{
    string mark("0123456789");
    decltype(input.size()) pos=0;
    while((pos=input.find_first_not_of(mark,pos))!=input.npos){
        result.push_back(pos);
        ++pos;
    }
    return result;
}
int main()
{
    string temp("ab2c3d7R4E6");
    vector<mytp> resultnum;
    vector<mytp> resultstr;
    cout<<"find first of"<<endl;
    resultnum=findnum_1(temp,resultnum);
    for(auto i:resultnum){
        cout<<i<<" ";
    }
    cout<<endl;
    resultstr=findstr_1(temp,resultstr);
    for(auto i:resultstr){
        cout<<i<<" ";
    }
    resultnum.clear();
    resultstr.clear();
    cout<<endl;
    cout<<"find first not of"<<endl;
    resultnum=findnum_2(temp,resultnum);
    for(auto i:resultnum){
        cout<<i<<" ";
    }
    cout<<endl;
    resultstr=findstr_2(temp,resultstr);
    for(auto i:resultstr){
        cout<<i<<" ";
    }
    cout<<endl<<temp<<endl;
    return 0;
}