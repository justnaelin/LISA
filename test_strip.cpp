#include <iostream>	// iostream
#include <string>	// string
#include <cstdlib>	// cstdlib
#include <algorithm>	// algorithm
using namespace std;

void parse(string input, string variables[]);
string tobinary(string input, bool ch);

int main()
{
/*
	string str = " W.,o?rd...s!?  "; //  W.,o?rd...s!?
	string res;
	for( int i = 0; i < str.length(); i++ )
		if( isalpha(str[i]) )
			res = res + str[i];
	
	cout << res << endl;
*/
//	int ch = 'c';
//	cout << static_cast<char>(ch) << endl;
/*
	string a = "99";
	if( isdigit(a[0]) )
		print(atoi(a.c_str()));
	else
		print(a[0]);
*/
	string var[2];
	string input = "c";
	try
	{
		parse(input, var);
	}
	catch(const char* msg)
	{
		cerr << msg;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void parse(string input, string variables[])
{
	if( all_of(input.begin(), input.end(), ::isdigit ) )
		cout << tobinary(input, false) << endl;
	else if( all_of(input.begin(), input.end(), ::isalpha ) )
		cout << tobinary(input, true) << endl;
	else
		throw "ValueType Error: argument is not a valid value";
}

string tobinary(string input, bool ch)
{
	int numeric;

	if( ch )
		numeric = input[0];
	else
		int numeric = atoi(input.c_str());
	string binary;

	while(numeric != 0)
	{
		binary = to_string(numeric % 2) + binary;
		numeric = numeric / 2;
	}

	if( ch )
		binary = "1" + binary;
	else
		binary = "0" + binary;


	return binary;
}
