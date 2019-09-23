#include "std_lib_facilities.h"

int main()
{
int a;
int b;

cout<<"Please give me 2 number:\n";
cin>>a>>b;
cout<<"First number:"<<a<<"\n";
cout<<"Second number:"<<b<<"\n";

a=a*b;
b=a/b;
a=a/b;

cout<<"After switch:\n";
cout<<"First number:"<<a<<"\n";
cout<<"Second number:"<<b<<"\n";

return 0;
}
