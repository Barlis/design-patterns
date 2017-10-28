#include "bar.h"
#include "foo.h"

int main()
{
    Bar* bar = new Bar();
    Foo* foo = new Foo(*bar);
    bar->Test(*foo);

    return 0;
}
