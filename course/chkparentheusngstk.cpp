/*CHECKED FOR BALANCED PARENTHESES USING STACK */
/*The latest opened parentheses should be closed first*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool checkbalance(string a){
stack<char> s;
int len=a.length();
for(int i=0;i<len;i++){
    if(a[i]=='(' | a[i]== '[' | a[i]== '{' ){
    s.push(a[i]);
    }
    else if(a[i]==')'| a[i]==']' |a[i]=='}' ){
        if(s.empty()){
            return false;
        }
        else if((s.top()=='(' and a[i]==')') |(s.top()=='[' and a[i]==']') |(s.top()=='{' and a[i]=='}')){
            s.pop();
        }else{return false;}
    }
}
return s.empty();
}
int main(){
    string tocheck="{()}";
   if(checkbalance(tocheck)){
    cout<<"Given String is Balanced in parentheses\n";
   }else{cout<<"String is not Blanced in parentheses\n";}
    return 0;
}