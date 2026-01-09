/*#include <stdio.h>

int a[] = {6,2,1,5,3};
int *q ;
int main(){
    q = a;
    printf("%p\n",a);
    q++;
    printf("%p\n",&q);
    printf("%p",a+3);
}

#include <stdio.h>

int a [3][2] = {2,3,4,6,7,5};
int *p;
int main(){
    //p=a;
    printf("%d",&a[0][1]);
}*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    //printf("%d",head->data );

    struct node *current = malloc(sizeof(struct node));
    current->data = 90;
    current->link = NULL;
    head->link = current; 

    current = malloc(sizeof(struct node));
    current->data = 100;
    current->link = NULL;

    head->link->link = current;
    
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}

