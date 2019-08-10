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

    p = new float [3];
    for (int i=0;i<100;i++){
    archiveTurma.seekg((i)*sizeof(aluno));
    archiveTurma.read((char*)(&alunoX),sizeof(aluno));

    archiveTurma.seekg((alunoX.id_usuario)*sizeof(User));
    archiveTurma.read((char*)(&usuarioBd),sizeof(User));

        p*[0] = alunoX.nota_alunos1;
        p*[1] = alunoX.nota_alunos2;
        p*[2] = alunoX.nota_alunos3;

        usuarioBd.media = usuarioBd.media + p;
        usuarioBd.media = usuarioBd.media + p+1;
        usuarioBd.media = usuarioBd.media + p+2;

        usuarioBd.media = media/3;

    archiveTurma.seekp((alunoX.id_usuario)*sizeof(User));
    archiveTurma.read((const char*)(&usuarioBd),sizeof(User));

    }

        archiveTurma.close();
        archiveBd.close();
}
*/
