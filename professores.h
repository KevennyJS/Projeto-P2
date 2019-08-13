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

void selecioMateria(char nameMateria[40]);
int id_para_materia();
void atribuirNotas();
void CalculaMediaTurma();
void visualizarTurma();

void criar_materia(int ID_ativo){
    int i;
    materias m;
    fflush(stdin);
    char nome[28]=".\\Materias\\";
    fstream materiaSaida;
    fstream leitura;

    cout << "Nome Da Materia: ";
    cin >> m.nome_materia;

    m.id_materia = id_para_materia();

    materiaSaida.open(".\\Materias\\MATERIAS.txt", ios::out | ios::in | ios::ate);
    materiaSaida.seekp((m.id_materia)*sizeof(materias));
    materiaSaida.write((const char *)(&m),sizeof(materias));
    materiaSaida.close();

    ofstream arquivo;
    strcat(nome,m.nome_materia);
    strcat(nome,".txt");
    arquivo.open(nome, ios::out);

    aluno UVazio = {0, 0, 0.0, 0.0, 0.0,0.0};

    for(int i = 0; i < 50; i++){
        arquivo.write((const char *)(&UVazio),sizeof(aluno));
    }
    arquivo.close();
    fstream arquivoS(nome, ios::in | ios::out | ios::ate);

    aluno prof = {1, ID_ativo, 0.0, 0.0, 0.0,0.0};
    arquivoS.seekp((1)*sizeof(aluno));
    arquivoS.write((const char *)(&prof),sizeof(aluno));
    arquivoS.close();

    limpar_tela;
    cout << "Materia Criada Com Sucesso!!!" << endl;
    Sleep(1500);
}

void home_prof(int ID_ativo){
    setlocale(LC_ALL,"portuguese");
    int opcao;

    while (opcao != 0){
        cout << "1- Criar Turma" << endl;
        cout << "2-Atribuir Nota" << endl;
        cout << "3-Media" << endl;
        cout << "4-Visualizar Turma" << endl;
        cout << "0-Deslogar" << endl;
        cout <<"Opção: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                limpar_tela;
                criar_materia(ID_ativo);
                limpar_tela;
                break;
            case 2:
                limpar_tela;
                atribuirNotas();
                break;
            case 3:
                CalculaMediaTurma();
                break;
            case 4:
                visualizarTurma();
                break;
            case 5:

                break;
        }
    }
}

int id_para_materia(){
    setlocale(LC_ALL,"portuguese");
    int total=0;
    struct materias m;
    fstream leitura(lista_materias, ios::in);

    if(leitura.fail()){
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    while(leitura &&! leitura.eof()){
        if(m.id_materia != 0 && m.id_materia <101){
            total=total+1;
        }
        leitura.read((char*)(&m),sizeof(materias));
    }
    leitura.close();
    return total+1;
}
void selecioMateria(char nameMateria[40]){  //quando for chamar essa funÃ§ao o parametro tem q ser zerado
    strcat(nameMateria,".//Materias//");
    char nameAux[15];
    cout << "Nome da Matéria a Selecionar:"<<endl;
    cin >> nameAux;
    strcat(nameAux,".txt");
    strcat(nameMateria,nameAux);
    //cout <<nameMateria<<endl;
}


void atribuirNotas(){
    int idDoAlunoNaDisciplina;
    char nameMateria[40]="";
    selecioMateria(nameMateria);

    do{
    cout << "Digite o id do aluno na turma"<<endl;
    cin  >> idDoAlunoNaDisciplina;
    }while(idDoAlunoNaDisciplina==0);

    float nota,nAvaliacao;
    aluno alunoX;
    fstream archive;
    archive.open(nameMateria,ios::ate|ios::in|ios::out);

    if(archive.fail())
        cout << "ALGUM PROBLEMA COM O ARQUIVO!!! FECHE O PROGRAMA " <<endl;

    archive.seekg((idDoAlunoNaDisciplina)*sizeof(aluno));
    archive.read((char*)(&alunoX),sizeof(aluno));

    cout << "Qual avaliação deseja atribuir a nota ?(1,2,3)"<<endl;
    cin >> nAvaliacao;
    if(nAvaliacao==1){
        cout << "Digite a nota:" ;
        cin >>alunoX.nota_alunos1;
    }else if(nAvaliacao==2){
        cout << "Digite a nota:" ;
        cin >>alunoX.nota_alunos2 ;
    }else if(nAvaliacao==3){
        cout << "Digite a nota:" ;
        cin >>alunoX.nota_alunos3;
    }else{
        cout << "opção Invalida!"<<endl;
    }

    archive.seekp((idDoAlunoNaDisciplina)*sizeof(aluno));
    archive.write((const char*)(&alunoX),sizeof(aluno));

    archive.close();
}



void CalculaMediaTurma(){
    char nomeDaDiciplina[40]="";
    selecioMateria(nomeDaDiciplina);

    float *p;
    aluno alunoX;

    fstream archiveTurma;
    archiveTurma.open(nomeDaDiciplina,ios::ate|ios::in|ios::out);

    if(archiveTurma.fail())
        cout << "ALGUM PROBLEMA COM O ARQUIVO!!! FECHE O PROGRAMA " <<endl;

    p = new float [3];
    for (int i=1;i<51;i++){
    archiveTurma.seekg((i)*sizeof(aluno));
    archiveTurma.read((char*)(&alunoX),sizeof(aluno));

        alunoX.media=0;

        p[0] = alunoX.nota_alunos1;
        p[1] = alunoX.nota_alunos2;
        p[2] = alunoX.nota_alunos3;

        alunoX.media = alunoX.media + *(p);
        alunoX.media = alunoX.media + *(p+1);
        alunoX.media = alunoX.media + *(p+2);

        alunoX.media = alunoX.media/3;

    archiveTurma.seekp((i)*sizeof(aluno));
    archiveTurma.write((const char*)(&alunoX),sizeof(aluno));

    }

        archiveTurma.close();
}
void visualizarTurma(){
    struct aluno materiaAtual;

    char nomeMateria[40]="";
    selecioMateria(nomeMateria);

    fstream archive;
    archive.open(nomeMateria,ios::in);

    if(archive.fail())
    cout <<"Algum problema com o arquivos renicie o programa e tente novamente"<<endl;

    archive.read((char*)(&materiaAtual),sizeof(aluno));
    while(archive && !archive.eof()){
        if(materiaAtual.id_disciplina!=0){
            cout <<"id_materia : " <<materiaAtual.id_disciplina<<"///"<<" Id do aluno: "<<materiaAtual.id_usuario<<endl;
            cout << setw(10) << "Nota 1"<< setw(10) << "Nota 2"<< setw(10) << "Nota 3"<<"\n"
                 << setw(10) <<setprecision(1)<<setiosflags(ios::showpoint) << materiaAtual.nota_alunos1
                 << setw(10) << materiaAtual.nota_alunos2
                 << setw(10) << materiaAtual.nota_alunos3 <<endl;
                cout<<"\nMEDIA: "<<materiaAtual.media<<endl;
        }
        archive.read((char*)(&materiaAtual),sizeof(aluno));
    }
    system("pause");
    archive.close();

}
