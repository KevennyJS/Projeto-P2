#include <iostream>
#include "adm.h"
#include "professores.h"
#include "alunos.h"
#define limpar_tela system("CLS");
#include <locale.h>
#include <conio.h>
#include <conio2.h>
#include <windows.h>


#define COR_CABECALHO LIGHTRED
#define COR_CORPO LIGHTGRAY
#define COR_ALERTA LIGHTRED
#define COR_LETRA BLACK
#define COR_DETALHE CYAN
#define COR_FUNDO RED
#include "layouts.h"
using namespace std;

void cadastro_para_aluno();

int main(){
    //inicializar();
    setlocale(LC_ALL,"portuguese");
    int verifica=0,existe=0,opcao=1;
    char login[15], senha[15];
    char professor='p';
    extra::ajuda();

    User usuario;
    ifstream leitura;

    while(opcao!=0){
        limpar_tela;                                                 // EDITANDOOOOOOOOOOOOOOOOOOOOO

        logoPrincipal();
        gotoxy(30,9);
        cout<<"OLÁ, USUÁRIO. BEM VINDO AO SIGAA LITE";
        criaMenu(8,40,30,10, COR_DETALHE,COR_LETRA);
        gotoxy(30,11);
        cout << "1- LOGIN";
        gotoxy(30,13);
        cout << "2- REGISTRAR-SE";
        gotoxy(30,15);
        cout << "0- SAIR";
        gotoxy(30,17);
        cout <<" # OPÇÃO: ";
        cin >>opcao;
        limpar_tela;

        if(opcao==1){
            logoPrincipal();
            bordaLogin();
            gotoxy(28,11);
            cout<<"LOGIN   ";
            gotoxy(28,15);
            cout<<"SENHA   ";
            gotoxy(39,11);
            cin>>login;
            gotoxy(39,15);
            cin>>senha;
            if(strcmp("0",login)==0 && strcmp("0",senha)==0) {limpar_tela; cout << "saindo..."; Sleep(2000);exit(1);}

            leitura.open("Bd.txt", ios::in);

            while(leitura && !leitura.eof()){
                if(usuario.id != 0)
                {
                    if(strcmp(usuario.login,login)==0){existe++;}
                    if(strcmp(usuario.login,login)==0 && strcmp(usuario.senha,senha)==0)
                    {
                        if(usuario.token == 'M'){
                            limpar_tela;
                            leitura.close();
                            home_adm();
                        }
                        else if(usuario.token == 'P' || usuario.token == 'p')
                        {
                            limpar_tela;

                            cout << setw(15) << "BEM VINDO " << usuario.nome << endl;
                            leitura.close();
                            Sleep(2000);
                            limpar_tela;
                            home_prof(usuario.id);
                        }
                        else if(usuario.token == 'A' || usuario.token == 'a')
                        {
                            limpar_tela;

                            cout << setw(15) << "BEM VINDO " << usuario.nome << endl;
                            leitura.close();
                            Sleep(2000);
                            limpar_tela;
                            home_aluno(usuario.id);
                        }
                        verifica=1;
                        break;
                    }
                }
                leitura.read((char*)(&usuario),sizeof(User));

            }
            leitura.close();

            if(existe==0){
                cout << "USUARIO NÃO EXISTE";
                Sleep(2000);
                existe=0;
            }

            else if(verifica==0){
                cout <<"USUARIO OU SENHA INCORRETO";
                Sleep(2000);
                verifica=0;
            }
        }
        else if (opcao==2){
            cadastro_para_aluno();
        }
        else if (opcao==0){
            msg(1,1);
            boneco();
        }
    }
}

void cadastro_para_aluno(){
    struct User newUser;
    int QuantTotal=0,quantIn=0;
    verificaCadastrados(quantIn);
    fstream archive;
    archive.open(nameArchive,ios::out|ios::in|ios::ate);

    if(archive.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

 logoPrincipal();
    criaMenu(2,30,15,5, COR_DETALHE,COR_LETRA);
    gotoxy(17,5);
    cout << "------------------------";
    gotoxy(17,6);
    cout << "---REGISTRO DE ALUNOS---";
    gotoxy(17,7);
    cout << "------------------------";
    criaMenu(8,30, 15,10, COR_DETALHE, COR_LETRA);

    do{
            gotoxy(17,10);
    cout <<"Digite o login: ";
            gotoxy(32,10);
    cin  >>newUser.login;
            gotoxy(17,11);
    if(VerificaUsuarioExistenteCadastro(newUser.login)==1){
        cout <<"Usuario já existe,tente outro!"<<endl;
    }
    }while(VerificaUsuarioExistenteCadastro(newUser.login)==1);

    cout<<"----------------------";
     gotoxy(17,12);
    cout << "DIGITE A SENHA...: ";
     gotoxy(32,12);
    cin  >>newUser.senha;
     gotoxy(17,13);
    cout << "DIGITE SEU NOME..:  ";
     gotoxy(35,13);
    cin.ignore();
    cin.getline(newUser.nome,40);
    newUser.token = 'A';
    newUser.id = (quantIn)+1; //logica para por o proximo id ...

    archive.seekp((newUser.id-1)*sizeof(User));
    archive.write((const char*)(&newUser),sizeof(User));

    archive.close();
    system("CLS");
}


