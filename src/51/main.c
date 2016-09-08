#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <error.h>

#include <THB/hash_table.h>
#include <THB/queue.h>
#include <THB/list.h>

#define MAX 1000 // 4000000000
#define MIN 100

#define NAME_LENGTH 10

typedef unsigned long ulong;

typedef struct {
	ulong num;
	int count;
} PrimeClass;

int **perm_table;

THB_HashTable *table;

PrimeClass max_count;

void print_int(int *a, int size) {
	for(int i = 0; i < size; i++) {
		printf("%i", *(a+i));
	}
	printf("\n");
}

int is_prime(ulong num) {
	ulong sq = (ulong)sqrtf((float)num);

	for(ulong i = 2; i <= sq; i++) {
		if(num % i == 0) return 0;
	}

	return 1;
}

void num_to_str(ulong num, int len, char *ret) {
	int i = len - 1;
	while(num > 0 && i >= 0) {
		ret[i] = '0' + num % 10;
		num = num / 10;
		i--;
	}
	while(i >= 0) {
		ret[i] = '0';
		i--;
	}
}

int swap(char *a, char *b) {
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(char *a, char *b) {
	while(a < b) {
		swap(a++, b--);
	}
}

void add_to_class(ulong num, char *numstr, char *class) {
	PrimeClass pclass;	
	if(THB_hash_table_search(table, class, &pclass)) {
		pclass.count++;
	} else {
		pclass.count = 1;
		pclass.num = num;
	}
	if(pclass.count > max_count.count) {
		max_count.count = pclass.count;
		max_count.num = pclass.num;
	}
	THB_hash_table_insert(table, class, &pclass);
}

void add_to_perm_classes(ulong num, char *numstr, int *pos, int count) {
	int *table;
	char *str = malloc(sizeof(char)*(NAME_LENGTH+1));
	for(int i = 1; i < (int)pow(2, count); i++) {
		table = perm_table[i];
		strcpy(str, numstr);
		for(int j = 0; j < count; j++) {
			if(table[j] == 1)
				str[pos[j]] = '*';
		}
		add_to_class(num, numstr, str);
	}
	free(str);
}

void add_to_classes(ulong num, char *numstr) {
	int num_start = -1;
	for(int i = 0; i < NAME_LENGTH && num_start == -1; i++) {
		if(numstr[i] != '0') {
			num_start = i;
			break;
		}
	}
	int pos[NAME_LENGTH];
	int ppos = 0;
	for(char c = '0'; c <= '9'; c++) {
		ppos = 0;
		for(int i = num_start; i < NAME_LENGTH - 1; i++) {
			if(numstr[i] == c) {
				pos[ppos++] = i;
			}
		}
		add_to_perm_classes(num, numstr, pos, ppos);
	}
}



int main(int argc, char **argv) {
	
	max_count.num = 0;
	max_count.count = 0;

	perm_table = (int**) malloc(sizeof(int*) * ((int)pow(2, NAME_LENGTH)));

	for(int i = 0; i < (int)pow(2, NAME_LENGTH); i++) {
		perm_table[i] = (int*) malloc(sizeof(int) * NAME_LENGTH);
	}

	for(int i = 0; i < (int)pow(2, NAME_LENGTH); i++) {
		int temp = i;
		for(int j = 0; j < NAME_LENGTH; j++) {
			if(temp % 2 == 1)
				perm_table[i][j] = 1;
			else
				perm_table[i][j] = 0;
			temp = temp / 2;
		}
	}

	table = (THB_HashTable*) malloc(sizeof(THB_HashTable));

	THB_hash_table_create(table, sizeof(PrimeClass), 512, NULL);

	char numstr[NAME_LENGTH + 1] = {'\0'};

	for(ulong i = MIN; i < MAX; i++) {
		if(is_prime(i)) {
			num_to_str(i, NAME_LENGTH, numstr);
			add_to_classes(i, numstr);
		}
	}

	printf("%li , %i\n", max_count.num, max_count.count);
	
	for(int i = 0; i < (int)pow(2, NAME_LENGTH); i++) {
		free(perm_table[i]);
	}

	free(perm_table);

	THB_hash_table_destroy(table);
	free(table);

}
