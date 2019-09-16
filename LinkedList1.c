#include "LinkedList1.h"

void initializeList(head** list, int listSize) {
    // check if size of list is invalid
    if(listSize < 1) {
        printf("Invalid list size: %d!\n", listSize);
        return;
    }
    // initialize with head element
    head* listHead = (head*)malloc(sizeof(head));
    listHead->size = listSize;
    listHead->list = (entry*)malloc(sizeof(entry));
    *list = listHead;
}

void fillList(head* listHead, size_t elementSize, void* defaultValue) {
    // initialize first element
    entry* element = (entry*)malloc(sizeof(entry));
    element->data = malloc(elementSize);
    int j = 0;
    for(j = 0; j < elementSize; j++) {
        *(char *)(element->data + j) = *(char *)(defaultValue + j);
    }
    element->next = NULL;
    entry* elementPointer = element;

    listHead->list = element;

    // initialize other elements
    int k = 1;
    for(k = 1; k < listHead->size; k++) {
        entry* newElement = (entry*)malloc(sizeof(entry));
        newElement->data = malloc(elementSize);
        for(j = 0; j < elementSize; j++) {
            *(char *)(newElement->data + j) = *(char *)(defaultValue + j);
        }
        newElement->next = NULL;
        elementPointer->next = newElement;
        elementPointer = elementPointer->next;
    }
}

void changeElementInList(head* list, void* elementData, size_t elementSize, int elementIndex) {
    if(list->size < elementIndex) {
        printf("Invalid index: %d (list size: %d)!\n", elementIndex, list->size);
        return;
    }
    entry* elementPointer = list->list;
    int k = 0;
    for(k = 0; k < elementIndex; k++) {
        elementPointer = elementPointer->next;
    }

    elementPointer->data = malloc(elementSize);
    for(k = 0; k < elementSize; k++) {
        *(char *)(elementPointer->data + k) = *(char *)(elementData + k);
    }
}

void* findElementByIndex(head* list, int elementIndex) {
    if(list->size < elementIndex) {
        printf("Invalid index: %d (list size: %d)!\n", elementIndex, list->size);
        return NULL;
    }
    entry* elementPointer = list->list;
    int k = 0;
    for(k = 0; k < elementIndex; k++) {
        elementPointer = elementPointer->next;
    }
    return elementPointer->data;
}

void deleteElementInList(head* list, int elementIndex) {
    if(list->size < elementIndex) {
        printf("Invalid index: %d (list size: %d)!\n", elementIndex, list->size);
        return;
    }
    if(elementIndex == 0) {
        list->list = list->list->next;
        return;
    }
    entry* elementPointer = list->list;
    int k = 0;
    for(k = 0; k < elementIndex-1; k++) {
        elementPointer = elementPointer->next;
    }
    elementPointer->next = elementPointer->next->next;
}

// print function for testing
void printList(head* list) {
    entry* elementPointer = list->list;
    int index = 0;
    printf("List:\n");
    while(elementPointer != NULL) {
        printf("\t Element %d: %f.\n", index++, *(float*)(elementPointer->data));
        elementPointer = elementPointer->next;
    }
}
