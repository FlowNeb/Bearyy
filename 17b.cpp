#include "std_lib_facilities.h"
using namespace std;

void print_arrey(ostream& os, int* a, int b)
{
	for(int i=0;i<b;i++)
	{
		os<<i<<". arrey="<<a[i]<<endl;
	}
}


int main()
{
int* o= new int(7);
int* p1=o;
cout<<&p1<<"--"<<*p1<<endl;
delete[]o;

int *t= new int(7);
for(int i=0;i<7;i++)
	{
	t[i]=pow(2,i);
	}
int* p2=t;
cout<<&p2<<"--"<<*p2<<endl;
print_arrey(cout,p2,7);
delete[]t;
int* p3=p2;
p2=p1;
p2=p3;
cout<<&p1<<"--"<<*p1<<endl;
print_arrey(cout,p1,7);
cout<<&p2<<"--"<<*p2<<endl;
print_arrey(cout,p2,7);
delete[]p1;
delete[]p2;
delete[]p3;

p1=new int[10];
for(int i=0;i<10;i++)
{
	p1[i]=pow(2,i);
}

p2=new int[10];
for(int i=0;i<10;i++)
{
	p2[i]=p1[i];
}

print_arrey(cout,p1,10);

delete[]p1;
delete[]p2;

vector<int> v;
for(int i=0;i<10;i++)
{
	v.push_back(pow(2,i));
}

vector<int> vec;
for(int i=0;i<v.size();i++)
{
	vec.push_back(v[i]);
}
for(int i=0;i<vec.size();i++)
{
	cout<<i<<"--"<<vec[i]<<endl;
}

 return 0;
}
