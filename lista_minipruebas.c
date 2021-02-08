#include <stdio.h>
#include "lista.h"

void mostrar_elemento(void* elemento, void* contador){
	if(elemento && contador){
		printf("Elemento %i: %c\n", *(int*)contador, *(char*)elemento);
		(*(int*)contador)++;
	}
}



void probar_operaciones_lista(){
	lista_t* lista = lista_crear();

	char j='j', u='u', l='l', i='i', a='a', n='n', p='p', q='q', x='x';

	if(lista_vacia(lista))
		printf("La lista esta vacia");
	lista_insertar(lista, &a);
	if(!lista_vacia(lista))
		printf("La lista ya no esta vacia!\n");
	lista_insertar(lista, &n);
	lista_insertar_en_posicion(lista, &j, 0);
	lista_insertar_en_posicion(lista, &u, 1);
	lista_insertar_en_posicion(lista, &l, 2);
	lista_insertar_en_posicion(lista, &i, 3);
	lista_insertar(lista, &p);
	lista_insertar(lista, &q);
	lista_insertar(lista, &x);

	/*Borrar primer elemento*/
	lista_borrar_de_posicion(lista, 6);
	
	/*Borrar elemento en una lista vacia*/
	lista_t* lista_2 = lista_crear();
	lista_borrar(lista_2);
	
	/*Lista borrar pruebas*/
	lista_borrar_de_posicion(lista, 6);
	lista_borrar_de_posicion(lista, 6);

	/*Borrar de lista nula*/
	lista_borrar_de_posicion(NULL, 2);

	/* Pedir elemento de lista nula */
	if(lista_ultimo(lista_2))
		printf("ULTIMO ELEMENTO LISTA VACIA: %c", *(char*)lista_ultimo(lista_2));	

	/*Borrar de lista vacia*/
	lista_borrar_de_posicion(lista_2, 2);
	
	/* Pedir elemento de lista vacia */
	lista_elemento_en_posicion(lista_2, 2);

	/*Borrar elemento nulo*/
	lista_insertar_en_posicion(lista, NULL, 6);
	lista_borrar_de_posicion(lista, 6);

	/* Cantidad de elementos de lista NULL es 0 */
	lista_elementos(NULL);

	/* Agregar elemento - borrarlo y luego chequear si la lista esta vacia */
	lista_t* lista_1 = lista_crear();
	char k = 'k';
	printf("Inserto k\n");
	lista_insertar(lista_1, &k);
	printf("Borro k\n");
	printf("Muestro la lista\n");
	printf("Elemento: %c\n", *(char*)lista_elemento_en_posicion(lista_1, 0));
	printf("Vuelvo a borrar el elemento\n");
	lista_borrar_de_posicion(lista_1, 4);
	if(lista_vacia(lista_1))
		printf("La lista esta vacia\n");
	printf("Vuelvo a insertar k\n");
	lista_insertar(lista_1, &k);
	lista_borrar(lista_1);
	printf("Lo borro\n");
	if(lista_vacia(lista_1))
		printf("La lista quedo vacia");

	/* MUESTRO LOS ELEMENTOS DE LA LISTA */

	printf("Elementos en la lista: ");
	for(size_t i=0;i<lista_elementos(lista);i++)
		printf("%c ", *(char*)lista_elemento_en_posicion(lista, i));

	printf("\n\n");

	printf("Imprimo la lista usando el iterador externo: \n");
	lista_iterador_t* it = lista_iterador_crear(lista);
	while(lista_iterador_tiene_siguiente(it))
		printf("%c ", *(char*)lista_iterador_siguiente(it));
	printf("\n\n");

	lista_iterador_destruir(it);

	int contador=0;
	printf("Imprimo la lista usando el iterador interno: \n");
	lista_con_cada_elemento(lista, mostrar_elemento, (void*)&contador);
	printf("\n");

	lista_destruir(lista_1);
	lista_destruir(lista_2);
	lista_destruir(lista);
}

void probar_operaciones_cola(){
	lista_t* cola = lista_crear();

	int numeros[]={1,2,3,4,5,6};

	for(size_t i=0;i<sizeof(numeros)/sizeof(int);i++){
		printf("Encolo %i\n", numeros[i]);
		lista_encolar(cola, &numeros[i]);
	}

	printf("\nDesencolo los numeros y los muestro: ");
	while(!lista_vacia(cola)){
		printf("%i ", *(int*)lista_primero(cola));
		lista_desencolar(cola);
	}
	printf("\n");
	lista_destruir(cola);
}

void probar_operaciones_pila(){
	lista_t* pila = lista_crear();
	char* algo="somtirogla";

	for(int i=0;algo[i]!= 0;i++){
		printf("Apilo %c\n", algo[i]);
		lista_apilar(pila, &algo[i]);
	}

	printf("\nDesapilo y muestro los elementos apilados: ");
	while(!lista_vacia(pila)){
		printf("%c", *(char*)lista_tope(pila));
		lista_desapilar(pila);
	}
	printf("\n");

	lista_destruir(pila);
}

int main(){

	printf("Pruebo que la lista se comporte como lista\n");
	probar_operaciones_lista();

	printf("\nPruebo el comportamiento de cola\n");
	probar_operaciones_cola();

	printf("\nPruebo el comportamiento de pila\n");
	probar_operaciones_pila();
	return 0;
}
