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
    int i,cont_materia=1;
    materias m;

    fflush(stdin);
    char nome[28]=".\\Materias\\";
    char adicao[15];

    cout << "Nome Da Materia: ";
    cin >> adicao;
    strcat(nome,adicao);
    strcat(nome,".txt");

    fstream materiaSaida(".\\Materias\\MATERIAS.txt", ios::out | ios::in | ios::ate);
    //
    for(int cont=0; cont < 100; cont++){
        if(m.id_materia != 0){
               cont_materia++;
        }
    }
    m.id_materia = cont_materia;
    strcpy(m.nome_materia,adicao);
    materiaSaida.seekp((cont_materia)*sizeof(materiaSaida));
    materiaSaida.write((const char *)(&m),sizeof(materiaSaida));
    materiaSaida.close();

    ofstream arquivo;
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
/*
void atribuirNotas(char* nameMateria,int idDoAlunoNaDisciplina){

    float nota,nAvaliacao;
    aluno alunoX;
    fstream archive;
    archive.open(nameMateria,ios::ate|ios::in|ios::out);

    if(archive.fail())
        cout << "ALGUM PROBLEMA COM O ARQUIVO!!! FECHE O PROGRAMA " <<endl;

    archive.seekg((idDoAlunoNaDisciplina-1)*sizeof(aluno));
    archive.read((char*)(&alunoX),sizeof(aluno));

    cout << "Qual avaliação deseja atribuir a nota ?(1,2,3)"<<endl;
    cin >> nAvaliacao;
    if(nAvaliacao==1;){
        cout << "Digite a nota:" ;
        cin >>alunoX.nota_alunos1;
    }else if(nAvaliacao==2){
        cout << "Digite a nota:" ;
        cin >>alunoX.nota_alunos2 ;
    }else if(nAvaliacao==3){
        cout << "Digite a nota:" ;
        cin >>alunoX.nota_alunos3;
    }else{
        cout << "opção Invalida!"<<endl;
    }

    archive.seekp((idDoAlunoNaDisciplina-1)*sizeof(aluno));
    archive.write((const char*)(&alunoX),sizeof(aluno));

    archive.close();
}
*/
