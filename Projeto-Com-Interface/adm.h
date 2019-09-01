#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <conio2.h>

#define COR_CABECALHO LIGHTRED
#define COR_CORPO LIGHTGRAY
#define COR_ALERTA LIGHTRED
#define COR_LETRA BLACK
#define COR_DETALHE CYAN
#define COR_FUNDO RED

#define limpar_tela system("CLS");
using namespace std;
void logoPrincipal();
void criaMenu(int altura,int largura,int cordX,int cordY,int corFundo,int corLetra);
char* lista_materias = (char*)".\\Materias\\MATERIAS.txt";
char* nameArchive =(char*)"Bd.txt";
int msg(int opcao,int cont);
void boneco();
void carregando();
struct User{

    int id;
    char login[15];
    char senha[15];
    char nome[40];
    char token;
    int materias;
};
struct aluno{ // arquivos das TURMAS;

    int id_disciplina; // essa aqui e a posição do aluno na materia
    int id_usuario;    // esse aqui recebe o id la do Bd
    float nota_alunos1;//distribui as 3 notas pra ficar mais facil o acesso para media, e para exibiï¿½ï¿½o das notas, e para o cadastro na materia
    float nota_alunos2;
    float nota_alunos3;
    float media;
    int faltas;
} ;
struct materias{

    int id_materia;
    char nome_materia[15];
};

void visualizaTeste();
void inicializar();
int VerificaUsuarioExistenteCadastro(char loginDesejado[]);
void cadastrar();
void atualizarInfo();
void noname();

void home_adm(){
    setlocale(LC_ALL,"portuguese");
    int opcao;
   logoPrincipal();
    while(opcao !=0 ){
        criaMenu(2,30,15,5, COR_DETALHE,COR_LETRA);
        gotoxy(17,5);
        cout << "===========================";
    gotoxy(17,6);
        cout << "============ADM============";
        gotoxy(17,7);
        cout << "===========================";
         criaMenu(8,30, 15,10, COR_DETALHE, COR_LETRA);
         gotoxy(17,10);
        cout << "1-APAGAR TODOS OS USUARIOS";
        gotoxy(17,11);
        cout << "2-CADASTRAR";
        gotoxy(17,12);
        cout << "3-LISTA DE CADASTRADOS";
        gotoxy(17,13);
        cout << "4-ATUALIZAR CADASTROS";
        gotoxy(17,14);
        cout << "5-VISUALIZAR MATERIAS";
        gotoxy(17,15);
        cout << "0-DESLOGAR";
        gotoxy(17,16);
        cout << "# OPÇÃO: ";
        cin >> opcao;
        clrscr();
        switch(opcao){

            case 1:
                inicializar();
                limpar_tela;
                msg(2,1);
                Sleep(2000);
               // logoPrincipal();
                break;
            case 2:
                limpar_tela;
                cadastrar();
                limpar_tela;
                logoPrincipal();
                gotoxy(17,8);
                cout << "USUARIO CADASTRADO!!!";
                Sleep(2000);
               // logoPrincipal();
                break;
            case 3:
                visualizaTeste();
                gotoxy(1,30);
                getch();
               // logoPrincipal();
                break;
            case 4:
                atualizarInfo();
                getch();
               // logoPrincipal();
                break;
            case 5:
                logoPrincipal();
                //clrscr();
                noname();
                getch();
                break;
        }
        limpar_tela;
        logoPrincipal();
        gotoxy(17,5);
        if(opcao == 0) msg(1,1);

    }
}

