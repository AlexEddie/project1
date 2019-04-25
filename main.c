#include <stdio.h>
//void rotationCipher(int count, int rotNun );

char text[500];
char CiphLib[500];
int numberText[500];
char alphabet[50];
char outText[500];
char character1;
char character2;
char grb;

int main(){
    
    int numOfrotation = 5;
    int counter = 0;
    int counter2 = 0; 
    
    FILE * inputFile;
    FILE * outputF;
    FILE * CipherLibrary;
    
    
    inputFile = fopen("inputStuff.txt", "r");
    CipherLibrary = fopen("SubstitutionCipherLibrary.txt","r");
    outputF = fopen("output.txt", "w");
    
 
    
    while (feof(inputFile) == 0 ){
        fscanf(inputFile, "%c", &character1);
        text[counter]= character1;
        counter ++;
    }
     while (feof(CipherLibrary) == 0){
        fscanf(CipherLibrary, "%c", &character2);
        CiphLib[counter2]= character1;
        counter2++;
    }
  
  fclose (inputFile);
  fclose (CipherLibrary);
  
  
     char  alphabet[2][26] = {{"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"},
     {"a""b""c""d""e""f""g""h""i""j""k""l""m""n""o""p""q""r""s""t""u""v""w""x""y""z"}};
     // changes lower case to upper case
     for (int k = 0; k<= counter;k++){
         for (int d =0; d<26; d++){
            if (text[k]==alphabet[1][d]){
                text[k]=alphabet[0][d];
            }
         }
     }
     
     
     
     
     //Substitution Cipher
     for (int x = 0; x<=counter2; x++){
         int bool2 = 0;
         for (int z = 0; z<=28; z++){
             if (text[x]==alphabet[0][z]){
                 bool2 = 1;
                 outText[x]= CiphLib[z];
            }else if((z>=27) && bool2==0){
                outText[x] = text[x];
            }
        }
    }

     
     
     
     /*
    // rotation cipher
   for (int z=0; z<=counter; z++){
       int bool1 = 0;
       for(int q = 0; q<=28;q++){
            if (text[z]==alphabet[0][q]){
                bool1 = 1;
                if ((q + numOfrotation)<=25){
                    numberText[z]=q+numOfrotation;
                    outText[z]= alphabet[0][q+numOfrotation];
                }else {
                    numberText[z]= ((q+numOfrotation)-26);
                    outText[z]= alphabet[0][(q+numOfrotation)-26];
                }
            }else if((q>=27) && bool1==0){
                outText[z] = text[z];
            }
        }
   }
   
   */
   
   
  for (int i= 0;i<(counter);i++){
      
      printf("%c ", outText[i] );
      fprintf(outputF,"%c", outText[i]);
  }
    //for (int f = 0; f <counter; f++){
      //  fprintf(outputF, "%c", numberText[f]);
   // }
  fclose (outputF);
 
  return 0;
}

/*void rotationCipher(int counter, int rN ){
     int ct = counter;
     //int rN = rotNum;
     char  alphabet[] = {"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"};
     for (int z=0; z<ct; z++){
        grb = text[z];
        int num = 0;
        while ((grb != alphabet[num]) || num < 26){
            if (num<26){
                num++;
            }
        }
        numberText[z] = (num + rN)%25;
    }
    //for (int f = 0; f <counter; f++){
     //   printf("%c", numberText[f]);
    //}
}*/
