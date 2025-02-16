#include<stdio.h>
#include<stdlib.h>

struct Node{
	int height;
	int key;
	struct Node*left;
	struct Node*right;
};

int getHeight(struct Node*n){
	if(n==NULL)
		return 0;
	return n->height;
}
int max(int*a,int*b){
	return(a>b)?a:b;
}
int getBalanceFactor(struct Node*n){
	if(n==NULL)
		return 0;
	return getHeight(n->left)-getHeight(n->right);
}
struct Node*createNode(int key){
	struct Node*node=(struct Node*)malloc(sizeof(struct Node));
	node->left=NULL;
	node->right=NULL;
	node->key=key;
	node->height=1;
	
	return node;
}

