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
void chamada();
int exibir_para_chamada();
void fazerchamada(char name[15]);

void criar_materia(int ID_ativo)
{
    int i;
    materias m;
    fflush(stdin);
    char nome[28]=".\\Materias\\";
    fstream materiaSaida;
    fstream leitura;
    criaMenu(1,30, 15,10, COR_DETALHE, COR_LETRA);
    gotoxy(17,10);
    cout << "Nome Da Materia: ";
    gotoxy(34,10);
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

    aluno UVazio = {0, 0, 0.0, 0.0, 0.0,0.0,0};

    for(int i = 0; i < 50; i++)
    {
        arquivo.write((const char *)(&UVazio),sizeof(aluno));
    }
    arquivo.close();
    fstream arquivoS(nome, ios::in | ios::out | ios::ate);

    aluno prof = {1, ID_ativo, 0.0, 0.0, 0.0,0.0,0};
    arquivoS.seekp((1)*sizeof(aluno));
    arquivoS.write((const char *)(&prof),sizeof(aluno));
    arquivoS.close();

    limpar_tela;
    gotoxy(17,10);
    cout << "Materia Criada Com Sucesso!!!" << endl;
    Sleep(1500);
}

void home_prof(int ID_ativo)
{
    setlocale(LC_ALL,"portuguese");
    int opcao;
    logoPrincipal();
    while (opcao != 0)
    {
        criaMenu(8,30, 15,10, COR_DETALHE, COR_LETRA);
        gotoxy(17,10);
        cout << "1- Criar Turma";
        gotoxy(17,11);
        cout << "2-Atribuir Nota";
        gotoxy(17,12);
        cout << "3-Media";
        gotoxy(17,13);
        cout << "4-Visualizar Turma";
        gotoxy(17,14);
        cout << "5-Fazer chamada";
        gotoxy(17,15);
        cout << "0-Deslogar";
        gotoxy(17,16);
        cout <<"Opção: ";
        cin >> opcao;
        //logoPrincipal();
        switch(opcao)
        {
        case 0:
            limpar_tela;
            logoPrincipal();
            gotoxy(17,5);
            msg(1,1);
            limpar_tela;
            break;
        case 1:
            limpar_tela;
            logoPrincipal();
            criar_materia(ID_ativo);
            limpar_tela;
            break;
        case 2:
            limpar_tela;
            logoPrincipal();
            atribuirNotas();
            limpar_tela;
            break;
        case 3:
            limpar_tela;
            CalculaMediaTurma();
            limpar_tela;
            break;
        case 4:
            limpar_tela;
            visualizarTurma();
            limpar_tela;
            break;
        case 5:
            limpar_tela;
            chamada();
            limpar_tela;
            break;
        }
        logoPrincipal();
    }
}

