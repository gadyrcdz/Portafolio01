#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GrupoProducto {
    char* categoria;
    char* detalles;
    struct GrupoProducto* siguiente;
} GrupoProducto;

typedef struct Articulo {
    char* titulo;
    GrupoProducto* gProducto;
    struct Articulo* siguiente;
} Articulo;

// Función para crear un nuevo grupo de productos
GrupoProducto* nuevoGrupoProducto(char* categoria, char* detalles) {
    GrupoProducto* g = (GrupoProducto*)malloc(sizeof(GrupoProducto));
    if (g == NULL) {
        exit(1);
    }
    g->categoria = (char*)malloc(strlen(categoria) + 1);
    g->detalles = (char*)malloc(strlen(detalles) + 1);
    strcpy(g->categoria, categoria);
    strcpy(g->detalles, detalles);
    g->siguiente = NULL;
    return g;
}

// Función para crear un nuevo artículo
Articulo* nuevoArticulo(char* categoria, char* detalles, char* titulo) {
    GrupoProducto* gp = nuevoGrupoProducto(categoria, detalles);
    Articulo* art = (Articulo*)malloc(sizeof(Articulo));
    art->titulo = (char*)malloc(strlen(titulo) + 1);
    strcpy(art->titulo, titulo);
    art->gProducto = gp;
    art->siguiente = NULL;
    return art;
}

// Función para añadir un artículo a la lista
void agregarArticulo(Articulo** inicio, char* titulo, GrupoProducto* gp) {
    Articulo* nuevoArt = nuevoArticulo(gp->categoria, gp->detalles, titulo);
    if (*inicio == NULL) {
        *inicio = nuevoArt;
    } else {
        Articulo* actual = *inicio;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoArt;
    }
}

// Función para imprimir la lista de artículos
void mostrarArticulos(Articulo* cabeza) {
    Articulo* actual = cabeza;
    while (actual != NULL) {
        printf("Titulo: %s, Categoria: %s, Detalles: %s\n", actual->titulo, actual->gProducto->categoria, actual->gProducto->detalles);
        actual = actual->siguiente;
    }
}

int main() {
    Articulo* listaArticulos = NULL;
    Articulo* art1 = nuevoArticulo("Categoria 1", "Detalles 1", "Articulo 1");
    Articulo* art2 = nuevoArticulo("Categoria 2", "Detalles 2", "Articulo 2");

    listaArticulos = art1;
    art1->siguiente = art2;

    mostrarArticulos(listaArticulos);

    return 0;
}
