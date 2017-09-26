//
//  main.cpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 18/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include <iostream>
#include <dirent.h>
#include <vector>
#include <string>
#include <fstream>
#include <list>


#include "OpenFile.hpp"
#include "Parser.hpp"
#include "ReadFile.hpp"
#include "ArmazenaBase.hpp"
#include "Grafo.hpp"
#include "No.hpp"
#include "NoGrafo.hpp"

int existeAdjascencia(string nomeSec, list<No>* matrix,int posicao){
    No aux;
    string verificaAdj = "";
    list<No>::iterator j = matrix[posicao].begin();
    while(j != matrix[posicao].end()){
        aux = *j;
        verificaAdj = aux.getAdj();
        if(verificaAdj == nomeSec){
            j->addPeso1();
            return 1;
            //break;
        }
        j++;
    }
    return 0;
}



using namespace std;
int main(int argc, const char * argv[]) {

    string strOriginal2 = "/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Grafos/maildir";
    //string strOriginal = "/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Grafos/Amostra Enron - 2016";
    vector<pair<string,vector<string>>> vetorDuplicado;
    ArmazenaBase ab =  ArmazenaBase(strOriginal2);
    vetorDuplicado = ab.criaVetorDuplicado();
    
    vector<string> vetorUnico = ab.criaVetorQuemEnviou(vetorDuplicado);
    //cout<<vetorUnico.size()<<endl;
    
    int tam = vetorUnico.size();
    Grafo g = Grafo(tam);
    g.setaInformacao(vetorUnico);
    
    string nomeFirst = "";
    string nomeSec="";
    string verificaAdj = "";
    int posicao;
    list<No>* matrix = g.getMatrix();
    No aux;
    for(auto pairFirst : vetorDuplicado){
        nomeFirst = pairFirst.first;
        auto pos = find(vetorUnico.begin(), vetorUnico.end(), nomeFirst);
        posicao = pos - vetorUnico.begin();
        if(pos != vetorUnico.end()) {
            //cout << pos - vetorUnico.begin() <<endl;
        } else {
            cout << "not found" << std::endl;
        }
        for(auto pairSecond : pairFirst.second){
            nomeSec = pairSecond;
            if(existeAdjascencia(nomeSec,matrix,posicao) == 1){
                
            }
            else {
                g.criaAdjacencia(posicao, nomeSec);
            }
        }

        //g.imprimeAdjacencia();
        
    }
    int vertices;
    vertices = g.getVertices(vetorDuplicado);
    cout<<vertices<<endl;

    cout<<"Num de arestas: "<<g.getAresta()<<endl;
   
    
    
    
    
    
    
    
    
    
    
    
    
    
//    for( auto coco : vetorDuplicado){
//        //cout<<"String, From:"<<coco.first<<endl;
//        for(auto bla: coco.second){
//            //cout<<"Vetor, To:"<<bla<<endl;
//            vetorUnico.push_back(bla);
//        }
//    }
//
//    int counter;
//    for( auto printer : vetorUnico){
//        cout<<printer<<endl;
//        counter++;
//    }
//    cout<<counter<<endl;
    
    
//    string strOriginal = "/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Grafos/Amostra Enron - 2016";
//    OpenFile *op = new OpenFile(strOriginal);
//    op->abreDiretorio();//aqui abre o diretorio
//    op->concatenaSentMail();//aqui concatena a pasta _sent_mail
//    op->concatenaFinal();// aqui concatena o path todos os arquivos que serao lidos
//
//    vector <string> pathParaLer = op->getPathParaLer();//retorna para esse vetor todos os paths que serao lidos
//    char delimitadores[] = " <>[],;-\n\r    ";
//    Parser *p = new Parser();
//    ReadFile *a = new ReadFile();
//
//    vector<string> vetorDeString;
//    vector<string> stringSplitada;
//    string from;//variavel que armazena quem enviou email
//    vector<string> toEmail;//vetor os que receberam o email
//    vector<pair<string,vector<string>>> vetorFinalDuplicado;//aqui armazena no pair .first quem mandou o email e no .second todos que receberam
//
//    vector<string>::iterator i = pathParaLer.begin();
//    vector<string>::iterator j = vetorDeString.begin();//aqui comeca a iterar linha por linha
//
//    for(i = pathParaLer.begin(); i != pathParaLer.end(); ++i){//ira abrir todos os arquivos de email
//        vetorDeString = a->readByLine((*i));//aqui le linha por linha do arquivo e joga num vetor de strings
//        j = vetorDeString.begin();
//        j++;//incrementa o iterador para ir direto para linha 3
//        j++;
//        while(j!= vetorDeString.end()){
//            stringSplitada = p->splitT((*j), delimitadores);//stringSplitada eh cada linha do arquivo quebrada em tokens
//
//            if(stringSplitada[0] == "Subject:"){
//                break;
//            }
//            if(distance(vetorDeString.begin(), j) == 2 ){//se distancia do inicio ==2 esta na linha do From:
//                from = stringSplitada[1];
//                //cout<<"Quem mandou email: "<<from<<endl;
//            }
//
//            if(distance(vetorDeString.begin(), j) >= 3 ){//se distancia do inicio >=3 esta na linha do To:
//                for (vector<string>::iterator k = stringSplitada.begin(); k != stringSplitada.end(); ++k){
//                    std::remove((*k).begin(), (*k).end(), '\t');//faz o trimm das strings depois do To:
//                    //cout <<"Depois do trimm: "<< *k<<endl;
//                }
//                for(unsigned int n=0;n<stringSplitada.size();++n){
//                    if(stringSplitada[n] != "To:"){//compara para nao adicionar o To:
//                        toEmail.push_back(stringSplitada[n]);//adiciona no vetor de emails de quem recebeu
//                    }
//                }
//            }
//            ++j;//vai para a proxima linha do vetorDeString
//        }
//        vetorFinalDuplicado.push_back(make_pair(from,toEmail));//bota no vetor de pair
//
//    }
    
    
    
    
//    for( auto coco : vetorFinalDuplicado){
//        cout<<"String, From:"<<coco.first<<endl;
//        for(auto bla: coco.second){
//            cout<<"Vetor, To:"<<bla<<endl;
//        }
//    }
    
    
    //para fazer o trimm
    
    /*std::string astring(" Test Test Test ");
    std::remove(astring.begin(), astring.end(), ' ');
    std::cout << astring << std::endl;
    */
    
    /*
    vector<string> L;
    
    string line;
    ifstream myfile ("/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Grafos/Amostra Enron - 2016/giron-d/_sent_mail/45");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            L.push_back(line);
        }
        myfile.close();
    }
   
    else cout << "Unable to open file";
    
    vector<pair<string,vector<string>>> vetorGeral;
    vector<string> vetorDeString;
    string from;
    vector<string> toEmail;
    char delimitadores[] = " <>[],;-\n\r    ";
    vector<string>::iterator i = L.begin();
    i++;
    i++;
    while(i!= L.end()){
        vetorDeString = splitT((*i), delimitadores);
        
        if(vetorDeString[0] == "Subject:"){
            break;
        }
        if(distance(L.begin(), i) == 2 ){
            from = vetorDeString[1];
            cout<<"Quem mandou email: "<<from<<endl;
        }
        
        if(distance(L.begin(), i) >= 3 ){
            for (vector<string>::iterator j = vetorDeString.begin(); j != vetorDeString.end(); ++j){
                std::remove((*j).begin(), (*j).end(), '\t');//faz o trimm das strings
                cout <<"Depois do trimm: "<< *j<<endl;
            }
            for(unsigned int n=0;n<vetorDeString.size();++n){
                if(vetorDeString[n] != "To:"){//compara para nao adicionar o To:
                    toEmail.push_back(vetorDeString[n]);//adiciona no vetor de emails de quem recebeu
                }
                
                
            }
        }

        ++i;//vai para a proxima linha do vetor L
    }
    for (vector<string>::iterator j = toEmail.begin(); j != toEmail.end(); ++j){
        //std::remove((*j).begin(), (*j).end(), '\t');//faz o trimm das strings
        cout << *j<<endl;
    }
    vetorGeral.push_back(make_pair(from,toEmail));
    
    for( auto coco : vetorGeral){
        cout<<"String, From:"<<coco.first<<endl;
        for(auto bla: coco.second){
            cout<<"Vetor, To:"<<bla<<endl;
        }
    }
    
    */

    return 0;
}
