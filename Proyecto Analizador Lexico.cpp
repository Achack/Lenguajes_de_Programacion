#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PalabrasReservadas();//Esta funcion se encarga de buscar entre el arreglo de palabras reservadas

const char *Palabrasreservadas[] = {"inicio","definir","repetir", "decimal","true","false""fin","mientras","si","sino","encender","apagar","string", "int", "boolean"}; //palabras reservadas

int IndicadorTam=sizeof(Palabrasreservadas)/sizeof(char *);//tamanio de las reservadas y el tamanio de memoria de el char
int i; //Auxiliar de los ciclos
char palabraIngresada[50]; //Se encarga de guardar y almacenar caracteres
char temp[2]; //temporal para guardar caracteres de una cadena
//Estos son los contadores de los elementos de la tabla
int contVariables=0;
int contrNumeros=0;
int contPalabrasReservadas=0;
int contSimbolos=0;
int contSignos=0;
int contApagado=0;
int contCiclos=0;
int contCondicional=0;
int contEncender=0;


int main(){
   
	printf("---- ANALIZADOR LEXICO en C ---\n");
	
	//Funcion para buscar en el arreglo de palabras reservadas
	//strcmp se utiliza para comparar los caracteres de dos Strings
	//reservadas[i] son las palabras reservadas que declaramos como variable global al inicio del programa
	//identificados es la palabra que el analizador lexico encontro
}
void PalabrasReservadas(){
	
	for(int i=0;i<IndicadorTam;i++){
		if(strcmp(Palabrasreservadas[i],palabraIngresada)==0){
		
			//Contador Encender
			if(strcmp(Palabrasreservadas[0],palabraIngresada)==0)
				contEncender++;
			
			//Contador Apagar
			if(strcmp(Palabrasreservadas[1],palabraIngresada)==0)
				contApagado++;
			
			//Contadorr Ciclo Repetir
			if(strcmp(Palabrasreservadas[4],palabraIngresada)==0)
				contCiclos++;
				
			//Contador Ciclo Mientras
			if(strcmp(Palabrasreservadas[6],palabraIngresada)==0)
				contCiclos++;
			
			//Contador Condicional
			if(strcmp(Palabrasreservadas[7],palabraIngresada)==0)
				contCondicional++;
				
			//Cuenta las palabras reservadas que encuentre
			contPalabrasReservadas++;
			palabraIngresada[0]='\0';
			break;
		}
		if(i==(IndicadorTam)-1){
			exit(-1);
		}
	}		
}

