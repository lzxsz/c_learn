//list_node.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  list_node_tag
{
	int data ; 
	struct LIST_NODE *next ;
} LIST_NODE;	

//[in]data   -- node of data
LIST_NODE *create_node(int data)
{
	LIST_NODE *node = NULL ;
	node = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	if(node == NULL){
		printf("malloc fair!\n");
	}
	memset(node,0,sizeof(LIST_NODE));
	node->data = data;
	node->next = NULL ;
	return node ;
}

int main(void)
{
	int data = 200 ;
	LIST_NODE *node_ptr = create_node(data);        //create a node for list
	printf("node_ptr->data=%d\n",node_ptr->data);   //print node data
	printf("node_ptr->next=%d\n",node_ptr->next);  
	free(node_ptr);
	return 0 ;
}
