#include "std_lib_facilities.h"

int main()
{
cout << "Please enter a nick name and gender, m if Male and f if Female\n";
string name;         
char friend_sex= 0;                          
cin >> name;         
cin >> friend_sex;
if (friend_sex == 'm') cout << "If you see "<<name<<" please ask him to call me.\n";
if (friend_sex == 'f') cout << "If you see "<<name<<" please ask her to call me.\n";
else cout<< "Thats not a gender.\n";
return 0;
}
