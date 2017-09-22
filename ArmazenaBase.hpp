//
//  ArmazenaBase.hpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 21/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef ArmazenaBase_hpp
#define ArmazenaBase_hpp
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <stdio.h>

#include "OpenFile.hpp"
#include "Parser.hpp"
#include "ReadFile.hpp"
using namespace std;

class ArmazenaBase {
private:
    string caminhoIni;
    
public:
    ArmazenaBase(string caminho);
    vector<pair<string,vector<string>>> criaVetorDuplicado();//cria o vetor em first quem enviou e em second quem recebeu
    vector<string> criaVetorQuemEnviou(vector<pair<string,vector<string>>> vetDupli);//cria vetor unico de todos que enviaram
};
#endif /* ArmazenaBase_hpp */
