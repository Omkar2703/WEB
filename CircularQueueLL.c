#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node*next;
}node;
typedef struct LL{
	node*last;
}LL;
void InsertBegin(LL*l, int ele){
	node*newrec;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
	if(l->last==NULL){
		l->last=newrec;
		l->last->next=newrec;
	}
	else{
		newrec->next=l->last->next;
		l->last->next=newrec;
	}
}
void InsertEnd(LL*l, int ele){
	node*newrec, *p;
 	newrec=(node*)malloc(sizeof(node));
 	newrec->data=ele;
 	if(l->last==NULL){
 		l->last=newrec;
		l->last->next=newrec;
	 }
	else{
		l->last->next=newrec;
		newrec->next=l->last->next;
		l->last=newrec;
	}
}
int DeleteFront(LL*l){
	node*p=l->last->next;
	if(l->last==NULL){
		return -1;
	}
	else if(p==l->last){
		l->last=NULL;
	}
	else{
		l->last->next=p->next;
		p->next=NULL;
	}
	return p->data;
}
int DeleteEnd(LL*l){
	node*p=l->last->next;
	int ele = l->last->data;
	if(l->last==NULL){
		return -1;
	}
	else if(p==l->last){
	l->last=NULL;		
	}
	else{
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=l->last->next;
		l->last->next=p;
	}
	return ele;
}
 void display(LL*l){
	node*p;
	if(l->last==NULL){
		printf("\nStack is Underflowed");
	}
	else{
		p=l->last->next;
		do{
			printf("%d\t", p->data);
			p=p->next;
		}while(p!=l->last->next);
	}
}
int main(){
 	LL l;
	l.last=NULL;
	int ele, ch;
	while(1){
		printf("\nMenu\n1. Enqueue Front.\n2. Enqueue Rear\n3. Dequeue Front\n4. Dequeue Rear\n5. display\n6. Exit");
		printf("\nEnter the choice:");
		scanf("%d", &ch);
		/*Here, we terminate the program by using break*/
		if(ch==6){
			printf("\nExit satisfied.");
			break;
		}
		switch(ch){
			case 1:
				{
					printf("\nEnter the Element to be Insert at front:");
					scanf("%d", &ele);
					InsertBegin(&l, ele);
					/*We display our Queue after every insertion so that we do not had to choose the display choice again and again*/
					display(&l);
				}
				break;
				case 2:
				{
					printf("\nEnter the Element to be Insert at end:");
					scanf("%d", &ele);
					InsertEnd(&l, ele);
					/*We display our Queue after every insertion so that we do not had to choose the display choice again and again*/
					display(&l);
				}
				break;
				case 3:
					{
						ele=DeleteFront(&l);
						if(ele==-1){
							printf("\nQueue is Underflow.");
						}
						else{
							printf("\n%d is Deleted\n", ele);
						}
					}
					break;
					case 4:
						{
							ele=DeleteEnd(&l);
							if(ele==-1){
							printf("\nQueue is Underflow.");
						}
						else{
							printf("\n%d is at Front\n", ele);
						}	
						}
						break;
						case 5:
							{
								display(&l);
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
