#include <iostream>
#include "adm.h"
#include "professores.h"
#define limpar_tela system("CLS");

using namespace std;
using namespace std;

int main(){
    int verifica=0;
    char login[15], senha[15];
    char professor='p';

    User usuario;
    ifstream leitura;
    leitura.open("Bd.txt", ios::in);

    while(1){
        limpar_tela;
        cout << "=====================" << endl << "========LOGIN========" << endl << "=====================" << endl << endl;
        cout << "LOGIN: ";
        cin >> login;
        cout << "SENHA: ";
        cin >> senha;
        if(strcmp("0",login)==0 && strcmp("0",senha)==0) {limpar_tela; cout << "saindo..."; Sleep(2000);exit(1);}

        while(leitura && !leitura.eof()){
            if(usuario.id != 0)
            {
                if(strcmp(usuario.login,login)==0 && strcmp(usuario.senha,senha)==0)
                {
                    if(usuario.token == 'A'){
                        limpar_tela;
                        leitura.close();
                        home_adm();
                    }
                    else if(usuario.token == 'P' || usuario.token == 'p')
                    {
                        limpar_tela;
                        cout << setw(15) << "Bem Vindo " << usuario.nome << endl;
                        leitura.close();
                        Sleep(2000);
                        home_prof(usuario.id);
                    }
                    else
                    {
                        cout << setw(15) << "Bem Vindo " << usuario.nome << endl;
                        leitura.close();
                        Sleep(2000);
                        // para facilitar, podem chamar a função para os alunos aqui
                    }
                    verifica=1;
                    break;
                }
            }
            leitura.read((char*)(&usuario),sizeof(User));

        }
        leitura.close();

        if(verifica==0){
            cout <<"Usuario Ou Senha Incorreto";
            Sleep(2000);
        }
    }
}

