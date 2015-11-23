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

namespace lisa
{
    static int reg;
    std::unordered_multimap<std::string, int> map;
    void erase();
    void done();
    void input();
    void output(string key);
    void plus(std::string x, std::string y);
    void minus(std::string x, std::string y);
    void store(std::string key);
    void init(std::string key, int x);
    void put(std::string x, std::string y);
}

#endif /* Lisa_h */
