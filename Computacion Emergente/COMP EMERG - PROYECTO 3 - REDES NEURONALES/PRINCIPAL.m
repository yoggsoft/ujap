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
% ============================== PRINCIPAL ===============================
clear all;
clc
disp('||=========================================================================||');
disp('||                                                                         ||');
disp('||                      UNIVERSIDAD JOSE ANTONIO PAEZ                      ||');
disp('||                          FACULTAD DE INGENIERIA                         ||');
disp('||                          ESCUELA DE COMPUTACION                         ||');
disp('||                ASIGNATURA: ELECTIVA I - COMP. EMERGENTE                 ||');
disp('||                              SECCION: 308C1                             ||');
disp('||                                                                         ||');
disp('||  INTEGRANTES:                                                           ||');
disp('||     Oscar Meza          C.I.: 17.614.360                                ||');
disp('||     Ricardo Gonzalez    C.I.: 18.180.965                                ||');
disp('||                                                                         ||');
disp('||=========================================================================||');
disp('             . . . Presione cualquier tecla para continuar . . .             ');
pause();
R=1;
while(R<=2)
    clc
    disp('||=========================================================================||');
    disp('||                       M E N U   P R I N C I P A L                       ||');
    disp('||=========================================================================||');
    disp('||                                                                         ||');
    disp('||  Seleccione el metodo a usar:                                           ||');
    disp('||       (1) Perceptrón                                                    ||');
    disp('||       (2) Adaline                                                       ||');
    disp('||       (3) SALIR                                                         ||');
    disp('||                                                                         ||');
    disp('||=========================================================================||');
    R=input('             Seleccione una opción: ');
    switch(R)
        case 1,
            Rx=1;
            while(Rx<=3)
                clc
                disp('||=========================================================================||');
                disp('||                           P E R C E P T R O N                           ||');
                disp('||=========================================================================||');
                disp('||                                                                         ||');
                disp('||  Seleccione la funcion a enseñar:                                       ||');
                disp('||       (1) AND                                                           ||');
                disp('||       (2) OR                                                            ||');
                disp('||       (3) XOR                                                           ||');
                disp('||       (4) Regresar al MENU PRINCIPAL                                    ||');
                disp('||                                                                         ||');
                disp('||=========================================================================||');
                Rx=input('             Seleccione una opción: ');
                X=[-1 0 0;-1 0 1;-1 1 0;-1 1 1];
                switch(Rx)
                    case 1,
                        clc;
                        D=[0;0;0;1];
                        ITE=PERCEP(X,D,0.01);
                        disp('|||| APRENDIZAJE DE FUNCION AND ||||||||||||||||||||||');
                        disp('||                                                  ||');
                        fprintf('||      Numero de iteraciones usadas:  %i',ITE);disp('            ||');
                        disp('||                                                  ||');
                        disp('||||||||||||||||||||||||||||||||||||||||||||||||||||||');
                        pause();
                    case 2,
                        clc;
                        D=[0;1;1;1];
                        ITE=PERCEP(X,D,0.01);
                        disp('|||| APRENDIZAJE DE FUNCION OR |||||||||||||||||||||||');
                        disp('||                                                  ||');
                        fprintf('||      Numero de iteraciones usadas:  %i',ITE);disp('            ||');
                        disp('||                                                  ||');
                        disp('||||||||||||||||||||||||||||||||||||||||||||||||||||||');
                        pause();
                    case 3,
                        clc;
                        disp('|||| APRENDIZAJE DE FUNCION XOR |||||||||||||||||||||||||||||||||');
                        disp('||                                                             ||');
                        D=[0;1;1;0];
                        ITE=PERCEP(X,D,0.01);
                        disp('||                                                             ||');
                        disp('|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||');
                        pause();
                end
            end
        case 2,
            Rxx=1;
            while(Rxx==1)
                clc
                disp('||=========================================================================||');
                disp('||                              A D E L I N E                              ||');
                disp('||=========================================================================||');
                disp('||                                                                         ||');
                disp('||  Se aplicara con funcion Sigmoide, ¿Que desea hacer?                    ||');
                disp('||       (1) Continuar                                                     ||');
                disp('||       (2) Regresar al MENU PRINCIPAL                                    ||');
                disp('||                                                                         ||');
                disp('||=========================================================================||');
                Rxx=input('             Seleccione una opción: ');
                if Rxx==1
                        clc
                        disp('::::: ADALINE CON FUNCION SIGMOIDE ::::::::::::::::::::');
                        disp(' ');
                        disp('    Forma de la Funcion a evaluar:   A*x+B');
                        A=input('    Valor de A: ');
                        B=input('    Valor de B: ');
                        CTTE=input('    Constante de Aprendizaje: ');
                        ITE=input('    Numero de Iteraciones: ');
                        RUIDO=input('    Ruido (Valores entre 0 y 1): ');
                        disp(' ');
                        disp('::::: RESULTADOS OBTENIDOS ::::::::::::::::::::::::::::');
                        [W,ERROR]=ADAL(A,B,CTTE,RUIDO,ITE);
                        disp('    Pesos: ');
                        disp(W);
                        disp('    Error: ');
                        disp(ERROR);
                        pause();
                end
            end
    end
end