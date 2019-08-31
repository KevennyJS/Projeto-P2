

using namespace std;
void bordaLogin();
void logoPrincipal();
void criaMenu(int altura,int largura,int cordX,int cordY,int corFundo,int corLetra);
void boneco();
void linhaHorizontal(int linha){
      int i;
       for (i=1;i<80;i++){
          gotoxy(i,linha);
          cout<<"_";
       }
}

void criaMenu(int altura,int largura,int cordX,int cordY,int corFundo,int corLetra){
int i,j;

    for (i=0;i<=altura;i++){
          for (j=0;j<=largura;j++){
            textbackground(corFundo);
            gotoxy(cordX+j,cordY+i);
            cout<<" ";
          }
    }
  textcolor(corLetra);
}


void logoPrincipal(){
    int i;
    textcolor(COR_LETRA);
    textbackground(COR_CORPO);
    clrscr();
    for (i=1;i<=80;i++){
        gotoxy(i,1);
        textbackground(COR_CABECALHO);
        cout<<" ";
        gotoxy(i,2);
        textbackground(COR_CABECALHO);
        cout<<" ";
        gotoxy(i,3);
        textbackground(COR_CABECALHO);
        cout<<" ";
    }
    gotoxy(27,2);
    cout<<"S I G A A   L I T E";
    //gotoxy(43,2);
    //cout<<"PESTISCARIA";
    //gotoxy(38,2);
    //cout<<" & ";
    textbackground(COR_CORPO);

}
void logoEntrada(){
    int i,j;
    for (i=1;i<=80;i++){
        gotoxy(i,1);
        textbackground(COR_CABECALHO);
        cout<<" ";
        gotoxy(i,2);
        textbackground(COR_CABECALHO);
        cout<<" ";
        gotoxy(i,3);
        textbackground(COR_CABECALHO);
        cout<<" ";
    }
    for (i=1,j=70;i<28 && j>38;i++,j--){
        gotoxy(i-1,2);
        clreol();
        gotoxy(i,2);
        cout<<"CHOPPERIA";
        gotoxy(j,2);
        cout<<"PESTISCARIA";
        Sleep(35);

    }

    gotoxy(38,2);
    cout<<" & ";
    textbackground(COR_CORPO);

}
void bordaLogin(){
  int i,j;
    for (i=23;i<=58;i++){
        for(j=6;j<20;j++){
          gotoxy(i,j);
          textbackground(WHITE);
          cout<<" ";
        }
    }
    textcolor(BLACK);
    gotoxy(35,7);
    cout<<"TELA LOGIN";
    textcolor(WHITE);
    for(i=38;i<55;i++){
        for(j=10;j<=16;j++){
          if (j==13)
            continue;
          gotoxy(i,j);
          textbackground(COR_DETALHE);
          cout<<" ";
          gotoxy(i,j);
          textbackground(COR_DETALHE);
          cout<<" ";

        }

    }

    for(i=26;i<36;i++){
        for(j=10;j<=16;j++){
             if (j==13)
            continue;
          gotoxy(i,j);
          textbackground(COR_DETALHE);
          cout<<" ";
          gotoxy(i,j);
          textbackground(COR_DETALHE);
          cout<<" ";
        }

    }

}

void bordaPadraoFunc(){
  int i,j;
  for (i=20;i<60;i++){
      //cabeçalho MENU
      gotoxy(i,9);
      cout<<"-";

      gotoxy(i,11);
      cout<<"-";

      gotoxy(i,20);
      cout<<"-";

      //fecha a parte inferior da tabela
      for(j=8;j<=20;j++){
          gotoxy(20,j);
          cout<<"|";
          gotoxy(60,j);
          cout<<"|";
      }

  }
}


void boneco()

{    int i;
      //logoPrincipal();
    //while(i<4){
            // system("cls");
             gotoxy(17,8);
             printf("  O ");
             gotoxy(17,9);
             printf(" /|\\ ");
             gotoxy(17,10);
             printf("  |");
             gotoxy(17,11);
             printf(" / \\");
             Sleep(250);
             //system("cls");
             gotoxy(25,8);
             printf("  O/ ");
             gotoxy(25,9);
             printf(" /| ");
             gotoxy(25,10);
             printf("  |");
             gotoxy(25,11);
             printf(" / \\ ");
             Sleep(250);
            // i++;
            // }


}


