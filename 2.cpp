#include "my.h"
#include <iostream>
using namespace std;

void swap_v(int a, int b)
{
int temp;
temp=a;
a=b;
b=temp;
}
void swap_r(int& a, int& b)
{
int temp;
temp=a;
a=b;
b=temp;
}

int main()
{
int x=7;
int y=9;

swap_r(x,y);
std::cout<<"x="<<x<<" "<<"y="<<y<<std::endl;

swap_v(7,9);
std::cout<<"x="<<x<<" "<<"y="<<y<<std::endl;

const int cx=7;
const int cy=9;
swap_v(cx,cy); //doesnt work but compile
std::cout<<"cx="<<cx<<" "<<"cy="<<cy<<std::endl;

swap_v(7.7,9.9);

double dx = 7.7;
double dy = 9.9;
swap_v(dx,dy); //doesnt work but compile
std::cout<<"dx="<<dx<<" "<<"dy="<<dy<<std::endl;
swap_v(7.7,9.9);
return 0;
}
