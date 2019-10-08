#include "std_lib_facilities.h"

int main()
{
cout << "Enter the name of the person you want to write to\n";
string name;                                
cin >> name;         
cout<< "Dear "<<name<<", How are you? I am fine. I miss you. How is school going? Right now i am writing a program\n";

cout << "Enter one of our friend name\n";
string friends;                                
cin >> friends;
cout<< "Have you seen "<<friends<<" lately?\n";

cout << "Please enter the gender of our friend, m if Male and f if Female\n";        
char friend_sex= 0;                          
cin >> friend_sex;
if (friend_sex == 'm') cout << "If you see "<<friends<<" please ask him to call me.\n";
if (friend_sex == 'f') cout << "If you see "<<friends<<" please ask her to call me.\n";
else cout<< "Thats not a gender.\n";

cout << "Please enter your age\n";
int age=0;
cin >> age;         

cout << "I hear you just had a birthday and you are "<<age<<" years old.\n";

if (age<0 || age>110)
{
 simple_error("you're kidding!");
}  
if (age<12)cout << "Next year you will be "<<age+1<<".\n";
if (age==17)cout << "Next year you will be able to vote.\n";
if (age>70)cout << "I hope you are enjoying retirement.\n";

cout<<"Yours sincerely,\nBenedek\n";
return 0;
}
