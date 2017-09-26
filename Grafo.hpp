//
//  Grafo.hpp
//  ListaAdjacenciaGrafos
//
//  Created by Martin Franzner on 22/08/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Grafo_hpp
#define Grafo_hpp

#include <stdio.h>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include "No.hpp"
#include "NoGrafo.hpp"
#include "ArmazenaBase.hpp"

using namespace std;
class Grafo {
private:
    int tamanho;
    int narestas;
    list<No>* matrizAdj;
    vector<NoGrafo> *vertice;
    
public:
    Grafo(int tamanho);//ja cria a matriz
    void criaAdjacencia(int lin, string adjasen);//bota valor na matriz
    void removeAdjacencia(int lin, int col);// bota valor como NULL
    void imprimeAdjacencia();//imprime a matriz
    //string adjacentes(int linha, string v[]); //mostra o numero de adjacencias em cada linha
    void setaInformacao(vector<string> vetorUnico);
    list<No>* getMatrix(){return this->matrizAdj;};
    int getAresta(){return this->narestas;};
    int getVertices(vector<pair<string,vector<string>>> vetorDuplicado);
    //void imprimeInformacao();
};
#endif /* Grafo_hpp */
