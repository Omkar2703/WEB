/*Doubly Linked List*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node*next, *prev;
}node;
typedef struct LL{
	node*start;
}LL;
void InsertBegin(LL*l, int ele){
	node*newrec;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
	newrec->next=NULL;
	newrec->prev=NULL;
	if(l->start==NULL){
		l->start=newrec;
	}
	else{
		newrec->next=l->start;
		l->start->prev=newrec;
		l->start=newrec;
	}
}
void InsertEnd(LL*l, int ele){
	node*newrec, *p;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
	newrec->next=NULL;
	newrec->prev=NULL;
	if(l->start==NULL){
		l->start=newrec;
	}
	else{
		p=l->start;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=newrec;
		newrec->prev=p;
	}
}
void DeleteBegin(LL*l){
	node*p;
	if(l->start==NULL){
		printf("\nDeletion is not possible.");
	}
	else{
		p=l->start;
		l->start=l->start->next;
		l->start->prev=NULL;
		free(p);
	}
}
void DeleteEnd(LL*l){
	node*p, *q;
	if(l->start==NULL){
		printf("\nDeletion is not possible.");
	}
	else if(l->start->next==NULL){
		/*For single node*/
		p=l->start;
		l->start=NULL;
		free(p);
	}
	else{
		q=l->start;
		while(q->next->next!=NULL){
			q=q->next;
		}
		p=q->next;
		q->next=NULL;
		p->prev=NULL;
		free(p);
	}
}
void Display(LL*l){
	node*p;
	int c;
	if(l->start==NULL){
		printf("\nLinked list is Empty.");
	}
	else{
		/*Here we diplay our linked list from beginning as well as end*/
		printf("\n\nDisplay Menu\n\n1. Display Forward\n2. Display backward\n");
		printf("\nEnter the choice:");
		scanf("%d", &c);
		if(c==1){
			p=l->start;
			while(p!=NULL){
				printf("%d\t", p->data);
				p=p->next;
			}
		}
		else if(c==2){
			p=l->start;
			while(p->next!=NULL){
				p=p->next;
			}
			while(p!=NULL){
				printf("%d\t", p->data);
				p=p->prev;
			}
		}
		else{
			printf("\nInvalid Choice.");
		}
	}
}
int main(){
	LL l;
	l.start=NULL;
	int ch, ele;
	while(1){
		printf("\nMenu\n1. InsertBegin\n2. InsertEnd\n3. DeleteBegin\n4. DeleteEnd\n5. Display\n6. Exit\n");
		printf("\nEnter the choice:");
		scanf("%d", &ch);
		if(ch==6){
			printf("\nExit Satisfied.");
			break;
		}
		switch(ch){
			case 1:
				{
					printf("\nEnter the Element to be inserted from Begin:");
					scanf("%d", &ele);
					InsertBegin(&l, ele);
					/*Display(&l);*/
				}
				break;
				case 2:
					{
						printf("\nEnter the Element to be inserted from End:");
						scanf("%d", &ele);
						InsertEnd(&l, ele);
						/*Display(&l);*/
					}
					break;
					case 3:
						{
							DeleteBegin(&l);
							/*Display(&l);*/
						}
						break;
						case 4:
							{
								DeleteEnd(&l);
								/*Display(&l);*/
							}
							break;
							case 5:
								{
									Display(&l);
								}
								break;
								default:
									{
										printf("\nInvalid choice.");
									}
		}
	}
	return 0;
}
