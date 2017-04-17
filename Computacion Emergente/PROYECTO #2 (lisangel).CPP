#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#define clausu  3

//------------------------------------------------------Declaracion de Variables

int i,j,l,m,k;                                         //Controladores de Ciclos
int n;                                                         		  //# Filas
int Matriz_Aleatoria[100][9];                         		  //Matriz Principal
int clausulas[clausu][clausu]={{4,3,2},{5,1,2},{3,-2,1}}; 				//Clausulas
int sumador,acumulador[100],evaluacion[100][9];

//-------------------------------------------------------------Llenado Aleatorio

void llenado_aleatorio()
{
   printf("# Filas para la Matriz: ");
   scanf("%i", &n);

   randomize();

   for(i=0; i<n; i++)
   {
		for(j=0; j<8; j++)
      {
      	Matriz_Aleatoria[i][j]=(rand()%2);
      }
   }
}

//--------------------------------------------Llenado de la Matriz de Evaluacion
void Evaluacion()
{
   for(l=0;l<n;l++)
   {
      for(i=0;i<clausu;i++)
   	{
         acumulador[i]=0;

      	for(j=0;j<clausu;j++)
      	{
      		if(clausulas[i][j]<=0)
         	{
         		k=(clausulas[i][j]*(-1));
         		evaluacion[i][j]=!Matriz_Aleatoria[l][k-1];
         	}
				if (clausulas[i][j]>0)
         	{
         		k=clausulas[i][j];
         		evaluacion[i][j]=Matriz_Aleatoria[l][k-1];
         	}
         }
      	j=0;
         acumulador[i]=(evaluacion[i][j]||evaluacion[i][j+1]||evaluacion[i][j+2]);
         sumador=sumador+acumulador[i];
      }
      for(m=0; m<n; m++)
      {
      	Matriz_Aleatoria[m][8]=sumador;
      }
      	sumador=0;
   }
}


void Imprimir()
{
	for(i=0; i<n; i++)
   {
		for(j=0; j<9; j++)
      {
      	printf("\t %i", Matriz_Aleatoria[i][j]);
      }
      printf("\n");
   }
}
//-------------------------------------------------------------Funcion Principal
void main()
{
	llenado_aleatorio();
   Evaluacion();
   Imprimir();
   getch();
}
