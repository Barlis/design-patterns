#include "bar.h"
#include "foo.h"

long Bar::call_count = 0;
Bar::Bar()
{
}

void Bar::Test(Foo& foo)
{
    call_count++;
    cout<<"Bar: been called for  "<<call_count<<" times"<<endl;
    cout<<"Bar: Test"<<endl;
    foo.Out();
}

