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
int exibir_materias();
void verMedia(int usuario_ID);
void visualizarNotas(int usuario_ID);
void cadastrar_na_materia(int id_aluno,char name[15]);
int id_na_materia(char nome_materia[28]);

void home_aluno(int usuario_ID){
    int opcao;

    while(opcao !=0 ){
        system("cls");
        cout << "===========================" << endl;
        cout << "===========ALUNO===========" << endl;
        cout << "===========================" << endl;

        cout << "1-Realizar Matricula" << endl;
        cout << "2-Ver Nota" << endl;
        cout << "3-Ver Media" << endl;
        cout << "0-Deslogar" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                system("cls");
                realizar_matricula(usuario_ID);
                break;
            case 2:

                break;
            case 3:
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
    int id_selecionado = exibir_materias();
    int confirm=0;
    struct materias m;
    fstream leitura(lista_materias, ios::in);

    if(leitura.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    while(leitura &&! leitura.eof()){
        if(m.id_materia != 0 && m.id_materia <101){
            if(m.id_materia==id_selecionado){ // se o id escolhido pelo usuário estiver na lista de materias disponiveis
                cadastrar_na_materia(usuario_ID,m.nome_materia);
                confirm=1;
                break;
            }
        }
        leitura.read((char*)(&m),sizeof(materias));
    }
    if(confirm==0){
        cout << "Materia inexistente" << endl;
    }
leitura.close();
}

void cadastrar_na_materia(int id_aluno,char name[15]){
    int id_materia;
    aluno usuario;
    char nome_materia[28]=".\\Materias\\";
    strcat(nome_materia,name);
    strcat(nome_materia,".txt");

    fstream arquivoS;
    arquivoS.open(nome_materia, ios::in | ios:: out | ios::ate);

    id_materia = id_na_materia(nome_materia);

    aluno add = {id_materia,id_aluno,0.0,0.0,0.0,0.0};

    arquivoS.seekp((id_materia)*sizeof(aluno));
    arquivoS.write((const char *)(&add),sizeof(aluno));

    arquivoS.close();
    limpar_tela; cout<< "Registrado Com Sucesso" <<endl; Sleep(2000);
}

int exibir_materias(){
    int id_selecionado;
    struct materias m;
    fstream leitura(lista_materias, ios::in);

    if(leitura.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    cout << "=================================================" << endl;
    cout << "================Lista De Materias================" << endl;
    cout << "=================================================" << endl;

    while(leitura &&! leitura.eof()){
        if(m.id_materia > 0 && m.id_materia <100 && m.nome_materia != ""){
            cout << setw(3) << m.id_materia << setw(2) << "|"
            << setw(15) << m.nome_materia << endl;
        }
        leitura.read((char*)(&m),sizeof(materias));
    }
    leitura.close();
    cout << "================================================="<<endl;

    cout << "ID da materia: ";
    cin >> id_selecionado;

    return id_selecionado;
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

int id_na_materia(char nome_materia[28]){
    int total=0;
    struct aluno a;
    fstream leitura(nome_materia, ios::in);

    if(leitura.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    while(leitura &&! leitura.eof()){
        if(a.id_disciplina != 0 && a.id_disciplina <100){
            total=total+1;
        }
        leitura.read((char*)(&a),sizeof(aluno));
    }
    leitura.close();
    return total+1;
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
