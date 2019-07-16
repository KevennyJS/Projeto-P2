#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char* nameArchive ="Bd.txt";
struct User{
    int id;
    char login[15];
    char senha[15];
    char nome[15];
    char token;
};

void inicializar();
void verificaCadastrados();
void cadastrar();
void visualizaTeste();

int main()
{
    //inicializar();
    cadastrar();
    visualizaTeste();
    return 0;
}
void inicializar(){
    struct User vazio ={0,"","","",' '};
    fstream archive;
    archive.open(nameArchive,ios::out|ios::app);

    if(archive.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    for(int i=0;i<100;i++){
        archive.write((const char*)(&vazio),sizeof(User));
    }
    archive.close();
}

void verificaCadastrados(int &QuantUsuariosIn,int &QuantUsuariosTotal){
    struct User usu;
    fstream archive;
    archive.open(nameArchive,ios::in);

    if(archive.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    archive.read((char*)(&usu),sizeof(User));
    while(archive &&!archive.eof()){
            if(usu.login != "")     //tem algum problema ... <<<<<
            QuantUsuariosIn++;
        archive.read((char*)(&usu),sizeof(User));
        QuantUsuariosTotal++;
    }
    archive.close();
}
void cadastrar(){
    struct User newUser;
    int QuantTotal=0,quantIn=0;
    verificaCadastrados(quantIn,QuantTotal);
    fstream archive;
    archive.open(nameArchive,ios::out|ios::in|ios::ate);

    if(archive.fail())
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;

        cout <<"Digite o login ,senha ,nome "<<endl;
        cin  >>newUser.login>>newUser.senha>>newUser.nome;
        cin.ignore();
        cout <<"Digite que tipo de conta o usuario esta criando P(professor) <-> A(Aluno)"<<endl;
        cin  >> newUser.token;
        newUser.id = (QuantTotal-quantIn); //logica para por o proximo id ...

        cout <<"\t"<<newUser.id<<endl;

        archive.seekp((newUser.id)*sizeof(User));
        archive.write((const char*)(&newUser),sizeof(User));

        archive.close();

}
void visualizaTeste(){
    struct User usu;
    fstream archive;
    archive.open(nameArchive,ios::in);

    if(archive.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    archive.read((char*)(&usu),sizeof(User));
    while(archive &&!archive.eof()){
            if(usu.id != 0)
            cout <<usu.id <<"\n"<<usu.login<<"\n"<<usu.senha<<endl;

        archive.read((char*)(&usu),sizeof(User));

    }
    archive.close();
}
