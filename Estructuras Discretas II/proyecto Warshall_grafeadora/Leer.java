import java.io.*;

//----------- Métodos para la Entrada de Datos ----------///

public class Leer{


        //**Cuando el datos e String
        public static String dato(){
        	
                String sdato = " ";
            
                try{
                	
                   InputStreamReader isr = new InputStreamReader(System.in);
                   
                   BufferedReader FlujoE = new BufferedReader(isr);
                   
                   sdato = FlujoE.readLine();
                  }
                catch(IOException e){
                	
                   System.err.println("Error:" + e.getMessage());
                   
                }
                return sdato;
            }
            
            //**Cuando el datos es Entero corto
            public static short datoShort(){
                
                try{
                   return Short.parseShort (dato());
                }
                catch (NumberFormatException e){
                	
                   return Short. MIN_VALUE;
                }
             }
             
             //**Cuando el dato es Entero
             public static int datoint(){
                try{
                	
                   return Integer.parseInt (dato());
                   
                }
                catch (NumberFormatException e){
                	
                   return Integer. MIN_VALUE;
                }
             }

             //**Cuando el datos es tipo Double
             public static double datoDouble(){
                try{
                   return Double.parseDouble (dato());
                }
                catch (NumberFormatException e){
                   return Double. NaN;
                }
             }
             
             //**Cuando el datos es Flotante
             public static float datoFloat(){
                try{
                   return Float.parseFloat (dato());
                }
                catch (NumberFormatException e){
                   return Float. NaN;
                }
             }

             //**Cuando el datos es Entero largo
             public static long datoLong(){
                try{
                   return Long.parseLong (dato());
                }
                catch (NumberFormatException e){
                   return Long.MIN_VALUE;
                }
             }
	}
 