/* 
 * File:   lista.c
 * Author: marina
 *
 * Created on 17 de Outubro de 2014, 17:21
 */

#include "lista.h"

List *memAlloc(void) {
    return (List *) malloc(sizeof(List));
}

ListN *memAllocN(void) {
    return (ListN *) malloc(sizeof(ListN));
}

void printLista(List *head) {
    int i;
    while (head != NULL) {
        for (i = 0; i < SIZE; i++) {
            printf("%d ", head->data[i]);
        }
        printf("\n");
        head = head->next;
    }
}
    
List *insert(List *head, int *data) {
    List *newp, *end, *ret;
    int i = 0;

    if ((newp = memAlloc()) == NULL)
        exit(1);

    if (head == NULL)
        ret = newp;
    else {
        ret = head;
        end = head;
        while (end->next != NULL)
            end = end->next;
        end->next = newp;
    }

    for (; i < SIZE; i++)
        newp->data[i] = data[i];

    newp->next = NULL;
    return ret;
}

ListN *insertN(ListN *head, float *data) {
    ListN *newp, *end, *ret;
    int i = 0;
    
    if ((newp = memAllocN()) == NULL)
        exit(1);
    
    if (head == NULL)
        ret = newp;
    else {
        ret = head;
        end = head;
        while (end->next != NULL)
            end = end->next;
        end->next = newp;
    }
    
    for (; i < SIZE; i++)
        newp->data[i] = data[i];
    
    newp->next = NULL;
    return ret;
}

List *delete(List *head, List *obj) {
    List *previous, *ret;
    if (obj == NULL || head == NULL)
        return (NULL);
    if (obj == head) {
        ret = obj->next;
        free(obj);
        return (ret);
    }
    previous = head;
    while (previous->next != obj && previous->next != NULL)
        previous = previous->next;
    if (previous->next != NULL) { /* item found in list */
        previous->next = obj->next;
        free(obj);
    }
    return (head);    
}
