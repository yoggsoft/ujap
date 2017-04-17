//REALIZADOR POR:
//Luzmar Marin C.I.: 17.258.874.
//Raul Fung C.I: 16.399.723.

//---------- LIBRERIAS UTILIZADAS ---------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <math.h>

//---------- CONSTANTES DEFINIDAS ---------------------------------------------
//-- CONSTANTES ---- //-- DESCRIPCION DE SU USO -------------------------------

#define ITMAX 1000     //-- maximo de iteraciones
#define GAP 50       //-- % de individuos a ser reemplazados en cada generacion
#define MAX 29       //-- tamaño matriz de adyacencia y vector individuo
#define N 100        //-- tamaño de la poblacion
#define n 4          //-- cantidad de candidatos a padre
#define PM 0.01      //-- probabilidad de mutacion (1/N)
#define PC 0.8       //-- probabilidad de cruce

//---------- FUNCIONES --------------------------------------------------------
//-- PROTOTIPOS ------------------- //-- DESCRIPCION DE SU USO ----------------
void popaux();                      //-- genera una poblacion aleatoria
void alg();				     	         //-- implementacion del algoritmo genetico
int costo(int v[]);                 //-- evaluar el costo del recorrido
int cost(int v[]);				      //-- funcion de aptitud
void cruce();                       //-- funcion de cruce
void cambio(int hijo[],int papa[],int p1,int p2);
void rfinales();                    //-- busca el mejor individuo de toda la ejecucion
void mutacion(int x);               //-- funcion de mutacion
void pop();	         			      //-- inicializa aleatoriamente la poblacion
void ordenamiento();   			      //-- ordena la matriz de poblacion
void torneo();                      //-- elije un padre entre n posibles candidatos
void vectoralea();   			      //-- genera un individuo de forma aleatoria


//---------- VARIABLES GLOBALES -----------------------------------------------
//-- VARIABLES -------------------- //-- DESCRIPCION DE SU USO ----------------
int sola[MAX]; 	         		   //-- mejor individuo actual
int msol[MAX];                      //-- mejor individuo de toda la ejecucion
int costos_aux[N];					   //-- vector de fitness auxiliar
int costo_hijo1;                    //-- calculo del costo de hijo 1
int costo_hijo2;                    //-- calculo del costo de hijo 2
int costos[N];					         //-- vector de fitness
int fsola;                          //-- fitness mejor individuo actual
int fmsol=5000;                     //-- fitness mejor individuo
int hijo1[MAX];                     //--
int hijo2[MAX];                     //--
int ite=0;                          //--
int individuo[MAX];                 //-- individuo de la poblacion
int matriz[MAX][MAX];               //-- matriz que contiene el archivo txt
int poblacion_aux[N][MAX];          //-- matriz de poblacion auxiliar
int poblacion[N][MAX];              //-- matriz de poblacion
int mpapa1_costo;                   //-- costo del padre 1
int mpapa2_costo;                   //-- costo del padre 2
int mpapa1[MAX];                    //-- padre 1
int mpapa2[MAX];                    //-- padre 2
int vect[MAX];                      //--
int vect_n1[MAX];                   //--
int vect_n2[MAX];                   //--


//---------- CARGA DEL ARCHIVO TXT --------------------------------------------
void carga(){
     FILE *archivo;
     int i=0,j=0,x1,cont=0;
     if((archivo=fopen("TSP29.txt","r"))==NULL){
     		cout<<"Carga Fallida";
         exit(0);
     }
	  for (i=0;i<MAX;i++){
     		for (j=cont;j<MAX;j++){
         	if (i==j){
	         	matriz[i][i]= 0;
            }
            else{
               fscanf (archivo, "%i", &x1);
             	matriz[i][j]= x1;
      	     	matriz[j][i]= x1;
            }
         }
         cont++;
     }
     fclose(archivo);

	for (i=0;i<=4;i++)
		{
			for (j=0;j<=4;j++)
				printf("%i\t",matriz[i][j]);
			printf("...%i\n",matriz[i][28]);
		}
		printf(".\t.\t.\t.\t.\n");
		printf(".\t.\t.\t.\t.\n");
		printf(".\t.\t.\t.\t.\n");
		printf("%i\t%i\t%i\t%i\t%i",matriz[0][28],matriz[1][28],matriz[2][28],matriz[3][28],matriz[4][28]);
}

