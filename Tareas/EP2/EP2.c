/*
 * •Realice una función que reciba como parámetro el nombre del archivo y un arreglo de alumnos y lea todos los
 *	 alumnos que se encuentre en el archivo y los guarde en el arreglo de alumnos
 * •Realice  una  función  que  reciba  un  arreglo  de  alumnos  y los  ordene  de  forma ascendente por apellido.
 * •Realice una función que imprima un arreglo de alumnos, con apellido, nombre y su promedio.
 */

#include <stdio.h>
#include <string.h>

#define MXSIZE 100

typedef struct
{
	char name[50];
	char lastName[50];
	float average;
} Student;

int readStudents(char*, Student*);
void sortStudents(Student*, int);
void printStudents(Student*, int);
void quickSort(Student* arr, int l, int h);

int main(void)
{
	Student students[MXSIZE];
	int size = readStudents("./aprendizaje2.dat", students);
	sortStudents(students, size);
	printStudents(students, size);

	return 0;
}

int readStudents(char* fname, Student* st)
{
	FILE* fptr = fopen(fname, "rb");

	if(fptr == NULL)
	{
		printf("Error opening file");
		return 0;
	}

	int s = fread(st, sizeof(Student), MXSIZE, fptr);

	if(fclose(fptr) == EOF)
		printf("Error closing file");

	return s;
}

void quickSort(Student* arr, int l, int h)
{
	if(l >= h)
		return;

	Student p = arr[h];
	int i = l - 1;

	for(int j = l; j <= h - 1; j++)
	{
		if(strcmp(arr[j].lastName, p.lastName) < 0)
		{
			i++;
			Student temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	Student temp = arr[i + 1];
	arr[i + 1] = arr[h];
	arr[h] = temp;

	int part = (i + 1);

	quickSort(arr, l, part - 1);
	quickSort(arr, part + 1, h);
}

void sortStudents(Student* st, int s)
{
	quickSort(st, 0, s - 1);
}

void printStudents(Student* st, int s)
{
	for(int i = 0; i < s; i++)
		printf("%s, %s: %.1f\n", st[i].lastName, st[i].name, st[i].average);
}
