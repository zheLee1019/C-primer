#include<iostream>
#include"TextQuery.h"
#include"QueryResult.h"
using namespace std;

int main()
{
    TextQuery tq("/home/lizhe/CLionProjects/learncpp/txt");
    string key;
    while(true){
        cout<<"please enter a word, press q to quit"<<endl;

        if(!(cin>>key)||key=="q"){
            break;
        }
        print_12(cout,tq.Query(key));

    }
    return 0;
}