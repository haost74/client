#include <iostream>
#include "lib/client/client.hpp"
#include <json/json.h>

#include <boost/lambda/lambda.hpp>

#include <boost/variant.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include <boost/regex.hpp>
#include <boost/type_index.hpp>

template <typename T>
void f(T p)
{
   std::cout << typeid(T).name() << '\n';
   std::cout << typeid(p).name() << '\n';
}

template<typename T>
void f2(T p)
{
   std::cout << "T is "
              << boost::typeindex::type_id_with_cvr<T>()
              << std::endl;

    std::cout << "p is "
              << boost::typeindex::type_id_with_cvr<decltype(p)>()
              << std::endl;              
}

class A{
  
};


int main(int argc, char * argv[]){

{
    int x = 10;
    //f2(x);

    const int cx = 10;
    //f2(cx);

    int& rx = x;
    f2(rx);
}

int x = 22;
const int cx = x;
int& xr = x;
const A a;
auto ar = &a;
   f(ar);

   return 0;

    int i  = 1000;
    while (i)
    {
        --i;
        clientAsync::client client;
    }


    return 0;
}