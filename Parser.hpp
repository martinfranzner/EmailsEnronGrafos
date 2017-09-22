//
//  Parser.hpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 19/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
class Parser {
private:
    
public:
    Parser();
    vector<string> splitT(const string str, const string delimiter);
    vector<string> splitT1(char * str, char * delimiter);
};
#endif /* Parser_hpp */
