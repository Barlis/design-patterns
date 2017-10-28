#include "foo.h"
#include "bar.h"

long Foo::call_count = 0;
void Foo::Test()
{
    call_count++;
    cout<<"Foo: been called for  "<<call_count<<" times"<<endl;
    bar_.Test(*this);
}
void Foo::Out()
{
    cout<<"Foo: Out"<<endl;
}

