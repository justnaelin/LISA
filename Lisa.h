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
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <functional>
#include <unordered_map>

namespace lisa
{
    typedef std::unordered_multimap<std::string, int> umm;
    typedef std::unordered_map<std::string, std::function<void(void)>> umm2;

    umm variables;
    umm2 functions;

    void erase()
    {
        variables.erase("REG");
    }

    void start()
    {
        variables.insert(umm::value_type("REG", 0));
    }

    void done()
    {
        erase();
        exit(0);
    }

    void input()
    {
        int val;
        std::cin >> val;

        erase();
        variables.insert(umm::value_type("REG", val));
    }

    void output(std::string key)
    {
        auto range = variables.equal_range(key);

        for(auto it = range.first; it != range.second; it++)
            std::cout << it->second << " ";
        std::cout << std::endl;
    }

    void plus(std::string x, std::string y)
    {
        if(variables.find(x) != variables.end() && variables.find(y) != variables.end())
        {
            erase();
            variables.insert(umm::value_type("REG", variables.find(x)->second + variables.find(y)->second));
        }
    }

    void minus(std::string x, std::string y)
    {
        if(variables.find(x) != variables.end() && variables.find(y) != variables.end())
        {
            erase();
            variables.insert(umm::value_type("REG", variables.find(x)->second - variables.find(y)->second));
        }
    }

    void store(std::string key)
    {
        variables.erase(key);
        variables.insert(umm::value_type(key, variables.find("REG")->second));
    }

    void init(std::string key, int value)
    {
	    variables.erase(key);
    	variables.insert(umm::value_type(key, value));
    }

    void inita(std::string key, int size, int arr[])
    {
        variables.erase(key);
        for(int i = size - 1; i > -1; i--)
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
        
        erase();
        variables.insert(umm::value_type("REG", it->second));
    }

    bool if_statement(std::string statement) 
    {
    	if(statement == "NEG")
            return variables.find("REG")->second < 0;
    	else if(statement == "POS")
    	    return variables.find("REG")->second > 0;
    	else if(statement == "ZERO")
    	    return variables.find("REG")->second == 0;
    	else
    	    exit(0);
    }

    void loop(std::string name) 
    {
        auto range = functions.equal_range(name);
    	while(true)
        {
            for(auto it = range.first; it != range.second; it++)
                it->second();
        }
    }

    void func(std::string name, std::vector<std::function<void(void)>> funcs)
    {
        functions.erase(name);
        for(int i = 0; i < funcs.size(); i++)
            functions.insert(umm2::value_type(name, funcs[i]));
    }

    void go(std::string name)
    {
        auto range = functions.equal_range(name);
        for(auto it = range.first; it != range.second; it++)
            it->second();
    }
}

// TODO: parse
// TODO: exception handling

#endif /* Lisa_h */

