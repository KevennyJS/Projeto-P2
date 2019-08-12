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

int id_para_materia();

void criar_materia(int ID_ativo){
    int i,cont_materia=1,cont;
    materias m;
    fflush(stdin);
    char nome[28]=".\\Materias\\";
    fstream materiaSaida;
    fstream leitura;

    cout << "Nome Da Materia: ";
    cin >> m.nome_materia;

    m.id_materia = id_para_materia();

    materiaSaida.open(".\\Materias\\MATERIAS.txt", ios::out | ios::in | ios::ate);
    materiaSaida.seekp((m.id_materia)*sizeof(materias));
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
int id_para_materia(){
    int total=0;
    struct materias m;
    fstream leitura(lista_materias, ios::in);

    if(leitura.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    while(leitura &&! leitura.eof()){
        if(m.id_materia != 0 && m.id_materia <101){
            total=total+1;
        }
        leitura.read((char*)(&m),sizeof(materias));
    }

    return total+1;
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

/*
void CalculaMediaTurma(char* nomeDaDiciplina){
    float p*;
    aluno alunoX;
    User usuarioBd;

    fstream archiveTurma;
    archiveTurma.open(nomeDaDiciplina,ios::ate|ios::in|ios::out);
    fstream archiveBd;
    archiveTurma.open(nomeDaDiciplina,ios::ate|ios::in|ios::out);

    if(archiveTurma.fail())
        cout << "ALGUM PROBLEMA COM O ARQUIVO!!! FECHE O PROGRAMA " <<endl;

    if(archiveBd.fail())
        cout << "ALGUM PROBLEMA COM O ARQUIVO!!! FECHE O PROGRAMA " <<endl;

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
