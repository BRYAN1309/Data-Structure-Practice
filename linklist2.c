#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int data;
	struct node*next;
}*temp,*head,*newNode;

void insert(int data){
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
	}
	else{
		temp=head;
		while (temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
}
void print(){
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void del(int num){
	temp=head;
	if(head->data==num){
		head=head->next;
		free(temp);
	}
	else{
		while(temp->next->data!=num)
				temp=temp->next;
			struct node*ptr=temp->next;
			temp->next=ptr->next;
			free(ptr);
	}
}
void search(int num){
	temp=head;
	if(head->data=num){
		printf("data %d ditemukan",num);
	}
	else{
		while(temp!=NULL){
			temp=temp->next;
		}
		printf("data %d tidak dapat ditemukan",num);
	}
}
int findmin(){
	int min=head->data;
	temp=head->next;
	while(temp!=NULL){
		if(temp->data<min){
			min=temp->data;
		}
		temp=temp->next;
	}
	return min;
}
int findmax(){
	int max=head->data;
	temp=head->next;
	while(temp!=NULL){
		if(temp->data>max){
			max=temp->data;
		}
		temp=temp->next;
	}
	return max;
}
void sort(){
	if(head==NULL){
		return;
	}
	struct node*i,*j;
	int tempData;
	for(i=head;i->next!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(i->data>j->data){
				tempData=i->data;
				i->data=j->data;
				j->data=tempData;
			}
		}
	}
}
int main(){

	insert(2);
	insert(1);
	insert(3);
	insert(5);
	insert(6);
	print();
	del(3);
	print();
	search(2);
	int min=findmin();
	int max=findmax();
	printf("Minimum value in the list: %d\n", min);
    printf("Maximum value in the list: %d\n", max);
    sort();
    print();
return 0;	
}
