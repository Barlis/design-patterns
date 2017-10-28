#ifndef FOO_H_
#define FOO_H_
#include<iostream>
using namespace std;
class Bar;

class Foo{
public:
    Foo(Bar& bar): bar_(bar)
    {
    }
    void Test();
    void Out();
public:
    static long call_count;
    Bar& bar_;
};

#endif

