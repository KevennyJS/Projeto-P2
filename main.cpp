#include <iostream>
#include "adm.h"
#include "professores.h"
#include "alunos.h"
#define limpar_tela system("CLS");

using namespace std;

void cadastro_para_aluno();

int main(){
    setlocale(LC_ALL,"portuguese");
    int verifica=0,existe=0,opcao=1;
    char login[15], senha[15];
    char professor='p';

    User usuario;
    ifstream leitura;

    while(opcao!=0){
        limpar_tela;

        cout << "1- Login" <<endl;
        cout << "2- Registrar-se" << endl;
        cout << "0- Sair" <<endl;
        cout <<"Opção: ";
        cin >>opcao;
        limpar_tela;

        if(opcao==1){
            cout << "=====================" << endl << "========LOGIN========" << endl << "=====================" << endl << endl;
            cout << "LOGIN: ";
            cin >> login;
            cout << "SENHA: ";
            cin >> senha;
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
                            cout << setw(15) << "Bem Vindo " << usuario.nome << endl;
                            leitura.close();
                            Sleep(2000);
                            limpar_tela;
                            home_prof(usuario.id);
                        }
                        else if(usuario.token == 'A' || usuario.token == 'a')
                        {
                            limpar_tela;
                            cout << setw(15) << "Bem Vindo " << usuario.nome << endl;
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
                cout << "Usuario N�o Existe";
                Sleep(2000);
                existe=0;
            }

            else if(verifica==0){
                cout <<"Usuario Ou Senha Incorreto";
                Sleep(2000);
                verifica=0;
            }
        }
        else if (opcao==2){
            cadastro_para_aluno();
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

    cout << "======================" << endl;
    cout << "==Registro De Alunos==" << endl;
    cout << "======================" << endl;
    cout <<"Digite o login: ";
    cin  >>newUser.login;
    cout << "Digite a Senha: ";
    cin  >>newUser.senha;
    cout << "Digite Seu Nome: ";
    cin  >>newUser.nome;
    cin.ignore();
    newUser.token = 'A';
    newUser.id = (quantIn)+1; //logica para por o proximo id ...

    archive.seekp((newUser.id-1)*sizeof(User));
    archive.write((const char*)(&newUser),sizeof(User));

    archive.close();
    system("CLS");
}

