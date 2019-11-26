#include "std_lib_facilities.h"
using namespace std;

void print_arrey10(ostream& os, int* a)
{
	for(int i=0;i<10;i++)
	{
		os<<i<<". arrey="<<a[i]<<endl;
	}
}

void print_arrey(ostream& os, int* a, int b)
{
	for(int i=0;i<b;i++)
	{
		os<<i<<". arrey="<<a[i]<<endl;
	}
}
//
void print_vector(ostream& os,vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		os<<i<<". vec="<<v[i]<<endl;
	}
}






int main()
{
	int*arrey =new int[10];
	for(int i=0;i<10;i++)
		{
		cout<<arrey[i]<<endl;
		}
		print_arrey10(cout,arrey);
	delete[] arrey;

	int* arrey2= new int[10];
	for(int i=0;i<10;i++)
		{
		arrey2[i]=100+i;
		cout<<arrey2[i]<<endl;
		}
	delete[] arrey2;

	int* arrey3=new int[11];

	for(int i=0;i<11;i++)
		{
		arrey3[i]=100+i;
		cout<<arrey3[i]<<endl;
		}	
	print_arrey(cout,arrey3,11);
	delete[] arrey3;

	int* arrey4=new int[20];
	for(int i=0;i<20;i++)
		{
		arrey4[i]=100+i;
		cout<<arrey4[i]<<endl;
		}
		print_arrey(cout,arrey4,20);
		delete[] arrey2;

	vector<int> v;
	for(int i=0;i<10;i++)
	{
	v.push_back(100+i);
	}
	print_vector(cout,v);

	return 0;
}



