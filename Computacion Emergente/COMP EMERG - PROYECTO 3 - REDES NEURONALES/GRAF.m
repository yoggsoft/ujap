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
% =============================== GRAFICAR ================================
% ENTRADAS:   X: Valores de Entrada con umbral
%             D: Salida real calculada
%             Dx: Salida con ruido
%             W: Vector de Pesos
%             ITEx: Numero de Iteraciones o Epocas
% =========================================================================
function graficar(X,D,Dx,W,ITEx)
plot(X,D,'r-');
hold on;
    plot(X,Dx,'go');
    X2=X;
    D2=(W(1)*X2)-W(2);
    plot(X2,D2,'b-');
    T=strcat('Interacion: ',num2str(ITEx));
    title(T);
    pause(0.05);
hold off;