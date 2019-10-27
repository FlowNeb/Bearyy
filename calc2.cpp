#include "std_lib_facilities.h"

struct Token {
	char kind;
	double value;
	string name;
         string s;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
         Token(const char, std::string) { }
};
//tokens
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'Q'; //use to quit
const char print = ';'; //use to print result of calculation		
const char number = '8'; //use to indicate number
const char name = 'a';// use to indacete that its not a number 
const char sqrts = 's'; //square root
const char pows = 'p'; // number!

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
        case '!':
        case ',':
  	return Token(ch);
	case '.': //use to numbers like 1.2
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
                double val;
		cin >> val;  //read value
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {  //if we used letters
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
			cin.unget();
			if (s == "#") return Token(let);
			if (s == "sqrt") return Token(sqrts);		
			if (s == "exit") return Token(quit);
			if (s == "pow") return Token(pows);	
			return Token(name,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;	

double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) {return names[i].value;
}
	error("get: undefined name ",s);
}

void set_value(string s, double d)
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
                 return d;
	}
	case sqrts:  // used like number^(1/2)
	{		double d= primary();
			if (d<0) error ("negative under square");
			return sqrt (d); }
	case pows: // used like !
	{
		t = ts.get();
		if (t.kind == '(') {
			double lval = primary();
			int rval = 0;
			t = ts.get();
			if(t.kind == ',') rval = narrow_cast<int>(primary());
			else error("Second argument is not provided");
			double result = 1;
			for(double i = 0; i < rval; i++) {
				result*=lval;
			}
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return result;
		}
		else error("'(' expected"); 
	}
		
	case '-':  //negative numbers 
		return - primary();
	case number: //number
		return t.value;
	case name: //letter
		return get_value(t.name);
	
	
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*': //multiplicat numbers
			left *= primary();
			break;
		case '/': //divine numbers
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
 case '!': //factorial 
{ int z= left;
for (int n= 1; n < left; n++){
z*=1;
}
if (z == 0) left = 1;
else left = z;
break;
}
		default:
		ts.unget(t);
		return left;
		 }	
		}
}
	


double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+': //add numbers
			left += term();
			break;
		case '-': //subtract numbers
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	names.push_back(Variable(name,d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

	try {
 		names.push_back(Variable("k",1000)); //k is 1000 
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
