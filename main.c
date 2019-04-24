#include <stdio.h>
char text[500];
int main(){
    char character;
    int couter = 0;
    FILE * inputFile;
    inputFile = fopen("inputStuff.txt", "r");
  while (feof(inputFile) == 0 ){
     
      fscanf(inputFile, "%c", &character);
      printf("%c", character);
      text[couter]= character;
      
      couter ++;
  }
  for (int i= 0;i<couter;i++){
      //printf("%c %d", character, i);
  }
  return 0;
}
 