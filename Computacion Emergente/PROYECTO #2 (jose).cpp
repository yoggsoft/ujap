#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#define clausu  20
#define tam 20
#define gran 100

//------------------------------------------------------Declaracion de Variables

int i,j,l,m,k,q;                                         //Controladores de Ciclos
int n;
int hijos[gran][gran];                                                    		  //# Filas
int Matriz_Aleatoria[100][tam],Matriz_Aleatoria2[100][tam],padres_optimos[gran][gran];  //Matriz Principal
int clausulas[clausu][3]={
{4, -6, 14}     , {-6, -12, -7}  , {13, -18, -3}  , {13, -5, 11}  ,
{-19, -18, -13} , {-17, 5, -10}  , {-4, -10, 5}   , {2, -12, -19} ,
{16, -8, -1}    , {16, 13, -17}  , {-4, 3 ,1}     , {-6, -5, -14} ,
{11, -16, 5}    , {5, 15, 8}     , {5, 17, -15}   , {5, 17, -15}  ,
{-1, 7, 14}     , {-8, -17, -12} , {2, -11, 20}   , {-11, -9, -16}         } ;




//Clausulas


int sumador,acumulador[100],evaluacion[100][tam];

//-------------------------------------------------------------Llenado Aleatorio

void llenado_aleatorio()
{
   printf("Ingrese N: ");
   scanf("%i", &n);

   randomize();

   for(i=0; i<n; i++)
   {
		for(j=0; j<tam; j++)
      {
      	Matriz_Aleatoria[i][j]=(rand()%2);
      }
   }
}

//--------------------------------------------Llenado de la Matriz de Evaluacion
void Evaluacion()
{
   int max;
   for(l=0;l<n;l++)
   {
      for(i=0;i<clausu;i++)
   	{
         acumulador[i]=0;

      	for(j=0;j<3;j++)
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
      	Matriz_Aleatoria[m][tam]=sumador;
      }
      	sumador=0;
   }
}


void ordenar()
{
   int max,h,pos;

	for( k=0 ; k<n ; k++)
   {
   	max = 0;


      for( h=0 ; h<n ; h++)
      {
      	if( Matriz_Aleatoria[h][20] > max )
         {
         	max = Matriz_Aleatoria[h][20];
            pos = h;
         }
      }

      for( i=0 ; i<n ; i++)
      {
      	for( j=0 ; j<n ; j++)
      	{
         	Matriz_Aleatoria2[i][j] = Matriz_Aleatoria[pos][j];
         }
      }

      Matriz_Aleatoria[pos][20] = -1;


	}
}

void Imprimir()
{
	for(i=0; i<n; i++)
   {
		for(j=0; j<tam; j++)
      {
      	printf("\t %i", Matriz_Aleatoria[i][j]);
      }
      printf("\n");
   }
}

void Imprimir2()
{

   printf("\n\n\n\n\n");
   printf("\t\t\t\ttMatriz Ordenada");

	for(i=0; i<n; i++)
   {
		for(j=0; j<tam; j++)
      {
      	printf("\t %i", Matriz_Aleatoria2[i][j]);
      }
      printf("\n");
   }
}

void seleccion()
{
	randomize();
   int max1 = 0,x,l,m,k,pos1;
   int Matriz_padres[gran][gran];

   for(l=0 ; l<2 ; l++)
   {


      for( k=0 ; k<4 ; k++)
      {
         x=(rand()%2);


         for(j=0; j<tam; j++)
         {
            Matriz_padres[k][j] = Matriz_Aleatoria[x][j];
         }

      }

      max1 = 0;

      for(i=0 ; i<4 ; i++)
      {
         for( k=0 ; k<tam ; k++)
         {
            if( Matriz_padres[i][tam] > max1 )
            {
               max1 = Matriz_padres[i][tam];
               pos1 = k;
            }
         }
      }

      for(m=0 ; m<tam ; m++)
      {
      	padres_optimos[l][m] = Matriz_padres[pos1][m];
      }


	}


}

void cruce()
{

   int x,y,w,i,j;

	x = rand();
   y = rand();

   int hijos[gran][gran];

   int p0 = 0,p1 = 1;

   for( w=0 ; w<2 ; w++)
   {
   	for( i=0 ; i<20 ; i++)
      {
      	while(i<x)
         {
         	hijos[w][i] = padres_optimos[p0][i];
         }
         while(i>x && i<y)
         {
         	hijos[w][i] = padres_optimos[p1][i];
         }
         while(i>y)
         {
         	hijos[w][i] = padres_optimos[p0][i];
         }
      }
      p0=1;
      p1=0;
   }

}

void mutacion()
{

	int x=rand();

   if( x < 0,05)
   {
   	hijos[0][0] = !hijos[0][0];
      hijos[1][1] = !hijos[1][1];
   }

}

void llenado_hijo()
{
	int matriz_hijos[gran][gran];


   for( i=q ; i<2 ; i++)
   {
   	for( j=0 ; j<20 ; j++)
      {
      	matriz_hijos[i][j]=hijos[i][j];
      }

   }

}
void llenado_matriz_hijos()
{

   for( q=0 ; q<n ; q=q+2 )
   {
      llenado_hijo();
   }

}

void GAP()
{
   int gap;

	printf("Ingrese GAP: ");
   scanf("%i", &gap);

   porc = int((n/gap)*100);

   p = n*(porc/100);

   for( i=0 ; i<2 ; i++)
   {
   	for( j=0 ; j<20 ; j++)
      {
      	while(i<x)
         {
         	total[w][i] = padres_optimos[p0][i];
         }
         while(i>x && i<y)
         {
         	hijos[w][i] = padres_optimos[p1][i];
         }
         while(i>y)
         {
         	hijos[w][i] = padres_optimos[p0][i];
         }
      }











}









//-------------------------------------------------------------Funcion Principal
void main()
{
	llenado_aleatorio();
   Evaluacion();
   ordenar();
   Imprimir();
   Imprimir2();
   for(i=0 ; i<(n/2) ; i++)
   {
   	selecciom();
      cruce();
      mutacion();
   }

   llenado_hijos();
   llenado_matriz_hijos();








   getch();
}
