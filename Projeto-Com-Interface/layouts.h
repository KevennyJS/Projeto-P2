

using namespace std;
void bordaLogin();
void logoPrincipal();
void criaMenu(int altura,int largura,int cordX,int cordY,int corFundo,int corLetra);
void boneco();
void SigaaLite();
void carregando();
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
        cout<<"";
        gotoxy(j,2);
        cout<<"";
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
void SigaaLite()
{

    system("color 8f");
    //textcolor(RED);
    int contador;
   //S
   gotoxy(8,4);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
   gotoxy(8,10);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
   gotoxy(8,16);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
   gotoxy(21,4);
   printf("\xdb");
   gotoxy(8,15);
   printf("\xdb");
   for(contador=4;contador<10; contador++)
   {
       gotoxy(8,contador);
       printf("\xdb");
   }
  for(contador=10;contador<16;contador++)
   {
       gotoxy(22,contador);
       printf("\xdb");
   }

   //*************************************************

   //I

   /*gotoxy(45,9);
   printf("\x3df\xdf\xdf\xdf\x3df\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
   gotoxy(45,27);
   printf("\x3df\xdf\xdf\xdf\x3df\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");*/
  //gotoxy(52,9);
   //printf("\xdb");

   for(contador=4; contador<16; contador++)
   {
       gotoxy(35,contador);
       printf("\xdb");
   }
   //**********************************************************

   //G
     gotoxy(48,4);
     printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
     gotoxy(48,16);
     printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
     gotoxy(55,11);
     printf("\xdf\xdf\xdf\xdf\xdf\xdf");
   for(contador=4; contador<16;contador++)
   {
       gotoxy(48,contador);
       printf("\xdb");
       //A
         gotoxy(70,contador);
         printf("\xdb            \xdb");
         gotoxy(94,contador);
         printf("\xdb           \xdb");

   }
    for(contador=11;contador<16;contador++)
   {
        gotoxy(60,contador);
       printf("\xdb");
   }
    //A
   gotoxy(71,4);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
   gotoxy(95,4);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
   gotoxy(71,9);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
   gotoxy(95,9);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");

   //L
   gotoxy(65,26);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf");

   for(contador=20; contador<26; contador++)
   {
       gotoxy(65,contador);
       printf("\xdb");
       // I
       gotoxy(75,contador);
       printf("\xdb");
       // T
       gotoxy(85,contador);
       printf("\xdb");
       //E
       gotoxy(94,contador);
       printf("\xdb");


   }
   gotoxy(86,20);
   printf("\xdf\xdf\xdf\xdf");
   gotoxy(81,20);
   printf("\xdf\xdf\xdf\xdf");
   gotoxy(75,26);
   printf("\xdf");
   gotoxy(85,26);
   printf("\xdf");
   gotoxy(94,26);
   printf("\xdf");
   gotoxy(95,20);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf");
   gotoxy(95,23);
   printf("\xdf\xdf\xdf\xdf\xdf");
   gotoxy(95,26);
   printf("\xdf\xdf\xdf\xdf\xdf\xdf");

    //LINHA
    for(contador=10;contador<60;contador++)
    {
        gotoxy(contador,21);
    printf("\xcd");
    gotoxy(contador,23);
    printf("\xcd");
    gotoxy(contador,25);
    printf("\xcd");
    }
    //gotoxy(10,22);
    //printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    //printf("\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf");
   gotoxy(20,30);
   system("pause");
}


