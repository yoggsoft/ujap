#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#define tamvec  5
#define clausu  3
#define iteracion 5

//---------------------------------------------Declaracion de Variables Globales

int i,j,k,l,y,x,h,m,bandera;                               //Controladores de Ciclos
bool vector_variables[tamvec], vector_variables2[tamvec];  //Vector de Variables
bool vecindad[tamvec][tamvec];                              //Matriz de Vecindad
bool vector_optimo[20];
int clausulas[clausu][clausu]={{4,3,2},{5,1,2},{3,-2,1}};  //Matriz de Clausulas
bool evaluacion[clausu][clausu];
int local[tamvec];                                       // Matriz de Evaluacion
int acumulador[clausu], sumador=0,sum=0,acum=0,maxi=0,my=0,mayor=0,maximo=0,maxite=0;
int matriz_solucion[iteracion][tamvec],vector_solucion[iteracion];

//-------------------------------------------------------------Llenado Aleatorio
void llenado_aleatorio()                                     
{
	randomize();
   printf("\t Vector Aleatorio:\n");

   for (i=0; i<tamvec; i++)
   {
		vector_variables[i]=(rand()%2);
   	printf("\t %i", vector_variables[i]);
   }
   printf("\n \n");
}

//---------------------------------------------------------------Genero Vecindad
void generar_vecindad()
{
   for(i=0;i<tamvec;i++)
   {
    	for(j=0;j<tamvec;j++)
      {
      	if (i==j)
           	vecindad[i][j]=!vector_variables[j];
         else
         	vecindad[i][j]=vector_variables[j];
      }
   }
}

//-------------------------------------------------------Evaluo vector principal
void evaluacion_vector()
{
	for(i=0;i<clausu;i++)
	{
		acum=(vector_variables[i]||vector_variables[i+1]||vector_variables[i+2]);
		sum=sum+acum;
   }
}

//--------------------------------------------Llenado de la Matriz de Evaluacion
void llenado_evaluacion()
{
   for(l=0;l<=tamvec;l++)
   {
      for(i=0;i<=clausu;i++)
   	{
         acumulador[i]=0;

      	for(j=0;j<=clausu;j++)
      	{
      		if(clausulas[i][j]<=0)
         	{
         		k=(clausulas[i][j]*(-1));
         		evaluacion[i][j]=!vecindad[l][k-1];
         	}
				if (clausulas[i][j]>0)
         	{
         		k=clausulas[i][j];
         		evaluacion[i][j]=vecindad[l][k];
         	}
         }
      	j=0;
         acumulador[i]=(evaluacion[i][j]||evaluacion[i][j+1]||evaluacion[i][j+2]);
         sumador=sumador+acumulador[i];
         local[l]=sumador;
      }

	  	sumador=0;
   }
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

         for(y=0; y<=tamvec ; y++)
         {
       	 	vector_variables2[y]=vecindad[my][y];
            vector_variables[y]=vector_variables2[y];
	      }
      }
      else
      {
      	//vector_variables2[x]=vector_variables[x];
         // Imprimir que esa es la solucion
         bandera=0;
     	}
	}
}

//-------------------------------------------------------------Funcion Principal
void main()
{
  	for(i=1;i<=iteracion;i++)
 	{

      printf("Iteracion # %d",i);

   	llenado_aleatorio();

      do
      {
      	generar_vecindad();
    		evaluacion_vector();
    		llenado_evaluacion();
			cuasisolucion();
	  	}
      while(bandera==1);

      
      printf("El optimo local fue de %d y el vecino es el siguiente" , sum);

      for(y=0; y<=tamvec ; y++)
      {
         printf("\n");
         printf("   \t %d",vector_variables2[y]);
         matriz_solucion[i][y]=vector_variables2[y];
         vector_solucion[i]=sum;
      }

      for(h=0; h<=tamvec ; h++)
      {
         if(vector_solucion[h]>mayor)
         {
            mayor=vector_solucion[h];
            maximo=h;
            maxite=i;
         }
      }
   }


      printf("El mejor vecino fue de la Iteracion %d, y fue el vecino siguiente:", maxite);
      for(m=0; m<=tamvec ; m++)
      {
         printf("\n");
      	printf(" \t    %d", matriz_solucion[maxi][m]);
      }



   getch();
}

