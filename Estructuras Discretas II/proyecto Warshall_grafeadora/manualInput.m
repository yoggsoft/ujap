function[]= manualInput()
clc
disp('INGRESO MANUAL DE RED');
disp('');
Nnodos=input('Introduzca la cantidad de nodos: \n-->>');
fprintf('Grado de la Matriz: %i x %i \n',Nnodos,Nnodos)
a=0;
Rx=0;
while (Rx==0)
Nserver=input('Diga la cantidad de servidores: \n-->>');
while (Rx==0)
for i=1:Nserver
    fprintf('Diga la posicion del SERVIDOR %i: ',i);
    a=input('\n-->>');
    vec(i)=a;
end
disp('Los servidores estan en los nodos: ')
disp(vec)
fprintf('�Son correcto los nodos existentes y su posicion?(1/0): \n');
Rx=input('-->>');
end
Rx=0;
MAX=0;
while (Rx==0)
for i=1:Nnodos
    adj(i,i)=0;
    for j=1:Nnodos
        if (i~=j & i<j)
            fprintf('[%i,%i]: ',(i),(j))
            fprintf('Hay camino entre %i y %i? (1/0):  \n',(i),(j))
            resp=input('-->>');
            if (resp==1)
                adj(i,j)=resp;
                MAX=MAX+1;
            else 
                adj(i,j)=resp;
            end
        end
    end
end
C=adj+adj';
adj=C'
Rx=input('�Es correcta la matriz ingresada? (1/0): \n -->>');
G=warshall(adj,Nnodos);
disp('La Matriz Warshall es:');
disp('\n');
G
end
for i=1:Nserver
        fprintf('Conexion de Computadoras al SERVIDOR %i',vec(i));
        vectorIndice=adj(:,vec(i));
        vectorIndiceW=G(:,vec(i));
        disp('\n');
        disp(vectorIndice)
        disp(vectorIndiceW);
        disp('\n');
        for k=1:Nnodos
            if (vectorIndice(k)==vectorIndiceW(k))
               if(vectorIndice(k)==1)
                   pcOn(k)=k;
               else pcOn(k)=0;
               end
            end
        end 
end
disp('Las Computadoras no desconectables son:');
disp(pcOn);
disp('Al Desconectar estas computadoras, el sistema queda no funcional');
disp('Presione cualquier tecla para que Manuel no vea mas Discretas 2...');
pause;
clc
disp('Gracias por su cooperacion....');
pause;
end