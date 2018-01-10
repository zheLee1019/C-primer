#include<iostream>
#include<fstream>
#include"StrBlob.h"
//#include"StrBlobPtr.h"
using namespace std;

void read(vector<string>& result,string& fn)
{
    ifstream fin(fn);
    if(!fin){
        throw runtime_error("cannot open file");
    }
    string temp;
    while(getline(fin,temp)){
        result.push_back(temp);
    }
    fin.close();
}
int main()
{
    string fn("/home/lizhe/CLionProjects/learncpp/txt");
    vector<string> result;
    read(result,fn);
    StrBlob sb;
    for(auto i:result){
        sb.push_back(i);
    }
    auto bg=sb.begin();
    auto ed=sb.end();
    while(!bg.isequal(ed)){
        cout<<bg.deref()<<endl;
        bg.incr();
    }
    return 0;
}