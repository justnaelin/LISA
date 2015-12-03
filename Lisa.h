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

namespace lisa
{
    typedef std::unordered_multimap<std::string, int> umm;
    static int reg = 0;
    umm map;
    
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
        auto range = map.equal_range(key);
        for(auto it = range.first; it != range.second; it++)
            std::cout << it->second << std::endl;
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
    void put(std::string x, std::string y)
    {
        map.erase(x);
        map.insert(umm::value_type(x, map.find(y)->second));
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
    		//do something
    		if(!condition)
    			loop(condition);
    } 
}

// TODO: PARSE!!!

#endif /* Lisa_h */
