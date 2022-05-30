#include <stdio.h>
#define STDMX 10
#define STRMX 10

typedef struct
{
	char name[STRMX];
	float grade;
} Student;

void writeFile(char*);

int main(void)
{
	writeFile("archivo.txt");

	return 0;
}

void writeFile(char* fname)
{
	Student students[STDMX];

	int size;
	printf("size: ");
	scanf("%i", &size);

	for(int i = 0; i < size; i++)
	{
		printf("name: ");
		scanf("%s", students[i].name);
		printf("grade: ");
		scanf("%f", &students[i].grade);
	}

	FILE* file = fopen(fname, "w");

	for(int i = 0; i < size; i++)
		fprintf(file, "%s: %f\n", students[i].name, students[i].grade);

	fclose(file);
}
