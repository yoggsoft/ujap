#include<conio.h>
#include<stdio.h>
void main()
{
	int i,c=0;
	FILE *p;
	clrscr();
	if((p=fopen("C:\\ASCII.txt","w"))==NULL)
		printf("No se pudo abrir el archivo ASCII.txt");
	else
	{
		for(i=0;i<=300;i++)
		{
			printf("Alt  %i: %s\n",i,&i);
			fprintf(p,"Alt %i: %s\n",i,&i);
			if(c==20)
			{
				c=1;
				printf("\nPresione cualquier tecla para continuar con los prox 20 ...");
				getch();
            clrscr();
			}
			else
				c++;
		}
		fclose(p);
		printf("La lista ha sido creada correctamente.");
	}
	getch();
}