//
//  No.hpp
//  ListaAdjacenciaGrafos
//
//  Created by Martin Franzner on 22/08/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef No_hpp
#define No_hpp
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class No {
private:
    string adj;
    int peso;
    
    
public:
    No();
    void addAdj(string ad){this->adj = ad;};
    void addPeso(int ps){this->peso= ps;};
    void addPeso1(){this->peso+=1;};
    int getPeso(){return this->peso;};
    
        
    
    string getAdj(){return this->adj;};
};


#endif /* No_hpp */
