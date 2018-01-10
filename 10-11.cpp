#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
void elimDups(vector<string>& input)
{
    sort(input.begin(),input.end());
    auto end_unique=unique(input.begin(),input.end());
    input.erase(end_unique,input.end());
}
void changestyle(string& input,vector<string>& str)
{
    unsigned long pos_end=0,pos_begin=0;
    while((pos_end=input.find(" ",pos_end))!=input.npos){
        str.push_back(string{input.begin()+pos_begin,input.begin()+pos_end});
        pos_begin=++pos_end;
    }
    str.push_back(string{input.begin()+pos_begin,input.end()});
}
bool isshorter(const string& s1,const string& s2)
{
    return s1.size()<s2.size();
}

int main()
{
    string input{"the quick red fox jumps over the slow red turtle"};
    vector<string> str;
    changestyle(input,str);
    elimDups(str);
    stable_sort(str.begin(),str.end(),isshorter);
    for(auto i:str)
    {
        cout<<i<<" ";
    }
    return 0;
}
