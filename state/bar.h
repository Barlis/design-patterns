#ifndef BAR_H_
#define BAR_H_
#include<iostream>
using namespace std;

class Foo;

class Bar{
public:
    Bar();
    void Test(Foo& foo);
private:
    static long call_count;
};
#endif

