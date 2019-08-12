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
char* lista_materias = (char*)".\\Materias\\MATERIAS.txt";
char* nameArchive =(char*)"Bd.txt";

struct User{

    int id;
    char login[15];
    char senha[15];
    char nome[15];
    char token;
    float media;
    int materias;
};
struct aluno{ // arquivos das TURMAS;

    int id_disciplina; // essa aqui e a posição do aluno na materia
    int id_usuario;    // esse aqui recebe o id la do Bd
    float nota_alunos1;//distribui as 3 notas pra ficar mais facil o acesso para media, e para exibi��o das notas, e para o cadastro na materia
    float nota_alunos2;
    float nota_alunos3;
    float media;
} ;
struct materias{

    int id_materia;
    char nome_materia[15];
};

void visualizaTeste();
void inicializar();
void cadastrar();
void atualizarInfo();
void noname();

void home_adm(){
    int opcao;

    while(opcao !=0 ){
        cout << "===========================" << endl;
        cout << "============ADM============" << endl;
        cout << "===========================" << endl;

        cout << "1-Apagar Todos Os Usuarios" << endl;
        cout << "2-Cadastrar" << endl;
        cout << "3-Lista de Cadastrados" << endl;
        cout << "4-Atualizar Cadastrados" << endl;
        cout << "5-Visualizar Materias" << endl;
        cout << "0-Deslogar" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                inicializar();
                limpar_tela;
                cout << "Zerando...";
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
                atualizarInfo();
                getch();
                break;
            case 5:
                noname();
                getch();
                break;
        }
        limpar_tela;
        if(opcao == 0) cout << "Saindo..." << endl;
        Sleep(2000);
    }
}

void inicializar(){
    User adm = {1, "admin", "admin", "Admin", 'M'};
    User vazio = {0,"","","",' ',0,0};
    materias m_vazia = {0, ""};
    ofstream arq;
    ofstream archive;
    ofstream reset;

    reset.open(lista_materias, ios::trunc);

    for(int i=0; i<100; i++){

        reset.write((const char*)(&m_vazia),sizeof(materias));
    }
    reset.close();

    archive.open(nameArchive,ios::out);

    if(archive.fail())
    {
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    archive.write((const char*)(&adm),sizeof(User));
    for(int i=0; i<100; i++)
    {
        archive.write((const char*)(&vazio),sizeof(User));
    }
    archive.close();
}

void verificaCadastrados(int &QuantUsuariosIn) // id automatico verica�ao de quanto usuarios ja estao cadastrados
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

void cadastrar(){
    struct User newUser;
    char aux;
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
    again:
    cout <<"Tipo de conta P(professor) <-> A(Aluno) <-> M(Administrador)"<<endl;
    cin >> aux;
    if (aux == 'P' || aux == 'A' || aux == 'M') newUser.token = aux;
    else {cout << "Tipo de usuario Desconhecido, Tente novamente!" << endl;goto again;}
    newUser.id = (quantIn)+1; //logica para por o proximo id ...

    archive.seekp((newUser.id-1)*sizeof(User));
    archive.write((const char*)(&newUser),sizeof(User));

    archive.close();
    system("CLS");
}

void visualizaTeste(){
    struct User usu;
    fstream archive;
    archive.open(nameArchive,ios::in);

    if(archive.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    cout << "==================================================" << endl;
    cout << "===============Lista De Cadastrados===============" << endl;
    cout << "==================================================" << endl;

    cout << setiosflags(ios::left)
        << setw(16) << "Nome" << setw(2) << "|"
        <<setw(16) << "Login" << setw(2) << "|"
        << setw(7) << "Senha" << setw(2) << "|"
        <<setw(3) << "Tipo" << endl;

    archive.read((char*)(&usu),sizeof(User));
    while(archive &&! archive.eof()){
        if(usu.id != 0){
                cout << setiosflags(ios::left)
                << setw(16) << usu.nome << setw(2) << "|"
                << setw(16) << usu.login << setw(2) << "|"
                <<setw(7) << "*****" << setw(2) << "|"
                << setw(4) << resetiosflags(ios::right) << usu.token << endl;

        }
        archive.read((char*)(&usu),sizeof(User));
    }
    cout << "==================================================" << endl;
    archive.close();
}
void atualizarInfo(){
    short int opcao;
    fstream archive;
    struct User usuario;
    archive.open("Bd.txt",ios::out|ios::ate|ios::in);

    if(archive.fail()){
        cout <<"ALGUM PROBLEMA COM SEU ARQUIVO BD ,FECHE E TENTE NOVAMENTE!"<<endl;
    }
    cout<< "Informe o id referente a Atualizao"<<endl;
    cin >> usuario.id;

    archive.seekg((usuario.id-1)*sizeof(User));
    archive.read((char*)(&usuario),sizeof(User));

    cout << "-- ATUALIZAR INFORMAES --"<<endl;
    cout << "[1]- Login\n"
         << "[2]- Senha\n"
         << "[3]- Nome" <<endl;
    cin >>opcao;

    switch (opcao)
    {
    case 1:
        cout<<"Novo Login"<<endl;
        cin >>usuario.login;
        break;
    case 2:
        cout<<"Novo Senha"<<endl;
        cin >>usuario.senha;
        break;
    case 3:
        cout<<"Novo Nome"<<endl;
        cin >>usuario.nome;
        break;
    default:
        cout <<"Opo não existe!!!"<<endl;
    }

    archive.seekp((usuario.id-1)*sizeof(User));
    archive.write((const char*)(&usuario),sizeof(User));

    archive.close();
}
void noname(){
    struct materias m;
    fstream leitura(lista_materias, ios::in);

    if(leitura.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    cout << "=================================================" << endl;
    cout << "================Lista De Materias================" << endl;
    cout << "=================================================" << endl;

    while(leitura &&! leitura.eof()){
        if(m.id_materia != 0 && m.id_materia <101){
            cout << setw(3) << m.id_materia << setw(2) << "|"
            << setw(15) << m.nome_materia << endl;
        }
        leitura.read((char*)(&m),sizeof(materias));
    }
    leitura.close();
    cout << "================================================="<<endl;
}
