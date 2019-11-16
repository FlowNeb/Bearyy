#include "my.h"
#include <iostream>

namespace X
{
int var;
void print()
	{
	std::cout<<"X="<<var<<std::endl;
	}
}

namespace Y
{
int var;
void print()
	{
	std::cout<<"Y="<<var<<std::endl;
	}
}

namespace Z
{
int var;
void print()
	{
	std::cout<<"Z="<<var<<std::endl;
	}
}


int main()
{
X::var = 7;
X::print();                  
using namespace Y;
var = 9;
print();                      
	{         
	using Z::var;
	using Z::print;
	var = 11;
	print();          
	}
print();                 
X::print();                
return 0;
}
