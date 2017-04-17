/*
   Universidad José Antonio Páez
   Gilberto López Ambrosino.
   C.I.:18.178.045.

   Computación Emergente.

   Borland C++ v3.1 for DOS.
 */

//*************Librerias y Definiciones************//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define T 29					//Tamaño de la matriz.
#define PATH "c:\\e\\TSP.TXT"	//Fichero del archivo TXT.
#define N 100					//Tamaño de la poblacion.
#define n 4						//cantidad de candidatos a padre.
#define PGAP	50					//porcentaje para la generacion.
#define PM 0.01       			//probabilidad de mutacion.
#define PC 0.8        			//probabilidad de cruce.
#define ITMAX 100				//numero maximo de iteraciones.

//************Propotipo de Funciones*************//

void cargar();						//carga el archivo TXT de la matriz.
void mostrar();						//muestra la matriz cargada. (para probar la carga)
void generar_p();					//genera un recorrido.
void generar_poblacion();			//genera la matriz de poblacion.
void evaluar();						//busca costos.
int aptitud(int vec[]);				//funcion de Adaptacion.
int torneo();						//elije un padre.
void cruce();						//crossover
void mutar();						//mutacion de los hijos.
void cambiar_poblacion();			//actualiza la poblacion.
void algoritmo_genetico();			//algoritmo genetico simple.
void prueba(int ite, float x1, float x2, float x3);

//************Variables globales***************//

int M[T][T]; 				//matriz principal.
int P[T];					//recorrido aleatorio.
int poblacion[N][T];		//matriz de poblacion.
int poblacion_aux[N][T];	//auxiliar de la poblacion.
int GAP=(int)(N*PGAP/100);	//porcentaje GAP
int costos[N];				//vector de distancias.
int padres[n];				//candidatos a padre.
int P1[T];					//1er padre.
int P2[T];					//2do padre.
int H1[T];					//1er hijo.
int H2[T];					//2do hijo.

//************Definiciones de Funciones***********//

