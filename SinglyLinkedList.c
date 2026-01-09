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

void Display(NODE *head) {
    NODE *t = head;
    printf("List: ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->link;
    }
    printf("NULL\n");
}

/* ------------------ INSERT OPERATIONS ------------------ */

NODE* Insert_Beg(NODE *head, int x) {
    NODE *p = Create_Node(x);
    p->link = head;
    return p;
}

NODE* Insert_End(NODE *head, int x) {
    NODE *p = Create_Node(x);

    if (head == NULL) return p;

    NODE *t = head;
    while (t->link != NULL)
        t = t->link;

    t->link = p;
    return head;
}

NODE* Insert_Pos(NODE *head, int x, int pos) {
    if (pos == 1) {
        return Insert_Beg(head, x);
    }

    NODE *p = Create_Node(x);
    NODE *t = head;

    for (int i = 1; i < pos - 1 && t != NULL; i++)
        t = t->link;

    if (t == NULL) return head;

    p->link = t->link;
    t->link = p;
    return head;
}

/* ------------------ DELETE OPERATIONS ------------------ */

NODE* Delete_Beg(NODE *head) {
    if (head == NULL) return NULL;

    NODE *temp = head->link;
    free(head);
    return temp;
}

NODE* Delete_End(NODE *head) {
    if (head == NULL) return NULL;

    if (head->link == NULL) {
        free(head);
        return NULL;
    }

    NODE *t = head;
    while (t->link->link != NULL)
        t = t->link;

    free(t->link);
    t->link = NULL;
    return head;
}

NODE* Delete_Pos(NODE *head, int pos) {
    if (head == NULL) return NULL;

    if (pos == 1) {
        NODE *temp = head->link;
        free(head);
        return temp;
    }

    NODE *t = head;
    for (int i = 1; i < pos - 1 && t->link != NULL; i++)
        t = t->link;

    if (t->link == NULL) return head;

    NODE *del = t->link;
    t->link = del->link;
    free(del);

    return head;
}

/* ------------------ SORTING (ASCENDING) ------------------ */

void Sort_List(NODE *head) {
    NODE *i, *j;
    for (i = head; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}

/* ------------------ ORDERED LIST OPERATIONS ------------------ */

NODE* Ordered_Insert(NODE *head, int x) {
    NODE *p = Create_Node(x);

    if (head == NULL || x < head->data) {
        p->link = head;
        return p;
    }

    NODE *t = head;
    while (t->link != NULL && t->link->data < x)
        t = t->link;

    p->link = t->link;
    t->link = p;
    return head;
}

NODE* Ordered_Delete(NODE *head, int x) {
    if (head == NULL) return NULL;

    if (head->data == x) {
        NODE *temp = head->link;
        free(head);
        return temp;
    }

    NODE *t = head;
    while (t->link != NULL && t->link->data != x)
        t = t->link;

    if (t->link == NULL) return head;

    NODE *del = t->link;
    t->link = del->link;
    free(del);
    return head;
}


/* ------------------ MAIN ------------------ */

int main() {

    NODE *head = Init_List();

    head = Insert_End(head, 30);
    head = Insert_End(head, 10);
    head = Insert_End(head, 20);

    printf("Original:\n");
    Display(head);

    head = Insert_Beg(head, 5);
    Display(head);

    head = Insert_Pos(head, 15, 3);
    Display(head);

    head = Delete_Pos(head, 2);
    Display(head);

    Sort_List(head);
    printf("\nAfter sorting:\n");
    Display(head);

    head = Ordered_Insert(head, 12);
    Display(head);

    head = Ordered_Delete(head, 20);
    Display(head);

    return 0;
}
