#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AnalizadorDeCaracter(char letra); //Funcion que leera los caracteres
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

void AnalizadorDeCaracter(char letra){
	if(letra==32||letra=='}'||letra=='{'
		||letra=='('||letra==')'||letra==';'){
			Estados();
		}
		
		if( letra>='A' && letra<='Z' ){
			if(Estado==q0){
				Estado=q1;
			}else if(Estado==q1||Estado==q2){
				Estado=q2;
			}
			else if(Estado!=q0 && Estado!=q1 && Estado!=q2){
				exit(-1);
			}
		}
		
		if(letra>='a' && letra<='z'){
			if(Estado==q0){
				temp[0]=letra; 
				strcat(palabraIngresada,temp); 
				Estado=q3;
			}else if(Estado==q1||Estado==q2){
				Estado=q2;
			}
			else if(Estado==q3){
				temp[0]=letra; 
				strcat(palabraIngresada,temp);
				Estado=q3;}
			else{
				exit(-1);
			}
		}
		if(letra<='9'&&letra>='0'){
			if(Estado==q0){
				Estado=q4;
			}else if(Estado==q4||Estado==q5){
				Estado=q5;
			}else if(Estado==q13||Estado==q6){
				Estado=q6;
			}else if(Estado==q1||Estado==q2){
				Estado=q2;
			}else if(Estado==q7){
				Estado=q4;
			}else{
				exit(-1);
			}
		}
		if(letra=='+'){
			if(Estado==q0){
				Estado=q8;
			}else if(Estado==q8){
				Estado=q17;
			}
		}
		
		if(letra=='.'){
			if((letra)<'1' || (letra)>='9'){
				Estado=q19;
			}else{
				if(Estado==q4||Estado==q5&&((letra)=='1'||(letra)=='2'
				||(letra)=='3'||(letra)=='4'||(letra)=='5'||(letra)=='6'
				||(letra)=='7'||(letra)=='8'||(letra)=='9')){
					Estado=q20;
				}
				else if(Estado!=q4 && Estado!=q5){
					exit(-1);
				}
			}
		}
		if(letra=='^'){
			if(Estado==q0){
				Estado=q18;
			}
			else{
				exit(-1);
			} 
		}
		
		if(letra=='-'){
			if(Estado==q0){
				Estado=q7;
			}else if(Estado==q12){
				Estado=q10;}
		}	else if(Estado==q7){
			Estado=q17;
		}
		
		if(letra=='='){
			if(Estado==q0){
				Estado=q9;
			}else if(Estado==q18){
				Estado=q11;
			}
		}else if(Estado==q12){
			Estado=q16;
		}else if(Estado==q13){
			Estado=q15;
		}
		
		
		if(letra=='/'||letra=='*'){
			if(Estado==q0){
				Estado=q18;
			}else{
				exit(-1);
			}
		}
		
		if(letra=='<'){                
			if(Estado==q0){
				Estado=q12;
			}else{
				exit(-1);
			}
		}
		if(letra=='>'){   
			if(Estado==q0){
				Estado=q14;
			}else{
				exit(-1);
			}
		}	
		
		
		if(letra=='!'){
			if(Estado==q0){
				Estado=q18;
			}else{
				exit(-1);
			} 
		}

} 

//Funcion que va buscar las palabras reservadas
void Reservadas(){
	for(int i=0;i<IndicadorTam;i++){
		if(strcmp(reservadas[i],palabraIngresada)==0){

			//Contador Encender
			if(strcmp(reservadas[0],palabraIngresada)==0)
				contadorEncender++;

			//Contador Apagar
			if(strcmp(reservadas[1],palabraIngresada)==0)
				contadorApagado++;

			//Contador Ciclo Repeticion
			if(strcmp(reservadas[4],palabraIngresada)==0)
				contadorCiclos++;

			//Contador Ciclo Mientras
			if(strcmp(reservadas[6],palabraIngresada)==0)
				contadorCiclos++;

			//Contador Condicional
			if(strcmp(reservadas[7],palabraIngresada)==0)
				contadorCondicional++;

			//Cuenta las palabras reservadas que encuentro
			contadorPalabrasReservadas++;
			palabraIngresada[0]='\0';
			break;
		}
		if(i==(IndicadorTam)-1){
			exit(-1);
		}
	}

	

   
}
//Funcion que se encarga de analizar caracter a carater y decide a que tipo de elemento pertenece
void Estados(){
	
	switch(Estado){
			case 1:contadorVariables++; 	        // Suma variables A ... Z					//Estado vuelve ser 0
			break;
			case 2:contadorVariables++; 	        //  A ... Z	 a ... z  0 ... 9	
			break;
			case 3: Reservadas();		        // Palabras reservadas
			break;
			case 4:contadorNumeros++; 		//Numeros 0 ... 9
			break;
			case 5:contadorNumeros++; 		// 0 ... 9
			break;
			case 6:contadorNumeros++; 		// 0 ... 9
			break;
			case 7:contadorSignos++;		// -
			break;
			case 8:contadorSignos++; 		// +
			break;
			case 9:contadorSimbolos++; 		// =
			break;
			case 10:contadorSignos++; 		// -
			break;
			case 11:contadorSimbolos++; 		// =
			break;
			case 12:contadorSimbolos++; 		// <
			break;
			case 14:contadorSimbolos++; 		// >
			break;
			case 15:contadorSimbolos++; 		// = 
			break;
			case 16:contadorSimbolos++; 		// =;
			break;
			case 17:contadorSignos++; 		// - +
			break;
			case 18:contadorSignos++; 		//  / * ^ !
			break;
			case 19:contadorSimbolos++; 		// . \n \t etc... 
			break;
			case 20:contadorNumeros++; 		// .   0 ... 9				Para decimal
			break;
			default:
				break;
			}	
			
			Estado = q0;	
}

