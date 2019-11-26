#include "std_lib_facilities.h"
using namespace std;

int ga[10];
void f(int ax [], int ai)
{
int la [10];
	for(int i=0;i<ai;i++)
	{
		la[i]=ax[i];
		cout<<la[i]<<endl;
	}
int* p= new int[ai];
for(int i=0;i<ai;i++)
	{
		p[i]=ax[i];
		cout<<p[i]<<endl;
	}
	delete[]p;
}

int fact(int ai)
{
	int ay=1;
	for(int i=1;i<=ai;i++)
	{ay*=i;}
	return ay;
}

int main()
{
	for(int i=0;i<10;i++)
	{ga[i]=pow(2,i);}
	f(ga,10);

	int aa[10];
	for(int i=1;i<10;i++)
	{aa[i-1]=fact(i);}
	f(aa,10);

return 0;
}