//---------- GENERA UN VECTOR INICIAL DE FORMA ALEATORIA ----------------------
void vectoralea(){
   int i,aux,j=0,bandera;
   randomize();
   do{
      bandera=0;
      aux=random(MAX);
      for(i=0;i<j;i++){
         if(aux == vect[i])
            bandera=1;
      }
      if( bandera==0){
         vect[j]=aux;
         j++;
      }
	}while(j<MAX);
}

//---------- POBLACION --------------------------------------------------------
void pop(){
   int aux[MAX],cont=0,j,i;
   do{
      vectoralea();
      for(i=cont;i<N;i++){
         for(j=0;j<MAX;j++)
            poblacion[i][j]=vect[j]; //100 x 28
      }
      cont++;
   }while(cont!=N);
   for(i=0;i<N;i++){
      for(j=0;j<MAX;j++){
         aux[j]=poblacion[i][j];
      }
      costos[i]=cost(aux);
   }
}

//---------- CALCULA LOS RESULTADOS FINALES -----------------------------------
void rfinales(){
   int i;
   for(i=0;i<MAX;i++){
      sola[i]=poblacion[0][i];
   }
   fsola=costos[0];
   if(fsola<fmsol){
      for(i=0;i<MAX;i++){
         msol[i]=sola[i];
      }
      fmsol=fsola;
   }
}

//---------- ORDENAMIENTO -----------------------------------------------------
void ordenamiento(){
   int i,j,temp1,temp2;
   for(int v=0;v<N;v++){
      for(i=0;i<N-1;i++){
   	   if(costos[i]>costos[i+1]){
      	   temp1=costos[i+1];
            costos[i+1]=costos[i];
            costos[i]=temp1;
            for(j=0;j<=MAX;j++){
         	   temp2=poblacion[i+1][j];
               poblacion[i+1][j]=poblacion[i][j];
               poblacion[i][j]=temp2;
            }
         }
      }
   }
}

//---------- TORNEO -----------------------------------------------------------
void torneo(){
   int spapa[n][MAX],costo_spapa[n];
   int aux[n],vic,correc;
   for(int i=0;i<n;i++){
   	for(int j=0;j<n-1;j++){
      	for(int v=1;v<n;v++){
   			aux[i]=random(N);
      		if(aux[j]==aux[v])
      			aux[i]=random(N);
         }
      }
   }
   for(int i=0;i<n;i++){
      vic=aux[i];
      for(int j=0;j<MAX;j++){
      	spapa[i][j]=poblacion[vic][j];
         costo_spapa[i]=costos[vic];
      }
   }
   for (int i=0; i<n-1; i++){
   	for (int j=1; j<n; j++){
      	if(costo_spapa[i]<costo_spapa[j])
         	correc=i;
      }
   }
   for(int j=0; j<MAX; j++){
   	mpapa1[j]=spapa[correc][j];
	}
   mpapa1_costo=costo_spapa[correc];
   printf("\nMpapa 1: ");
   printf("%d",mpapa1_costo);
   for(int j=0; j<MAX; j++){
   	mpapa2[j]=spapa[correc][j];
   }
   mpapa2_costo=costo_spapa[correc];
   printf("\nMpapa 2: ");
   printf("%d",mpapa2_costo);
}

//---------- CRUCE ------------------------------------------------------------
void cruce(){
 	int i,p1,p2,band;
	//inicializar el vectores hijos
	for(i=0;i<MAX;i++){
	 	hijo2[i]=0;
      hijo1[i]=0;
   }
	randomize();
	do{
   	band=0;
   	p1=random(MAX);
		p2=random(MAX);
   	if(p1!=p2){
   		if((p1<p2)&&(p1>0)){
         	if(p2<MAX-1)
      			band=1;
      	}
   	}
	}while(band==0);
	for(i=p1;i<=p2;i++){
   	hijo1[i]=mpapa1[i];
    	hijo2[i]=mpapa2[i];
   }
	cambio(hijo1,mpapa2,p1,p2);
	cambio(hijo2,mpapa1,p1,p2);
}

