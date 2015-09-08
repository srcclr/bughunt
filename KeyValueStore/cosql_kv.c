#include <string.h>
#include <stdlib.h>
#include "cosql_kv.h"

hash_table* init() {
	hash_table* tab;

	tab = (hash_table*) malloc(sizeof(hash_table));
	int i;
	for(i = 0; i < TABLE_SIZE; i++)
		tab->nodes[i] = NULL;
	return tab;
}

void destroy(hash_table *tab) {
	int i; 
	for(i = 0; i < TABLE_SIZE; i++) {
		if(tab->nodes[i]) {
			free(tab->nodes[i]->key);
			free(tab->nodes[i]);
		}
	}
	free(tab);
	tab = NULL;
}

int add(hash_table* tab, char* k, int v) {
	int hash = hash_func(k);

	if(tab->nodes[hash] == NULL) 
		tab->nodes[hash] = malloc(sizeof(node));
	else return 1;
	tab->nodes[hash]->key = (char*) malloc(sizeof(char) * (strlen(k) + 1));
	strcpy(tab->nodes[hash]->key, k);
	tab->nodes[hash]->value = v;
	return 0;
}

int find(hash_table* tab, char* key) {
	int hash = hash_func(key);
	if(tab->nodes[hash] != NULL) 
		return tab->nodes[hash]->value;
	else return -1;
}

int hash_func(char* k)
{
    int hash = 1;
    char* c;
	for(c = k; *c; c++) 
        hash = *c + hash*31;
    
    return hash % TABLE_SIZE;
}