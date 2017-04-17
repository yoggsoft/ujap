#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#include <time.h>

#define clausu  91

void Llenado_Padres();
//void Mutacion();

//------------------------------------------------------Declaracion de Variables

int h,i,j,k,l,o,y,max3,pos3;                                       //Controladores de Ciclos
int n,x,z,m,w,q=0,f,b=0;
int sumador,acumulador[1000],evaluacion[1000][3],evaluacion_hijos[1000][3],Optimo_local[1000][21];
float a;

//----------------------------------------------------------------------Matrices

int Poblacion[1000][21],Poblacion_Ordenada[1000][21];
int Torneo[4][21],Padres[2][21],Hijos[1000][21],Hijo[2][21],Padres_ordenados[1000][21],Hijos_ordenados[1000][21];
int Matriz_Padres[1000][21],Matriz_Hijos[1000][21],Gap[100][21];

//---------------------------------------------------------------------Clausulas

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

//-------------------------------------------------------------Llenado Aleatorio

void llenado_aleatorio()
{
   printf("# Filas para la Matriz: ");
   scanf("%i", &n);

   randomize();

   for(i=0; i<n; i++)
   {
		for(j=0; j<20; j++)
      {
      	Poblacion[i][j]=(rand()%2);
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

      	for(j=0;j<3;j++)
      	{
      		if(clausulas[i][j]<=0)
         	{
         		k=(clausulas[i][j]*(-1));
         		evaluacion[i][j]=!Poblacion[l][k-1];
         	}
				if (clausulas[i][j]>0)
         	{
         		k=clausulas[i][j];
         		evaluacion[i][j]=Poblacion[l][k-1];
         	}
         }
      	j=0;
         acumulador[i]=(evaluacion[i][j]||evaluacion[i][j+1]||evaluacion[i][j+2]);
         sumador=sumador+acumulador[i];
      }
     	Poblacion[l][20]=sumador;
     	sumador=0;
   }
}

//----------------------------------------------------------------------Imprimir

void Imprimir()
{
	clrscr();
	printf("\n");
   printf("\t\t\t\tPOBLACION.");

	for(i=0; i<n; i++)
   {
   	printf("\n\n");
   	printf("\t\t\t");

		for(j=0; j<=20; j++)
      {
      	if(j==20)
         {
         printf("\t");
         }
      	printf("%i", Poblacion[i][j]);
      }
   }
   printf("\n\n");
}

void ImprimirII()
{
   clrscr();
	printf("\n");
   printf("\t\t\t   POBLACION ORDENADA.");

	for(i=0; i<n; i++)
   {
   	printf("\n\n");
   	printf("\t\t\t");

		for(j=0; j<=20; j++)
      {
      	if(j==20)
         {
         printf("\t");
         }
      	printf("%i", Poblacion_Ordenada[i][j]);
      }
   }
   printf("\n\n");
}

void ImprimirIII()
{
	printf("\n");
   printf("\t\t\t\t TORNEO.");

	for(i=0; i<4; i++)
   {
   	printf("\n\n");
   	printf("\t\t\t");

		for(j=0; j<=20; j++)
      {
      	if(j==20)
         {
         printf("\t");
         }
      	printf("%i", Torneo[i][j]);
      }
   }
   printf("\n\n");
}

void ImprimirIV()
{
	printf("\n");
   printf("\t\t\t\t PADRES.");

	for(i=0; i<2; i++)
   {
   	printf("\n\n");
   	printf("\t\t\t");

		for(j=0; j<=20; j++)
      {
      	if(j==20)
         {
         printf("\t");
         }
      	printf("%i", Padres[i][j]);
      }
   }
   printf("\n\n");
}

void ImprimirV()
{
	for(i=0; i<2; i++)
   {
   	printf("\n\n");
   	printf("\t\t\t");

		for(j=0; j<20; j++)
      {
        	printf("%i", Hijo[i][j]);
      }
   }
   printf("\n\n");
}

void ImprimirVI()
{

	printf("\n");
   printf("\t\t\t   MATRIZ PADRES.");

	for(i=0; i<n; i++)
   {
   	printf("\n\n");
   	printf("\t\t\t");

		for(j=0; j<=20; j++)
      {
      	if(j==20)
         {
         printf("\t");
         }
      	printf("%i", Matriz_Padres[i][j]);
      }
   }
   printf("\n\n");
}

