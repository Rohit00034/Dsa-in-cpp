#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;
bool CheckHigherPriority(char current, char topele) {
    map<char,int> m = {{'+',1},{'-',1},{'*',2},{'/',2}};
    return m[current] > m[topele];
}

string infixtopostfix(string exp){
    string postfix;
    stack<char> s;
for(int i=0;i<exp.length();i++){
    if(exp[i]=='*'|exp[i]=='+'|exp[i]=='-'|exp[i]=='/'){ //checking for operand
        if(s.empty()){
            s.push(exp[i]);
        }
        else if(CheckHigherPriority(exp[i],s.top())){
            s.push(exp[i]);
        }

        else if(!CheckHigherPriority(exp[i],s.top())){
            while (((!s.empty()) && !CheckHigherPriority(exp[i],s.top())  ))
            {
                postfix.append(string(1,s.top()));
                s.pop();
            }
            s.push(exp[i]);
        }
        
    }else{
        postfix.append(string(1,exp[i]));
    }
    

}
while(!s.empty()){
        postfix.append(string(1,s.top()));
        s.pop();
    }
return postfix;
}
int main(){
    cout<<infixtopostfix("A+B*C-D*E-D");
    return 0;
}