#include<algorithm>
#include<iostream>
#include<fstream>
#include<iterator>
using namespace std;

void writedata(const string& file,const string& oddfile,const string& evenfile)
{
    ifstream fin(file,ios::in);
    if(!fin){
        cout<<"fin err"<<endl;
    }
    istream_iterator<int> in(fin),eof;
    vector<int> res(in,eof);
    ofstream odd(oddfile,ios::out),even(evenfile,ios::out);
    if(!odd||!even){
        cout<<"fout err"<<endl;
    }
    ostream_iterator<int> oddout(odd," "),evenout(even," ");
    for_each(res.cbegin(),res.cend(),[&](const int input){if(input%2==1)
    *oddout=input;
    else
    *evenout=input;});
    fin.close();
    odd.close();
    even.close();
}

int main()
{
    string file("/home/lizhe/CLionProjects/learncpp/text");
    string odd("/home/lizhe/CLionProjects/learncpp/odd");
    string even("/home/lizhe/CLionProjects/learncpp/even");
    writedata(file,odd,even);
    return 0;
}

