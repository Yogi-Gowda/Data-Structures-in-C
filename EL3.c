#include <stdio.h>
#include <stdlib.h>

typedef struct mynode {
    int data;
    struct mynode *link;
} NODE;


NODE* Create_Node(int x) {
    NODE *p = (NODE*)malloc(sizeof(NODE));
    p->data = x;
    p->link = NULL;
    return p;
}

NODE* Init_List() {
    return NULL;
}


NODE* Delete_Pos(NODE *head, int pos) {
    if (head == NULL) return NULL;

    if (pos == 1) {  
        NODE *temp = head->link;
        free(head);
        return temp;
    }

    head->link = Delete_Pos(head->link, pos - 1);
    return head;
}


NODE* Delete_Content(NODE *head, int x) {

    if (head == NULL) return head;

    if (head->data == x) {
        NODE *temp = head->link;
        free(head);
        return temp;
    }

    NODE *prev = head;
    NODE *cur = head->link;

    while (cur != NULL) {
        if (cur->data == x) {
            prev->link = cur->link;
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->link;
    }

    return head;
}


void Display(NODE *head) {
    NODE *t = head;
    printf("List: ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->link;
    }
    printf("NULL\n");
}


int main() {

    NODE *head = Init_List();

    NODE *a = Create_Node(10);
    NODE *b = Create_Node(20);
    NODE *c = Create_Node(30);

    head = a;
    a->link = b;
    b->link = c;

    printf("Original List:\n");
    Display(head);

    head = Delete_Pos(head, 2);     
    printf("\nAfter deleting position 2:\n");
    Display(head);

    head = Delete_Content(head, 30); 
    printf("\nAfter deleting content 30:\n");
    Display(head);

    return 0;
}
