#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>

#define limpar_tela system("CLS");
using namespace std;

void criar_materia(int ID_ativo){
    int i,cont_materia=0;
    materias m;
    fflush(stdin);
    char nome[28]=".\\Materias\\";
    fstream materiaSaida(".\\Materias\\MATERIAS.txt", ios::out | ios::in | ios::ate);

    cout << "Nome Da Materia: ";
    cin >> m.nome_materia;

    //
    while (materiaSaida &&! materiaSaida.eof()){
        if(m.id_materia != 0){
               cont_materia++;
        }materiaSaida.read((char*)(&m),sizeof(materias));
        if(m.id_materia == 0) break;
    }
    m.id_materia = cont_materia;
    cout << "O nome e " << m.nome_materia << " e o id e: " << m.id_materia;
    Sleep(2000);
    materiaSaida.close();
    materiaSaida.open(".\\Materias\\MATERIAS.txt", ios::out | ios::in | ios::ate);
    materiaSaida.seekp((cont_materia-1)*sizeof(materias));
    materiaSaida.write((const char *)(&m),sizeof(materias));
    materiaSaida.close();

    ofstream arquivo;
    strcat(nome,m.nome_materia);
    strcat(nome,".txt");
    arquivo.open(nome, ios::out);
    Sleep(2000);

    User prof = {ID_ativo, "", "", "", ' ', 0.0, 0};
    arquivo.write((const char *)(&prof),sizeof(User));

    User UVazio = {0, "", "", "", ' ', 0.0, 0};

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
