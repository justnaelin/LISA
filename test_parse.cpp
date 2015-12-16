#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <utility>
#include <functional>
#include <cstdlib>
#include "Lisa.h"

typedef std::function<void(void)> foo;

void parse(std::ifstream& fin);
// parsee helper functions
foo parseINIT(std::ifstream& fin);
foo parseOUTPUT(std::ifstream& fin);
foo parsePLUS(std::ifstream& fin);
foo parseMINUS(std::ifstream& fin);
foo parseSTORE(std::ifstream& fin);
foo parsePUT(std::ifstream& fin);
foo parseINITA(std::ifstream& fin);
foo parseAT(std::ifstream& fin);
//foo parseGO(std::ifstream& fin);
//foo parseFUNC(std::ifstream& fin);

int main()
{
	std::ifstream fin;
    // fin.open("/Users/naelinaquino/Documents/assembly/LISA/LISA/test.txt");

    parse(fin);
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
            parseINIT(fin)();
        else if(op == "INPUT")
            lisa::input();
        else if(op == "OUTPUT")
            parseOUTPUT(fin)();
        else if(op == "PLUS")
            parsePLUS(fin)();
        else if(op == "MINUS")
            parseMINUS(fin)();
        else if(op == "ERASE")
            lisa::erase();
        else if(op == "DONE")
            lisa::done();
        else if(op == "STORE")
            parseSTORE(fin)();
        else if(op == "PUT")
            parsePUT(fin)();
        else if(op == "INITA")
            parseINITA(fin)();
//        else if(op == "FUNC")
//            parseFUNC(fin)();
//        else if(op == "GO")
//            parseGO(fin);
    }
    
}

foo parseINIT(std::ifstream& fin)
{
    char next;
    std::string var;
    std::string val;
    
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
    return std::bind(&lisa::init, var, i);
}

foo parseOUTPUT(std::ifstream& fin)
{
    char next;
    std::string var;

    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var += next;
        fin.get(next);
    }
    
    return std::bind(&lisa::output, var);
}

foo parsePLUS(std::ifstream& fin)
{
    char next;
    std::string var1;
    std::string var2;
    
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
    
    return std::bind(&lisa::plus, var1, var2);
}

foo parseMINUS(std::ifstream& fin)
{
    char next;
    std::string var1;
    std::string var2;
    
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
    
    return std::bind(&lisa::minus, var1, var2);
}

foo parseSTORE(std::ifstream& fin)
{
    char next;
    std::string var;
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var += next;
        fin.get(next);
    }
    
    return std::bind(&lisa::store, var);
}

foo parsePUT(std::ifstream& fin)
{
    char next;
    std::string var1;
    std::string var2;
    
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
    
    return std::bind(&lisa::put, var1, var2);
}

foo parseINITA(std::ifstream& fin)
{
    char next;
    std::string var;
    std::string n;
    std::string val;
    
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
    
    int SIZE = stoi(n);
    int* arr = new int[SIZE];
    
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
    
    return std::bind(&lisa::inita, var, SIZE, arr);
}

foo parseAT(std::ifstream& fin)
{
    char next;
    std::string var;
    std::string val;
    
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
    return std::bind(lisa::at, var, i);
}

// do things
/*
foo parseGO(std::ifstream& fin)
{
    std::string var;
    
    while(next == ' ')
        fin.get(next);
    
    while(next != ' ' && next != '\n' && next != '\r' && !fin.eof())
    {
        var += next;
        fin.get(next);
    }
    
    std::string code = lisa::go(var);
    ofstream func_file("temp.txt");
    std::ifstream file;
    for(auto it = code.begin(); it < code.end(); it++)
    {
        func_file << *it;
    }
    func_file.close();
    file.open("temp.txt");
    
    parsee(file);
}

foo parseFUNC(std::ifstream& fin)
{
    std::string name;
    std::string code;
    std::string op;

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
*/
