#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
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
    auto end=count_if(words.begin(),words.end(),[sz](const string& s){return s.size()>sz;});
    cout<<end<<endl;

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
