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
#include <windows.h>
#define COR_CABECALHO LIGHTRED
#define COR_CORPO LIGHTGRAY
#define COR_ALERTA LIGHTRED
#define COR_LETRA BLACK
#define COR_DETALHE CYAN
#define COR_FUNDO RED

using namespace std;                                           // EDITANDO
void logoPrincipal();
void criaMenu(int altura,int largura,int cordX,int cordY,int corFundo,int corLetra);
void realizar_matricula(int usuario_ID);
int exibir_materias();
void visualizarNotas(int usuario_ID);
void cadastrar_na_materia(int id_aluno,char name[15]);
int id_na_materia(char nome_materia[28]);

void home_aluno(int usuario_ID){
    setlocale(LC_ALL,"portuguese");
    int opcao;

    while(opcao !=0 ){
        system("cls");
        logoPrincipal();
        criaMenu(2,30,15,5, COR_DETALHE,COR_LETRA);
        gotoxy(17,5);
        cout << "===========================";
         gotoxy(17,6);
        cout << "===========ALUNO===========";
         gotoxy(17,7);
        cout << "===========================";
        criaMenu(8,30, 15,10, COR_DETALHE, COR_LETRA);
        gotoxy(17,10);
        cout << "1-REALIZAR MATRICULA";
        gotoxy(17,11);
        cout << "2-VER NOTA";
        gotoxy(17,12);
        cout << "0-DESLOGAR";
        gotoxy(17,13);
        cout << "#OPÇÃO: ";
        gotoxy(26,13);
        cin >> opcao;

        switch(opcao){
            case 1:
                system("cls");
                realizar_matricula(usuario_ID);
                break;
            case 2:
                visualizarNotas(usuario_ID);
                break;
            case 0:

                limpar_tela;
                logoPrincipal();
                gotoxy(3,8);
                msg(1,1);
                break;
        }
    }
        limpar_tela;
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
            if(m.id_materia==id_selecionado){ // se o id escolhido pelo usuÃ¡rio estiver na lista de materias disponiveis
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

    aluno add = {id_materia,id_aluno,0.0,0.0,0.0,0.0,0};

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

//visualizarNotas(int usuario_ID); //tem que testar dps quando comeÃ§arem a botar nota nas parada

// aqui o aluno vai digitar o nome da "materia" para olhar as notas

void visualizarNotas(int usuario_ID){
    struct aluno materiaAtual;

    char nomeMateria[40]="";
    selecioMateria(nomeMateria);

    fstream archive;
    archive.open(nomeMateria,ios::in);

    if(archive.fail())
    cout <<"Algum problema com o arquivos reinicie o programa e tente novamente"<<endl;
    criaMenu(1,10,1,10, COR_DETALHE, COR_LETRA);
    archive.read((char*)(&materiaAtual),sizeof(aluno));
    while(archive && !archive.eof()){
        if(materiaAtual.id_usuario == usuario_ID ){
                gotoxy(1,10);
            cout << setw(10) << "Nota 1"<< setw(10) << "Nota 2"<< setw(10) << "Nota 3"<<"\n"
                 << setw(10) <<setprecision(2)<< materiaAtual.nota_alunos1
                 << setw(10) << materiaAtual.nota_alunos2
                 << setw(10) << materiaAtual.nota_alunos3 <<endl;

                 cout<<"\nMÉDIA : "<<materiaAtual.media;
                 cout<<"\t\tFALTAS: "<<materiaAtual.faltas<<endl;

        }
        archive.read((char*)(&materiaAtual),sizeof(aluno));
    }
    system("pause");
    archive.close();

}

