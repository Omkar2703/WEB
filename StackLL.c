#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node*next;
}node;
typedef struct LL{
	node*start;
}LL;
/*Push function in stack LL is made using Insert begin function.*/
void Push(LL*l, int ele){
	node*newrec;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
	newrec->next=l->start;
	l->start=newrec;
}
/*Pop function in stack LL is made using Delete Begin function.*/
int Pop(LL*l){
	node*p;
	if(l->start==NULL){
		return -1;
	}
	else{
		p=l->start;
		l->start=p->next;
		return p->data;
	}
}
/*Here, We Just need to Print the topmost element in the stack.*/
int Top(LL*l){
	if(l->start==NULL){
		return -1;
	}
	else{
		return l->start->data;
	}
}
void display(LL*l){
	node*p;
	if(l->start==NULL){
		printf("\nStack is Underflowed");
	}
	else{
		p=l->start;
		while(p!=NULL){
			printf("%d\n", p->data);
			p=p->next;
		}
		printf("\n");
	}
}
int main(){
	LL l;
	l.start=NULL;
	int ele, ch;
	while(1){
		printf("\nMenu\n1. Push.\n2. Pop\n3. Stacktop\n4. Display\n5. Exit.");
		printf("\nEnter the choice:");
		scanf("%d", &ch);
		/*Here, we terminate the program by using break*/
		if(ch==5){
			printf("\nExit satisfied.");
			break;
		}
		switch(ch){
			case 1:
				{
					printf("\nEnter the Element to be Insert:");
					scanf("%d", &ele);
					Push(&l, ele);
					/*We display our stack after every insertion so that we do not had to choose the display choice again and again*/
					display(&l);
				}
				break;
				case 2:
					{
						ele=Pop(&l);
						if(ele==-1){
							printf("\nStack is Underflow.");
						}
						else{
							printf("\n%d is Poped\n", ele);
						}
					}
					break;
					case 3:
						{
							ele=Top(&l);
							if(ele==-1){
							printf("\nStack is Underflow.");
						}
						else{
							printf("\n%d is at top\n", ele);
						}	
						}
						break;
						case 4:
							{
								display(&l);
							}
							break;
							default:
								{
									printf("\nInvalid Choice.");
								}
		}
	}
	return 0;
}