void cargar()
{
	FILE *file;
		int i,j,k=0,valor;
		if((file=fopen(PATH,"r"))==NULL)
		{
			printf("No se pudo abrir el Archivo TSP.TXT");
			getch();
			exit(0);
		}
		for(i=0;i<29;i++)
		{
			for(j=k;j<29;j++)
			{
				if(i==j)
					valor=0;
				else
					fscanf(file,"%i",&valor);
				M[i][j]=valor;
				M[j][i]=valor;
			}
			k++;
		}
	fclose(file);
}
//*******************************************************//
void mostrar()
{
	int i,j;
	for (i=0;i<=4;i++)
		{
			for (j=0;j<=4;j++)
				printf("%i\t",M[i][j]);
			printf("...%i\n",M[i][28]);
		}
		printf(".\t.\t.\t.\t.\n");
		printf(".\t.\t.\t.\t.\n");
		printf(".\t.\t.\t.\t.\n");
		printf("%i\t%i\t%i\t%i\t%i",M[0][28],M[1][28],M[2][28],M[3][28],M[4][28]);
}
//*******************************************************//
void generar_p()
{
	int valor,i,j,s;
		j=0;
		do
		{
			s=0;
			valor=random(T);
			for(i=0;i<j;i++)
			{
				if(valor == P[i])
				s=1;
			}
			if(s==0)
			{
				P[j]=valor;
				j++;
			}
		}
		while(j<T);
}
//*******************************************************//
void generar_poblacion()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		generar_p();
		for(j=0;j<T;j++)
			poblacion[i][j]=P[j];
	}
}
//*******************************************************//
void evaluar()
{
	int i,j,aux[T];
	for(i=0;i<N;i++)
	{
		for(j=0;j<T;j++)
			 aux[j]=poblacion[i][j];
		costos[i]=aptitud(aux);
	}
}
//*******************************************************//
int aptitud(int vec[])
{
	int i,s=0;
		for(i=0;i<T;i++)
		{
			if((i+1)>=T)
				s+=M[vec[T-1]][vec[0]];
			else
				s+=M[vec[i]][vec[i+1]];
		}
	return s;
}
//*******************************************************//
void sort()
{
	int i,j,v,temp1,temp2;
	for(v=0;v<N;v++)
		for(i=0;i<N-1;i++)
			if(costos[i]>costos[i+1])
			{
				temp1=costos[i+1];
				costos[i+1]=costos[i];
				costos[i]=temp1;
				for(j=0;j<T;j++)
				{
					temp2=poblacion[i+1][j];
					poblacion[i+1][j]=poblacion[i][j];
					poblacion[i][j]=temp2;
				}
			}
}
//*******************************************************//
void aux_poblacion()
{
	for(int i=0;i<GAP;i++)
		for(int j=0;j<T;j++)
			poblacion_aux[i][j]=poblacion[i][j];
}
//*******************************************************//
int torneo()
{
	int valor,i,j,s,menor;
	j=0;
	do
	{
		s=0;
		valor=random(N);
		for(i=0;i<j;i++)
		{
			if(valor == padres[i])
			s=1;
		}
		if(s==0)
		{
			padres[j]=valor;
			j++;
		}
	}
	while(j<n);
	menor=padres[0];
	for(i=0;i<n;i++)
	{
		if(padres[i]<menor)
			menor=padres[i];
	}
	return menor;
}
//*******************************************************//
void cruce()
{
	int i,k,s=0,l,a,b;
	k=(int)(T/2);
	l=k+1;
	a=l;
	b=l;
	H1[k]=P1[k];
	H2[k]=P2[k];
	if((T%2)==0)
	{
		H1[k-1]=P1[k-1];
		H2[k-1]=P2[k-1];
		s=1;
	}
	for(i=0;i<T;i++)
	{
		if(s==0)
		{
			if(P2[l]!=H1[k])
			{
				H1[a]=P2[l];
				a++;
				if(a==T)
					a=0;
			}
			if(P1[l]!=H2[k])
			{
				H2[b]=P1[l];
				b++;
				if(b==T)
					b=0;
			}
		}
		else
		{
			if((P2[l]!=H1[k])&&(P2[l]!=H1[k-1]))
			{
				H1[a]=P2[l];
				a++;
				if(a==T)
					a=0;
			}
			if((P1[l]!=H2[k])&&(P1[l]!=H2[k-1]))
			{
				H2[b]=P1[l];
				b++;
				if(b==T)
					b=0;
			}
		}
		l++;
		if(l==T)
			l=0;
	}
}
//*******************************************************//
void mutar(int hijo[])
{
	int a,b,aux,s=0;
	a=random(T);
	b=random(T);
	do
	{
		if(a==b)
			b=random(T);
		else
			s=1;
	}while(s==0);
	aux=hijo[a];
	hijo[a]=hijo[b];
	hijo[b]=aux;
}
//*******************************************************//
void cambiar_poblacion()
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<T;j++)
			poblacion[i][j]=poblacion_aux[i][j];
}
//*******************************************************//
void prueba(int ite, float x1, float x2, float x3)
{
	FILE *file;
	int i,j;
	if (ite==1)
	{
		if((file=fopen("c:\\e\\Prueba.txt","w"))==NULL)
		{
			printf("No se pudo crear o abrir el Archivo Prueba.TXT");
			getch();
			exit(0);
		}
		fprintf(file,"\n\n******************************* Matriz Principal **********************************\n\n");
				for(i=0;i<T;i++)
				{
					for(j=0;j<T;j++)
						fprintf(file,"%i\t",M[i][j]);
					fprintf(file,"\n");
		}
	}
	else
	{
		if((file=fopen("c:\\e\\Prueba.txt","a"))==NULL)
		{
			printf("No se pudo crear o abrir el Archivo Prueba.TXT");
			getch();
			exit(0);
		}
	}
	fprintf(file,"\n\n*******************************Iteracion: %i **********************************\n\n",ite);
	fprintf(file,"Poblacion Actual\n\n");
	for(i=0;i<N;i++)
	{
		fprintf(file,"(%i)----->\t",i);
		for(j=0;j<T;j++)
			fprintf(file,"%i\t",poblacion[i][j]);
		fprintf(file,"-----> %i\t\n",costos[i]);
	}
	fprintf(file,"\n<--------Padres-------->\n\n");
	if(!(x1<PC))
		fprintf(file,"NO ");
	fprintf(file,"Hubo Cruce (%.4f) <---> (%.4f)\n",x1,PC);
	for(i=0;i<T;i++)
		fprintf(file,"%i\t",P1[i]);
	fprintf(file,"\n");
	for(i=0;i<T;i++)
		fprintf(file,"%i\t",P2[i]);
	fprintf(file,"\n\n<---------Hijos-------->\n\n");
	if(!(x2<PM))
		fprintf(file,"NO ");
	fprintf(file,"Mutó el 1er Hijo (%.4f) <---> (%.4f)\n",x2,PM);
	for(i=0;i<T;i++)
		fprintf(file,"%i\t",H1[i]);
	fprintf(file,"\n\n");
	if(!(x3<PM))
		fprintf(file,"NO ");
	fprintf(file,"Mutó 2do Hijo (%.4f) <---> (%.4f)\n",x3,PM);
	for(i=0;i<T;i++)
		fprintf(file,"%i\t",H2[i]);
	fprintf(file,"\n\nPoblacion Auxiliar\n\n");
		for(i=0;i<N;i++)
		{
			fprintf(file,"(%i)----->\t",i);
			for(j=0;j<T;j++)
				fprintf(file,"%i\t",poblacion_aux[i][j]);
			fprintf(file,"\n",i);
		}
	fprintf(file,"\nSolucion Actual\n");
	fprintf(file,"\n\n\n\nRecorrido:\n");
	for(i=0;i<T;i++)
		fprintf(file,"%i ",poblacion[0][i]);
	fprintf(file,"\n\nDistancia: %i\n\n",costos[0]);
	fprintf(file,"\nPoblacion total: %i",N);
	fprintf(file,"\nCantidad de candidatos a padre: %i",n);
	fprintf(file,"\nIteracion: %i",ite);
	fprintf(file,"\nPorcentaje GAP: %i",GAP);
	fprintf(file,"\nProbabilidad de cruce: %.2f",PC);
	fprintf(file,"\nProbabilidad de mutar: %.2f",PM);
	fclose(file);
}
//*******************************************************//
void algoritmo_genetico()
{
	int ite=1,i,j,k,a,b;
	float p1,p2,p3;
	generar_poblacion();
	evaluar();
	sort();
	do
	{
		aux_poblacion();
		for(i=GAP;i<N;i+=2)
		{
			a=torneo();
			b=torneo();
			for(j=0;j<T;j++)
			{
				P1[j]=poblacion[a][j];
				P2[j]=poblacion[b][j];
			}
			p1=random(100);
			p1/=100;
			if(p1<PC)
				cruce();
			else
				for(k=0;k<T;k++)
				{
					H1[k]=P1[k];
					H2[k]=P2[k];
				}
			p2=random(100);
			p2/=100;
			if(p2<PM)
				mutar(H1);
			p3=random(100);
			p3/=100;
			if(p3<PM)
				mutar(H2);
			for(k=0;k<T;k++)
			{
				poblacion_aux[i][k]=H1[k];
				poblacion_aux[i+1][k]=H2[k];
			}
		}
		cambiar_poblacion();
		evaluar();
		sort();
		prueba(ite,p1,p2,p3);
		ite++;
	}while(ite!=ITMAX);
}

//***********Programa Principal***********//
void main()
{
	int i;
	randomize();
	clock_t inicio;
	float tiempo;
	inicio=clock();
	clrscr();
	cargar();
	algoritmo_genetico();
	printf("********* Matriz de Adyancencia **********\n\n\n");
	mostrar();
	printf("\n\n\n\nRecorrido:\n");
	for(i=0;i<T;i++)
		printf("%i ",poblacion[0][i]);
	printf("\n\nDistancia: %i\n\n",costos[0]);
	printf("\nPoblacion total: %i",N);
	printf("\nCantidad de candidatos a padre: %i",n);
	printf("\nNumero de iteraciones %i",ITMAX);
	printf("\nPorcentaje GAP: %i",PGAP);
	printf("\nProbabilidad de cruce: %.2f",PC);
	printf("\nProbabilidad de mutar: %.2f",PM);
	tiempo=(clock()-inicio)/(double)CLOCKS_PER_SEC;
	printf("\n\nDuracion: %.4f seg.",tiempo);
	getch();
}