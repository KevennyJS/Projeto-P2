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
    aluno usuario;
    int cont_alunos=1;
    char nome_materia[28]=".\\Materias\\";
    strcat(nome_materia,name);
    strcat(nome_materia,".txt");

    fstream arquivoS(nome_materia,ios::in | ios::out | ios::ate);
    usuario.id_usuario = id_aluno;
    while(arquivoS &&! arquivoS.eof()){
        if(usuario.id_usuario != 0){
            cont_alunos++;
            usuario.id_disciplina = cont_alunos;

            cout<<"id na diciplina" << usuario.id_disciplina <<endl;
            cout<<"id do usuario" << usuario.id_usuario <<endl;
            cout << "contador de alunos" << cont_alunos <<endl<<endl;getch();
        }arquivoS.read((char*)(&usuario),sizeof(aluno));
    }
    Sleep(2000);
    arquivoS.close();
    arquivoS.open(nome_materia, ios::in | ios:: out | ios::ate);

    aluno add = {cont_alunos,id_aluno,0.0,0.0,0.0};

    arquivoS.seekp((cont_alunos)*sizeof(aluno));
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

//visualizarNotas(int usuario_ID); //tem que testar dps quando começarem a botar nota nas parada

// aqui o aluno vai digitar o nome da "materia" para olhar as notas
/*
void visualizarNotas(int usuario_ID){
    struct aluno materiaAtual;

    char nomeMateria[30];
    cout <<"Digite o nome da materia que deseja visualizar as notas!"<<endl;
    cin  >> nomeMateria;
    cin.ignore;
    strcat(nomeMateria,".txt");

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
