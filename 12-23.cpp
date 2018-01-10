#include<iostream>
#include"string.h"
#include<string>
using namespace std;

char* associate(char* str1,char* str2,size_t len1,size_t len2)
{
    char* result=new char[len1+len2+1];
    int cnt=0;
    while(str1[cnt]!='\0'){
        result[cnt]=str1[cnt];
        ++cnt;
    }
    int cnt2=0;
    while(str2[cnt2]!='\0'){
        result[cnt]=str2[cnt2];
        ++cnt;
        ++cnt2;
    }
    result[cnt]='\0';
    return result;
}
string associate(string s1,string s2)
{
    return s1.append(s2);
}
int main()
{
    char *arr1="hello";
    char *arr2="world!";
    char* res1=associate(arr1,arr2,strlen(arr1),strlen(arr2));
    cout<<res1<<endl;
    cout<<associate(string(arr1),string(arr2))<<endl;
    delete[] res1;
    return 0;
}