function[] = manual()
clc
disp('INGRESO MANUAL DE VERTICES');
disp('');
Nnodos=input('Introduzca la cantidad de nodos: \n-->>')
fprintf('Grado de la Matriz: %i x %i \n',Nnodos,Nnodos);
adj=zeros(Nnodos);
MAX=0;
Rx=0;
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

Rx=input('¿Es correcta la matriz ingresada? (1|0): \n -->>');
end

disp('Presione cualquier tecla para continuar...');
pause;
MAX=Nnodos;
MAX=MAX*2;
actual=zeros(MAX,1)';
destino=zeros(MAX,1)';
estado=zeros(MAX,1)';
k=1;
while (k<MAX)
    for i=1:Nnodos
        for j=1:Nnodos
            if adj(i,j)==1
                actual(k)=i;
                destino(k)=j;
                k=k+1;
        end
    end
end
actual
destino
G=zeros(MAX);
G=zeros(MAX);
estado=zeros(MAX,1)';
for (i=1:MAX)
    G(actual(i),destino(i))=true;
end

G
pause
clc
disp('INGRESE LOS NODOS QUE DESEA HALLAR LOS RECORRIDOS: ');
disp('');
nodoA=input('Ingrese Nodo A: \n-->>');
nodoB=input('Ingrese Nodo B: \n-->>');
inicio=nodoA;
fin=nodoB;
a=inicio;
estado(1)=inicio;
%estado(1)
buscarcaminos(G,Nnodos,estado,a,fin)
draw_layout(adj);
end