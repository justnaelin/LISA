#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <utility>
#include <functional>
#include <cstdlib>
#include "Lisa.h"
using namespace std;

void parse(ifstream& fin);
// parse helper functions
void parseINIT(char& next, ifstream& fin);
void parseOUTPUT(char& next, ifstream& fin);
void parsePLUS(char& next, ifstream& fin);
void parseMINUS(char& next, ifstream& fin);
void parseSTORE(char& next, ifstream& fin);
void parsePUT(char& next, ifstream& fin);
void parseINITA(char& next, ifstream& fin);
void parseAT(char& next, ifstream& fin);
void parseGO(char& next, ifstream& fin);
void parseFUNC(char& next, ifstream& fin);

int main()
{
	std::ifstream fin;
    fin.open("easy");

    parse(fin);
    fin.close();

	return EXIT_SUCCESS;
}

void parse(std::ifstream& fin)
{
    char next;
    std::string op;
    std::string var;
    std::string val;
    
    while(fin.get(next) && !fin.eof())
    {
        op = "";
        
        while(next == ' ')
            fin.get(next);
        
        // Get operation
        while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
        {
            next = toupper(next); // Uppercase
            op += next; // Add char to std::string
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
        else if(op == "INITA")
            parseINITA(next, fin);
        else if(op == "FUNC")
            parseFUNC(next, fin);
        else if(op == "GO")
            parseGO(next, fin);
        else if(op == "AT")
            parseAT(next, fin);
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
    string var;
    string n;
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
        n += next;
        fin.get(next);
    }
    
    while(next == ' ')
        fin.get(next);
    
    const int SIZE = stoi(n);
    int arr[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        val = "";
        // TODO: while it is an integer
        while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
        {
            val += next;
            fin.get(next);
        }
        arr[i] = stoi(val);
        
        while(next == ' ')
            fin.get(next);
    }
    
    lisa::inita(var, SIZE, arr);
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
    
    string code = lisa::go(var);
    ofstream func_file("temp.txt");
    ifstream file;
    for(auto it = code.begin(); it < code.end(); it++)
    {
        func_file << *it;
    }
    func_file.close();
    file.open("temp.txt");
    
    parsee(file);
}

void parseFUNC(char& next, ifstream& fin)
{
    string name;
    string code;
    string op;

    while(next == ' ')
        fin.get(next);

    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        name += next;
        fin.get(next);
    }

    while(next == ' ' || next == '\n' || next == '\r')
        fin.get(next);

    while(op != "CNUF")
    {
      op = "";
      while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
      {
          op += next;
          fin.get(next);
      }
      if(op != "CNUF")
      {
          code += op;
          code += next;
          fin.get(next);
      }
    }
    
    lisa::func(name, code);
}
