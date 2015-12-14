#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

static const int NO_OPERATIONS = 12;
static const string FILENAME = "example";
static const string OPERATIONS[] = {"DONE", "OUTPUT", "INIT", "LOOP", "IF", "INPUT", "PLUS", "MINUS", "STORE", "INITA", "FUNC", "GO"};

void parse(ifstream& fin);
bool empty(string line);
bool comment(string& line);
bool operation(string line);

int main()
{
	ifstream fin;

	try
	{
		parse(fin);
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
	return EXIT_SUCCESS;
}

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
                        end = line.find_first_of(" \t\n\r", begin);                     // find whitespace

			if( line.empty() )
				break;

                        if( end == string::npos )                                       // end of line
			{
                                word = line;
				line = "";
			}

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
