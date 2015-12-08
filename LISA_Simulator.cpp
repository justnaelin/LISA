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
    // READ FILE
    
    // TEST INPUT/OUTPUT 
    lisa::input();
    lisa::output("reg");
    
    // TEST INIT
    lisa::init("var1", 7);
    lisa::init("var2", 8);
    cout << "var1: ";
    lisa::output("var1");           // note: should output 7 
    cout << "var2: ";
    lisa::output("var2");           // note: should output 8

    // TEST PLUS/MINUS/STORE
    lisa::plus("var1", "var2"); 
    lisa::store("var1");            // note: var1 and reg should be holding the same value, 15
    cout << "var1: ";
    lisa::output("var1");
    cout << "reg: ";
    lisa::output("reg");
    lisa::minus("var1", "var2");    // note: var2 and reg should be holding the same value, 7
    lisa::store("var2");
    cout << "var2: ";
    lisa::output("var2");
    cout << "reg: ";
    lisa::output("reg");

    // TEST PUT
    lisa::put("var1", "var2");
    cout << "var1: ";
    lisa::output("var1");

    // TEST IF_STATEMENT
    cout << "reg value is ";
    if(lisa::if_statement("NEG"))
	cout << "negative" << endl;
    if(lisa::if_statement("POS"))
	cout << "positive" << endl;
    if(lisa::if_statement("ZERO"))
	cout << "zero" << endl;
    
    
    lisa::done(); 
    
    return EXIT_SUCCESS;
}
