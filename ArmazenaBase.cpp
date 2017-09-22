//
//  ArmazenaBase.cpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 21/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "ArmazenaBase.hpp"
ArmazenaBase::ArmazenaBase(string caminho){
    this->caminhoIni = caminho;
}
vector<string> ArmazenaBase::criaVetorQuemEnviou(vector<pair<string,vector<string>>> vetDupli){
    vector<string> vetorUnico;
    for( auto coco : vetDupli){
        vetorUnico.push_back(coco.first);
    }
    sort(vetorUnico.begin(), vetorUnico.end());
    vetorUnico.erase( unique( vetorUnico.begin(), vetorUnico.end() ), vetorUnico.end() );

    unsigned int counter = 0;
    for( auto printer : vetorUnico){
        cout<<printer<<endl;
        counter++;
    }
    cout<<counter<<endl;
    
    return vetorUnico;
}
vector<pair<string,vector<string>>> ArmazenaBase::criaVetorDuplicado(){
    //string strOriginal = "/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Grafos/Amostra Enron - 2016";
    OpenFile *op = new OpenFile(this->caminhoIni);
    op->abreDiretorio();//aqui abre o diretorio
    op->concatenaSentMail();//aqui concatena a pasta _sent_mail
    op->concatenaFinal();// aqui concatena o path todos os arquivos que serao lidos
    
    vector <string> pathParaLer = op->getPathParaLer();//retorna para esse vetor todos os paths que serao lidos
    char delimitadores[] = " <>[],;-\n\r    ";
    Parser *p = new Parser();
    ReadFile *a = new ReadFile();
    
    vector<string> vetorDeString;
    vector<string> stringSplitada;
    string from;//variavel que armazena quem enviou email
    vector<string> toEmail;//vetor os que receberam o email
    vector<pair<string,vector<string>>> vetorFinalDuplicado;//aqui armazena no pair .first quem mandou o email e no .second todos que receberam
    
    vector<string>::iterator i = pathParaLer.begin();
    vector<string>::iterator j = vetorDeString.begin();//aqui comeca a iterar linha por linha
    
    for(i = pathParaLer.begin(); i != pathParaLer.end(); ++i){//ira abrir todos os arquivos de email
        vetorDeString = a->readByLine((*i));//aqui le linha por linha do arquivo e joga num vetor de strings
        j = vetorDeString.begin();
        j++;//incrementa o iterador para ir direto para linha 3
        j++;
        while(j!= vetorDeString.end()){
            stringSplitada = p->splitT((*j), delimitadores);//stringSplitada eh cada linha do arquivo quebrada em tokens
            
            if(stringSplitada[0] == "Subject:"){
                break;
            }
            if(distance(vetorDeString.begin(), j) == 2 ){//se distancia do inicio ==2 esta na linha do From:
                from = stringSplitada[1];
                //cout<<"Quem mandou email: "<<from<<endl;
            }
            
            if(distance(vetorDeString.begin(), j) >= 3 ){//se distancia do inicio >=3 esta na linha do To:
                for (vector<string>::iterator k = stringSplitada.begin(); k != stringSplitada.end(); ++k){
                    std::remove((*k).begin(), (*k).end(), '\t');//faz o trimm das strings depois do To:
                    //cout <<"Depois do trimm: "<< *k<<endl;
                }
                for(unsigned int n=0;n<stringSplitada.size();++n){
                    if(stringSplitada[n] != "To:"){//compara para nao adicionar o To:
                        toEmail.push_back(stringSplitada[n]);//adiciona no vetor de emails de quem recebeu
                    }
                }
            }
            ++j;//vai para a proxima linha do vetorDeString
        }
        vetorFinalDuplicado.push_back(make_pair(from,toEmail));//bota no vetor de pair
        
    }
    
    return vetorFinalDuplicado;
}
