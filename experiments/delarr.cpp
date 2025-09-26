#include <iostream>
using namespace std;
int main(){
    int a[4]={1,2,3,4};
    delete [] a;  //gives warning
    /*a is a stack-allocated array (automatic storage).
It lives on the stack, and its lifetime is managed automatically — when main() ends, it’s destroyed.

delete[] is only for memory allocated with new[].

Using delete[] on a is undefined behavior, and the compiler is warning you about that (-Wfree-nonheap-object).*/
    
    return 0;
}