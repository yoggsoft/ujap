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
% ============================= PERCEPTRON ===============================
% ENTRADAS:   X: Patrón de entrada en conjunto con el Umbral 
%             D: Salida Deseada
%             CTTE: Constante de Aprendizaje 
% SALIDAS:    ITE: Numero de Iteraciones
% =========================================================================
function [ITE]=perceptron (X,D,CTTE)
    T=size(X);              % Cantidad de filas y columnas de X
    ERROR=zeros(T(1),1);   % Vector de Errores 
    W=zeros(T(2),1);        % Vector de Pesos
    Y=zeros(T(1),1);        % Vector de Salidas del Sistema
    ITE=0;                 % Valor de retorno de la Función
    S=-1;                  % Condición de Termino
    while(S~=T(1)&&ITE<10000)
        for(i=1:T(1))
            ACTV=X(i,:)*W;   % ACTV = X(i)+W(i)-U
            if(ACTV>0)        % Asignación del valor de Y con base en el 
                Y(i)=1;         % resultado de activación,(Funcion Escalón) 
            else                % unitario.
        		Y(i)=0;
            end
        ERROR(i)=D(i)-Y(i);   % Cálculo del Error, (Val_Real-Val_Sistema)
            for(j=1:T(2))    % Ajuste de los pesos
                W(j)=W(j)+CTTE*ERROR(i)*X(i,j); 
            end                 % Fin del For 'j'
        end                     % Fin del For 'i'
        ITE=ITE+1;
        S=sum(ERROR==zeros);
    end   
    if(ITE==10000) 
        disp('||  En 10000 iteraciones el perceptron no ha podido converger  ||'); 
        disp('||  Cálculo Detenido                                           ||'); 
    end