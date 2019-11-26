#include "std_lib_facilities.h"
using namespace std;


vector<int> gv(10);
void f(vector<int> v)
{
vector<int> lv(v.size());
	for(int i=0;i<v.size();i++)
	{
		lv[i]=v[i];
		cout<<lv[i]<<endl;
	}

vector<int> lv2=v;
for(int i=0;i<lv2.size();i++)
{cout<<lv2[i]<<endl;}
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
	{gv[i] = pow(2,i);}
	f(gv);

	vector<int> vv(10);
	for(int i=1;i<10;i++)
	{vv[i-1]=fact(i);}
	f(vv);


return 0;
}
