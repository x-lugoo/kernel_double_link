#include <stdlib.h> 
#include <stdio.h>
#include "list.h" 

struct ST { 
    unsigned char ch; 
    int 	this_data; 
    struct list_head  i_list; 
} *st; 


#define LISTSIZE 24 

int main() 
{
	int i; 
	
	struct ST *pst; 
	struct list_head list_head;   

	struct list_head *list_find;
	struct ST *p_find;

	struct list_head *list_remove,*list_remove1;
	struct ST *p_del;


	INIT_LIST_HEAD(&list_head); 
	for(i = 0; i < LISTSIZE; i++) { 
		pst = malloc(sizeof(struct ST)); 
		if(!pst) { 
		    printf("malloc fail.\n"); 
		    break; 
		} 
		pst->ch = 'a' + i; 
		//add list
		list_add_tail(&pst->i_list, &list_head); 
	} 

	if(list_empty(&list_head))
	{
		printf("check list empty !!!\n");
	}
     
	i = 0;  
	list_for_each(list_find, &list_head) { 
		p_find = list_entry(list_find, struct ST, i_list); 
		printf("%p  value %d = %c\n", p_find, i, p_find->ch); 
		i++; 
	}
	printf("total %d \n\n", i); 

	if(list_empty(&list_head))
	{
		printf("check list empty !!!\n");
	}

	i=0;
	list_for_each_safe(list_remove, list_remove1, &list_head)
	{
		list_del(list_remove);
		p_del=list_entry(list_remove, struct ST, i_list);
		free(p_del);
		printf("node %d has removed from the doublelist\n",i++);
	}

	if(list_empty(&list_head))
		{
		printf("the list is empty !!!\n");
	}
}
