#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define CABEZA 1 

/*tipos de datos astractos*/
typedef struct DirectorioTrabajador{
     unsigned char nombreTrabajador[20];
     unsigned char numeroTelefono[20]; 
     unsigned char direccionTrabajador[20];
}DirectorioTrabajador;

typedef struct NODO{
   DirectorioTrabajador DirectorioTrabajadores; 
   struct NODO* ptr_siguienteNodo;
}nodo; 
/*VARIABLES GLOBALES*/
nodo *colaLista=NULL;
nodo *cabezaLista=NULL;
unsigned char CantidadTrabajadores=0;  
enum {EscribirDatos=1,VerLista,EliminarNodo,BorrarLista,SalirMenu};

/*PROTOTIPO DE FUNCIONES*/
nodo *CrearNodo();
void InsertarEnLista();
void CrearTrabajador(nodo *nodo);  
void VaciarLista();
void ImprimirLista();
void ImprimirOpciones();
void EliminarElemento(unsigned char posicion);
unsigned char ElementoEliminar(); 
void GuardarListaEnArchivo();
/*INCIO DE LA FUNCION PRINCIPAL*/
int main(void){
     
   unsigned char MenuOpcion=0; 
   printf("BIENVENIDO....\r\n");

   while(TRUE){

       ImprimirOpciones();
        scanf("%hhd",&MenuOpcion); 
    
    if(MenuOpcion==SalirMenu){ 
        printf("finalizó sesion.Sus datos han sido almacenados correctamente\r\n");
        printf("los datos almacenados fueron:\r\n");
        ImprimirOpciones();
        VaciarLista(); 
        break;   
       } 

    switch (MenuOpcion){

            case EscribirDatos:
                            InsertarEnLista(); 
                            GuardarListaEnArchivo();
                            break;
            case VerLista: 
                            printf("actualmente se encuentran %d trabajadores.\r\n",CantidadTrabajadores); 
                            ImprimirLista(); 
                            break; 

            case EliminarNodo: 
                              EliminarElemento(ElementoEliminar()); 
                              break; 
            case BorrarLista: 
                            VaciarLista();
                            break; 

            default: printf("ingrese una opcion ueea valida\r\n");
                    break;
        }

     }//FIN DEL BUCLE INFINITO
   
    return 0;
}//FIN DE LA FUNCION PRINCIPAL


//
nodo* CrearNodo(){
  nodo *NuevoNodo=(nodo*)malloc(sizeof(nodo));
  if(NuevoNodo==NULL)printf("error!... insuficiente espacio en memoria\r\n");
    return(NuevoNodo);
}
//
void CrearTrabajador(nodo* nodo){
    fflush(stdin);
     printf("ingresa el nombre del trabajdor:\r\n");
      scanf("%s",nodo->DirectorioTrabajadores.nombreTrabajador);
    fflush(stdin); 
     printf("ingrese el numero telefonico de %s\r\n",nodo->DirectorioTrabajadores.nombreTrabajador); 
      scanf("%s",nodo->DirectorioTrabajadores.numeroTelefono);
    fflush(stdin);
     printf("ingrese la direccion del trabajaddor %s\r\n",nodo->DirectorioTrabajadores.nombreTrabajador);
      scanf("%s",nodo->DirectorioTrabajadores.direccionTrabajador);
    CantidadTrabajadores++;  
    }
//
void InsertarEnLista(){
  nodo *NuevoNodo=CrearNodo();
   
  if(cabezaLista==NULL && NuevoNodo!=NULL){
        CrearTrabajador(NuevoNodo);
       cabezaLista=NuevoNodo;
       colaLista=NuevoNodo;
      return; 
      }
    else if(NuevoNodo!=NULL){
         CrearTrabajador(NuevoNodo);
      colaLista->ptr_siguienteNodo=NuevoNodo;
      colaLista=NuevoNodo;  
        return; 
    }  
}
//
void VaciarLista(){
    if(cabezaLista==NULL){
       printf("esta lista es una lista vacia,por favor primero ingrese valores en ella\r\n");
        return; 
      }
    nodo *eliminarNodo=cabezaLista; 
    nodo *auxiliar=NULL; 
  while(eliminarNodo!=NULL){
        auxiliar=eliminarNodo->ptr_siguienteNodo;
        free(eliminarNodo); 
        eliminarNodo=auxiliar;     
       }
       cabezaLista=NULL;
       colaLista=NULL;
       CantidadTrabajadores=0; 
       printf("la lista se ha vaciado correctamente"); 
}

//
void ImprimirLista(){
    if(cabezaLista==NULL){
         printf("esta lista es una lista vacia, por favor primero ingrese valores en ella\r\n");
         return;
        }

     nodo *RecorrerNodo=cabezaLista;
    while(RecorrerNodo!=NULL){
           printf("\n\nnombre: %s\n numero telefonico: %s\ndireccion: %s\r\n",
           RecorrerNodo->DirectorioTrabajadores.nombreTrabajador,
           RecorrerNodo->DirectorioTrabajadores.numeroTelefono,
           RecorrerNodo->DirectorioTrabajadores.direccionTrabajador);
           RecorrerNodo=RecorrerNodo->ptr_siguienteNodo;
           }
           
}

void EliminarElemento(unsigned char posicion){
    unsigned char MoverPosicion=1; 
    nodo *buscarElemento=cabezaLista; 
    nodo *NodoAuxiliar=NULL;

    for(MoverPosicion=1; MoverPosicion!=posicion && buscarElemento->ptr_siguienteNodo!=NULL;MoverPosicion++){
          NodoAuxiliar=buscarElemento;
          buscarElemento=buscarElemento->ptr_siguienteNodo;         
        }
     if(MoverPosicion!=posicion || buscarElemento==NULL){
        printf("la posicion que desea buscar no se encuentra\\\
                \r\nen la lista o la lista está vacia");
               return;  
        }
      if(MoverPosicion==CABEZA) cabezaLista=buscarElemento->ptr_siguienteNodo; 
         else NodoAuxiliar->ptr_siguienteNodo=buscarElemento->ptr_siguienteNodo; 
            
     free(buscarElemento);
      CantidadTrabajadores--; 
}

void ImprimirOpciones(){
      printf("\n\nIngrese una opcion:\\\
      \n(1) para insertar datos en la lista.\\\
      \n(2) para ver los datos que hay en la lista.\\\
      \n(3)para eliminar un elemento de la lista.\\\
      \n(4) para eliminar todos los elementos de la lista.\\\
      \n(5)para final sesion en del menu\r\n");
}


unsigned char  ElementoEliminar(){
  unsigned char numero=0;
   printf("ingrese el numero del elemento que desea eliminar");
   scanf("%hhd",&numero);
   return(numero); 
}
void GuardarListaEnArchivo(){
  FILE *ptr_Archivo=fopen("DatosTrabajadores-txt","w");
  if(ptr_Archivo==NULL){
    printf("error al intentar abrir el archivo...\r\n");
    return; 
  } nodo *RecorrerLista=cabezaLista;
    fprintf(ptr_Archivo,"NOMBRE\tTELEFONO\tDIRECCION\r\n");
     while(RecorrerLista!=NULL){
           fprintf(ptr_Archivo,"%s\t%s\t%s\r\n",
           RecorrerLista->DirectorioTrabajadores.nombreTrabajador,
           RecorrerLista->DirectorioTrabajadores.numeroTelefono,
           RecorrerLista->DirectorioTrabajadores.direccionTrabajador);
            RecorrerLista=RecorrerLista->ptr_siguienteNodo;
           }
fclose(ptr_Archivo);
printf("elemento guardado\r\n");
  
}