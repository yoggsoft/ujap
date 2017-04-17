///////////////////////////////////////////////////////////////////////////
// Programa VIDA. Compilada con Borland C++ 3.1 sin uso de objetos
//
// Esto no es un ejemplo de buena programacion ni esta optimizado
// en velocidad, solo tiene por proposito ilustrar sobre el algoritmo
// de VIDA. Es decir, esta pensado para ser facil de entender.
//
///////////////////////////////////////////////////////////////////////////
#include <conio.h>             // funciones de impresion
#include <stdlib.h>            // funciones aleatorias
#include <dos.h>               // el delay()

#define FILAS 80               // 80 es el maximo
#define COLS 49                // 49 es el maximo
#define POBLACION_INICIAL 900  // 3920 es el maximo
#define VELOCIDAD 300          // Menor numero es mas rapido
#define CELULA 1               // No modificar

char pantalla[FILAS][COLS];    // Pantalla del ciclo anterior
char pantalla2[FILAS][COLS];   // Pantalla del ciclo actual

///////////////////////////////////////////////////////////////////////////
//      Inicializa la matriz de pantaala y pone las celulas iniciales
///////////////////////////////////////////////////////////////////////////
void IniciarPantalla(void)
{
unsigned int col,
				 fila;

for(col=0; col<COLS; col++)                // Exploramos todo el mundo
	for(fila=0; fila<FILAS; fila++)
		pantalla2[fila][col]=0;              // Pomemos el mundo a 0 (vacio)

for(int n=0; n<POBLACION_INICIAL; n++)     // Siembra celulas aleatoriamente
	{
	fila=random(FILAS);
	col=random(COLS);
	pantalla2[fila][col]=CELULA;
	}
}


///////////////////////////////////////////////////////////////////////////
//  Imprime en pantalla la matriz de las celulas  (modo texto 80x25)
///////////////////////////////////////////////////////////////////////////
void ImprimirPantalla(unsigned int ciclo)
{
unsigned int col,
				 fila,
				 poblacion=0;                       // Contador de la poblacion

textcolor(10);                                  // color verde. Innecesario
																// pero bonito :-)
for(col=0; col<COLS; col++)
	for(fila=0; fila<FILAS; fila++)
		{
		pantalla[fila][col]=pantalla2[fila][col]; // Actualiza los cambios
		pantalla2[fila][col]=0;                   // Borramos el antiguo mundo
		if(pantalla[fila][col]==CELULA)           // Si hay celula
			{
			gotoxy(fila+1,col+1);                  // Vamos a esa casilla
			putch('O');                            // Imprimimos la celula
			poblacion++;                           // y la contamos
			}
		else                                      // Si no la hay
			gotoxy(fila+1,col+1);                  // Vamos a esa casilla
			putch(' ');                            // y la vacimos
		}

gotoxy(1,COLS+1);                               // Imprimimos las estadisticas
textcolor(15);
cprintf("CICLO:%-5u POBLACION:%-5u          ESC: Salir", ciclo, poblacion);
}


///////////////////////////////////////////////////////////////////////////
//  Cuenta los vecinos a una celula dada
///////////////////////////////////////////////////////////////////////////
unsigned char CuentaVecinos(long fila, long col)
{
unsigned char vecinos=0;
long arriba,
	  abajo,
	  izquierda,
	  derecha;

  // calcula las ayacentes (mundo toroidal)
arriba=fila-1;
if(arriba<0) arriba=FILAS-1;

abajo=fila+1;
if(abajo==FILAS) abajo=0;

izquierda=col-1;
if(izquierda<0) izquierda=COLS-1;

derecha=col+1;
if(derecha==COLS) derecha=0;

if(pantalla[arriba][izquierda]==CELULA) vecinos++;
if(pantalla[arriba][col]==CELULA) vecinos++;
if(pantalla[arriba][derecha]==CELULA) vecinos++;

if(pantalla[fila][izquierda]==CELULA) vecinos++;
if(pantalla[fila][derecha]==CELULA) vecinos++;

if(pantalla[abajo][izquierda]==CELULA) vecinos++;
if(pantalla[abajo][col]==CELULA) vecinos++;
if(pantalla[abajo][derecha]==CELULA) vecinos++;
return(vecinos);
}


///////////////////////////////////////////////////////////////////////////
//   Calcula si la celulas se reproducen, viven o mueren
///////////////////////////////////////////////////////////////////////////
void CicloVida(void)
{
unsigned int col,
				 fila;

for(col=0; col<COLS; col++)              // Exploramos todo el mundo
	for(fila=0; fila<FILAS; fila++)
		{
		unsigned char vecinos;

		vecinos=CuentaVecinos(fila,col);   // Cuenta los vecinos de esa casilla

		if(pantalla[fila][col]==0 &&       // Si en una casilla vacia y
			vecinos==3)                     // hay tres vecinos
				pantalla2[fila][col]=CELULA; // nace una celula

		if(pantalla[fila][col]==CELULA &&  // Si hay una celula y
			vecinos>1 &&                    // tiene mas de dos vecinos y
			vecinos<4)                      // menos de cuatro
				pantalla2[fila][col]=CELULA; // la celula sobrevive
		}

}


///////////////////////////////////////////////////////////////////////////
//컴컴컴컴컴컴컴컴컴 Nos despedimos y pomenos los creditos 컴컴컴컴컴컴컴컴
///////////////////////////////////////////////////////////////////////////
void DespedidaYCierre(void)
{
clrscr();
cprintf("\r\n\r\n\r\n");
cprintf("                IMPLEMENTACION DEL PROGRAMA VIDA\r\n");
cprintf("\r\n");
cprintf("   Bueno, esto es todo. Este programa esta en modo texto y no tiene\r\n");
cprintf(" ninguna optimizacion en velocidad, ni siquiera la implementacion\r\n");
cprintf(" esta pensada para ser veloz. Su unico proposito es ilustrar sobre\r\n");
cprintf(" algoritmo del programa. De las multiples implementaciones de este\r\n");
cprintf(" esta es seguramente la mas senciila de entender.\r\n\r\n");
cprintf("   Programado por SILICOn, y puesto bajo licencia GNU. Modificalo y\r\n");
cprintf(" distribullelo como gustes, pero no te olvides de citar la fuente.\r\n");
cprintf("\r\n");
cprintf("\r\n");
cprintf("   NOTA: Es mi primera escursion en la vida artificial.\r\n");
}


///////////////////////////////////////////////////////////////////////////
// La funcion principal
///////////////////////////////////////////////////////////////////////////
void main(void)
{
unsigned int ciclo=0;        // Ciclo de vida actual

textmode(C4350);             // Modo texto de 80x50
directvideo=1;               // Escritura directa a pantalla (mas rapido)
randomize();                 // Inicializa aleatoriamente el aleatorizador :-)
IniciarPantalla();           // Borra el mundo y siembra las primeras celulas

while(!kbhit())              // Mientras no pulsemos una tecla
	{
	ciclo++;                  // Contamos un ciclo mas
	ImprimirPantalla(ciclo);  // Imprimimos el mundo en la pantalla
	CicloVida();              // Calculamos un ciclo de vida
	delay(VELOCIDAD);         // Esperamos para que valla mas despacio
	}
DespedidaYCierre();
}
