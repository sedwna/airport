#include <iostream>
#include <vector>
#include  "../include/app.hpp"
#include "../include/airplane.hpp"

using namespace std;
int main()
{
    try
    {
          App app;
    return app.exec();
    }
    catch(...)
    {
        // std::cerr << e.what() << '\n';
    }
    
  
}