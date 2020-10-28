#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char* name;
    struct node* next;
} node;

#define HASH_MAX 10
node* hashtable[HASH_MAX];

unsigned int hash(char* str);
unsigned int create(char* a);
void destroy(node* node_ptr);
int find(char* a);

int main()
{
    // set pointers to NULL!
    for (int i = 0; i < HASH_MAX; i++)
    {
        hashtable[i] = NULL;
    }
    
    // get the band together
    int x = create("John");
    int y = create("Paul");
    int z = create("Ringo");
    int c = create("George");
    fprintf(stdout, "%d %s\n%d %s\n%d %s\n%d %s\n", x, hashtable[x]->name, y, hashtable[y]->name, z,
    hashtable[z]->next->name, c, hashtable[c]->name);

    int yes = find("Ringo");
    int no = find("Jerry");
    fprintf(stdout, "%d\n%d\n", yes, no);

    // let it be (free)
    for (int j = 0; j < HASH_MAX; j++)
    {
        if (hashtable[j] != NULL)
        {
            destroy(hashtable[j]);
        }
    }
    return 0;
}

unsigned int hash(char* str)
{
  //from Doug L at Harvard's CS50
	int sum = 0;
	for (int j = 0; str[j] != '\0'; j++)
	{
		sum +=str[j];
	}
	return sum % HASH_MAX;
}

unsigned int create(char* a) 
{
    int n = hash(a);
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL)
        exit(1);
    else 
    {
        new_node->name = a;
        new_node->next = hashtable[n];
        hashtable[n] = new_node;
    }
    return n;
}

void destroy(node* node_ptr) 
{
    if (node_ptr->next == NULL)
        free(node_ptr);
    else 
    {
        destroy(node_ptr->next);
        free(node_ptr);
    }
    return;
}

int find(char* a) 
{
    int n = hash(a);
    if (hashtable[n] != NULL)
    {
        for (node* trav = hashtable[n]; trav !=NULL; trav = trav->next) {
            if (trav->name == a)
                return 1;
        }
    }
    return 0;
}
