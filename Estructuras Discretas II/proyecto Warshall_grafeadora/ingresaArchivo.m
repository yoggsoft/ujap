function[]=ingresaArchivo()
nombrearchivo = input('Ingrese el nombre del archivo: ','s');
[arch,error]=fopen(nombrearchivo,'r');
if (arch > -1)
    vector = fscanf(arch,'%lf');
    res=fclose(arch);
    disp('los numeros son: ');
    vector
else 
    disp('Error al abrir el archivo');
end