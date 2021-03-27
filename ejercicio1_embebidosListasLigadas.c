#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define BANDERA 1

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
/**/
nodo *cabezaLista=NULL;
nodo *colaLista=NULL;

/*PROTOTIPO DE FUNCIONES*/
nodo *CrearNodo();
void InsertarEnLista();
void CrearTrabajador(nodo *nodo);  
void VaciarLista();
void ImprimirLista();
void ImprimirOpciones();
enum {EscribirDatos=1,VerLista,BorrarLista,SalirMenu};

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
                            break;
            case VerLista: 
                            ImprimirLista(); 
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

void ImprimirOpciones(){
      printf("\n\nIngrese una opcion:\\\
      \n(1) para insertar datos en la lista.\\\
      \n(2) para ver los datos que hay en la lista.\\\
      \n(3) para eliminar todos los elementos de la lista.\\\
      \n(4)para final sesion en del menu\r\n");
}