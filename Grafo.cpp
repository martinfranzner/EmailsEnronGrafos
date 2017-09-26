//
//  Grafo.cpp
//  ListaAdjacenciaGrafos
//
//  Created by Martin Franzner on 22/08/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Grafo.hpp"
#include <algorithm>
#include <list>
using namespace std;
Grafo::Grafo(int tamanho) {
   
    this->tamanho = tamanho;
    
    this->matrizAdj = new list<No>[this->tamanho];
    
    //this->vertice = new NoGrafo[this->tamanho];
    this->vertice = new vector<NoGrafo>[this->tamanho];
//    for(int i = 0; i < tamanho; ++i) {
//        this->vertice[i] = *new NoGrafo();
//    }
    
}
void Grafo::setaInformacao(vector<string> vetorUnico){
    string nom = "";
    NoGrafo n;
    //n.addAdjNome(vetorUnico[i]);
    for(int i=0; i<this->tamanho; ++i){
        n.addAdjNome(vetorUnico[i]);
        //nom = vetorUnico[i];
        this->vertice[i].push_back(n);
    }
}

//void Grafo::imprimeInformacao(){
//    for(int i=0; i<tamanho; ++i){
//        cout<<i<<" - "<<this->vertice[i].getAdjNome()<<endl;
//    }
//}


void Grafo::criaAdjacencia(int lin, string adjasen){
    this->narestas++;
    No p;
    p.addPeso(1); //adicionar +1 no peso cada vez que acha uma adjascencia
    p.addAdj(adjasen);
    this->matrizAdj[lin].push_back(p);
}


void Grafo::removeAdjacencia(int lin, int col){
        for(list<No>::iterator it=this->matrizAdj[lin].begin();it != this->matrizAdj[lin].end(); ++it){
            advance(it,col);
            this->matrizAdj[lin].erase(it);
    }
}


void Grafo::imprimeAdjacencia(){
    cout<<"-----------------------------------"<<endl;
    for(int adj=0; adj < tamanho; adj++){
        cout<<"Linha: "<<adj<<"|| ";
        for(list<No>::iterator it=this->matrizAdj[adj].begin(); it != this->matrizAdj[adj].end(); ++it) {
            cout<<"("<<it->getAdj()<<")"<<(it->getPeso())<<" - ";
            
        }
        cout<<"\r";
    }
}
int Grafo::getVertices(vector<pair<string,vector<string>>> vetorDuplicado){
    vector<string> vetorUnico;
        for( auto coco : vetorDuplicado){
            //cout<<"String, From:"<<coco.first<<endl;
            for(auto bla: coco.second){
                //cout<<"Vetor, To:"<<bla<<endl;
                vetorUnico.push_back(bla);
            }
        }
    sort(vetorUnico.begin(), vetorUnico.end());
    vetorUnico.erase( unique( vetorUnico.begin(), vetorUnico.end() ), vetorUnico.end() );
    return vetorUnico.size();
}

//int Grafo::adjacentes(int linha, string v[]){
//    int count = 0;
//    for(list<No>::iterator it=this->matrizAdj[linha].begin(); it != this->matrizAdj[linha].end(); ++it){
//        v[count] = it->getAdj();
//        count++;
//    }
//    return count;
//}


