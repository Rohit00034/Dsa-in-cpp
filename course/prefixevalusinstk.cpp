/*IMPLEMENTED EVALUATION OF PREFIX USING STACK*/
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
int performop(int a,int b,char ch){
    if(ch=='*'){
        return a*b;
    }
    else if(ch=='+'){
        return a+b;
    }
    else if(ch=='-'){
        return a-b;
    }
    else if(ch=='/'){
        return a/b;
    }else{
        cout<<"ERROR\n";
        return 0;
    }
}
/*the logic for postfix and prefix is the same just the string is traversed in reverse order or
reversed and the order of pushing the a and b is different*/
int evalprefix(string exp){
    stack<int> s1;
    reverse(exp.begin(),exp.end());
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='/' | exp[i]=='+'|exp[i]=='-'|exp[i]=='*'){
            if(s1.empty()){
                cout<<"INVALID EXPRESSION";
                return 0;
            }
            int a=s1.top();
            s1.pop();
            int b=s1.top();
            s1.pop();
            s1.push(performop(a,b,exp[i]));
        }
        else{
            string s(1,exp[i]);
            int operand=stoi(s);
            s1.push(operand);
        }
    }
    return s1.top();
}
int main(){
    cout<<evalprefix("-+*23*549");
    return 0;
}