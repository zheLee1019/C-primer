#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string expression{ "This is (haha)." };
    stack<char> sk;
    bool flag=false;
    for(auto i:expression){
        if(i=='('){
            flag=true;
            continue;
        }
        if(i==')'){
            flag=false;
        }
        if(flag==true){
            sk.push((i));
        }
    }
    string res="";
    while(!sk.empty()){
        res.insert(res.end(),sk.top());
        sk.pop();
    }
    auto pos_b=expression.find("(");
    expression.replace(pos_b+1,res.size(),res);
    cout << expression << endl;

    return 0;
}