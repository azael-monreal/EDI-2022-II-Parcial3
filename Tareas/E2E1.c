/*
 * Realice un programa en C que dado un arreglo ordenado de N enterosdiferentes
 * y un valor objetivo, regrese el índice si el valor objetivo existe dentro del
 * arreglo, si no, regrese el índice donde debería estar si fuera insertado
 * enorden. (Donde 0 < N <=100).
 *
 * Ejemplo 1:
 * 		Entrada:  nums = [1, 3, 5, 6], objetivo = 5
 * 		Salida:  2
 *
 * Ejemplo 2:
 * 		Entrada:  nums = [1, 3, 5], objetivo = 2
 * 		Salida: 1
 *
 * Ejemplo 3:
 * 		Entrada: nums = [1, 3, 5, 6], objetivo = 7
 * 		Salida: 4
 */

#include <stdio.h>

#define SIZE 100

void readArray(int arr[], int* size, char name[]);
int searchIndex(int list[], int size, int target);

int main(void)
{
	int nums[SIZE];
	int n_size;

	readArray(nums, &n_size, "nums");

	int num;

	printf("Search for: ");
	scanf("%d", &num);

	printf("The number '%d' is or would be found on index %d\n", num,
		   searchIndex(nums, n_size, num));

	return 0;
}

void readArray(int arr[], int* size, char name[])
{
	printf("%s size: ", name);
	scanf("%d", size);
	for(int i = 0; i < *size; i++)
	{
		printf("%s[%d]: ", name, i);
		scanf("%d", &arr[i]);
	}
}

int searchIndex(int list[], int size, int target)
{
	int l = 0, r = size - 1;

	while(l <= r)
	{
		int guess = (l + r) / 2;

		if(list[guess] == target)
			return guess;

		if(list[guess] < target)
			l = guess + 1;
		else
			r = guess - 1;
	}
	return l;
}
