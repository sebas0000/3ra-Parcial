#include <stdio.h>
#include <stdlib.h>
int nvl=0;
struct node{
    struct node* left_child;
    struct node* right_child;

    int data;
};

struct node* newNode(int data){
    size_t node_size = sizeof(struct node);
    struct node* new_Node = (struct node*) malloc(node_size);
    new_Node -> data = data;
    new_Node -> left_child = NULL;
    new_Node -> right_child = NULL;

    return new_Node;
}

void insertNode(struct node* nd, int data){
    if(data>nd->data){
        if(nd->right_child==NULL){
            nd->right_child=newNode(data);
        }else{
            insertNode(nd->right_child,data);
        }
    }else{
        if(nd->left_child==NULL){
            nd->left_child=newNode(data);
        }else{
            insertNode(nd->left_child,data);
        }
    }
}

void search(struct node* nd,int num){
    nvl= nvl+1;
    if(num == nd->data){
	   	printf("Se encontro en el nivel %d\n",nvl);
    }
	else if(num < nd->data){
		search(nd->left_child,num);
	}
    else if(num > nd->data){
		search(nd->right_child,num);
    }
    else {
		printf("No se encontró en ningun nivel\n");
	}
}

int main(){
    int n=0;
    
    struct node* root=NULL;
    
    root=newNode(6);
    
    insertNode(root,2);
    insertNode(root,12);
    insertNode(root,3);
    insertNode(root,1);
    insertNode(root,8);
    insertNode(root,13);
    
    printf("inserta el nodo a buscar: ");
    
    scanf("%d",&n);
    
    search(root,n);
    
    return 0;
}