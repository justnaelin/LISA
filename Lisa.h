//
//  Lisa.h
//  LISA
//
//  Created by Naelin Aquino on 11/23/15.
//  Copyright © 2015 Naelin Aquino. All rights reserved.
//

#ifndef Lisa_h
#define Lisa_h
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <functional>
#include <unordered_map>

namespace lisa
{
    typedef std::function<void(void)> f;
    typedef std::unordered_multimap<std::string, int> umm;
    typedef std::unordered_map<std::string, std::function<void(void)>> umm2;
    static int reg = 0;
    umm variables;
    umm2 functions;
    
    void erase()
    {
        reg = 0;
    }

    void done()
    {
        erase();
        exit(0);
    }

    void input()
    {
        std::cin >> reg;
    }

    void output(std::string key)
    {
        if(key == "reg")
	    std::cout << reg << std::endl;
        else 
        {
            auto range = variables.equal_range(key);

            for(auto it = range.first; it != range.second; it++)
                std::cout << it->second << " ";
	    std::cout << std::endl;
        }
    }

    void plus(std::string x, std::string y)
    {
        if(variables.find(x) != variables.end() && variables.find(y) != variables.end())
            reg = variables.find(x)->second + variables.find(y)->second;
    }

    void minus(std::string x, std::string y)
    {
        if(variables.find(x) != variables.end() && variables.find(y) != variables.end())
            reg = variables.find(x)->second - variables.find(y)->second;
    }

    void store(std::string key)
    {
        variables.erase(key);
        variables.insert(umm::value_type(key, reg));
    }

    void init(std::string key, int value)
    {
	    variables.erase(key);
    	variables.insert(umm::value_type(key, value));
    }

    void inita(std::string key, int size, int arr[])
    {
        variables.erase(key);
        for(int i = 0; i < size; i++)
            variables.insert(umm::value_type(key, arr[i]));
    }

    void put(std::string key, std::string y)
    {
        variables.erase(key);
        variables.insert(umm::value_type(key, variables.find(y)->second));
    }

    void at(std::string key, int index)
    {
        auto range = variables.equal_range(key);
        auto it = range.first;
        
        for(int i = 0; i < index; i++)
            it++;
        
        reg = it->second;
    }

    bool if_statement(std::string statement) 
    {
    	if(statement == "NEG")
            return reg < 0;
    	else if(statement == "POS")
    	    return reg > 0;
    	else if(statement == "ZERO")
    	    return reg == 0;
    	else
    	    exit(0);
    }
/*
    void loop(std::string instructions) 
    {
    	while(true)
        {
            // parse through instructions
            // do it
            // should be a condition in here somewhere
            // if condition, run through instructions again
            // if !condition, break out of infinite loop
        }
    }

    void func(std::string name, std::string code)
    {
        functions.erase(name);
        functions.insert(umm2::value_type(name, code));
    }

    std::string go(std::string name)
    {
        auto it = functions.find(name);
        return it->second;      
    }
*/
}

// TODO: parse
// TODO: exception handling

#endif /* Lisa_h */
