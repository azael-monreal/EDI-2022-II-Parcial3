/* Realice una función recursivaque invierta una cadena de caracteres.   Se
 * tiene que modificar la cadena de entrada en el mismo arreglo, no se debe
 * crear una nueva cadena o solo imprimirla de forma inversa.
 *
 * Ejemplo1:
 * 		Entrada:	“hello”
 * 		Salida:		“olleh”
 *
 * Ejemplo2:
 * 		Entrada:	“Estructuras”
 * 		Salida:		“sarutcurtsE”
 *
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100

void recursiveInverse(char* str, int size, int l);

int main(void)
{
	char in[SIZE];

	printf("Input: ");
	scanf("%s", in);

	recursiveInverse(in, strlen(in) - 1, 0);

	printf("Output: %s\n", in);

	return 0;
}

void recursiveInverse(char* str, int size, int l)
{
	if (l > size / 2)
		return;
	else
	{
		char tmp = str[l];
		str[l] = str[size - l];
		str[size - l] = tmp;

		recursiveInverse(str, size, l + 1);
	}
}
