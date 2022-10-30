 #include<stdio.h>
 #include<stdlib.h>
 typedef struct node{
 	int data;
 	struct node*next;
 }node;
 typedef struct LL{
 	node*start;
 }LL;
 void Enqueue(LL*l, int ele){
 	node*newrec, *p;
 	newrec=(node*)malloc(sizeof(node));
 	newrec->data=ele;
 	newrec->next=NULL;
 	if(l->start==NULL){
 		l->start=newrec;
	 }
	else{
		p=l->start;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=newrec;
	}
 }
 int Dequeue(LL*l){
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
 int front(LL*l){
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
			printf("%d\t", p->data);
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
		printf("\nMenu\n1. Enqueue.\n2. Dequeue\n3. QueueFront\n4. Display\n5. Exit.");
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
					Enqueue(&l, ele);
					/*We display our Queue after every insertion so that we do not had to choose the display choice again and again*/
					display(&l);
				}
				break;
				case 2:
					{
						ele=Dequeue(&l);
						if(ele==-1){
							printf("\nQueue is Underflow.");
						}
						else{
							printf("\n%d is Deleted\n", ele);
						}
					}
					break;
					case 3:
						{
							ele=front(&l);
							if(ele==-1){
							printf("\nQueue is Underflow.");
						}
						else{
							printf("\n%d is at Front\n", ele);
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
									printf("\nInvalid choice.");
								}
		}
	}
	return 0;
 }