void inicializar(){
    User adm = {1, "admin", "admin", "Admin", 'M'};
    User vazio = {0,"","","",' ',0};
    materias m_vazia = {0, ""};
    system("md Materias");
    system("dir > Materias\\MATERIAS.txt");
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

void verificaCadastrados(int &QuantUsuariosIn) // id automatico vericaï¿½ao de quanto usuarios ja estao cadastrados
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
    logoPrincipal();
       criaMenu(1,55,15,12,BLACK,WHITE);
       criaMenu(2,55,15,10, COR_DETALHE, COR_LETRA);


       do{
            gotoxy(22,8);
       cout<<"****CRIANDO CADASTRO****";
            gotoxy(17,11);
    cout <<"DIGITE O LOGIN: ";
            gotoxy(32,11);
    cin  >>newUser.login;
            gotoxy(17,12);
    if(VerificaUsuarioExistenteCadastro(newUser.login)==1){
        cout <<"Usuario já existe,tente outro!"<<endl;
    }
    }while(VerificaUsuarioExistenteCadastro(newUser.login)==1);

       criaMenu(2,55, 15,14, COR_DETALHE, COR_LETRA);


    //cout<<"----------------------";
     gotoxy(17,15);
    cout << "DIGITE A SENHA...: ";
     gotoxy(35,15);
    cin  >>newUser.senha;
    criaMenu(1,55,15,17,BLACK,WHITE);
    criaMenu(2,55, 15,18, COR_DETALHE, COR_LETRA);
     gotoxy(17,19);
    cout << "DIGITE SEU NOME..:  ";
     gotoxy(35,19);
    cin.ignore();
    cin.getline(newUser.nome,40);
    gotoxy(17,23);
    again:
    cout <<"P(professor) <-> A(Aluno) <-> M(Administrador): ";
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
    logoPrincipal();
    criaMenu(1,55,15,5,BLACK,WHITE);
    gotoxy(12,5);
    cout << "==============================================================";
    gotoxy(12,6);
    cout << "======================LISTA DE CADASTRADOS====================";
    gotoxy(12,7);
    cout << "==============================================================";
    criaMenu(5,100,1,10, COR_DETALHE,COR_LETRA);
    gotoxy(1,8);
    cout << setiosflags(ios::left)
        << setw(32) << "NOME" << setw(2) << "|"
        <<setw(32) <<  "LOGIN" << setw(2) << "|"
        << setw(14) <<  "SENHA" << setw(2) << "|"
        <<setw(6) <<   "TIPO"<<endl;

    archive.read((char*)(&usu),sizeof(User));
    gotoxy(1,10);
    while(archive &&! archive.eof()){
        if(usu.id != 0){
                cout << setiosflags(ios::left)
                << setw(32) << usu.nome << setw(2) << "|"
                << setw(32) << usu.login << setw(2) << "|"
                <<setw(14) << "*****" << setw(2) << "|"
                << setw(6) << resetiosflags(ios::right) << usu.token<<endl;

        }
        archive.read((char*)(&usu),sizeof(User));
    }
    //gotoxy(17,12);
   // cout << "==================================================";
    archive.close();
}
void atualizarInfo(){
    setlocale(LC_ALL,"portuguese");
    short int opcao;
    fstream archive;
    struct User usuario;
    archive.open("Bd.txt",ios::out|ios::ate|ios::in);
    logoPrincipal();
    if(archive.fail()){
        cout <<"ALGUM PROBLEMA COM SEU ARQUIVO BD ,FECHE E TENTE NOVAMENTE!"<<endl;
    }
    gotoxy(17,9);
    cout<< "INFORME O ID REFERENTE A ATUALIZACAO: ";
    gotoxy(54,9);
    cin >> usuario.id;

    archive.seekg((usuario.id-1)*sizeof(User));
    archive.read((char*)(&usuario),sizeof(User));
    criaMenu(5,30,15,10, COR_DETALHE,COR_LETRA);
    gotoxy(17,11);
    cout << "-- ATUALIZAR INFORMAÇÕES --";
    gotoxy(17,12);
    cout<< "[1]- LOGIN";
    gotoxy(17,13);
    cout<< "[2]- SENHA";
    gotoxy(17,14);
    cout<< "[3]- NOME ";
    gotoxy(17,15);
    cout<< " # OPÇÃO: ";
    gotoxy(27,15);
    cin >>opcao;
    clrscr();
    logoPrincipal();
    gotoxy(17,9);
    cout<<"ATUALIZANDO.....";
    criaMenu(5,30,15,10, COR_DETALHE,COR_LETRA);

    switch (opcao)
    {
    case 1:
         gotoxy(17,11);
        cout<<"NOVO LOGIN: ";
        gotoxy(30,11);
        cin >>usuario.login;
        break;
    case 2:
        gotoxy(17,12);
        cout<<"NOVA SENHA: ";
        gotoxy(30,12);
        cin >>usuario.senha;
        break;
    case 3:
        gotoxy(17,13);
        cout<<"NOVO NOME: ";
        gotoxy(30,13);
        cin >>usuario.nome;
        break;
    default:
        cout <<"OPÇÃO NÃO EXISTE!!!"<<endl;
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
    criaMenu(2,30,15,5, COR_DETALHE,COR_LETRA);
    gotoxy(17,5);
    cout << "===========================";
    gotoxy(17,6);
    cout << "  ===LISTA DE MATERIAS===";
    gotoxy(17,7);
    cout << "===========================";

    while(leitura &&! leitura.eof()){
        if(m.id_materia != 0 && m.id_materia <101){
            cout << setw(3) << m.id_materia << setw(2) << "|"
            << setw(15) << m.nome_materia << endl;
        }
        leitura.read((char*)(&m),sizeof(materias));
    }
    leitura.close();
    //cout << "================================================="<<endl;
}
namespace extra{
void ajuda(){
    fstream archive;
    archive.open("Ajuda.txt",ios::out|ios::trunc);

    if(archive.fail()){
        cout << "Algum problema com os arquivos , feche e abra novamente"<<endl;
    }
    archive << "***************AJUDA*****************"<<"\n"
    <<"Como Utilizar:\n"
    <<"***********************************************************************************************************\n"
    <<"\n"<<"Como Aluno:\n1º-O aluno começa se cadastrando no menu inicial\n"
    <<"2º-Logando,temos as seguintes opções com suas respectivas funcionalidades:"<<"\n"
    <<"->(1)Realizar Matricula:Esta função realiza a matricula do aluno na materia X\n->(2)Ver notas...\n"
    <<"***********************************************************************************************************\n"
    <<"Como Professor:\n1º-Um administrador tem que cadastrar o professor\n2º-Logando,temos as seguintes opções com suas respectivas funcionalidades:\n"
    <<"->(1) Criar Turma \n->(2)Atribuir Nota \n->(3)Media:Calcula dos alunos de uma turma \n->(4)Visualizar Turma:visualiza informações sobre uma turma\n"
    <<"***********************************************************************************************************\n"
    <<"Como Administrador:\n1º-O administrador recebe a primeira conta do sistema diretamente dos desenvolvedores\n"
    <<"2º-O Administrador pode cadastrar qualquer tipo de conta\n"
    <<"3º-Caso as base de dados estejam com problema o adminstrador pode resetalas usando a função (1)\n"
    <<"4º-O administrador tambem pode atualizar dados de qualquer usuario\n"
    <<"***********************************************************************************************************\n"
    <<"***********************************************************************************************************\n"
    <<"Contato:(79)00000000"<<endl;

    archive.close();

}
}

int msg(int opcao,int cont){


    if(opcao==1){
        cout<<"SAINDO";
        boneco();
    }
    else if(opcao==2){
        cout<<"ZERANDO";
    }
    if(cont <= 3){
        Sleep(750);
        cout<<".";
        msg(0,cont+1);
    }
    return 0;
}

int VerificaUsuarioExistenteCadastro(char loginDesejado[]){
    fstream archive;
    archive.open("Bd.txt",ios::in);

    User instanciaVerifica;

    if(archive.fail())
        cout << "ALGUM PROBLEMA COM O ARQUIVO!"<<endl;

    while(!archive.eof()){
        archive.read((char*)(&instanciaVerifica),sizeof(User));
        if(strcmp(loginDesejado,instanciaVerifica.login)==0)
            return 1;
    }
archive.close();
    return 0;

}

