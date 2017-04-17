#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#define tamvec  5
#define clausu  3
#define iteracion 5

//---------------------------------------------Declaracion de Variables Globales

int i,j,k,l;                                           //Controladores de Ciclos
int vector_variables[tamvec], vector_variables2[tamvec];                                   //Vector de Variables
int vecindad[tamvec][tamvec];                                         //Matriz de Vecindad
int vector_optimo[20];
int clausulas[clausu][clausu]={{4,3,2},{5,1,2},{3,-2,1}};             //Matriz de Clausulas
int evaluacion[clausu][clausu];
int local[tamvec];                // Matriz de Evaluacion
int acumulador[clausu], sumador=0,sum=0,acum=0,maxi=0,my=0,x=0,band, bandera;

//-------------------------------------------------------------Llenado Aleatorio
void llenado_aleatorio()
{
	randomize();

   for (i=0; i<tamvec; i++)
   {

     	vector_variables[i]=(rand()%2);
   	printf("\t %i", vector_variables[i]);
   }
   printf("\n \n");
}

//----------------------------------------------------------------------Vecindad
void generar_vecindad()
{
   for(i=0;i<tamvec;i++)
   {
    	for(j=0;j<tamvec;j++)
      {
      	if (i==j)
           	vecindad[i+1][j]=!vector_variables[j];
         else
         	vecindad[i+1][j]=vector_variables[j];
         //printf("\t %i", vecindad[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

//---------------------------------------------------------Imprimir 91 Clausulas
void imprimir_clausulas()
{
	for(i=0;i<clausu;i++)
   {
   	printf("\n \n \t");
   	for(j=0;j<clausu;j++)
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
	for(i=0;i<clausu;i++)
	{
		acum=(vector_variables[i]||vector_variables[i+1]||vector_variables[i+2]);
		printf("%i",acum);
      sum=sum+acum;
   }
   printf("\t %i",sum);
}

//--------------------------------------------Llenado de la Matriz de Evaluacion

void llenado_evaluacion()
{
   for(l=0;l<=tamvec;l++)
   {

		for(i=0;i<clausu;i++)
   	{
         acumulador[i]=0;
         printf("\n \n \t");

   		for(j=0;j<clausu;j++)
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


         /*if(sumador>sum)
   		{
   			sum=sumador;
            vector_variables[i]=vecindad[l][i];
				printf("%i ", vecindad[l][i]);
         }
         */
      }

      local[l]=sumador;
	  	printf("\n");
      printf("\t %i",sumador);
   	sumador=0;

   }
   //printf("\t %i",sum);
}

void cuasisolucion()
{
   for(x=0; x<=tamvec ; x++)
   {
      if(local[x]>sum)
      {
      	sum=local[x];
         my=x;
         bandera=1;
         for(y=0; x<=tamvec ; x++)
         	 	vector_variables2[x]=vecindad[my][x];
      {

      }
      else
      {
      	vector_variables2[i]=2;
         bandera=0;
      }
   }
}

int comp_vec(int a[],int b[])
{

	for(i=0; i<=tamvec ; i++)
   {
   	if(a[i]==b[i])
      	band=1;
      else band=0;
   }
   return band;
}

/*void igual_vec(int vector_variable[],int vector_variable2[])
{
   int a[];
   int b[];
	for(i=0 ; i<=5 ; i++)
	  	a[i]=b[i];
}
*/

//-------------------------------------------------------------Funcion Principal
void main()
{

   for(i=1 ; i<=iteracion ; i++)
   {


      llenado_aleatorio();

      do
      {
         generar_vecindad();
         evaluacion_vector();
         //imprimir_clausulas();
         llenado_evaluacion();
         cuasisolucion();
          if( vector_variables2[0] == 2)
         {
            printf("el primer vector aletorio fue la solucion mas optima");
         }
         else
         {
            printf("\n\n\n");
            printf("La solucion local de la iteracion %d es:",sum);
            printf("\n\n\n");
            for(i=0 ; i<=5 ; i++)
               {
                  printf("\t   %d",vector_variables2[i]);
                  vector_variables[i]=vector_variables2[i];
               }
         }

      }
      while(bandera==1);

    vector_optimo[i]=sum;
    }



   getch();
}

