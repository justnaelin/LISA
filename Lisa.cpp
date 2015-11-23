//
//  Lisa.cpp
//  LISA
//
//  Created by Naelin Aquino on 11/23/15.
//  Copyright © 2015 Naelin Aquino. All rights reserved.
//

#include "Lisa.h"
#include <cstdlib>

namespace lisa
{
    reg = 0;
    void erase()
    {
        reg = 0;
    }
    void done()
    {
        clear();
        exit(0);
    }
    void input()
    {
        cin >> reg;
    }
    void output(string key)
    {
        std::unordered_multimap<std::string, int>::iterator it;
        for(it = map.find(key).begin(); it != map.find(key).end(); it++)
            cout << *it << endl;
    }
    void plus(std::string x, std::string y)
    {
        if(map.find(x).begin() == map.find(x).end() && map.find(y).begin() == map.find(y).end())
            reg = map.find(x)->second + map.find(y)->second;
    }
    void minus(std::string x, std::string y)
    {
        if(map.find(x).begin() == map.find(x).end() && map.find(y).begin() == map.find(y).end())
            reg = map.find(x)->second - map.find(y)->second;
    }
    void store(string key)
    {
        map.erase(key);
        map.insert(key, reg);
    }
    void init(std::string key, int x)
    {
        map.erase(key);
        map.insert(key, x);
    }
    void put(std::string x, std::string y)
    {
        map.erase(x);
        map.insert(x, map.find(y)->second);
    }

}