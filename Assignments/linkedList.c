#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
//Created by Scott Killeen 

FILE *openInputFile(char *filename){
  FILE *fp = fopen(filename, "r");
  if ( fp == NULL ){
    perror("Error: ");
    exit(1);
  }
  return fp;
}

FILE *openOutputFile(char *filename){
  FILE *fp = fopen(filename, "w");
  if ( fp == NULL ){
    perror("Error: ");
    exit(1);
  }
  return fp;
}

LinkedList readAndAddToStart(LinkedList list, FILE *inputFile){
  int myNumber;
  fscanf(inputFile, "%d", &myNumber);
  if (myNumber == NULL){
    perror("Error: ");
    exit(1);
  }
  LinkedList ptr = malloc(sizeof(struct ListNode));
  ptr->data = myNumber;
  ptr->next=list;
  return ptr;
}

LinkedList readAndAddToEnd(LinkedList list, FILE *inputFile){
  int myNumber;
  fscanf(inputFile, "%d", &myNumber);
  if (myNumber == NULL){
    perror("Error: ");
    exit(1);
  }
  LinkedList ptr = malloc(sizeof(struct ListNode));
  LinkedList temp=list;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  temp->next=ptr;
  ptr->data=myNumber;
  ptr->next=NULL;
  return list;
}

LinkedList deleteFirst(LinkedList list){
  if (list == NULL){
    return list; }
  LinkedList temp;
  free(list);
  return list->next;
}

LinkedList deleteLast(LinkedList list){
  if (list == NULL){
    return list; }
  LinkedList temp = list;
  LinkedList temp2 = list;
  while((temp->next!= NULL) && (temp->next->next != NULL)){
    temp=temp->next;
  }
  temp2 = temp->next;
  free(temp2);
  temp->next = NULL;
  return list;
}
  
void printList(LinkedList list, FILE *outputFile){
  fprintf(outputFile,"[");
   while(list != NULL){
  fprintf(outputFile, "%d,", list->data);
   list=list->next;
  }
  fprintf(outputFile,"\b]\n");
}
