#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>

#define limpar_tela system("CLS");
using namespace std;

void criar_materia(int &ID_ativo){
    fflush(stdin);
    char nome[30]=".\\Materias\\";
    char adicao[30];

    cout << "Nome Da Materia: ";
    gets(adicao);
    strcat(nome,adicao);
    strcat(nome,".txt");

    ofstream arquivo(nome, ios::out);

    User prof = {ID_ativo, 0, 0, 0, 0};
    arquivo.write((const char *)(&prof),sizeof(User));

    User UVazio = {0, 0, 0 , 0, 0};

    for(int i = 0; i < 50; i++){
        arquivo.write((const char *)(&UVazio),sizeof(User));
    }

    arquivo.close();
    limpar_tela;
    cout << "Materia Criada Com Sucesso!!!" << endl;
    Sleep(1500);
}

void home_prof(int ID_ativo){
    int opcao;
    setlocale(LC_ALL,"portuguese");

    while (opcao != 0){
        cout << "1- Criar Turma" << endl;
        cout << "0-Deslogar" << endl;
        cout <<"Opção: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                limpar_tela;
                criar_materia(ID_ativo);
                limpar_tela;
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
        }
    }
}
