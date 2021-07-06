//
// Created by pedro on 05/07/2021.
//

#include <stdio.h>

#define MAX_SIZE 100

typedef struct item {
    int key;
} TItem;

typedef struct list {
    TItem items[MAX_SIZE];
    int size;
} TList;


/* Start a list */
void TListStart(TList *list) {
    list->size = 0;
}

/* Return 1 if a list is empty and 0 otherwise */
int TListIsEmpty(TList *list) {
    return list->size == 0;
}

/* Insert an element x in a list */
void TListInsertBeginning(TList *list, TItem item) {
    list->items[list->size++] = item;
}

/* Remove an element from the ending of the list and return through the pX parameter
 * the function returns 0 if there is not an element in position p in the list, 1 otherwise */
int TListRemoveEnding(TList *list, TItem *item) {
    if (TListIsEmpty(list))
        return 0;
    *item = list->items[--list->size];
    return 1;
}

/* return the list size */
int TListSize(TList *list) {
    return list->size;
}

void TListPrint(TList *list) {
    printf("[");
    for (int i=0;i<list->size;i++) {
        printf("%d ", list->items[i].key);
    }
    printf("]\n");
}

void TListConcatenate(TList *list1, TList *list2, TList *list3) {
    int i;

    for (i=0;i<list1->size;i++)
        list3->items[list3->size++] = list1->items[i];

    for (i=0;i<list2->size;i++)
        list3->items[list3->size++] = list2->items[i];

}


int TListSplit(TList *list1, TList *list2, TList *list3, int pos) {
   if (pos >= MAX_SIZE)
       return 0;
   int i = 0;
   for (i=0;i<pos;i++)
        list2->items[i] = list1->items[i];
   list2->size = pos;

   for (i=pos;i<list1->size;i++)
        list3->items[i-pos] = list1->items[i];
   list3->size = list1->size - pos;

   return 1;
}

void TListCopy(TList *list1, TList *list2) {
    int i;
    for (i=0;i<list1->size;i++)
        list2->items[i] = list1->items[i];
    list2->size = list1->size;
}

int TListSearch(TList *list, TItem *item) {
    int i;
    for (i=0;i<list->size;i++)
        if (list->items[i].key == item->key)
            return i;
    return -1;
}

void TListTest() {
    TList list;
    TListStart(&list);

    if (TListIsEmpty(&list) == 1)
        printf("The list is empty.\n");

    TItem item;
    item.key = 9;
    printf("TList >> ");
    TListPrint(&list);
    printf("Adding item: %d\t", item.key);
    TListInsertBeginning(&list, item);
    printf("TList >> ");
    TListPrint(&list);
    item.key = 8;
    printf("Adding item: %d\t", item.key);
    TListInsertBeginning(&list, item);
    printf("TList >> ");
    TListPrint(&list);

    TItem removedItem;
    if (TListRemoveEnding(&list, &removedItem) == 1)
        printf("Removed item: %d\t", removedItem.key);
    else
        printf("Impossible to remove an item!!!\t");
    printf("TList >> ");
    TListPrint(&list);

    item.key = 7;
    printf("Adding item: %d\t", item.key);
    TListInsertBeginning(&list, item);
    printf("TList >> ");
    TListPrint(&list);

    item.key = 6;
    printf("Adding item: %d\t", item.key);
    TListInsertBeginning(&list, item);
    printf("TList >> ");
    TListPrint(&list);

    if (TListRemoveEnding(&list, &removedItem) == 1)
        printf("Removed item: %d\t", removedItem.key);
    else
        printf("Impossible to remove an item!!!\t");
    printf("TList >> ");
    TListPrint(&list);

    printf("The list size is %d.\n", TListSize(&list));

    TList list1;
    TListStart(&list1);
    TList list2;
    TListStart(&list2);
    TList list3;
    TListStart(&list3);

    item.key = 0;
    TListInsertBeginning(&list1, item);
    item.key = 1;
    TListInsertBeginning(&list1, item);
    item.key = 2;
    TListInsertBeginning(&list1, item);

    item.key = 3;
    TListInsertBeginning(&list2, item);
    item.key = 4;
    TListInsertBeginning(&list2, item);
    item.key = 5;
    TListInsertBeginning(&list2, item);

    TListConcatenate(&list1, &list2, &list3);
    printf("\nTList 1 >> ");
    TListPrint(&list1);
    printf("TList 2 >> ");
    TListPrint(&list2);
    printf("TList 3 >> ");
    TListPrint(&list3);

    TList list4;
    TListStart(&list4);
    TList list5;
    TListStart(&list5);

    TListSplit(&list3, &list4, &list5, 3);
    printf("TList 4 >> ");
    TListPrint(&list4);
    printf("TList 5 >> ");
    TListPrint(&list5);

    TList list6;
    TListStart(&list6);

    TListCopy(&list5, &list6);
    printf("TList 6 >> ");
    TListPrint(&list5);

    item.key = 5;
    int posSearched = TListSearch(&list5, &item);
    if (posSearched != -1)
        printf("Item found at position %d.\n", posSearched);
    else
        printf("Item not found.\n");

    item.key = 0;
    posSearched = TListSearch(&list6, &item);
    if (posSearched != -1)
        printf("Item found at position %d.\n", posSearched);
    else
        printf("Item not found.\n");
}

int main() {
    TListTest();
}
