//
//  Parser.cpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 19/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Parser.hpp"
Parser::Parser(){
    
}
vector<string> Parser::splitT1(char * str, char * delimiter){
    vector<string> * v = new vector<string>();
    
    char * pch;
    char *next_token = NULL;
    
    pch = strtok_r(str, delimiter, &next_token);
    
    while (pch != NULL)
    {
        v->push_back(pch);
        
        pch = strtok_r(NULL, delimiter, &next_token);
    }
    
    return *v;
}

vector<string> Parser::splitT(const string str, const string delimiter){
    return splitT1((char *)str.c_str(), (char *)delimiter.c_str());
}

