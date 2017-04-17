function[]=buscarcaminos(MatBol,Nodos,vecEst,Emp,Term)
G=MatBol;
Nnodos1=Nodos;
estado1=vecEst;
a1=Emp;
fina=Term;
aux=0;
b=1;
pos=1;
control=true;
while (b~=fina)
    a1=vecEst(pos);
    b=b+1;
    if ((G(a1,b)==true) & ~visitado(b,vecEst))
        b=b+1;
        pos=pos+1;
        vecEst(pos)=b;
        vecEst;
        if (b~=fina)
            control=false;
            pos=pos+1;
            buscarcaminos(G,Nnodos1,vecEst,a1,fina);
        else
            control=true;
            vecEst
        end    
        b=vecEst(pos);
        vecEst(pos)=0;
        pos=pos-1;
    end
    
end    
    if (control==false)
        disp('\n No hay ningun camino entre esos vertices...');
        disp('\n Presione cualquier tecla para terminar...');
        pause;
        clc
    end