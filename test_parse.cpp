#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Lisa.h"
using namespace std;

static const int NO_OPERATIONS = 12;
static const string FILENAME = "example";
static const string OPERATIONS[] = {"DONE", "OUTPUT", "INIT", "LOOP", "IF", "INPUT", "PLUS", "MINUS", "STORE", "INITA", "FUNC", "GO"};

void parse(ifstream& fin);
bool empty(string line);
bool comment(string& line);
bool operation(string line);
void parsee(ifstream& fin);
// parsee helper functions
void parseINIT(char& next, ifstream& fin);
void parseOUTPUT(char& next, ifstream& fin);
void parsePLUS(char& next, ifstream& fin);
void parseMINUS(char& next, ifstream& fin);
void parseSTORE(char& next, ifstream& fin);
void parsePUT(char& next, ifstream& fin);
void parseINITA(char& next, ifstream& fin);
void parseAT(char& next, ifstream& fin);
void parseGO(char& next, ifstream& fin);

int main()
{
	ifstream fin;
    //fin.open("/Users/naelinaquino/Documents/assembly/LISA/LISA/en.lproj/test.txt");

	try
	{
		//parse(fin);
        cout << "try\n";
        parsee(fin);
        cout << "done\n";
	} catch(string& msg)
	{
		cerr << msg << endl;
	}
	// TODO
	// compile
	// disregard empty lines
	// disregard comments
	// validate operations
	// validate parameter list
	// exception handling
    fin.close();
	return EXIT_SUCCESS;
}
/*
void parse(ifstream& fin)
{
	size_t line_no;
	string line;
	string word;

	fin.open(FILENAME.c_str());
	line_no = 1;
	while( getline(fin, line) )
        {
		comment(line);
cout << line << endl;
		if( empty(line) )
		{
			line_no++;
			continue;
		}

                size_t begin;
		bool first;

		first = true;
                while( begin = line.find_first_not_of(" \t\n\r") != string::npos )      // find non-whitespace
                {
                        size_t end;
                        end = line.find_first_of(" \t\n\r");                            // find whitespace

                        if( end == line.length() )                                  // end of line
                                word = line;

                        else                                                            // parse word
                        {
                                word = line.substr(begin - 1, end);
                                line = line.substr(end + 1, line.length());
                        }

			string temp;
			for( size_t index = 0; index < word.length(); index++ )
				temp += toupper(word[index]);
			word = temp;

			if( first )
			{
				if( !operation(word) )
					throw "Unrecognized operation: " + word + "\nat line number: " + std::to_string(line_no) + "\n\"" + line + "\"";
				first = false;
			}
                }
//                cout << line << endl << word << endl;

		line_no++;
        }

	fin.close();
}
*/
bool empty(string line)
{
	if( size_t ch = line.find_first_not_of(" \t\n\r") == string::npos )
		return true;

	return false;
}

bool comment(string& line)
{
	size_t position;
	position = line.find('/');

	if( position != string::npos )
	{
		line = line.substr(0, position);
		return true;
	}

	return false;
}

bool operation(string word)
{
	for( size_t index = 0; index < NO_OPERATIONS; index++ )
	{
		if( word == OPERATIONS[index] )
			return true;
	}

	return false;
}

void parsee(ifstream& fin)
{
    char next;
    string op;
    string var;
    string val;
    
    while(fin.get(next) && !fin.eof())
    {
        op = "";
        
        while(next == ' ')
        {
            cout << "HERE\n";
            fin.get(next);
        }
        
        // Get operation
        while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
        {
            next = toupper(next); // Uppercase
            op += next; // Add char to string
            fin.get(next);
        }
        
        while(next == ' ')
            fin.get(next);
        
        if(op == "INIT")
            parseINIT(next, fin);
        else if(op == "INPUT")
            lisa::input();
        else if(op == "OUTPUT")
            parseOUTPUT(next, fin);
        else if(op == "PLUS")
            parsePLUS(next, fin);
        else if(op == "MINUS")
            parseMINUS(next, fin);
        else if(op == "ERASE")
            lisa::erase();
        else if(op == "DONE")
            lisa::done();
        else if(op == "STORE")
            parseSTORE(next, fin);
        else if(op == "PUT")
            parsePUT(next, fin);
    }
    
}

void parseINIT(char& next, ifstream& fin)
{
    string var;
    string val;
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var += next;
        fin.get(next);
    }

    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        val += next;
        fin.get(next);
    }

    int i = stoi(val);
    lisa::init(var, i);
}

void parseOUTPUT(char& next, ifstream& fin)
{
    string var;

    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var += next;
        fin.get(next);
    }
    
    lisa::output(var);
}

void parsePLUS(char& next, ifstream& fin)
{
    string var1;
    string var2;
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var1 += next;
        fin.get(next);
    }
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var2 += next;
        fin.get(next);
    }
    
    lisa::plus(var1, var2);
}

void parseMINUS(char& next, ifstream& fin)
{
    string var1;
    string var2;
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var1 += next;
        fin.get(next);
    }
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var2 += next;
        fin.get(next);
    }
    
    lisa::minus(var1, var2);
}

void parseSTORE(char& next, ifstream& fin)
{
    string var;
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var += next;
        fin.get(next);
    }
    
    lisa::store(var);
}

void parsePUT(char& next, ifstream& fin)
{
    string var1;
    string var2;
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var1 += next;
        fin.get(next);
    }
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var2 += next;
        fin.get(next);
    }
    
    lisa::put(var1, var2);
}

void parseINITA(char& next, ifstream& fin)
{
    
}

void parseAT(char& next, ifstream& fin)
{
    string var;
    string val;
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var += next;
        fin.get(next);
    }
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        val += next;
        fin.get(next);
    }
    
    int i = stoi(val);
    lisa::at(var, i);
}

void parseGO(char& next, ifstream& fin)
{
    string var;
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var += next;
        fin.get(next);
    }
    
    lisa::go(var);
}
