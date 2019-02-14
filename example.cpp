/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

typedef void (*VoidFunctionPointer)();

class Base
{
    public:
    Base(){};
    
    void SetCallback( VoidFunctionPointer PtrToSet)
    {
        mPtrToCallback = PtrToSet;
    }
    
    void SetCallback_2( void (*PtrToSet)())
    {
        mPtrToCallback_2 = PtrToSet;
    }
    
    static void OnMessageReceived()
    {
        mPtrToCallback();
        mPtrToCallback_2();
    }
    
    static VoidFunctionPointer mPtrToCallback;
    static void (*mPtrToCallback_2)();
};

VoidFunctionPointer Base::mPtrToCallback;
void (*Base::mPtrToCallback_2)();

void TEST()
{
    printf("\n TEST CALLBACK WORKING \n");
}

int main()
{
    printf("Hello World");
    
    Base base;
    base.SetCallback(&TEST);
    base.SetCallback_2(&TEST);
    base.OnMessageReceived();

    return 0;
}

