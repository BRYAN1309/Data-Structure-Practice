#include<stdio.h>
int size=0;
void swap(int*a,int*b){
	int temp=*b;
	*b=*a;
	*a=temp;
}
void heapify(int array[],int size,int i){
	if(size==1){
		printf("single element");
	}
	else{
		int largest=i;
		int l=2*i+1;
		int r=2*i+2;
		if(l<size&&array[l]>array[largest]){
			largest=l;
		}
		if(r<size&&array[r]>array[largest]){
			largest=r;
		}
		if(largest!=i){
			swap(&array[i],&array[largest]);
			heapify(array,size,largest);
		}
	}
}
void insert(int array[],int newNum){
	if(size==0){
		array[0]=newNum;
		size+=1;
	}
	else{
		array[size]=newNum;
		size+=1;
		for(int i = size/2-1;i>=0;i--){
			heapify(array,size,i);
		}
	}
}
void deleteRoot(int array[], int num){
	int i;
	for(i=0;i<size;i++){
		if(num==array[i])
			break;
	}
	swap(&array[i],&array[size-1]);
	size-=1;
	for(i = size/ 2-1;i>=0;i--){
		heapify(array,size,i);
	}
}
void print(int array[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}
void max(int array[]){
	printf("Max element = %d\n",array[0]);
}
void search(int array[],int key){
	int i;
	for( i=0;i<size;i++){
		if(key==array[i]){
			printf("%d element can be found in heap",key);
			break;
		}
		else{
			printf("%d Element cannot be found",key);
			break;
		}
	}
}
int main(){
	int array[10];
	insert(array,5);
	insert(array,7);
	insert(array,89);
	insert(array,34);
	insert(array,23);
	insert(array,56);
	insert(array,2);
	insert(array,3);
	insert(array,22);
	insert(array,11);
	
	print(array,size);
	
	deleteRoot(array,3);
	
	print(array,size);
	
	max(array);
	
	search(array,89);
	
}

