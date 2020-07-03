    #include <iostream>

namespace foo // Define a namespace named foo
{
    // This do something belongs to the namespace foo
    int doSomething(int x, int y)
    {
        return x + y ;
    }
}

namespace goo // Define a namespace named goo
{
    // This do something belongs to the namespace goo
    int doSomething(int x, int y)
    {
        return x - y ;
    }
}

namespace basicMath
{
    constexpr double pi{3.14} ;
    constexpr double e{2.7} ;
}

int main()
{
    int a{13} ;
    int b{6} ;

    // We can acess a particular namespace with the scope resolution operator (::)
    std::cout << foo::doSomething(a,b) << " != " << goo::doSomething(a,b) << '\n' ;
    std::cout << "pi ~ " << basicMath::pi << " and e ~ " << basicMath::e << '\n' ;

    return 0;
}
