#include<iostream>
#include<map>
#include<sstream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
pair<string,string> getpair(string& ipt)
{
    auto pos=ipt.find(' ');
    return make_pair(string(ipt.begin(),ipt.begin()+pos),string(ipt.begin()+pos+1,ipt.end()));
}
bool readtxt(string& path_convert,map<string,string>& res_convert,string& path_txt,vector<string>& res_txt)
{
    ifstream fin1(path_convert);
    ifstream fin2(path_txt);
    if(!fin1||!fin2)
        return false;
    string temp;
    while(getline(fin1,temp)){
        res_convert.insert(getpair(temp));
    }
    fin1.close();
    while(getline(fin2,temp)){
        res_txt.push_back(temp);
    }
    fin2.close();
    return true;
}
void changestr(map<string,string>& convert,vector<string>& txt,vector<string>& result)
{
    for(auto str:txt){
        istringstream temp(str);
        ostringstream ot;
        string buf;
        while(temp>>buf){
            auto iter=convert.find(buf);
            if(iter==convert.end()){
                ot<<buf<<" ";
            }else{
                ot<<(iter->second)<<" ";
            }
        }
        result.push_back(ot.str());
    }
}
int main()
{
    string path_convert{"/home/lizhe/CLionProjects/learncpp/convert"};
    string path_txt{"/home/lizhe/CLionProjects/learncpp/txt"};
    map<string,string> res_convert;
    vector<string> res_txt;
    if(!readtxt(path_convert,res_convert,path_txt,res_txt)){
        cout<<"error in readfile"<<endl;
    }
    vector<string> res;
    changestr(res_convert,res_txt,res);
    for(auto i:res){
        cout<<i<<endl;
    }
    return 0;
}