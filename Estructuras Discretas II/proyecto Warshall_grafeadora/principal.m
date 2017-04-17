
function[]= principal()
clc;
Rx=1;
while(Rx<=3)
disp(' UNIVERSIDAD JOSE ANTONIO PAEZ')
disp(' FACULTAD DE INGENIERIA')
disp(' ESCUELA DE COMPUTACION')
disp(' ASIGNATURA: ELECTIVA I - COMP. EMERGENTE')
disp(' SECCION: 308C1')
disp(' INTEGRANTES: ')     
disp(' Manuel Antonio Reyes          C.I.: 17.079.726')
disp(' Luis Miguez                   C.I.: 17.776.745 ')

disp('||=========================================================================||');
    disp('||                           I N C I D E N T E S                           ||');
    disp('||=========================================================================||');
    disp('||                                                                         ||');
    disp('||  Seleccione como introducir la matriz:                                  ||');
    disp('||       (1) Ingreso por Arcos                                             ||');
    disp('||       (2) Ingreso por Adyacente                                         ||');
    disp('||       (3) Creditos                                                      ||');
    disp('||       (4) SALIR                                                         ||');
    disp('||                                                                         ||');
    disp('||=========================================================================||');
    Rx=input('             Seleccione una opción: ');


switch(Rx)
    case 1,
        clc
        manual
        disp('Presione cualquier tecla para continuar...')
        pause;
        clc
        
    case 2,
        
        i,j=1;
        resp=0;
        clc
        r=input('Ingrese el grado de la matriz: \n\n -->>')
        disp('Matriz Aleatoria: ');
        MAT=round(rand(r))
        MAT=MAT'
        MAT=zeros(r,r);
        while resp==0
            clc
            for i=1:r
                for j=i:r
                    control=0;
                    while control==0
                        if i==j
                            MAT(i,j)=0;
                        else
                            fprintf('\nMatriz [ %i , %i]',i,j)
                            valor=input('\n(1/0)-->>');
                            if ((valor==0) | (valor==1))
                                MAT(i,j)=valor;
                                MAT(j,i)=MAT(i,j);
                                control=1;
                            end
                        end
                    end
                end
            end
            
            resp=input('¿Es correcta la matriz ingresada? (1|0): \n -->>');
        end      
        disp('Presione cualquier tecla para continuar...')
        pause;
        draw_layout(MAT)
        clc
    
    case 3,
        clc
       disp('      _   __                        ');
       disp('     | | / /                        ');
       disp('     | |/ /  ___   ___  _ __   __ _ ');
       disp('     |    \ / _ \ / _ \|  _ \ / _` |');
       disp('     | |\  \ (_) | (_) | |_) | (_| |');
       disp('     \_| \_/\___/ \___/| .__/ \__,_|');
       disp('                       | |          ');
       disp('                       |_|          ');
       disp(',_____ _ _              _           ');
       disp('| ___ (_) |            | |          ');
       disp('| |_/ /_| | ____ _  ___| |__  _   _ ');
       disp('|  __/| | |/ / _` |/ __| |_ \| | | |');
       disp('| |   | |   < (_| | (__| | | | |_| |');
       disp('\_|   |_|_|\_\__,_|\___|_| |_|\__,_|');
       disp(''); 
       disp('Presione Cualquier tecla para volver al menu...')
       pause;
       clc 
    case 4,
        clc
        break  
        
        
end
end
end