//
//  LISA_Simulator.cpp
//  LISA
//
//  Created by Naelin Aquino on 11/23/15.
//  Copyright © 2015 Naelin Aquino. All rights reserved.
//

#include "Lisa.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    // Read in the file
    // 
    lisa::init("var1", 7);
    lisa::init("var2", 8);
    lisa::plus("var1", "var2");
    lisa::store("var1");
    lisa::output("var1");
    lisa::done();
    return EXIT_SUCCESS;
}
