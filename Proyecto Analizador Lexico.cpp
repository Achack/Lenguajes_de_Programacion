#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Reservadas();//Esta funcion se encarga de buscar entre el arreglo de palabras reservadas

const char *reservadas[] = {"inicio","definir","repetir", "decimal","true","false""fin","mientras","si","sino","encender","apagar","string", "int", "boolean"}; //palabras reservadas

int IndicadorTam=sizeof(reservadas)/sizeof(char *);//tamanio de las reservadas y el tamanio de memoria de el char
int i; //Auxiliar de los ciclos
char palabraIngresada[50]; //Se encarga de guardar y almacenar los caracteres concatenados 
char temp[2]; //temporal para guardar caracteres de una cadena


int main(){
   
	printf("---- ANALIZADOR LEXICO en C ---\n");
	
	//Funcion para buscar en el arreglo de palabras reservadas
	//strcmp se encarga de comparar caracter por caracter dos Strings
	//reservadas[i] son las palabras reservadas que declaramos como variable global al inicio del programa
	//identificados es la palabra que el analizador lexico encontro
void Reservadas(){
	for(int i=0;i<IndicadorTam;i++){
		if(strcmp(reservadas[i],palabraIngresada)==0){
		
			//Contador Encender
			if(strcmp(reservadas[0],palabraIngresada)==0)
				contadorEncender++;
			
			//Contador Apagar
			if(strcmp(reservadas[1],palabraIngresada)==0)
				contadorApagado++;
			
			//Contadorr Ciclo Repetir
			if(strcmp(reservadas[4],palabraIngresada)==0)
				contadorCiclos++;
				
			//Contador Ciclo Mientras
			if(strcmp(reservadas[6],palabraIngresada)==0)
				contadorCiclos++;
			
			//Contador Condicional
			if(strcmp(reservadas[7],palabraIngresada)==0)
				contadorCondicional++;
				
			//Cuenta las palabras reservadas que encuentre
			contadorPalabrasReservadas++;
			palabraIngresada[0]='\0';
			break;
		}
		if(i==(IndicadorTam)-1){
			exit(-1);
		}
	}		
}

   
}
