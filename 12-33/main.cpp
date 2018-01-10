#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<sstream>
#include"TextQuery.h"
#include"QueryResult.h"
using namespace std;

int main()
{
    string fn("/home/lizhe/CLionProjects/learncpp/txt");
    TextQuery tq(fn);
    string word;
    do{
        cout<<"please enter a word, press q to quit"<<endl;
        if(cin>>word&&word!="q"){
            print_12(cout,tq.Query(word));
        }
        else
            break;
    }while(true);
    return 0;
}