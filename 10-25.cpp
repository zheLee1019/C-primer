#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std::placeholders;
using namespace std;
bool check_size(const string& s,string::size_type sz)
{
    return s.size()>=sz;
}
void elimDups(vector<string>& words)
{
    sort(words.begin(),words.end(),
         [](const string& s1,const string & s2)
         {return s1<s2;});
    auto end=unique(words.begin(),words.end());
    words.erase(end,words.end());
}
void biggies(vector<string>& words,vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(),words.end(),[](const string& s1,const string& s2)
    {return s1.size()<s2.size();});
    auto end=partition(words.begin(),words.end(),bind(check_size,_1,sz));
    for_each(words.begin(),end,[](const string& s){cout<<s<<" ";});

}
void turn2vec(string& input,vector<string>& res)
{
    unsigned long pos_b=0,pos_e=0;
    while((pos_e=input.find(" ",pos_b))!=input.npos){
        res.push_back(string{input.begin()+pos_b,input.begin()+pos_e});
        pos_b=++pos_e;
    }
    res.push_back(string{input.begin()+pos_b,input.end()});
}
int main()
{
    string expre{"the quick red fox jumps over the slow red turtle"};
    vector<string>res;
    turn2vec(expre,res);
    biggies(res,5);
    return 0;
}

