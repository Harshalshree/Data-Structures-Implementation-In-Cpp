#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct llist{
	void* data;
	struct llist* next;
};

struct llist* head=NULL;
struct llist* last=NULL;

void add_node(struct llist** prev_node,void* node_data,int data_size){
	struct llist* new_node=(struct llist*)malloc(sizeof(struct llist));
	new_node->next=NULL;
	new_node->data=malloc(data_size);
	memcpy(new_node->data,node_data,data_size);
	(*(prev_node))->next=new_node;
	last=new_node;
}

void init_node(void* node_data,int data_size){
	head=(struct llist*)malloc(sizeof(struct llist));
	last=(struct llist*)malloc(sizeof(struct llist));
	head->next=NULL;
	head->data=malloc(data_size);
	memcpy(head->data,node_data,data_size);
	last=head;
}

void print_list(struct llist* head_node,void (*func)(void*)){
	struct llist* node=head_node;
	while(node!=NULL){
		(*func)(node->data);
		node=node->next;
	}
}

void print_int(void *num){
	printf("%d",*((int*)num));
}

void print_str(void* str){
	printf("%s",(char*)str);
}

void print_float(void *flt){
	printf("%f",*((float*)flt));
}

void print_char(void *chr){
	printf("%c",*((char*)chr));
}

void main(){
	// use appropriate datatype
	int array[5]={5,3,6,1,5};
	for(int i=0;i<5;i++){
		if(i==0){
			init_node(&array[0],sizeof(array[0]));
		}
		else
			add_node(&last,&array[i],sizeof(array[i]));
	}
	print_list(head,print_int);
}