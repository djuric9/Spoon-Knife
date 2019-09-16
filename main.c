#include <stdio.h>
#include <stdlib.h>

#include "LinkedList1.h"

int main() {
    head* linkedList;
    float defaultValue = 0;

    float num1 = 2.8;
    float num2 = 40.1;
    float num3 = 0.23;

    initializeList(&linkedList, 3);
    fillList(linkedList, sizeof(defaultValue), &defaultValue);
    printList(linkedList);

    changeElementInList(linkedList, &num1, sizeof(defaultValue), 1);
    changeElementInList(linkedList, &num2, sizeof(defaultValue), 2);
    printList(linkedList);
    changeElementInList(linkedList, &num3, sizeof(defaultValue), 0);
    printList(linkedList);
    deleteElementInList(linkedList, 0);
    printList(linkedList);
    deleteElementInList(linkedList, 1);
    printList(linkedList);
    return 0;
}
