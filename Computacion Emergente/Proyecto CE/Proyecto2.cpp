#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>

//---------------------------------------------Declaracion de Variables Globales

int i,j,k,l;                                           //Controladores de Ciclos
int vector_variables[5];                                   //Vector de Variables
int vecindad[6][5];                                         //Matriz de Vecindad

int clausulas[3][3]={{4,3,2},{5,1,2},{3,2,1}};             //Matriz de Clausulas
int evaluacion[3][3];                                    // Matriz de Evaluacion
int acumulador[3], sumador=0,sum=0,acum=0;

//-------------------------------------------------------------Llenado Aleatorio
void llenado_aleatorio()
{
	randomize();

   for (i=0; i<5; i++)
   {

     	vector_variables[i]=(rand()%2);
   	printf("\t %i", vector_variables[i]);
   }
   printf("\n \n");
}

//----------------------------------------------------------------------Vecindad
void generar_vecindad()
{
   for(i=0;i<6;i++)
   {
    	for(j=0;j<5;j++)
      {
      	vecindad[0][j]=vector_variables[j];
         if (i==j)
           	vecindad[i+1][j]=!vector_variables[j];
         else
         	vecindad[i+1][j]=vector_variables[j];
         printf("\t %i", vecindad[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

//---------------------------------------------------------Imprimir 91 Clausulas
void imprimir_clausulas()
{
	for(i=0;i<3;i++)
   {
   	printf("\n \n \t");
   	for(j=0;j<3;j++)
      {
      	printf("\t %i", clausulas[i][j]);
      }
   	printf("\n");
   }
   printf("\n");
}

//-------------------------------------------------------Evaluo vector principal
void evaluacion_vector()
{
	for(i=0;i<3;i++)
	{
		acum=(vector_variables[i]||vector_variables[i+1]||vector_variables[i+2]);
		printf("%i",acum);
      sum=sum+acum;
   }
   printf("\t %i",sum);
}

//--------------------------------------------Llenado de la Matriz de Evaluacion
/*
void llenado_evaluacion()
{
   for(l=0;l<6;l++)
   {

		for(i=0;i<3;i++)
   	{
         acumulador[i]=0;
         printf("\n \n \t");

   		for(j=0;j<3;j++)
      	{
      		if(clausulas[i][j]<=0)
         	{
         		k=(clausulas[i][j]*(-1));
         		evaluacion[i][j]=!vecindad[l][k-1];
         	}
				if (clausulas[i][j]>0)
         	{
         		k=clausulas[i][j];
         		evaluacion[i][j]=vecindad[l][k-1];
         	}
         	printf("\t %i", evaluacion[i][j]);
      	}
      	printf("\n");
         j=0;
         acumulador[i]=(evaluacion[i][j]||evaluacion[i][j+1]||evaluacion[i][j+2]);
      	printf("%i",acumulador[i]);
         sumador=sumador+acumulador[i];

         if(sumador>sum)
   		{
   			sum=sumador;
            vector_variables[i]=vecindad[l][i];
				printf("%i ", vecindad[l][i]);
         }
      }
	  	printf("\n");
      printf("\t %i",sumador);
   	sumador=0;
   }
   printf("\t %i",sum);


}
*/

void evaluacion( int vector_variables2[0], int vector_variables2[1], int vector_variables2[2], int vector_variables2[3], int vector_variables2[4], int vector_variables2[5])
{
	max = evalua(vector_variables2[0], vector_variables2[1], vector_variables2[2], vector_variables2[3], vector_variables2[4], vector_variables2[5]);

   for(i = 0 ; i<=5 ; i++)
   {
   	sum = evalua(vecindad[i][0],vecindad[i][1], vecindad[i][2], vecindad[i][3], vecindad[i][4], vecindad[i][5]);

      if(sum>max)
      {
         printf("El primer optimo local-local es %d",sum);
         max=sum;
      	evaluacion(vecindad[i][0],vecindad[i][1], vecindad[i][2], vecindad[i][3], vecindad[i][4], vecindad[i][5]);
      }
   }
}

int evalua(a,b,c,d)
{
   int vec[5]= {a,b,c,d};
	for(i=0 ; i<=5 ; i++)
   {
   	x = clausula[i][0];
      if(x<0)	vec[x*(-1)]=!vec[x*(-1)];

      y = clausula[i][0];
      if(y<0)	vec[y*(-1)]=!vec[y*(-1)];

      z = clausula[i][0];
      if(x<0)	vec[z(-1)]=!vec[z*(-1)];

      suma+=vec[x]



//-------------------------------------------------------------Funcion Principal
void main()
{
 	llenado_aleatorio();
   generar_vecindad();
   evaluacion_vector();
   imprimir_clausulas();
   llenado_evaluacion();

   getch();
}

