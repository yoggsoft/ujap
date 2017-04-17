#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#define clausu 91


// Llenando una solucion aleatoria

int clausulas[clausu][3]={
{4,-6,14}       , {-6,-12,-7}    , {13,-18,-3}    , {13,-5,11}     ,
{-19,-18,-13}   , {-17,5,-10}    , {-4,-10,5}     , {2,-12,-19}    ,
{16,-8,-1}      , {16,13,-17}    , {-4,3,1}       , {-6,-5,-14}    ,
{11,-16,5}      , {5,15,8}       , {5,17,-15}     , {16,9,3}       ,
{-1,7,14}       , {-8,-17,-12}   , {2,-11,20}     , {-11,-9,-16}   ,
{7,3,18}        , {-3,9,8}       , {-3,13,6}      , {-5,11,4}      ,
{-9,12,-1}      , {6,8,-15}      , {11,19,-3}     , {9,-17,2}      ,
{-17,-8,-10}    , {3,2,-15}      , {-8,14,-5}     , {7,-2,13}      ,
{4,9,3}         , {7,14,-19}     , {4,-6,-8}      , {13,5,3}       ,
{15,-10,-5}     , {-9,20,-6}     , {-20,-15,5}    , {-11,19,14}    ,
{-15,16,-10}    , {1,18,8}       , {1,13,-3}      , {18,4,5}       ,
{11,19,4}       , {3,-17,-18}    , {1,17,2}       , {-6,-14,-7}    ,
{-10,20,2}      , {2,-12,20}     , {-14,3,-18}    , {5,4,-15}      ,
{-10,15,9}      , {-14,17,5}     , {-17,-11,16}   , {-19,16,2}     ,
{7,-10,15}      , {-10,16,-17}   , {20,-3,-2}     , {-2,-16,-8}    ,
{-17,9,-16}     , {-5,7,9}       , {9,-18,-3}     , {19,-12,-14}   ,
{13,-17,9}      , {-18,11,-10}   , {13,-14,18}    , {-8,2,-4}      ,
{-2,6,7}        , {-9,-19,-17}   , {-17,-4,-8}    , {3,-7,15}      ,
{11,1,-4}       , {-2,-13,5}     , {5,-18,-6}     , {20,15,-2}     ,
{6,7,-20}       , {1,-20,19}     , {3,-2,-19}     , {15,-2,-20}    ,
{3,-6,-19}      , {-15,17,-13}   , {-16,6,-10}    , {2,7,-14}      ,
{4,-6,-3}       , {12,-3,-18}    , {-16,-11,-3}   , {6,-2,5}       ,
{-14,11,-16}    , {-4,6,1}       , {4,-6,19}                       };

int sa[100],vecino[100];
int acumulador[100],evaluacion[100][100];
int i,j,k,p,n,sumador,al,alea;
float e,t;


void SA()
{
	for( i=0 ; i < 20 ; i++)
   {
   	sa[i]=(rand()%2);
   }

   for(j=0;j<clausu;j++)
   {
      acumulador[j]=0;

      for(k=0;k<3;k++)
      {
         if(clausulas[j][k]<=0)
         {
            p=(clausulas[j][k]*(-1));
            evaluacion[j][k]=!sa[p-1];
         }
         else
         {
            p=clausulas[j][k];
            evaluacion[j][k]=sa[p-1];
         }
      }
      acumulador[j]=(evaluacion[j][k]||evaluacion[j][k+1]||evaluacion[j][k+2]);
      sumador=sumador+acumulador[j];
   }
   sa[20]=sumador;

   for( i=0 ; i <= 20 ; i++)
   {
   	printf("\nSolucion Aleatoria [%d] = %d",i,sa[i]);
      if(i==20)
      	printf("\nSolucion Aleatoria Evaluada = %d",sa[i]);
   }



}

void vecinos()
{
	al = (rand()%21);

   for(i=0 ; i<=20 ; i++)
   {
		vecino[i]=sa[i];
   }
   vecino[al] = !sa[al];


   for(j=0;j<clausu;j++)
   {
      acumulador[j]=0;

      for(k=0;k<3;k++)
      {
         if(clausulas[j][k]<=0)
         {
            k=(clausulas[j][k]*(-1));
            evaluacion[j][k]=!vecino[k-1];
         }
         else
         {
            k=clausulas[j][k];
            evaluacion[j][k]=vecino[k-1];
         }
      }
      acumulador[j]=(evaluacion[j][k]||evaluacion[j][k+1]||evaluacion[j][k+2]);
      sumador=sumador+acumulador[j];
   }
   vecino[20]=sumador;
}


void comparacion()
{
   e = exp((vecino[20] - sa[20])/t);
   alea = (rand()%2);

	if(vecino[20]>sa[20])
   {
   	for(i=0 ; i<=20 ; i++)
   	{
      	sa[i] = vecino[i];
      }
   }

   else
   {
   	if( alea < e )
      {
      	for(i=0 ; i<=20 ; i++)
   		{
      		sa[i] = vecino[i];
      	}
      }
   }
}


void main()
{
   printf("Ingrese la cantidad de Iteraciones");
   scanf("%d",&n);
   t=1000;
   while(t>0 && t<100)
   {
      for(i=0 ; i<=n ; i++)
      {
         SA();
         vecinos ();
         comparacion;
         t=t-(t*.1);
      }
   }
   getch();
}


