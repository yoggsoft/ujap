% UNIVERSIDAD JOSE ANTONIO PAEZ
% FACULTAD DE INGENIERIA
% ESCUELA DE COMPUTACION
% ASIGNATURA: ELECTIVA I - COMP. EMERGENTE
% SECCION: 308C1
%
% INTEGRANTES:
%     Oscar Meza          C.I.: 17.614.360
%     Ricardo Gonzalez    C.I.: 18.180.965
%
% ======================= ADALINE (FUNCION SIGMOIDE) ======================
% ENTRADAS:   A: Termino Dependiente en la funcion 
%             B: Termino Independiente en la funcion
%             CTTE: Constante de Aprendizaje 
%             RUIDO: Ruido
%             ITE: Numero de Iteraciones o Epocas
% SALIDAS:    W: Vector de Pesos
%             ERROR: Error generado
% =========================================================================

function [W,ERROR]=ADAL(A,B,CTTE,RUIDO,ITE)
    PUNT=200;
    x=rand(PUNT,1);                     % Valores de entrada
    FUNC=vectorize(strcat(num2str(A),'*x+',num2str(B))); % Ajuste de la función dada
    D=eval(FUNC);                     % Salida real calculada.
    
    Dx=zeros(PUNT,1);                      % Salida con ruido
    for(i=1:PUNT)
        Dx(i)=D(i)+(-(2*RUIDO*rand())+rand());
    end
    
    x=[x -ones(PUNT,1)];                % Concatenamos X y el Umbral.
    W=zeros(2,1);                         % Vector de Pesos
    Epocas=0; 
    Y=zeros(PUNT,1);
    
    while(Epocas<=ITE)
        for(i=1:size(x))
            Act=x(i,:)*W;   % ACT = X(i)+W(i)-U
                                % Por tratarse de una función sigmoide 
                                % logistica, 'Y' se calcula como:
                                % Y = 1/(1+exp(-Act));
            Y(i)=1/(1+exp(-Act)); 
            ERROR=(D(i)-Y(i));
            for j=1:2
                W(j)=W(j)+CTTE*ERROR*Y(i)*(1-Y(i))*x(i,j); 
            end
            
        end          
        Epocas=Epocas+1;
        GRAF(x,D,Dx,W,Epocas);
    end