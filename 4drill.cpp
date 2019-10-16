//Feladat 1-5 ig



#include "std_lib_facilities.h"

int main()
{
double a=0;
double b=0;

while (cin>>a>>b)  
{         

if (a>b)  {cout<<"larger value: "<<a<<" smaller value: "<<b<<"\n";}
if (b>a)  {cout<<"larger value: "<<b<<" smaller value: "<<a<<"\n";}
if (a==b) {cout<<"the numbers are equal.\n";}

if ((a-b)<(1.0/100))  {cout<<"the numbers are almost equal \n";}
}



return 0;

}








//6 Feladat



#include "std_lib_facilities.h"

int main()
{
double a=0;
bool x = true;
double small;
double large;

while(cin>>a)
{
 cout<<a<<"\n";
 if(x){
small = a;
large = a;
x=false;
}
else if (a<small) 
{   small = a;
    cout<<"the smallest so far"<<"\n";  
    
}
else if (a>large)
{   large = a;
    cout<<"the largest so far"<<"\n";
    
}

}
return 0;

}





//feladat7-11ig


#include "std_lib_facilities.h"

int main()
{
double a=0;
string unit;
bool x = true;
double small=0;
double large=0;
double sum=0;
double count=0;
vector <double> v;

cout<<"Give me a number and a unit \n";
while(cin>>a>>unit)
{
if (unit == "cm"){
a=a/100;
sum=sum+a;
count++;}
else if (unit == "m"){
a=a;
sum=sum+a;
count++;}
else if (unit == "in"){
a=a/100*2.54;
sum=sum+a;
count++;}
else if (unit == "ft"){
a=a/100*2.54*12;
sum=sum+a;
count++;}
else{cout<<"illegal or wrong unite\n";} 

if(x)
{small = a;
large = a;
x=false;}

else if (a<small) 
{   small = a;}
else if (a>large)
{   large = a;}

v.push_back(a);

cout<<"Largest: "<<large<<'\n';
cout<<"Smallest: "<<small<<'\n';
cout<<"Sum: "<<sum<<'\n';
cout<<"Pices: "<<count<<'\n';

sort(v.begin(),v.end());
 for (int i = 0;i<v.size();i++){
   cout<<v[i]<<" ";
 }

}
return 0;

}