void ImprimirVII()
{

	printf("\n");
   printf("\t\t\t  MATRIZ HIJOS");

	for(i=0; i<n; i++)
   {
   	printf("\n\n");
   	printf("\t\t\t");

		for(j=0; j<=20; j++)
      {
      	if(j==20)
         {
         printf("\t");
         }
      	printf("%i", Matriz_Hijos[i][j]);
      }
   }
   printf("\n\n");
}

void ImprimirVIII()
{

	printf("\n");
   printf("\t\t\tMATRIZ HIJOS ORDENADOS");

	for(i=0; i<n; i++)
   {
   	printf("\n\n");
   	printf("\t\t\t");

		for(j=0; j<=20; j++)
      {
      	if(j==20)
         {
         printf("\t");
         }
      	printf("%i", Hijos_ordenados[i][j]);
      }
   }
   printf("\n\n");
}

void ImprimirIX()
{

	printf("\n");
   printf("\t\t\tMATRIZ PADRES ORDENADOS");

	for(i=0; i<n; i++)
   {
   	printf("\n\n");
   	printf("\t\t\t");

		for(j=0; j<=20; j++)
      {
      	if(j==20)
         {
         printf("\t");
         }
      	printf("%i", Padres_ordenados[i][j]);
      }
   }
   printf("\n\n");
}




//------------------------------------------------------------Ordernar Poblacion

void Ordenar_Poblacion()
{
   int max,pos;

	for(k=0;k<n;k++)
   {
   	max=-1;

      for( h=0 ; h<n ; h++)
      {
      	if( Poblacion[h][20] > max )
         {
         	max = Poblacion[h][20];
            pos = h;
         }
      }

      for( j=0 ; j<=20 ; j++)
      {
        	Poblacion_Ordenada[k][j] = Poblacion[pos][j];
      }
      Poblacion[pos][20] = -1;
  	}
}

//-------------------------------------------------------------Seleccion(Torneo)

void Seleccion()
{
	randomize();
   int max,pos;
   int p0,p1;
   m=(int)(n/2);
   f=0;

  	for(y=0,q=0 ; y<m,q<n ; y++,q=q+2)
  	{
      f=f+2;
      for(l=0;l<2;l++)
      {
         for( k=0 ; k<4 ; k++)
         {
            x=(rand()%n);

            for(j=0; j<=20; j++)
            {
               Torneo[k][j] = Poblacion_Ordenada[x][j];
            }
         }
         ImprimirIII();

         max=-1;

         for( h=0 ; h<4 ; h++)
         {
            if(Torneo[h][20]>max)
            {
               max = Torneo[h][20];
               pos = h;
            }
         }

         for( j=0 ; j<=20 ; j++)
         {
            Padres[l][j] = Torneo[pos][j];

         }
         Torneo[pos][20]=-1;
      }

//-------------------------------------------------------------Llenado de Padres
      f=f+2;
      for (i=q, k=0; i<(f+2),k<2;i++,k++)
      {

         for(j=0;j<=20;j++)
         {
            Matriz_Padres[i][j]=Padres[k][j];
         }
      }

//-------------------------------------------------------------------------Cruce

      a=(float)rand()/RAND_MAX;

      if(a<0.7)
      {
         p0=0;
         p1=1;

         z=rand()%18+1;
         w=rand()%(20-z+1)+z;

         printf("%i",z);
         printf("\n");
         printf("%i",w);

         for( l=0 ; l<2 ; l++)
         {
            for( i=0 ; i<=20 ; i++)
            {
               if(i<z)
                  Hijo[l][i] = Padres[p0][i];

               if(i>=z && i<=w)
                  Hijo[l][i] = Padres[p1][i];

               if(i>w)
                  Hijo[l][i] = Padres[p0][i];
            }
            p0=1;
            p1=0;
         }
      }
      else
      {
         for( i=0 ; i<2 ; i++)
         {
            for( j=0 ; j<20 ; j++)
            {
               Hijo[i][j] = Padres[i][j];
            }
         }
      }

//----------------------------------------------------------------------Mutacion

      for(i=0; i<2;i++)
      {
         for(j=0;j<=20;j++)
         {
         	a=(float)rand()/RAND_MAX;
            if(a<0.05)
            {
               Hijo[i][j] = !Hijo[i][j];
            }
         }
      }

//--------------------------------------------------------------Llenado de Hijos

      for(i=0; i<2;i++)
      {
      	for(j=0;j<20;j++)
         {
         	Matriz_Hijos[b][j]=Hijo[i][j];
         }
         b++;
      }

//----------------------------------------------------------------------Imprimir

      ImprimirIV();
      printf("\n");
      printf("\t\t\t\t CRUCE.");
      ImprimirV();
      printf("\n");
      printf("\t\t\t\t MUTACION.");
      ImprimirV();
      printf("\t\t\t\t MATRIZ HIJOS");
      ImprimirVII();
   }
   ImprimirVI();
}

