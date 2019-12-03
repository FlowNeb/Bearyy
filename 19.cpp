#include "std_lib_facilities.h"
using namespace std;


template<typename T> struct S
{ 
public:
	S(T val)
	{this->val=val;};
	T& get();
	T& get() const;	
	void set(const T&);
	void operator=(const T&);
private:
	T val;
};

template<typename T> 
T& S<T>::get()
	{return this->val;}
template<typename T> 
T& S<T>::get() const 
	{return this->val;}
template<typename T> 
void S<T>::set(const T& a)
	{val=a;}
template<typename T> 
void S<T>::operator=(const T& a)
	{val=a;}
template<typename T> 
void read_val(T& v)
	{cin>>v;}

int main ()
{
S<int> i(22);
S<vector<int>> v(vector<int>{21,22,23});
S<char> c('t');
S<double> d (22.22);
S<string> t ("two");

cout<< i.get() <<endl;
for(int vec : v.get())
	{cout<<"vec:"<<vec<<endl;}
cout<< c.get ()<<endl;
cout<< d.get ()<<endl;
cout<< t.get ()<<endl;

cout<<"give me a number:"<<endl;
int number;
read_val(number);
i.set(number);
cout<<i.get()<<endl;

cout<<"write a character:"<<endl;
char character;
read_val(character);
c.set(character);
cout<<c.get()<<endl;

cout<<"write a a number like 22.22(do not write this):"<<endl;
double dot;
read_val(dot);
d.set(dot);
cout<<d.get()<<endl;

cout<<"write something(use letters):"<<endl;
string something;
read_val(something);
t.set(something);
cout<<t.get()<<endl;

return 0;
}
