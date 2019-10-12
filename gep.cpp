#include "std_lib_facilities.h"

int main()
{
double a=0;
char b;
double c=0;
double d=0;
double e=0;

cout << "Please enter a number,an expression(+ - / *),a number.\n";
if(cin){
cin>>a>>b>>c; 
switch(b)
    {     
case '+':
     e=a+c;
     break;
case '-':
     a=a-c;
     break;
case '/':
if (c==0) error("diveding with 0\n");
     a=a/c;
     break;
case '*':
     a=a*c;
     break;
case 'q' :
 exit(0); break;
     }
cout<<a<<"\n";
        }
while(cin){
cin>>b>>d;
switch(b){
case '+':
     a=a+d;
cout<<a<<"\n";
     break;
case '-':
     a=a-d;
cout<<a<<"\n";
     break;
case '/':
if (d==0) error("diveding with 0\n");
     a=a/d;
cout<<a<<"\n";
     break;
case '*':
     a=a*d;
cout<<a<<"\n";
     break;
case 'q' :
 exit(0); break;
        }
         }

return 0;
}