//----------------------------------------------------------------Ordenar Padres

void Ordenar_Matriz_Padres()
{
	int max,pos;

	for(k=0;k<n;k++)
   {
   	max=-1;

      for( h=0 ; h<n ; h++)
      {
      	if( Matriz_Padres[h][20] > max )
         {
         	max = Matriz_Padres[h][20];
            pos = h;
         }
      }

      for( j=0 ; j<=20 ; j++)
      {
        	Padres_ordenados[k][j] = Matriz_Padres[pos][j];
      }
      Matriz_Padres[pos][20] = -1;
  	}
}

//--------------------------------------------------------------Evaluacion Hijos

void Evaluacion_Hijos()
{
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
         		evaluacion_hijos[i][j]=!Matriz_Hijos[l][k-1];
         	}
				if (clausulas[i][j]>0)
         	{
         		k=clausulas[i][j];
         		evaluacion_hijos[i][j]=Matriz_Hijos[l][k-1];
         	}
         }
      	j=0;
         acumulador[i]=(evaluacion_hijos[i][j]||evaluacion_hijos[i][j+1]||evaluacion_hijos[i][j+2]);
         sumador=sumador+acumulador[i];
      }
     	Matriz_Hijos[l][20]=sumador;
     	sumador=0;
   }

   ImprimirVII();

}

//----------------------------------------------------------Ordenar Matriz Hijos

void Ordenar_Matriz_Hijos()
{
	int max,pos;

	for(k=0;k<n;k++)
   {
   	max=-1;

      for( h=0 ; h<n ; h++)
      {
      	if( Matriz_Hijos[h][20] > max )
         {
         	max = Matriz_Hijos[h][20];
            pos = h;
         }
      }

      for( j=0 ; j<=20 ; j++)
      {
        	Hijos_ordenados[k][j] = Matriz_Hijos[pos][j];
      }
      Matriz_Hijos[pos][20] = -1;
  	}
}

void GAP()
{
   int gap,porc,p;

	printf("Ingrese GAP: ");
   scanf("%i", &gap);

   porc = int((n/gap)*100);

   p = int(n*(porc/100));

   for( i=0 ; i<2 ; i++)
   {
   	for( j=0 ; j<20 ; j++)
      {
      	while(i<p)
         {
         	Gap[i][j] = Padres_ordenados[i][j];
         }

         while(i>p)
         {
         	Gap[i][j] = Hijos_ordenados[i][j];
         }

      }
	}

   for( h=0 ; h<n ; h++)
   {
	  	if( Gap[h][20] > max3 )
      {
      	max3 = Gap[h][20];
         pos3 = h;
      }
   }
   for(k=0 ; k<=n ; k++)
   {
   	for(l=0 ; l<=21 ; l++)
      {
      	Optimo_local[k][l] = Gap[pos3][l];
      }
   }


}


//-------------------------------------------------------------Funcion Principal

void main()
{
	llenado_aleatorio();
   Evaluacion();
   Imprimir();
   Ordenar_Poblacion();
   ImprimirII();

   m=(int)(n/2);

	for(y=0;y<m;y++)
   {
      Seleccion();
   }
   Ordenar_Matriz_Padres();
   ImprimirIX();
   Evaluacion_Hijos();
   Ordenar_Matriz_Hijos();
   ImprimirVIII();
   getch();

}
