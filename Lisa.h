//
//  Lisa.h
//  LISA
//
//  Created by Naelin Aquino on 11/23/15.
//  Copyright © 2015 Naelin Aquino. All rights reserved.
//

#ifndef Lisa_h
#define Lisa_h
#include <unordered_map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

namespace lisa
{
    typedef std::unordered_multimap<std::string, int> umm;
    typedef std::unordered_map<std::string, std::string> umm2;
    static int reg = 0;
    umm map;
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
            auto range = map.equal_range(key);
            
            for(auto it = range.first; it != range.second; it++)
                std::cout << it->second << std::endl;
        }
    }
    void plus(std::string x, std::string y)
    {
        if(map.find(x) != map.end() && map.find(y) != map.end())
                reg = map.find(x)->second + map.find(y)->second;
    }
    void minus(std::string x, std::string y)
    {
        if(map.find(x) != map.end() && map.find(y) != map.end())
            reg = map.find(x)->second - map.find(y)->second;
    }
    void store(std::string key)
    {
        map.erase(key);
        map.insert(umm::value_type(key, reg));
    }
    void init(std::string key, int x)
    {
        map.erase(key);
        map.insert(umm::value_type(key, x));
    }
    void inita(std::string key, int size, int arr[])
    {
        map.erase(key);
        for(int i = 0; i < size; i++)
            map.insert(umm::value_type(key, arr[i]));
    }
    void put(std::string key, std::string y)
    {
        map.erase(key);
        map.insert(umm::value_type(key, map.find(y)->second));
    }
    void at(std::string key, int index)
    {
        auto range = map.equal_range(key);
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
    void loop(bool condition) 
    {
    	if(!condition)
        {
	    // do something
    	    loop(condition);
        }
    }
    void func(std::string name, std::string code)
    {
        functions.insert(umm2::value_type(name, code));
    }
    void go(std::string name)
    {
        functions.find(name);
    }
}

// TODO: parse
// TODO: exception handling
// TODO: testing
// TODO: benchmarks
// TODO: documentation

#endif /* Lisa_h */
