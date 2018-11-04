//JUEGO 2 (SNAKE).
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

#include<gotoxy.h>
#include<ocultarcursor.h>

#define ARRIBA 72     //NUMERO ASOCIADO A LA FLECHA ARRIBA DEL TECLADO
#define IZQUIERDA 75  //NUMERO ASOCIADO A LA FLECHA IZQUIERDA DEL TECLADO
#define DERECHA 77    //NUMERO ASOCIADO A LA FLECHA DERECHA DEL TECLADO
#define ABAJO 80      //NUMERO ASOCIADO A LA FLECHA ABAJO DEL TECLADO
#define ESC 27        //NUMERO AOCIADO A LA TECLA ESC

int cuerpo[200][2];

int n=1;
int tam=10;
int x=10,y=12;
int dir=3;
int xc=30,yc=15;
int velocidad=100, h=1;
int puntaje=0;

char tecla;

void pintar_limites()
{
     //LIMITES ORIZONTALES
     for(int i=2;i<78;i++)
     {
             gotoxy(i,3);
             printf("%c",205);
             gotoxy(i,23);
             printf("%c",205);
             }//FOR LIMITES ORIZONTALES
     //LIMITES VERTICALES
     for(int i=4;i<23;i++)
     {
             gotoxy(2,i);
             printf("%c",186);
             gotoxy(77,i);
             printf("%c",186);
             }//FOR LIMITES VERTICALES
     //ESQUINAZ
     gotoxy(2,3);
     printf("%c",201);
     gotoxy(77,3);
     printf("%c",187);
     gotoxy(2,23);
     printf("%c",200);
     gotoxy(77,23);
     printf("%c",188);
     }//VOID PINTAR_LIMITES()

void guardar_posicion()
{
     cuerpo[n][0]=x;
     cuerpo[n][1]=y;
     n++;
     if(n==tam) n=1;
     }//VOID GUARDAR_CUERPO()

void pintar_cuerpo()
{
     for(int i=1;i<tam;i++)
     {
             gotoxy(cuerpo[i][0],cuerpo[i][1]);
             printf("*");
             }
     }//VOID PINTAR_CUERPO

void borrar_cuerpo()
{
             gotoxy(cuerpo[n][0],cuerpo[n][1]);
             printf(" ");
     }//VOID BORRAR_CUERPO

void teclas_mover()
{
     if(kbhit())
     {
      tecla=getch();
      switch(tecla)
      {
                   case ARRIBA:
                   if(dir!=2)
                   dir=1;
                   break;
                   case ABAJO:
                   if(dir!=1)
                   dir=2;
                   break;
                   case DERECHA:
                   if(dir!=4)
                   dir=3;
                   break;
                   case IZQUIERDA:
                   if(dir!=3)
                   dir=4;
                   break;
                   }//SWITCH(TECLA)
     }//IF(KBHIT())
     }//VOID TECLAS_MOVER()
     
void cambiar_velocidad()
{
     if(puntaje==h*20)
     {
                      velocidad -=10;
                      h++;
                      }//IF (PUNTAJE)
     }//VOID CAMBIAR_VELOCIDAD()
     
void comer()
{
     if(x==xc&&y==yc)
     {
                     xc=(rand()%73)+4;
                     yc=(rand()%19)+4;
                     tam++;
                     puntaje+=10;
                     gotoxy(xc,yc);
                     printf("%c",4);
                     cambiar_velocidad();
                     }//IF(X==XC&&Y==XY)
 }//VOID COMER()
 
 bool game_over()
 {
      if(y==3||y==23||x==2||x==77) return false;
      for(int j=tam-1;j>0;j--)
      {
              if(cuerpo[j][0]==x&&cuerpo[j][1]==y)
              return false;
              }//FOR CHOQUE CUERPO.
      return true;
  }//BOOL GAME_OVER()

void puntos()
{
     gotoxy(60,1);
     printf("puntos: %d",puntaje);
     }//VOID PUNTOS

int main()
{
    SetConsoleTitle("SNAKE");
    /*
    gotoxy(2,24);
    printf("LAMOS INDUSTRIES %c. COPYRIGHT %c 2014.",169,184);
    gotoxy(65,24);
    printf("V 1.0.0");
    gotoxy(2,1);
    printf("MUEVES LA SERPIENTE CON LAS FLECHAS DEL TECLADO");
    */
    pintar_limites();
    ocultarcursor();
    
    gotoxy(xc,yc);
    printf("%c",4);
    
    while(tecla!=ESC&&game_over())
    {
                    borrar_cuerpo();
                    guardar_posicion();
                    pintar_cuerpo();
                    puntos();
                    
                    comer();
                    
                    teclas_mover();
                    teclas_mover();
                    
                    if(dir==1)y--;
                    if(dir==2)y++;
                    if(dir==3)x++;
                    if(dir==4)x--;
                    Sleep(velocidad);
    }//WHILE(TECLA!=ESC)
    
    getch();
}//INT MAIN()
