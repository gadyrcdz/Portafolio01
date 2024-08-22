#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct Patogeno {
    int efecto;
    char* nombre;
    struct Patogeno* next;
};

struct Vacuna {
    char* pais;
    char* vacuna;
    char* nombre;
    int cantidad;
    struct Vacuna* next;
};

struct CantidadCover {
    char* pais;
    char* nombre;
    struct CantidadCover* next;
};

// nodos de patogeno
struct Patogeno* crearPatogeno(int efecto, char* nombre) {
    struct Patogeno* nuevoPatogeno = (struct Patogeno*)malloc(sizeof(struct Patogeno));
    if (nuevoPatogeno == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevoPatogeno->nombre = malloc(strlen(nombre) + 1);
    if (nuevoPatogeno->nombre == NULL) {
        printf("Error al asignar memoria para el nombre.\n");
        exit(1);
    }
    strcpy(nuevoPatogeno->nombre, nombre);
    nuevoPatogeno->efecto = efecto;
    nuevoPatogeno->next = NULL;
    return nuevoPatogeno;
}

// agrega los nodos a la lista
void agregarPatogeno(struct Patogeno** head, int efecto, char* nombre) {
    struct Patogeno* nuevoPatogeno = crearPatogeno(efecto, nombre);
    if (*head == NULL) {
        *head = nuevoPatogeno;
    } else {
        struct Patogeno* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuevoPatogeno;
    }
}


// free obligatorio
void liberarListaPatogenos(struct Patogeno* head) {
    struct Patogeno* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->nombre);
        free(temp);
    }
}

// nodo vacuna
struct Vacuna* crearVacuna(char* pais, char* vacuna, char* nombre, int cantidad) {
    struct Vacuna* nuevaVacuna = (struct Vacuna*)malloc(sizeof(struct Vacuna));
    if (nuevaVacuna == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevaVacuna->pais = malloc(strlen(pais) + 1);
    nuevaVacuna->vacuna = malloc(strlen(vacuna) + 1);
    nuevaVacuna->nombre = malloc(strlen(nombre) + 1);

    if (nuevaVacuna->pais == NULL || nuevaVacuna->vacuna == NULL || nuevaVacuna->nombre == NULL) {
        printf("Error al asignar memoria para las cadenas.\n");
        exit(1);
    }
    
    strcpy(nuevaVacuna->pais, pais);
    strcpy(nuevaVacuna->vacuna, vacuna);
    strcpy(nuevaVacuna->nombre, nombre);
    nuevaVacuna->cantidad = cantidad;
    nuevaVacuna->next = NULL;
    return nuevaVacuna;
}

// agrega los nodos a la lista
void agregarVacuna(struct Vacuna** head, char* pais, char* vacuna, char* nombre, int cantidad) {
    struct Vacuna* nuevaVacuna = crearVacuna(pais, vacuna, nombre, cantidad);
    if (*head == NULL) {
        *head = nuevaVacuna;
    } else {
        struct Vacuna* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuevaVacuna;
    }
}

// imprime vacunas
void imprimirVacunas(struct Vacuna* head, char* pais, char* patogeno) {
    struct Vacuna* temp = head;
    int cantidadBus = 0;
    while (temp != NULL) {
        if(strcmp(temp->pais,pais)==0){
            if(strcmp(temp->nombre,patogeno)==0){
                cantidadBus+=temp->cantidad;
                temp = temp->next;

            }else{
                temp = temp->next;
            }       

        }else{

            temp = temp->next;
        }
    }
    printf("Pais: %s, Nombre del Patogeno: %s, Cantidad: %d\n", pais, patogeno, cantidadBus);


}



// free obligatorio
void liberarListaVacunas(struct Vacuna* head) {
    struct Vacuna* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->pais);
        free(temp->vacuna);
        free(temp->nombre);
        free(temp);
    }
}
int main() {
    int opcion;
    char repetir = TRUE;
    int cantidadP = 0;
    struct Patogeno* listaPatogenos = NULL;
    struct Vacuna* listaVacunas = NULL;
    struct CantidadCover* listaCantidadCover = NULL;

    do {
        printf("\n\nMenu de Opciones\n");
        printf("1. Incluir Patogeno\n");
        printf("2. Incluir Vacuna\n");
        printf("3. Incluir Cantidad Cubierta\n");
        printf("4. Salir\n");

        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int efect;
                char* name = (char*)malloc(100 * sizeof(char));
                printf("Incluir Patogeno nombre: \n");
                scanf("%s", name);

                printf("Incluir Patogeno efecto: \n");
                scanf("%d", &efect);

                agregarPatogeno(&listaPatogenos, efect, name);
                cantidadP+=1;
                break;
            }
            case 2: {
                char* pais = (char*)malloc(100 * sizeof(char));
                char* vacuna = (char*)malloc(100 * sizeof(char));
                char* nombre = (char*)malloc(100 * sizeof(char));
                int cantidad;

                printf("Incluir pais de origen: \n");
                scanf("%s", pais);

                printf("Incluir nombre de la vacuna: \n");
                scanf("%s", vacuna);

                printf("Incluir nombre del patogeno: \n");
                scanf("%s", nombre);

                printf("Incluir cantidad disponible: \n");
                scanf("%d", &cantidad);

                agregarVacuna(&listaVacunas, pais, vacuna, nombre, cantidad);
                break;
            }
            case 3: {
                char* pais = (char*)malloc(100 * sizeof(char));
                char* nombreP = (char*)malloc(100 * sizeof(char));
                printf("Pais a Buscar: \n");
                scanf("%s", pais);

                printf("Patogeno a Buscar: \n");
                scanf("%s", nombreP);
                

                imprimirVacunas(listaVacunas,pais,nombreP);
                break;
            }
            case 4: {
                repetir = FALSE;
                break;
            }
            default:
                printf("Opción no válida.\n");
        }
    } while (repetir);


    return 0;
}
