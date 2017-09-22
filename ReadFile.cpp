//
//  ReadFile.cpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 21/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//
#include <fstream>
#include "ReadFile.hpp"
ReadFile::ReadFile(){
    
}
vector<string>ReadFile::readByLine(string fileToRead)
{
    vector<string> L;
    string line;
    ifstream myfile (fileToRead);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            L.push_back(line);
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    /*
    ifstream file;
    
    string nome = fileToRead;
    string linha;
    vector<string> * L = new vector<string>();
    
    file.open(nome);
    
    if (file.is_open())
    {
        while (getline(file, linha))
        {
            L->push_back(linha);
        }
        file.close();
    }
    else
    {
        cout << "Erro de abertura de arquivo";
    }
    */
    return L;
}
