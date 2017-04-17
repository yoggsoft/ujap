clear all;
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
            ITE=PERCEPTRON(X,D,0.01);
            disp('|||| APRENDIZAJE DE FUNCION AND ||||||||||||||||||||||');
            disp('||                                                  ||');
            fprintf('||      Numero de iteraciones usadas:  %i',ITE);disp('            ||');
            disp('||                                                  ||');
            disp('||||||||||||||||||||||||||||||||||||||||||||||||||||||');
            pause();
        case 2,
            clc;
            D=[0;1;1;1];
            ITE=PERCEPTRON(X,D,0.01);
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
            ITE=PERCEPTRON(X,D,0.01);
            disp('||                                                             ||');
            disp('|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||');
            pause();
    end
end