#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define LEFT_UPPER_CORNER "┌"
#define RIGHT_UPPER_CORNER "┐"
#define LEFT_LOWER_CORNER "└"
#define RIGHT_LOWER_CORNER "┘"
#define HORIZONTAL_LINE "─"
#define VERTICAL_LINE "│"
#define TOP_T "┬"
#define BOTTOM_T "┴"
#define LEFT_T "├"
#define RIGHT_T "┤"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#define CLEAN_SCREEN "\033[2J"

void gotoxy(int x, int y)
{
	printf("\033[%d;%dH", y, x);
}

int rangedRand(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

/* -------------------------------------- PRACTICA 11 ---------------------------------------------------*/
/*Estructura para el nodo de la lista doblemente enlazada circular*/
struct DLNode
{
	int positionList;
	char stringNode[10];
	struct DLNode *next;
	struct DLNode *prev;
} *DLhead = NULL;

struct DLNodeHead
{
	DLNode *entry;
};

DLNodeHead eliminados = {0};
DLNodeHead insertados = {0};
DLNodeHead DoubleLinkdeList = {0};

void DLNode_append(DLNodeHead *head, DLNode *data)
{
	if (head->entry == NULL)
	{
		head->entry = data;
		head->entry->next = head->entry;
		head->entry->prev = head->entry;
	}
	else
	{
		DLNode *temp = head->entry;
		while (temp->next != head->entry)
		{
			temp = temp->next;
		}
		temp->next = data;
		data->prev = temp;
		data->next = head->entry;
		head->entry->prev = data;
	}
}

struct Node
{
	int data;
	char user[10];
	struct Node *next;
	struct Node *prev;
} *head = NULL; // lo interpretamos como el apuntador primero

// HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

char sp_car[] = {"#$%&/?+!._"};
char sp_num[] = {"0123456789"};
char sp_may[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char sp_min[] = {"abcdefghijklmnopqrstuvwxyz"};

char vocales[] = {"aeiou\0"};

/*---------------------------------DESARROLLO DE FUNCIONES ---------------------------------------*/

/**
 * @brief Genera una cadena compuesta por caracteres aleatorios
 *
 * 1 mayuscula + 2 minusculas + 2 numeros + 1 caracter especial:
 *
 * (solo del arreglo sp_car) + una mayuscula, en ese orden
 *
 * @param user
 */
void GenCad(char *user)
{
	// user = (char*)malloc(1+2+2+1+1+1);
	strncat(user, sp_may + rangedRand(0, strlen(sp_may) - 1), 1);

	strncat(user, sp_min + rangedRand(0, strlen(sp_min) - 1), 1);
	strncat(user, sp_min + rangedRand(0, strlen(sp_min) - 1), 1);

	strncat(user, sp_num + rangedRand(0, strlen(sp_num) - 1), 1);
	strncat(user, sp_num + rangedRand(0, strlen(sp_num) - 1), 1);

	strncat(user, sp_car + rangedRand(0, strlen(sp_car) - 1), 1);

	strncat(user, sp_may + rangedRand(0, strlen(sp_may) - 1), 1);

	user[10] = '\0';
}

/**
 * @brief Genera un nodo, implementa la informacion en el nodo y lo retorna
 *
 * @return struct Node*
 */
struct Node *GeneraNodo()
{
	Node *newNode = new Node;
	newNode->data = 100 + rand() % 501;

	GenCad(newNode->user);

	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

/**
 * @brief Inserta un nodo al final de la lista
 *
 */
void insertaNodo()
{
	// Genero un nuevo nodo
	Node *newNode = new Node;

	Node *temp = NULL;
	newNode = GeneraNodo();

	temp = head;

	int position = 0;
	int DLposition = 0;

	// Si la lista esta vacia, el nuevo nodo sera el primero
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		// Mientras exista un siguiente nodo, me muevo a el.
		while (temp->next != NULL)
		{
			temp = temp->next;
			position++;
			DLposition++;
		}

		// Al llegar al ultimo nodo, el siguiente sera el nuevo nodo.
		temp->next = newNode;
		newNode->prev = temp;
	}

	{

		DLNode *Newtemp = new DLNode;
		Newtemp->positionList = position;
		strcpy(Newtemp->stringNode, newNode->user);
		DLNode_append(&insertados, Newtemp);
	}

	{
		for (char *c = vocales; *c != '\0'; c++)
		{
			if (*c == newNode->user[0])
			{
				DLNode *newDLNode = new DLNode;
				newDLNode->positionList = 0;
				strcpy(newDLNode->stringNode, newNode->user);
				DLNode_append(&DoubleLinkdeList, newDLNode);
			}
		}
	}
}

/**
 * @brief Elimina el nodo cuyo dato sea especificado por el usuario
 *
 */
void eliminaNodo()
{
	int del_data = 0;

	int position = 0;

	// SetConsoleTextAttribute(hCon, 14);
	printf("\n\tDato: ");
	scanf("%d", &del_data);

	// Si tengo una lista no vacia, busco el nodo a eliminar
	if (head != NULL)
	{
		if (head->data == del_data)
		{
			{
				DLNode *temp = new DLNode;
				temp->positionList = position;
				strcpy(temp->stringNode, head->user);
				DLNode_append(&eliminados, temp);
			}

			// Si el nodo a eliminar es el primero, enlazo head al siguiente nodo
			head = head->next;

			// En caso de que me quede con un solo elemento, el previo sera NULL ya que la lista estara vacia
			if (head != NULL)
				head->prev = NULL;
		}
		else
		{
			// Recorro la lista hasta encontrar el nodo a eliminar
			for (Node *i = head; i != NULL; i = i->next, position++)
			{
				// Una vez encontrado
				if (i->data == del_data)
				{
					{
						DLNode *temp = new DLNode;
						temp->positionList = position;
						strcpy(temp->stringNode, i->user);
						DLNode_append(&eliminados, temp);
					}

					// Si el nodo a eliminar es el ultimo, el previo del siguiente sera NULL
					if (i->next == NULL)
						i->prev->next = NULL;
					else
					{
						// Hago el movimiento de los nodos correspondientes para que el siguiente y el anterior se enlacen
						i->prev->next = i->next;
						i->next->prev = i->prev;
					}
					// free(i);
					break;
				}
			}
		}
	}

	// En caso de que tenga una lista vacia, simplemente no se hace nada
}

/*realiza todo el proceso de simulacion de nodos, puede crear mas funciones auxiliares a esta pero siempre partiendo de aqui*/
void imprimir()
{
	// // este codigo solo es de prueba, desarrolle lo solicitado
	// int j = 0;

	// // SetConsoleTextAttribute(hCon, 11);
	// printf("\n");
	// for (Node *i = head; i != NULL; i = i->next)
	// {
	// 	printf("[%d, %s]->", i->data, i->user);
	// 	j++;
	// 	if (j == 9)
	// 	{
	// 		printf("\n");
	// 		j = 0;
	// 	}
	// }
	// printf("\n\n");

	printf(CLEAN_SCREEN);
	int x = 0;
	int y = 0;
	gotoxy(x, 3);
	// Print head node inside box
	{
		// print in green
		printf(GREEN);
		printf(LEFT_UPPER_CORNER);
		for (int i = 0; i < 4; i++)
			printf(HORIZONTAL_LINE);
		printf(TOP_T);
		for (int i = 0; i < 14; i++)
			printf(HORIZONTAL_LINE);
		printf(RIGHT_UPPER_CORNER);

		printf("\n");

		printf(VERTICAL_LINE);

		printf(RESET);
		printf("HEAD");
		printf(GREEN);
		printf(VERTICAL_LINE);
		printf(RESET);
		printf("%p", head);
		printf(GREEN);
		printf(VERTICAL_LINE);

		printf("\n");

		printf(LEFT_LOWER_CORNER);
		for (int i = 0; i < 4; i++)
			printf(HORIZONTAL_LINE);
		printf(BOTTOM_T);
		for (int i = 0; i < 14; i++)
			printf(HORIZONTAL_LINE);
		printf(RIGHT_LOWER_CORNER);

		printf(RESET);
	}

	y = 0;
	gotoxy(22, 4);
	printf("▶");

	x += 23;

	// Print next node inside box
	Node *temp = head;
	while (temp != NULL)
	{
		// gotoxy(x++, 4);
		// printf("▶");

		gotoxy(x, y);
		y += 2;

		printf(YELLOW);
		printf(LEFT_UPPER_CORNER);
		for (int i = 0; i < 14; i++)
			printf(HORIZONTAL_LINE);
		printf(RIGHT_UPPER_CORNER);

		gotoxy(x, y++);

		printf(VERTICAL_LINE);
		printf(RESET);
		printf("      %3d     ", temp->data);
		printf(YELLOW);
		printf(VERTICAL_LINE);

		gotoxy(x, y++);

		printf(LEFT_T);
		for (int i = 0; i < 14; i++)
			printf(HORIZONTAL_LINE);
		printf(RIGHT_T);

		gotoxy(x, y++);
		printf(VERTICAL_LINE);
		printf(RESET);
		printf("N[0x%9p]", temp->next);
		printf(YELLOW);
		printf(VERTICAL_LINE);

		if (temp->next != NULL)
		{
			printf(RESET);

			printf("▶");

			printf(YELLOW);
		}

		gotoxy(x, y++);
		printf(LEFT_T);
		for (int i = 0; i < 14; i++)
			printf(HORIZONTAL_LINE);
		printf(RIGHT_T);

		gotoxy(x - 1, y++);
		if (temp->prev != NULL)
		{
			printf(RESET);

			printf("◄");

			printf(YELLOW);
		}
		else
		{
			printf(" ");
		}
		printf(VERTICAL_LINE);
		printf(RESET);
		printf("P[0x%9p]", temp->prev);
		printf(YELLOW);
		printf(VERTICAL_LINE);

		gotoxy(x, y++);
		printf(LEFT_LOWER_CORNER);
		for (int i = 0; i < 14; i++)
			printf(HORIZONTAL_LINE);
		printf(RIGHT_LOWER_CORNER);

		printf(RESET);

		gotoxy(x, y++);
		printf("0x%14p", temp);

		temp = temp->next;

		y = 0;
		x += 18;
	}
	printf("\n");
}

/* Genera una nueva lista que sera doblemente circular, en esta inserta los nodos que en la inserción de la lista principal contengan como primera
mayúscula alguna vocal.
 El nodo contiene la cadena y un número que corresponde al lugar que ocupa en la lista original
 desarrollar el codigo de insercion doble circular con base en el código de listas simples de esta práctica
*/
void DoublylinkedList()
{
	{
		for (DLNode *temp = DoubleLinkdeList.entry; temp != 0; temp = temp->next)
		{
			printf("[%d,%s]->", temp->positionList, temp->stringNode);
		}
	}
}
/* Realiza impresiones despues de que el proceso de inserción y eliminación concluyo */
void AfterList()
{

	printf("\nNodos Insertados: "); // Menciona cuantos nodos se insertaron en todo el proceso de ejecución
	{
		int i = 0;
		for (DLNode *temp = insertados.entry; (temp != insertados.entry || i != 0); temp = temp->next, i++)
		{
			printf("[%d,%s]->", temp->positionList, temp->stringNode);
		}
		exit(1);
	}
	printf("\nNodos Eliminados: "); // Menciona cuantos nodos se eliminaron en todo el proceso de ejecución
	{
		for (DLNode *temp = eliminados.entry; temp != 0; temp = temp->next)
		{
			printf("[%d,%s]->", temp->positionList, temp->stringNode);
		}
	}
	printf("\nNodos Finales: "); // Menciona con cuantos nodos termino la lista
	{
		int size = 0;
		if (head != 0)
		{
			size++;
			for (Node *temp = head->next; temp != 0 && temp != head; temp = temp->next)
			{
				size++;
			}
		}
		printf("%d", size);
	}
	printf("\nDatos eliminados ordenados: "); // Muestra en orden descendente el valor de data de los nodos que se eliminaron
	{
		// Sort the list
		for (DLNode *temp = eliminados.entry; temp != 0; temp = temp->next)
		{
			for (DLNode *temp2 = temp->next; temp2 != 0; temp2 = temp2->next)
			{
				if (temp->positionList < temp2->positionList)
				{
					DLNode temp3 = *temp;
					temp->positionList = temp2->positionList;
					strcpy(temp->stringNode, temp2->stringNode);

					temp2->positionList = temp3.positionList;
					strcpy(temp2->stringNode, temp3.stringNode);
				}
			}
		}

		// Print the list
		for (DLNode *temp = eliminados.entry; temp != 0; temp = temp->next)
		{
			printf("[%d,%s]->", temp->positionList, temp->stringNode);
		}
	}
	printf("\nNueva lista generada: "); // muestra la lista en base a las condiciones de la función DoublylinkedList
	DoublylinkedList();
}

/*--------------------------------------------------------------------------------------------------------*/
/*en todo momento se estra mostrando la lista y un menu, en el primer caso pues head hacia null con su flecha
y asi, opciones de 1 inserta, 2 elimina en el cual pide el data a eliminar*/
int main()
{
	head = NULL;
	int op_user = 0;
	srand(time(0));

	do
	{
		// fflush(stdin);
		// SetConsoleTextAttribute(hCon, 8);
		printf("[1] Inserta\n[2] Elimina\n[0] Salir\n\n");
		scanf("%d", &op_user);
		switch (op_user)
		{
		case 1:
			insertaNodo();
			imprimir();
			break;
		case 2:
			eliminaNodo();
			imprimir();
			break;
		}
	} while (op_user != 0); // cero para terminar

	AfterList();

	while (head != NULL)
	{
		Node *temp = head;
		head = head->next;
		free(temp);
	}
}
