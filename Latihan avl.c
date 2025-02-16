#include<stdio.h>
#include<stdlib.h>
struct Node{
	int height;
	int key;
	struct Node*left;
	struct Node*right;
};
int getHeight(struct Node*n){
	if(n==NULL){
		return 0;
	}
	return n->height;
}
struct Node*createNode(int key){
	struct Node*node=(struct Node*)malloc(sizeof(struct Node));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	
	return node;
}
int max(int a,int b){
	return(a>b)?a:b;
}
int getBalanceFactor(struct Node*n){
	if(n==NULL){
		return 0;
	}
	
	return	getHeight(n->left)-getHeight(n->right);
}
struct Node * rightRotate(struct Node*y){
	struct Node*x=y->left;
	struct Node*T2=x->right;
	
x->right = y;
y->left=T2;

y->height=max(getHeight(y->right),getHeight(y->left))+1;
x->height=max(getHeight(x->right),getHeight(x->left))+1;
return x;
}
struct Node *leftRotate(struct Node*x){
	struct Node*y=x->right;
	struct Node*T2=y->left;
	
	y->left=x;
	x->right=T2;
	
x->height=max(getHeight(x->right),getHeight(x->left))+1;
y->height=max(getHeight(y->right),getHeight(y->left))+1;
return y;

}
struct Node*insert(struct Node*node,int key){
	if(node==NULL){
		return createNode(key);
	}
	if(key<node->key){
		node->left=insert(node->left,key);
	}
	if(key>node->key){
		node->right=insert(node->right,key);
	}
	else{
		return node;
	}
	node->height=1 + max(getHeight(node->left),getHeight(node->right));
	int bf= getBalanceFactor(node);
	//ll
	if(bf>1&&key<node->left->key){
		return rightRotate(node);
	}
	//rr
	if(bf<-1&&key>node->right->key){
		return leftRotate(node);
	}
	//lr
	if(bf>1&&key>node->left->key){
		node->left=leftRotate(node);
		return rightRotate(node);
	}
	//rl
	if(bf<-1&&key<node->right->key){
		node->right=rightRotate(node);
		return leftRotate(node);
	}
	return node;
}
void inorder(struct Node*root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}
struct Node* minValueNode(struct Node*node){
	struct Node* current=node;
	while(current!=NULL){
		current=current->left;
	}
	return current;
}
struct Node*deleteNode(struct Node*root,int key){
	if(root == NULL){
		return root;
	}
	if(key<root->key){
		root->left=deleteNode(root->left,key);
	}
	else if(key>root->key){
		root->right=deleteNode(root->right,key);
	}
	else{
		if((root->left==NULL)||(root->right=NULL)){
			struct Node *temp= root->left?root->left:root->right;
			if(temp=NULL){
				temp=root;
				root=NULL;
			}
			else
				*root=*temp;
			free(temp);		
		}
		else{
			struct Node * temp=minValueNode(root->right);
			root->key=temp->key;
			root->right=deleteNode(root->right,temp->key);
		}
	}
	if(root==NULL)
		return root;
	root->height= 1+ max(getHeight(root->left),getHeight(root->right));
	int balance=getBalanceFactor(root);
	
	if(balance > 1&& getBalanceFactor(root->left)>=0){
		return rightRotate(root);
	}
	if(balance > 1&& getBalanceFactor(root->left)<0){
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance<-1 && getBalanceFactor(root->right)<=0){
		return leftRotate(root);
	}
	if(balance <-1 && getBalanceFactor(root->right)>0){
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

struct Node*findmin(struct Node*root){
	while(root!=NULL){
		root=root->left;
	}
	return root;
}
struct Node*findmax(struct Node*root){
	while(root!=NULL){
		root=root->right;
	}
	return root;
}
	
int main(){
	struct Node *root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    
//    deleteNode(root, 3);
    
    inorder(root);
    printf("\n");
    struct Node *minNode = findmin(root);
    struct Node *maxNode = findmax(root);
    
    printf("Minimum value in the tree: %d\n", minNode->key);
    printf("Maximum value in the tree: %d\n", maxNode->key);
	return 0;
}
