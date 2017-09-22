//
//  OpenFile.cpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 18/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "OpenFile.hpp"
#include <stdio.h>

using namespace std;

OpenFile::OpenFile(string  caminho){
    this->pathInicial = caminho;
    
}
vector <string> OpenFile::abreDiretorio(){
    const char * c = this->pathInicial.c_str();
    string aux;
    if (auto dir = opendir(c)) {
        while (auto f = readdir(dir)) {
            if (!f->d_name || f->d_name[0] == '.')
                continue; // Skip everything that starts with a dot
            aux = pathInicial+"/"+f->d_name;
            this->pathUsuario.push_back(aux);
            
            cout<<aux<<endl;
            //printf("File: %s\n", f->d_name);
        }
        closedir(dir);
    }
    return this->pathUsuario;
}

vector <string> OpenFile::concatenaSentMail(){
    string dName = "";
    string aux = this->pathInicial;
    for (unsigned int i=0; i<this->pathUsuario.size(); i++){
        const char * c = this->pathUsuario[i].c_str();
        if (auto dir = opendir(c)) {
            while (auto f = readdir(dir)) {
                if ((!f->d_name || f->d_name[0] == '.'))
                    continue; // Skip everything that starts with a dot
                dName = f->d_name;
                if(dName == "_sent_mail"){
                    //cout<<dName<<endl;
                    aux = aux+"/"+pathUsuario[i];
                    aux = aux+"/_sent_mail";
                    cout<<aux<<endl;
                    this->pathFinal.push_back(aux);
                }
                else if(dName == "sent_items"){
                    //cout<<dName<<endl;
                    aux = aux+"/"+pathUsuario[i];
                    aux = aux+"/sent_items";
                    cout<<aux<<endl;
                    this->pathFinal.push_back(aux);
                }
                
                printf("File: %s\n", f->d_name);
            }
            closedir(dir);
        }
        aux = this->pathInicial;

    }
    return this->pathFinal;
}
vector <string> OpenFile::concatenaFinal(){
    //abreDiretorio(); //pensei em chamar elas toads aqui ja para nao precisar chamar na main de novo...
    //concatenaSentMail();
    
    //vector<string>::iterator i = this->pathFinal.begin();
    string aux= "";
    string barra = "/";
    //i = this->pathFinal.begin(); i != this->pathFinal.end(); ++i
    for (unsigned int i=0; i<this->pathFinal.size(); i++){
        //cout<<*i<<endl;
        aux = pathFinal[i]+"/";
        cout<<aux<<endl;
        string c = aux;
        cout<<c<<endl;
        if (auto dir = opendir(c.c_str())) {
            while (auto f = readdir(dir)) {
                if (!f->d_name || f->d_name[0] == '.')
                    continue; // Skip everything that starts with a dot
                printf("File: %s\n", f->d_name);
                aux = barra + f->d_name;
                cout<<aux<<endl;
                this->pathArquivoFinal.push_back(aux);
                
            }
            closedir(dir);
        }
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for( auto printer : pathArquivoFinal){
        cout<<printer<<endl;
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    return this->pathArquivoFinal;
    
}
vector <string> OpenFile::getPathParaLer(){
    return this->pathArquivoFinal;
}

