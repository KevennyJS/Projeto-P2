#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void realizar_matricula(int usuario_ID);
void exibir_materias();
void verMedia(int usuario_ID);
void visualizarNotas(int usuario_ID);

void home_aluno(int usuario_ID){
    int opcao;

    while(opcao !=0 ){
        system("cls");
        cout << "===========================" << endl;
        cout << "===========ALUNO===========" << endl;
        cout << "===========================" << endl;

        cout << "1-Realizar Matricula" << endl;
        cout << "2-" << endl;
        cout << "3-Ver Nota" << endl;
        cout << "4-Ver Media" << endl;
        cout << "0-Deslogar" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                system("cls");
                realizar_matricula(usuario_ID);
                break;
            case 2:
                system("cls");
                exibir_materias();
                system("pause");
                break;
            case 3:

                break;
            case 4:
                system("cls");
                verMedia(usuario_ID);
                system("pause");
                break;
        }
    }
        limpar_tela;
        if(opcao == 0) cout << "Saindo..." << endl;
        Sleep(2000);

}
void realizar_matricula(int usuario_ID){


}
void exibir_materias(){
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

    cout << "================================================="<<endl;
}
void verMedia(int usuario_ID){

    struct User mediaAtual;
    fstream archive;
    archive.open("bd.txt",ios::in);

    if(archive.fail())
        cout <<"Alguem problema com os arquivos renicie o programa"<<endl;

    archive.read((char*)(&mediaAtual),sizeof(User));

        while(archive && !archive.eof()){
            //if(mediaAtual.id == usuario_ID)
            cout <<"MEDIA:"<<mediaAtual.media<<endl;
            archive.read((char*)(&mediaAtual),sizeof(User));
        }
        archive.close();

}

//visualizarNotas(int usuario_ID); //tem que testar dps quando começarem a botar nota nas parada

// aqui o aluno vai digitar o nome da "materia" para olhar as notas
/*
void visualizarNotas(int usuario_ID){
    struct aluno materiaAtual;

    char nomeMateria[40]="";
    selecioMateria(nomeMateria);

    fstream archive;
    archive.open(nomeMateria,ios::in);

    if(archive.fail())
    cout <<"Algum problema com o arquivos renicie o programa e tente novamente"<<endl;

    archive.reed((char*)(&materiaAtual),sizeof(aluno));
    while(archive && !archive.eof()){
        if(materiaAtual.id_usuario == usuario_ID){
            cout << setw(10) << "Nota 1"<< setw(10) << "Nota 2"<< setw(10) << "Nota 3"<<"\n"
                 << setw(10) <<setprecision(1)<<setiosflags(ios::showpoint) << materiaAtual.nota_alunos1
                 << setw(10) << materiaAtual.nota_alunos2
                 << setw(10) << materiaAtual.nota_alunos3 <<endl;
        }
        archive.reed((char*)(&materiaAtual),sizeof(aluno));
    }
    archive.close();

}
*/
void selecioMateria(char nameMateria[40]){  //quando for chamar essa funçao o parametro tem q ser zerado
    strcat(nameMateria,".//Materias//");
    char nameAux[15];
    cout << "Nome da Materia a Selecionar:"<<endl;
    cin >> nameAux;
    strcat(nameAux,".txt");
    strcat(nameMateria,nameAux);
    //cout <<nameMateria<<endl;
}