//---------- CAMBIO -----------------------------------------------------------
void cambio(int hijo[],int papa[],int p1,int p2){
	int t,i,k,j,v,cont,band;
  	t=p2+1;
  	cont=p2+1;
  	v=MAX;
  	k=MAX;
  	do{
  		for(i=cont;i<v;i++){
    		band=0;
    		for(j=p1;j<=p2;j++){
       		if(papa[i]==hijo[j])
          	   band=1;
         }
    	   if(band==0){
      	   hijo[t]=papa[i];
       	   t++;
         }
      }
  	   if(i==MAX){
   	   cont=0;
    	   v=p2;
   	}
  		if(t==MAX){
   		t=0;
    		cont=0;
    		v=p2;
    		k=p1-1;
   	}
  }while(t<=k);
}

//---------- MUTACION ---------------------------------------------------------
void mutacion(int x){
   int p1,p2,aux,band=0;
   float prob;
   randomize();
   prob=random(100);
   prob/=100;
   if(prob<PM){
      p1=random(MAX);
      p2=random(MAX);
      if(p1==p2){
         while(band==0){
            p2=random(MAX);
            if(p1!=p2)
            band=1;
         };
      }
      if(x==1){
         aux=hijo1[p1];
         hijo1[p1]=hijo1[p2];
         hijo1[p2]=aux;
      }
      if(x==2){
         aux=hijo2[p1];
         hijo2[p1]=hijo2[p2];
         hijo2[p2]=aux;
      }
   }
}

//---------- CALCULO LOS COSTOS DE UNA POSIBLE SOLUCION -----------------------


//---------- -------------------------------------------------------
void popaux(){
   for(int i=0;i<GAP;i++){
      for(int j=0;j<MAX;j++)
         poblacion_aux[i][j]=poblacion[i][j];
   	costos_aux[i]=costos[i];
   }
}

//---------- ALGORITMO GENETICO -----------------------------------------------
void alg(){
   int Ps,cont=0,a=1,b=2, i=0, j=0;
   pop();
   ordenamiento();
   do{
      Ps=random(100);
      Ps/=100;
      popaux();
      for(int i=GAP;i<N/2;i++){
         torneo();
         if(Ps<PC)
             cruce();
         else{
            for(i=0;i<MAX;i++){
               hijo1[i]=mpapa1[i];
               hijo2[i]=mpapa2[i];
            }
            costo_hijo1=mpapa1_costo;
				costo_hijo2=mpapa2_costo;
         }
         mutacion(a);
         mutacion(b);
      }
      cont++;
   }while(cont!=ITMAX);
}

//---------- PROGRAMA PRINCIPAL -----------------------------------------------
int main(){
   int i,j;
   carga();
   alg();
   rfinales();
   printf("\n\n ******************************************************************************");
   printf("\n\n                              PROYECTO REALIZADO POR: ");
   printf("\n\n ******************************************************************************");
   printf("\n\n     Luzmar Marin C.I.: 17.258.874.");
   printf("\n\n     Raul Fung C.I: 16.399.723.");
   printf("\n\n ******************************************************************************");
   printf("\n\n                              VALORES OBTENIDOS ");
   printf("\n\n ******************************************************************************");
   printf("\nVariables definidas: \n");
   printf("\n1.- GAP = %d%",GAP);
   printf("\n3.- Iteraciones = %d",ITMAX);
   printf("\n2.- Poblacion = %d individuos",N);
   printf("\n4.- Probabilidad de cruce = %.2f ",PC);
   printf("\n5.- Probabilidad de mutacion = %.2f ",PM);
   printf("\n\n\nMejor Solucion Encontrada: \n");
   printf("\n\nRecorrido: ");
   for(int i=0;i<MAX;i++){
	   printf(" %d ",sola[i]);
   }
   printf("\n\nDistancia o fitness = %d",fsola);
   printf("\n\n ******************************************************************************");
   getch();
   exit(0);
}
