#include <stdio.h>
//void rotationCipher(int count, int rotNun );

char text[500];
char CiphLib[500];
int numberText[500];
char outText[500];
char  alphabet[2][26] = {{"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"},
     {"a""b""c""d""e""f""g""h""i""j""k""l""m""n""o""p""q""r""s""t""u""v""w""x""y""z"}};
char character1;
char character2;
char grb;


//void caps(char * txt, char * abc, int count);
void rot(int counter, int numOfrotation);
void subC(int counter2);

int main(){
    
    int numOfrotation = 5;
    int counter = 0;
    int counter2 = 0; 
    
    FILE * inputFile;
    FILE * outputF;
    FILE * cipherLibrary;
    
    
    inputFile = fopen("inputStuff.txt", "r");
    cipherLibrary = fopen("SubstitutionCipherLibrary.txt","r");
    outputF = fopen("output.txt", "w");
    
 
    
    while (feof(inputFile) == 0 ){
        fscanf(inputFile, "%c", &character1);
        text[counter]= character1;
        counter ++;
    }
     while (feof(cipherLibrary) == 0){
        fscanf(cipherLibrary, "%c", &character2);
        CiphLib[counter2]= character2;
        counter2++;
    }
  
  fclose (inputFile);
  fclose (cipherLibrary);
  
    for (int k = 0; k<= counter;k++){
         for (int d =0; d<26; d++){
            if (text[k]==alphabet[1][d]){
                text[k]=alphabet[0][d];
            }
         }
     }
      for (int k = 0; k<= counter2;k++){
         for (int d =0; d<26; d++){
            if (CiphLib[k]==alphabet[1][d]){
                CiphLib[k]=alphabet[0][d];
            }
         }
     }
     
     rot(counter, numOfrotation);
     subC(counter2);
     
     //Substitution Cipher
     /*
     for (int x = 0; x<=counter2; x++){
         int bool2 = 0;
         for (int z = 0; z<=28; z++){
             if (text[x]==alphabet[0][z]){
                 bool2 = 1;
                 outText[x] = CiphLib[z];
            }else if((z>=27) && bool2==0){
                outText[x] = text[x];
            }
        }
    }
*/
     
     
     
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
   
   
  for (int i= 0;i<=(counter2);i++){
      
      printf("%c ", outText[i]);
      //fprintf(outputF,"%c", CiphLib[i]);
  }
    //for (int f = 0; f <counter; f++){
      //  fprintf(outputF, "%c", numberText[f]);
   // }
  fclose (outputF);
 
  return 0;
}

void rot(int counter, int numOfrotation){
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
}


//Substitution Cipher

void subC(int counter2){
     for (int x = 0; x<=counter2; x++){
         int bool2 = 0;
         for (int z = 0; z<=28; z++){
             if (text[x]==alphabet[0][z]){
                 bool2 = 1;
                 outText[x] = CiphLib[z];
            }else if((z>=27) && bool2==0){
                outText[x] = text[x];
            }
        }
    }
}

/*
void caps(char * txt, char * abc, int count){
      for (int k = 0; k<= count;k++){
         for (int d =0; d<26; d++){
            if (txt[k]==*abc[1][d]){
                txt[k]=*abc[0][d];
            }
         }
     }
}
*/

