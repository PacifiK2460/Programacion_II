#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <windows.h>

int t,velocidad=40;

//funcion para ir a la posicion x,y
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void retrasar(unsigned int mseconpersonaje_xd){
    clock_t goal = mseconpersonaje_xd + clock();
    while (goal > clock());
}

//instrucciones en la parte de arriba de consola
void pa_arriba(){
    system("cls");
    gotoxy(10,2);
    printf("Presiona X para salir \n\tBarra espaciadora para saltar");
    gotoxy(62,2);
    printf("Puntaje : ");
    gotoxy(1,25);
    
    //Se imprime el piso
	for(int x=0;x<79;x++){
    	printf("ß");	
	}
}

//funcion para imprimir personaje
void personaje_xd(int salto=0){
    static int a=1;
 	
    if(salto==0){
    	t=0;
	}else if(salto==2){
		t--;
	}else t++;
	
	gotoxy(2, 14-t);
	printf("    ÛÛÛÛÛÛÛ  ");
	gotoxy(2, 15-t);
	printf("    ÛÛ Û ÛÛ  ");
	gotoxy(2, 16-t);
	printf("    ÛÛÛÛÛÛÛ  ");
	gotoxy(2, 17-t);
	printf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(2, 18-t);
	printf("ÛÛ ÛÛÛÛÛÛÛÛÛ ÛÛ");
	gotoxy(2, 19-t);
	printf("ÛÛ ÛÛÛÛÛÛÛÛÛ ÛÛ");
	gotoxy(2, 20-t);
	printf("ÛÛ ÛÛÛÛÛÛÛÛÛ ÛÛ");
    gotoxy(2, 21-t);
    printf("   ÛÛÛÛÛÛÛÛÛ   ");
    gotoxy(2, 22-t);
	printf("   ÛÛÛÛÛÛÛÛÛ   ");
    gotoxy(2, 23-t);
    
    //Movimientos de los pies del personaje
    if(salto==1 || salto==2){
	    printf("     ÛÛ     ÛÛ   ");
	    gotoxy(2,24-t);
	    printf("   ÛÛ     ÛÛ   ");
    }else if(a==1){
	    printf("   ÛÛ     ÛÛ   ");
	    gotoxy(2,24-t);
	    printf("     ÛÛ     ÛÛ   ");
	    a=2;
    }else if(a==2){
	    printf("   ÛÛ     ÛÛ   ");
	    gotoxy(2,24-t);
	    printf("   ÛÛ     ÛÛ   ");
	    a=1;
    }
    
	gotoxy(2,25-t);
    
    //imprimir parte del piso q pisa el personaje
	if(salto!=0){
        printf("                ");
    }else{
        printf("ßßßßßßßßßßßßßßßßß");
    }
    retrasar(velocidad);
}

//funcion para imprimir obstaculos
void obj(){
    static int x=0,scr=0;
    
    if(x==56 && t<4){
	    scr=0;
	    velocidad=40;
	    gotoxy(36,8);
	    printf("GAME OVER");
	    getch();
	    gotoxy(36,8);
	    printf("         ");
    }
    
    gotoxy(74-x,20);
    printf("Û      Û ");
    gotoxy(74-x,21);
    printf("Û      Û ");
    gotoxy(74-x,22);
    printf("ÛÛÛÛÛÛÛÛ ");
    gotoxy(74-x,23);
    printf("   ÛÛ  ");
    gotoxy(74-x,24);
    printf("   ÛÛ  ");
    x++;
    if(x==73){
	    x=0;
	    scr++;
	    gotoxy(70,2);
	    printf("     ");
	    gotoxy(70,2);
	    printf("%d",scr);
	    
		if(velocidad>20){
	    	velocidad--;
		}
    }
}

int main(){
    system("mode con: lines=29 cols=82");
    char ch;
    int i;
    pa_arriba();
    
    //para que detecte el uso de teclas
	while(true){
        while(!kbhit()){
            personaje_xd();
            obj();
        }
        ch=getch();
        
        //si se presiona espacio el personaje salta
		if(ch==' '){
            for(i=0;i<10;i++){
	            personaje_xd(1);
	            obj();
            }
            for(i=0;i<10;i++){
	            personaje_xd(2);
	            obj();
            }
            //si se presiona x el programa termina
        }else if(ch=='x'){
        	return t;
		}
    }  

	return t;
}