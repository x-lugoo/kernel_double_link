#include<stdio.h>
#include"list.h"
#include<stdlib.h>

struct test_kernel_list{
	int a;
	struct list_head h_list;
	char name[20];
	void*(*func)(void*);
//	struct list_head h_list;
};

int main(void)
{
	struct list_head head;
	struct list_head *list_find;
	int i = 0;
	int offset;
	struct test_kernel_list *pst1;
	struct test_kernel_list *pst2;
	struct test_kernel_list *pst3;
	struct test_kernel_list *pst4;
	struct test_kernel_list *pst5;
	struct test_kernel_list *pfind;
	
	pst1 = malloc(sizeof(struct test_kernel_list));
	pst1->a = 200;
	strcpy(pst1->name,"jeff");
	pst2 = malloc(sizeof(struct test_kernel_list));
	pst2->a = 900;
	strcpy(pst2->name,"xiehuan");
	INIT_LIST_HEAD(&head);
	list_add_tail(&pst1->h_list,&head);	
	list_add_tail(&pst2->h_list,&head);	
//	offset = (long)(&((struct test_kernel_list *)0)->h_list);
	list_for_each(list_find,&head){
		pfind = list_entry(list_find,struct test_kernel_list,h_list);
//		pfind = (struct test_kernel_list*)((char*)list_find - offset);
		printf("i= %d %p,%d,%s\n",i,pfind,pfind->a,pfind->name);
		i++;
	}

	return 0;
}
