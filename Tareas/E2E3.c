/*
 * Dados un arreglo de N alumnos (nombres) y un arreglo de promedios, donde cada
 * elemento del arreglo de promedios corresponda al promedio de un alumno en el
 * arreglo de nombres.  Realice una función que ordene a los alumnos de forma
 * descendente por promedio, utilizando el algoritmo de su preferencia. (Donde 0
 * <N <=100)
 *
 * Ejemplo:
 * 		Entrada:
 * 			nombres = [“Juan”, “Pedro”, “Sandra”, “Paola”],
 * 			promedios = [6.5, 7.3, 5.2, 10.0]
 *
 * 		Salida:
 * 			nombres = [“Paola”, “Pedro”, “Juan”, “Sandra”],
 * 			promedios = [10.0, 7.3, 6.5, 5.2]
 */

#include <stdio.h>
#include <string.h>

#define TBSIZE 100
#define STRSIZE 100

void readTable(int* size, char keys[TBSIZE][STRSIZE], char kLabel[], float values[], char vLabel[]);
void printTable(int size, char keys[TBSIZE][STRSIZE], char kLabel[], float values[], char vLabel[]);
void quickSort(char arr[TBSIZE][STRSIZE], float values[], int l, int h);

int main(void)
{
	char names[TBSIZE][STRSIZE];
	float avrgs[TBSIZE];
	int size;

	readTable(&size, names, "Name", avrgs, "Average");
	quickSort(names, avrgs, 0, size - 1);
	printTable(size, names, "Name", avrgs, "Average");

	return 0;
}

void readTable(int* size, char keys[TBSIZE][STRSIZE], char kLabel[], float values[], char vLabel[])
{
	printf("%s size: ", "Table");
	scanf("%d", size);

	for (int i = 0; i < *size; i++)
	{
		printf("\n*** Entry %d ***\n", i + 1);
		printf("%s: ", kLabel);
		char temp[STRSIZE];
		scanf("%s", temp);

		strcpy(keys[i], temp);

		printf("%s: ", vLabel);
		scanf("%f", &values[i]);
	}
}

void printTable(int size, char keys[TBSIZE][STRSIZE], char kLabel[], float values[], char vLabel[])
{
	printf("\n*** Ordered Table ***\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s\t%.1f\n", keys[i], values[i]);
	}
}

void quickSort(char keys[TBSIZE][STRSIZE], float values[], int l, int h)
{
	if (l >= h)
		return;

	float p = values[h];
	int i = l - 1;

	for (int j = l; j <= h - 1; j++)
	{
		if (values[j] > p)
		{
			i++;
			float tempv = values[i];
			values[i] = values[j];
			values[j] = tempv;

			char tempk[STRSIZE];
			strcpy(tempk, keys[i]);
			strcpy(keys[i], keys[j]);
			strcpy(keys[j], tempk);
		}
	}
	float temp = values[i + 1];
	values[i + 1] = values[h];
	values[h] = temp;

	char tempk[STRSIZE];
	strcpy(tempk, keys[i + 1]);
	strcpy(keys[i + 1], keys[h]);
	strcpy(keys[h], tempk);

	int part = (i + 1);

	quickSort(keys, values, l, part - 1);
	quickSort(keys, values, part + 1, h);
}