int id_para_materia()
{
    setlocale(LC_ALL,"portuguese");
    int total=0;
    struct materias m;
    fstream leitura(lista_materias, ios::in);

    if(leitura.fail())
    {
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    while(leitura &&! leitura.eof())
    {
        if(m.id_materia != 0 && m.id_materia <101)
        {
            total=total+1;
        }
        leitura.read((char*)(&m),sizeof(materias));
    }
    leitura.close();
    return total+1;
}
void selecioMateria(char nameMateria[40])   //quando for chamar essa funÃ§ao o parametro tem q ser zerado
{
    strcat(nameMateria,".//Materias//");
    char nameAux[15];
    logoPrincipal();
    criaMenu(1,55,16,6,BLACK,WHITE);
    //criaMenu(2,55,15,10, COR_DETALHE, COR_LETRA);
    //gotoxy(28,8);
    //cout<<"****ATRIBUINDO NOTAS****";
    gotoxy(17,7);
    cout << "NOME DA MATERIA A SELECIONAR: ";
    gotoxy(46,7);
    cin >> nameAux;
    strcat(nameAux,".txt");
    strcat(nameMateria,nameAux);
}

void atribuirNotas()
{
    int idDoAlunoNaDisciplina=0;
    char nameMateria[40]="";
    selecioMateria(nameMateria);

    criaMenu(2,55, 15,14, COR_DETALHE, COR_LETRA);
    do
    {
        gotoxy(17,15);
        cout << "DIGITE O ID DO ALUNO NA TURMA: ";
        gotoxy(49,15);
        cin  >> idDoAlunoNaDisciplina;
    }
    while(idDoAlunoNaDisciplina==0);

    float nota=0,nAvaliacao=0;
    aluno alunoX;
    fstream archive;
    archive.open(nameMateria,ios::ate|ios::in|ios::out);

    if(archive.fail())
    {
        cout << "ALGUM PROBLEMA COM O ARQUIVO!!! FECHE O PROGRAMA " <<endl;
    }
    archive.seekg((idDoAlunoNaDisciplina+1)*sizeof(aluno));
    archive.read((char*)(&alunoX),sizeof(aluno));
    criaMenu(1,55,15,17,BLACK,WHITE);
    criaMenu(2,55, 15,18, COR_DETALHE, COR_LETRA);
    gotoxy(17,19);
    cout << "QUAL AVALIAÇÃO DESEJA ATRIBUIR A NOTA ?(1,2,3):";
    gotoxy(65,19);
    cin >> nAvaliacao;
    if(nAvaliacao==1)
    {
        criaMenu(1,55,15,21,BLACK,WHITE);
        criaMenu(2,55, 15,22, COR_DETALHE, COR_LETRA);
        gotoxy(17,23);
        cout << "DIGITE A NOTA:" ;

        do
        {
            gotoxy(32,23);
            cin >>alunoX.nota_alunos1;
            if(alunoX.nota_alunos1 > 10)
            {
                gotoxy(30,26);
                cout << "Nota acima do permitido"<<endl;
            }
        }
        while(alunoX.nota_alunos1>10);
    }
    else if(nAvaliacao==2)
    {
        criaMenu(1,55,15,21,BLACK,WHITE);
        criaMenu(2,55, 15,22, COR_DETALHE, COR_LETRA);
        gotoxy(17,23);
        cout << "DIGITE A NOTA: " ;
        do
        {
            gotoxy(32,23);
            cin >>alunoX.nota_alunos2;
            if(alunoX.nota_alunos2 > 10)
            {
                gotoxy(30,26);
                cout << "Nota acima do permitido"<<endl;
            }
        }
        while(alunoX.nota_alunos2>10);
    }
    else if(nAvaliacao==3)
    {
        criaMenu(1,55,15,21,BLACK,WHITE);
        criaMenu(2,55, 15,22, COR_DETALHE, COR_LETRA);
        gotoxy(17,23);
        cout << "DIGITE A NOTA:" ;
        do
        {
            gotoxy(32,23);
            cin >>alunoX.nota_alunos3;
            if(alunoX.nota_alunos3 > 10)
            {
                gotoxy(30,26);
                cout << "Nota acima do permitido"<<endl;
            }
        }
        while(alunoX.nota_alunos3 > 10);
    }
    else
    {
        cout << "opção Invalida!"<<endl;
    }

    archive.seekp((idDoAlunoNaDisciplina+1)*sizeof(aluno));
    archive.write((const char*)(&alunoX),sizeof(aluno));

    archive.close();
}
void chamada()
{
    int id_selecionado = exibir_para_chamada();
    int confirm=0;
    struct materias m;
    fstream leitura(lista_materias, ios::in);

    if(leitura.fail())
    {
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }

    while(leitura &&! leitura.eof())
    {
        if(m.id_materia != 0 && m.id_materia <100)
        {
            if(m.id_materia==id_selecionado)
            {
                fazerchamada(m.nome_materia);
                confirm=1;
                break;
            }
        }
        leitura.read((char*)(&m),sizeof(materias));
    }
    if(confirm==0)
    {
        cout << "Materia inexistente" << endl;
    }
    leitura.close();
}

void fazerchamada(char name[15])
{
    int opcao;
    int cont_ids=1;
    int falta;
    aluno a;
    char nome_materia[28]=".\\Materias\\";
    strcat(nome_materia,name);
    strcat(nome_materia,".txt");

    fstream arquivoS;
    arquivoS.open(nome_materia, ios::in | ios:: out | ios::ate);

    while(arquivoS &&! arquivoS.eof())
    {
        arquivoS.seekg((cont_ids+1)*sizeof(aluno));
        arquivoS.read((char*)(&a),sizeof(aluno));


        if(cont_ids < 50 && a.id_disciplina != 0)
        {

            cout<< "Aluno: " << a.id_disciplina << endl <<endl;
            cout << "1- Presente\n2- 2 Faltas\n3- 4 Faltas\nOpção: "<<endl;
            cin >> opcao;
            if(opcao == 1)
                a.faltas = a.faltas;
            else if(opcao == 2)
                a.faltas = a.faltas + 2;
            else if(opcao == 3)
                a.faltas = a.faltas + 4;

            arquivoS.seekp((cont_ids+1) * sizeof(aluno));
            arquivoS.write((const char *) (&a), sizeof(aluno));
        }
        arquivoS.read((char*)(&a),sizeof(aluno));

        cont_ids++;
    }
    arquivoS.close();
    cout << "chamada finalizada.";
    Sleep(1000);
}

void CalculaMediaTurma()
{
    char nomeDaDiciplina[40]="";
    selecioMateria(nomeDaDiciplina);

    float *p;
    aluno alunoX;

    fstream archiveTurma;
    archiveTurma.open(nomeDaDiciplina,ios::ate|ios::in|ios::out);

    if(archiveTurma.fail())
        cout << "ALGUM PROBLEMA COM O ARQUIVO!!! FECHE O PROGRAMA " <<endl;

    p = new float [3];
    for (int i=1; i<51; i++)
    {
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
void visualizarTurma()
{
    struct aluno materiaAtual;

    char nomeMateria[40]="";
    selecioMateria(nomeMateria);

    fstream archive;
    archive.open(nomeMateria,ios::in);

    if(archive.fail())
        cout <<"Algum problema com o arquivos renicie o programa e tente novamente"<<endl;

    archive.read((char*)(&materiaAtual),sizeof(aluno));
    while(archive && !archive.eof())
    {
        if(materiaAtual.id_disciplina!=0 && materiaAtual.id_disciplina!=1)
        {
            cout <<"id_materia : " <<materiaAtual.id_disciplina<<" /// "<<" Id do aluno: "<<materiaAtual.id_usuario<<endl;
            cout << setw(10) << "Nota 1"<< setw(10) << "Nota 2"<< setw(10) << "Nota 3"<< setw(10) << "Faltas"<<"\n"
                 << setw(10) <<setprecision(2)<<materiaAtual.nota_alunos1
                 << setw(10) << materiaAtual.nota_alunos2
                 << setw(10) << materiaAtual.nota_alunos3
                 << setw(10) <<materiaAtual.faltas<<endl;
            cout<<"\nMEDIA: "<<materiaAtual.media<<endl;
        }
        archive.read((char*)(&materiaAtual),sizeof(aluno));
    }
    system("pause");
    archive.close();

}
int exibir_para_chamada()
{
    int id_selecionado;
    struct materias m;
    fstream leitura(lista_materias, ios::in);
    logoPrincipal();

    if(leitura.fail())
    {
        cout << "ALGUM PROBLEMA NO ARQUIVO...REABRA O PROGRAMA"<<endl;
    }
    gotoxy(1,5);
    cout << "=================================================";
    gotoxy(1,6);
    cout << "================LISTA DE MATERIAS================";
    gotoxy(1,7);
    cout << "=================================================";

    gotoxy(1,8);
    while(leitura &&! leitura.eof())
    {
        if(m.id_materia > 0 && m.id_materia <100 && m.nome_materia != "")
        {
            cout << setw(3) << m.id_materia << setw(2) << "|"
                 << setw(15) << m.nome_materia << endl;
        }
        leitura.read((char*)(&m),sizeof(materias));
    }
    leitura.close();
    cout << "================================================="<<endl;

    cout << "ID da materia: ";
    cin >> id_selecionado;
    cout <<endl;
    return id_selecionado;
}
