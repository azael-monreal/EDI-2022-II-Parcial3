/*
 * 1: grupo de elementos que no se repite
 * 2: opereaciones:
 *	 2.1: agregar
 *	 2.2: eliminar
 *	 2.3: pertenencia
 * 3:
 * 	3.1: interseccion
 * 	3.2: union
 * 	3.3: complemento - elementos no en set
 * 	3.4: diferencia - elementos en a y no en b
 */

#include <stdio.h>

#define SET_TYPE int
#define SET_MSIZE 100

typedef struct Set
{
	char* name;
	int data[SET_MSIZE];
	int size;
} Set;

void set_init(Set*);
int set_add(Set*, SET_TYPE);
int set_delete(Set*, SET_TYPE);
int set_find(Set, SET_TYPE);
int set_exists(Set, SET_TYPE);
void set_print(Set);

Set set_union(Set, Set);
Set set_intersection(Set, Set);
Set set_complement(Set, Set);
Set set_difference(Set, Set);

int main(void)
{
	Set setA;
	set_init(&setA);

	set_add(&setA, 5);
	set_add(&setA, 7);
	set_add(&setA, 11);
	set_add(&setA, 16);
	set_add(&setA, 23);

	printf("SetA: ");
	set_print(setA);

	Set setB;
	set_init(&setB);

	set_add(&setB, 5);
	set_add(&setB, 10);
	set_add(&setB, 11);
	set_add(&setB, 21);

	printf("SetB: ");
	set_print(setB);

	printf("Union A∪B: ");
	set_print(set_union(setA, setB));
	printf("Intersection A∩B: ");
	set_print(set_intersection(setA, setB));
	printf("Difference A-B: ");
	set_print(set_difference(setA, setB));
	printf("Complement A-B: ");
	set_print(set_complement(setA, setB));

	printf("\n");
	return 0;
}

void set_init(Set* set) { set->size = 0; }

int set_isEmpty(Set set) { return !(set.size); }
int set_isFull(Set set) { return !(set.size == SET_MSIZE); }

int set_find(Set set, SET_TYPE target)
{
	int l = 0, r = set.size - 1;

	while(l <= r)
	{
		int m = (l + r) / 2, x = set.data[m];

		if(x == target)
			return m;

		if(x < target)
			l = m + 1;
		else
			r = m - 1;
	}

	return l;
}

int set_exists(Set set, SET_TYPE target)
{
	int l = 0, r = set.size - 1;

	while(l <= r)
	{
		int m = (l + r) / 2, x = set.data[m];

		if(x == target)
			return 1;

		if(x < target)
			l = m + 1;
		else
			r = m - 1;
	}

	return 0;
}

int set_add(Set* set, SET_TYPE value)
{
	if(!set_isFull(*set))
		return -1;

	int pos = 0, exists = 0;

	if(!set_isEmpty(*set))
		pos = set_find(*set, value), exists = set->data[pos] == value;

	if(exists)
		return 0;

	for(int i = set->size; i > pos; i--)
		set->data[i] = set->data[i - 1];

	set->data[pos] = value;
	set->size++;

	return 1;
}

int set_delete(Set* set, SET_TYPE value)
{
	if(set_isEmpty(*set))
		return -1;

	int pos = set_find(*set, value), exists = set->data[pos] == value;

	if(!exists)
		return 0;

	set->size--;

	for(int i = pos; i < set->size; i++)
		set->data[i] = set->data[i + 1];

	return 1;
}

void set_print(Set set)
{
	if(!set.size)
	{
		printf("Set is empty\n");
		return;
	}

	printf("[ ");
	for(int i = 0; i < set.size; i++)
		printf("%d ", set.data[i]);
	printf("]\n");
}

Set set_union(Set setA, Set setB)
{
	Set setUnion;
	set_init(&setUnion);

	for(int i = 0; i < setA.size; i++)
		set_add(&setUnion, setA.data[i]);
	for(int i = 0; i < setB.size; i++)
		set_add(&setUnion, setB.data[i]);

	return setUnion;
}

Set set_intersection(Set setA, Set setB)
{
	Set setIntersection;
	set_init(&setIntersection);

	for(int i = 0; i < setA.size; i++)
	{
		if(set_exists(setB, setA.data[i]))
			set_add(&setIntersection, setA.data[i]);
	}

	return setIntersection;
}

Set set_difference(Set setA, Set setB)
{
	Set setDifference;
	set_init(&setDifference);

	for(int i = 0; i < setA.size; i++)
	{
		if(!set_exists(setB, setA.data[i]))
			set_add(&setDifference, setA.data[i]);
	}
	return setDifference;
}

Set set_complement(Set setA, Set setB)
{
	// Set setComplement;
	// set_init(&setComplement);
	//
	// for(int i = 0; i < setB.size; i++)
	// {
	// 	if(!set_exists(setA, setB.data[i]))
	// 		set_add(&setComplement, setB.data[i]);
	// }
	// return setComplement;

	return set_difference(setB, setA);
}
