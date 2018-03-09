#include "myclass.hpp"

int main ()
{
    MyClass<int>* a = new MyClass<int>();
    a->foo();
    return 0;
}

