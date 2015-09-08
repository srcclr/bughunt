#ifndef COSQL_KV_H_
#define COSQL_KV_H_

#define TABLE_SIZE 100

typedef struct
{
    char *key;
    int value;
} node;

typedef struct
{
    int num_nodes;
    node *nodes[TABLE_SIZE];
} hash_table;

hash_table* init();
void destroy(hash_table *tab);

int add(hash_table *tab, char *key, int value);
int find(hash_table *tab, char *key);

int hash_func(char *key);

#endif

