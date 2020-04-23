/*
 * circularQ.c
 *
 *  Created on: 2020. 4. 19.
 *      Author: young
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;


QueueType *createQueue();
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();


int main(void)
{
    QueueType *cQ = createQueue();
    element data;

    char command;

    do{
        printf("\n-----------------------------------------------------\n");
        printf("                     Circular Q                   \n");
        printf("------------------------------------------------------\n");
        printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
        printf("------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch(command) {
        case 'i': case 'I':
            data = getElement();
            enQueue(cQ, data);
            break;
        case 'd': case 'D':
            deQueue(cQ,&data);
            break;
        case 'p': case 'P':
            printQ(cQ);
            break;
        case 'b': case 'B':
            debugQ(cQ);
            break;
        case 'q': case 'Q':
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    }while(command != 'q' && command != 'Q');


    return 1;
}


QueueType *createQueue()
{
    QueueType *cQ;
    cQ = (QueueType *)malloc(sizeof(QueueType));
    cQ->front = 0;
    cQ->rear = 0;
    return cQ;
}

element getElement()
{
    element item;
    printf("Input element = ");
    scanf(" %c", &item);
    return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
    if(cQ->front == cQ->rear){
        printf("비었습니다.\n");
        return 1;
    }
    else return 0;
}

/* complete the function */
int isFull(QueueType *cQ)
{
  if(((cQ->rear+1)%MAX_QUEUE_SIZE) == cQ->front){
      printf("꽉 찼습니다.");
      return 1;
  }
  else return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
    if(isFull(cQ)){
        return;
    }
    else {
        cQ->rear = (cQ->rear+1) % MAX_QUEUE_SIZE;
        cQ->queue[cQ->rear] = item;
    }
    return;
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{
    if(cQ->front == cQ->rear){
        isEmpty(cQ);
        return;
    }
    else{
    cQ->front = (cQ->front+1) % MAX_QUEUE_SIZE;
    cQ->queue[cQ->front] = NULL;
    }
    return ;
}


void printQ(QueueType *cQ)
{
    int i, first, last;

    first = (cQ->front + 1)%MAX_QUEUE_SIZE;
    last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

    printf("Circular Queue : [");

    i = first;
    while(i != last){
        printf("%3c", cQ->queue[i]);
        i = (i+1)%MAX_QUEUE_SIZE;

    }
    printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

    printf("\n---DEBUG\n");
    for(int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        if(i == cQ->front) {
            printf("  [%d] = front\n", i);
            continue;
        }
        printf("  [%d] = %c\n", i, cQ->queue[i]);

    }
    printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}
