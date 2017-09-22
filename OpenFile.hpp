//
//  OpenFile.hpp
//  EmailGrafosEnron
//
//  Created by Martin Franzner on 18/09/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef OpenFile_hpp
#define OpenFile_hpp

#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <vector>

using namespace std;
class OpenFile {
private:
    string pathInicial;
    vector <string> pathFinal;
    vector <string> pathUsuario;
    vector <string> pathArquivoFinal;
    
public:
    OpenFile(string  caminho);
    vector <string> abreDiretorio();
    vector <string> concatenaSentMail();
    vector <string> concatenaFinal();
    vector <string> getPathParaLer();
};
#endif /* OpenFile_hpp */
