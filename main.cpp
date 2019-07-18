#include <iostream>
#include "biblioteca.h"

using namespace std;

int main(){
    int Tipo_user,opcao;

    while (opcao !=0 ){
        cout << "==========================" << endl << "Essa home e so para testes" << endl <<  "==========================" << endl;
        cout << "1-Inicializar" << endl;
        cout << "2-Cadastrar" << endl;
        cout << "3-visualizar cadastrados" << endl;
        cout << "4-Login" << endl;
        cout << "5-criar materia" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                inicializar();
                limpar_tela;
                cout << "Criando Arquivo...";
                Sleep(2000);
                break;
            case 2:
                limpar_tela;
                cadastrar();
                limpar_tela;
                cout << "Usuario Cadastrado!!!";
                Sleep(2000);
                break;
            case 3:
                visualizaTeste();
                getch();
                break;
            case 4:
                Tipo_user=login();
                break;
            case 5:
                criar_materia();
                break;
        }
        limpar_tela;
    }
    return 0;
}

