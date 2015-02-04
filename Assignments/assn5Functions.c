//By Scott Killeen
//Creating Functions to be used by assn5Testing.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Counts the total amount of spaces in a sentence.
int countSpaces(char theString[]){
  int spaceCount = 0;
  int i;
  for(i=0; i < strlen(theString); i++){
    if(theString[i]==' ') //If there is a space
      spaceCount++;
  }
  return spaceCount;
}

//Splits a string into individual words.
char** splitString(char theString[], int *arraySize){
  int spaceCount = countSpaces(theString); //Get number of spaces
  *arraySize = spaceCount + 1; 
  char** stringSplit = malloc((*arraySize) * sizeof(char*));
  int count = 1; //char count
  int words = 0; //word count
  int j =0;
  int i = 0; 
  while(theString[i] != ' ' && theString[i] != '\0'){
    count++; //getting number of chars
    i++;
  }
  while (spaceCount >=0) {
    char* nextWord = malloc((count) * sizeof(char)); //malloc uses the number of chars we got from previous while loop.
    int location = 0; //keeping track of where we are in the string
    int value = j + location; 
    while (theString[value] != ' ' && theString[value] != '\0'){//until we reach end of a word
      nextWord[location] = theString[value];
      location++;
      value++;
    }
    nextWord[location] = '\0';
    stringSplit[words] = nextWord; 
    words++; //wordcount
    j = value + 1;
    spaceCount--; //go until no more spaces are left
  }
  return stringSplit;
}
//Cleanup function to free heap space
void cleanup(char *words[], int numWords){
  int i = 0;
  while (i < numWords) {
    free (words[i]);
    i++;
  }
  free(words);
} 



