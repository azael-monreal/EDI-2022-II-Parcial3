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

void recursiveInverse(char* str);

int main(void)
{
	char in[SIZE];

	printf("Input: ");
	scanf("%s", in);

	recursiveInverse(in);

	printf("Output: %s\n", in);

	return 0;
}

void recursiveInverse(char* str)
{
	int size = strlen(str);
	if (size <= 1)
		return;
	char tmp = str[0];
	str[0] = str[size - 1];
	str[size - 1] = '\0';

	recursiveInverse(str + 1);

	str[size - 1] = tmp;
}
