#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#define limpar_tela system("CLS");

#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

using namespace std;
char* nameArchive ="Bd.txt";
struct User
{
    int id;
    char login[15];
    char senha[15];
    char nome[15];
    char token;
};
struct aluno // arquivos das TURMAS
{
    int id_disciplina;
    int id_usuario;
    int nota_alunos1;//distribui as 3 notas pra ficar mais facil o acesso para media, e para exibição das notas, e para o cadastro na materia
    int nota_alunos2;
    int nota_alunos3;
} ;

void login(int &ID_ativo)
{
    int verifica=0;
    char login[15], senha[15];
    char professor='p';

    User usuario;
    ifstream leitura;
    leitura.open("Bd.txt", ios::in);

    limpar_tela;
    cout << "=====================" << endl << "========LOGIN========" << endl << "=====================" << endl << endl;
    cout << "LOGIN: ";
    cin >> login;
    cout << "SENHA: ";
    cin >> senha;

    while(leitura && !leitura.eof())
    {
        if(usuario.id != 0)
        {
            if(strcmp(usuario.login,login)==0 && strcmp(usuario.senha,senha)==0)
            {
                if(usuario.token == 'P' || usuario.token == 'p')
                {
                    ID_ativo=usuario.id;
                    limpar_tela;
                    cout << setw(15) << "Bem Vindo " << usuario.nome << endl;
                    leitura.close();
                    Sleep(2000);
                    // para facilitar, podem chamar a função para os professores aqui ;
                }
                else
                {
                    cout << setw(15) << "Bem Vindo " << usuario.nome << endl;
                    leitura.close();
                    Sleep(2000);
                    // para facilitar, podem chamar a função para os alunos aqui
                }
                cout << "achou senha";
                verifica=1;
                getch();
                break;
            }
        }
        leitura.read((char*)(&usuario),sizeof(User));

    }
    leitura.close();
    if(verifica==0)
        cout <<"Usuario Ou Senha Incorreto";
    Sleep(2000);
}

void inicializar()
{
    struct User vazio = {0,"","","",' '};
    ofstream archive;
    archive.open(nameArchive,ios::out);

    if(archive.fail())
    {
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    for(int i=0; i<100; i++)
    {
        archive.write((const char*)(&vazio),sizeof(User));
    }
    archive.close();
}

void verificaCadastrados(int &QuantUsuariosIn) // id automatico vericaçao de quanto usuarios ja estao cadastrados
{
    struct User usu;
    fstream archive;
    archive.open(nameArchive,ios::in);

    if(archive.fail())
    {
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    archive.read((char*)(&usu),sizeof(User));
    while(archive &&!archive.eof())
    {
        if(usu.id!=0)
            QuantUsuariosIn++;
        archive.read((char*)(&usu),sizeof(User));

    }
    archive.close();
}

void cadastrar()
{
    struct User newUser;
    int QuantTotal=0,quantIn=0;
    verificaCadastrados(quantIn);
    fstream archive;
    archive.open(nameArchive,ios::out|ios::in|ios::ate);

    if(archive.fail())
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;

    cout <<"Digite o login: ";
    cin  >>newUser.login;
    cout << "Digite a Senha: ";
    cin  >>newUser.senha;
    cout << "Digite Seu Nome: ";
    cin  >>newUser.nome;
    cin.ignore();
    cout <<"Digite que tipo de conta o usuario esta criando P(professor) <-> A(Aluno)"<<endl;
    cin  >> newUser.token;
    newUser.id = (quantIn)+1; //logica para por o proximo id ...



    archive.seekp((newUser.id-1)*sizeof(User));
    archive.write((const char*)(&newUser),sizeof(User));

    archive.close();
    system("CLS");
}

void visualizaTeste()
{
    struct User usu;
    fstream archive;
    archive.open(nameArchive,ios::in);

    if(archive.fail())
    {
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    archive.read((char*)(&usu),sizeof(User));
    while(archive &&!archive.eof())
    {
        if(usu.id != 0)
            cout <<"\n"<<usu.id <<"\n"<<usu.login<<"\n"<<usu.senha<<endl;

        archive.read((char*)(&usu),sizeof(User));

    }
    archive.close();
}

void criar_materia(int &ID_ativo)
{
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
    Sleep(2000);
}




#endif // BIBLIOTECA_H_INCLUDED
