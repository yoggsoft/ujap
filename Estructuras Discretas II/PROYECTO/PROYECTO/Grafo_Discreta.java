// Rafael
// Yaruby
// Yudith

import java.awt.*;
import java.awt.event.*;
import java.io.*;

class Grafo_Discreta{
	
	//---Variables
	String resp;
	int MatrizAd[][];
    int NodoA,NodoB;	
	int i,j,h,k,p;
	boolean esta=false;
    public boolean G[][];
    public int estado[], pos=0, a, b=0;
    public static int inicio, fin;
    int Nnodos;	
	public int MAX;
	public int numNodos;
	public int actual1[];
	public int destino1[];
	boolean bandera=false;
    
    	
    public static void main( String args[] ) 
    {        
        new Grafo_Discreta();
    }
    
    public Grafo_Discreta()
    {
    	
    	try{
         
        System.out.print("Introduzca la cantidad de nodos: ");
		Nnodos=Leer.datoint();
		numNodos=Nnodos;
		System.out.println("El tamaño de la matriz es de: " +Nnodos+"x"+Nnodos);
		
		//-Se define el tamaño de la matriz de Adyacencia
		MatrizAd = new int[Nnodos][Nnodos];
		
		
		System.out.println("");
		System.out.println("Ingrese s para responder 'SI' o n para responder 'NO'");
		System.out.println("");
     	MAX=0;
     	for(i=0 ; i < Nnodos ; i++){
			
			 MatrizAd[i][i]=0;//--marca la diagonal de la matriz

             for(j=0 ; j < Nnodos ; j++){
                    
        	 	    if(i!=j & i<j){ //--Condicional para no ingresar diagonal
        	 	                    //--y solo pide la triangular superior
         		
          		       		System.out.print("["+(i+1)+"]"+"["+(j+1)+"] :");
          		       		System.out.print("Existe camino entre el vertice["+(i+1)+"] y el vertice["+(j+1)+"] ? (s/n):");
                       		resp=Leer.dato();
          		         
          		       		if(resp.compareTo("s")==0 | resp.compareTo("S")==0)
          		       		{
          		       	  		MatrizAd[i][j]=1; //1-posee comunicación
          		       	  		MatrizAd[j][i]=MatrizAd[i][j];
          		       	  		MAX++;
          		       	  		
          		       		}
          		       		if(resp.compareTo("n")==0 | resp.compareTo("N")==0)
          		       		{
          		       	  		MatrizAd[i][j]=0; //2-no posee comunicación
          		       	  		MatrizAd[j][i]=MatrizAd[i][j];
          		       		}   		       		
        		    }
          	        MatrizAd[i][i]=0; //--
             }
             System.out.println("");
        }
        
        System.out.println("Matriz de Adyacencia...");
        System.out.println("");
          
		for( i=0 ; i < Nnodos ;i++)
		{
            for(j=0 ; j < Nnodos ; j++)
            {

         	 System.out.print(" "+MatrizAd[i][j]+" ");
            }
            System.out.println("");
            System.out.println("");
        }

        MAX=MAX*2;
       	actual1= new int[MAX];
	    destino1= new int[MAX];
        k=0;  
        while( k!=MAX )
        {
           for( i=0 ; i < Nnodos ; i++){
               for(j=0 ; j < Nnodos; j++){

                  if(MatrizAd[i][j]==1){
               	 
               	    actual1[k]=i+1;
               	    destino1[k]=j+1;
               	    k++;
                  }
               }
           }   
        } 	       	    
	   	//--Se Ingresan los nodos a buscar			
		System.out.println("");
        System.out.println("Ingrese el Nodo#1 y Nodo#2 para saber si existe camino");
        System.out.print("Ingrese Nodo#1: ");
        NodoA=Leer.datoint();
        System.out.print("Ingrese Nodo#2: ");
    	NodoB=Leer.datoint();    
	    
	    inicio=NodoA;
	    fin=NodoB;
	    
	    MainCaminos(actual1, destino1);

      
        }
        catch(NumberFormatException e)
        {
        	  System.out.println("Formato invalido!!!");
              System.err.println("Error:" + e.getMessage());
        }
              
  }
  
  /**
   * En este constructor inicializamos el grafo y las variables y llamamos al
   * método que busca los caminos.
   * -param actual Vector que contiene los nodos "inicio" de cada arista.
   * -param destino Vector que contiene los nodos "destino" de cada arista.
   */

  public void MainCaminos(int actual[], int destino[])
  {
    G = new boolean [MAX][MAX];
    estado = new int [MAX];

    for (int i = 0; i < MAX; i++) {
      estado[i] = 0;
      for (int j = 0; j < MAX; j++)
        G[i][j] = false;
    }

    for (int i = 0; i < actual.length; i++)
      G[actual[i]][destino[i]] = true;

    a=inicio;
    estado[0]=inicio;

    for (i=0;i<MAX;i++)
    {
    	for (j=0;j<MAX;j++)
    	{
    		System.out.print(" "+G[j][i]+" ");
    		System.out.print("||");   	
    	}
    	System.out.println("");
    }

    buscarCaminos(estado);
  }  
  /**
   * Éste método sigue un esquema de backtracking (todas las soluciones). Busca
   * todos los caminos simples entre el nodo inicial y el final y va mostrando
   * las soluciones encontradas.
   * -param estado Almacena las soluciones encontradas.
   */

  public void buscarCaminos(int estado[]){
    int aux=0;
    b=0;
    do{
      a=estado[pos];
      b++;
      if (G[a][b] && !visitado(b)){
          pos++;
          estado[pos]=b;
          if (!esFinal(b)){
          	  bandera=false;
		      buscarCaminos(estado);
		      
          }else{
          	  bandera=true;
              escribirSolucion();
              
          }   
            b=estado[pos];
       		estado[pos]=0;//borrar estado
       		pos--;
       	  //break; //Primera solución
     }
   }while (b <= numNodos-1);
          
     if(bandera==false){
      	System.out.println("No hay camino!!!");
     }
  }
  
  /**
   * Comprueba si el nodo es el nodo destino.
   * -param nodo Nodo a comprobar.
   * -return Devuelve true si es el estado final, false de lo contrario.
   */

  public boolean esFinal (int nodo)
  {
      return (nodo == fin);
  }

  /**
   * Escribe la solucón por pantalla.
   */

  public void escribirSolucion()
  {
    String sol="Solucion: [ ";
    int cursor=0;
    while (estado[cursor] != 0){
      sol+=(estado[cursor]+" ");
      cursor++;
    }
    sol+=("]");
    System.out.println(sol);
  }

  /**
   * Compureba que el nodo no esté en la solución para no volver a visitarlo y
   * que asi el camino sea simple.
   * -param nodo Nodo a comprobar
   * -return Devuelve true si ya ha sido visitado, flase de lo contrario.
   */

  public boolean visitado(int nodo)
  {
    boolean fueVisitado=false;
    int cursor=0;
    while (estado[cursor] != 0){
      if (estado[cursor] == nodo)
        fueVisitado=true;
        cursor++;
    }
    return fueVisitado;
  }

  

}



