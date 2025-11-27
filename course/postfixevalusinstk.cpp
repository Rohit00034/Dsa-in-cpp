/*IMPLEMENTED EVALUATION OF POSTFIX USING STACK*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int performop(int a,int b,char ch){
if(ch=='*'){
    return a*b;
}
else if(ch=='-'){
    return a-b;
}
else if(ch=='+'){
    return a+b;
}
else if(ch=='/'){
    return a/b;
}else{
    cout<<"ERROR";
    return 0;
}
}
int evalpostfix(string exp){
    stack<int> s1;
    int len =exp.length();
    for(int  i=0;i<len;i++){
        if(exp[i]=='*'| exp[i]=='/' | exp[i]=='*' | exp[i]=='+' | exp[i]=='-'){
            if(s1.empty()){
                cout<<"INVALID EXPRESSION\n";
                return 0;
            }
            int b=s1.top();
            s1.pop();
            int a=s1.top();
            s1.pop();
            s1.push(performop(a,b,exp[i]));
        }
        else{
            // int a=str[i] -'0'; //as str[i] is a char and any char returns ascii value.e.g '9' is 57 is ascii and '0' is 48 so we get 57-48=9
            /*we did not use the above method because the char holds only 1 value which will only be valid 
            for siingle digit numbers */
            string chartostr(1,exp[i]);
            int operand=stoi(chartostr); /*this directly converts any string to int if and only if 
            the string is a number*/
            s1.push(operand);
        }
        
    }
    return s1.top();
}
int main(){
    cout<<evalpostfix("23*54*+9-");
    return 0;
}