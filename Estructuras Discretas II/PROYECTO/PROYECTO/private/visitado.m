function[fuevisitado]=visitado(nodo,state)
fuevisitado=false;
cursor=1;
while (state(cursor)~=1)
    if (state(cursor) == nodo)
        fuevisitado=true;
        cursor=cursor+1;
    else
        fuevisitado=false;
    end
end
end

