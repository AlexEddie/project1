#include <stdio.h>
//void rotationCipher(int count, int rotNun );
int numberText[500];

char text[500];
char word[500];
char CiphLib[500];
char outText[500];
char comword[10000];

char  alphabet[2][26] = {{"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"},
     {"a""b""c""d""e""f""g""h""i""j""k""l""m""n""o""p""q""r""s""t""u""v""w""x""y""z"}};
     
char character1;
char character2;
char grb;


void caps(int counter, int counter2);
void rot(int counter, int numOfrotation);
void subC(int counter2);
void subCD(int counter2);

int main(){
    
    
    int counter = 0;
    int counter2 = 0; 
    int counter3 = 0;
    
    FILE * inputFile;
    FILE * outputF;
    FILE * cipherLibrary;
    
    
    

    inputFile = fopen("inputStuff.txt", "r");
    cipherLibrary = fopen("SubstitutionCipherLibrary.txt","r");
    outputF = fopen("output.txt", "w");
    
    while (feof(inputFile) == 0 ){
        char w;
        fscanf(inputFile, "%s", &w);
        word[counter3]= w;
         counter3++;
    }
    
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
    caps(counter, counter2);
   printf("Please press R if you wish to uses the  rotation cipher \n or S substitution cipher\n :");
    char keyRS;
    char keyED;
    scanf("%c", &keyRS);
    int i = 0;
    while (i <1){
        if(keyRS==alphabet[0][17]||keyRS==alphabet[1][17]){
            
            i =1;
            int h = 0;
            while (h<1){
                printf("if you wish to encrypt please press E \n if you wish do decrypt pressd D \n :");
                scanf("%c", &keyED);
                if(keyED==alphabet[0][4]||keyED==alphabet[1][4]){
                    h=1;
                    printf("please ender the encryption key this can be between 1 and 26 \n :");
                    int nor;
                    scanf("%d", &nor);
                    if ((nor>0)&&(nor<26)){
                        int numOfrotation = nor-1;
                        //printf("\n \n %d",numOfrotation);
                         
                        rot(counter, numOfrotation);
                        for (int i= 0;i<=(counter-1);i++){
                                printf("%c ", outText[i]);
                                fprintf(outputF,"%c", outText[i]);
                            }
                        
                    }
                    
                }else if(keyED==alphabet[0][3]||keyED==alphabet[1][3]){//decode
                    h = 1;
                    printf("please ender the decryption key this can be between 1 and 26 \n :");
                     int nor;
                    scanf("%d", &nor);
                    if ((nor>0)&&(nor<=26)){
                        
                        int numOfrotation = ((25 - (nor-1)));
                        if (numOfrotation<0){
                            numOfrotation = numOfrotation+25;
                        }                        
                        //printf(" %d /n", numOfrotation);
                         
                        rot(counter, numOfrotation);
                        
                        for (int i= 0;i<=(counter-1);i++){
                               printf("%c", outText[i]);
                                fprintf(outputF,"%c", outText[i]);
                            }
                        }

                //}else if (keyED!=NULL){
                    //printf("you have entered an invale input \n if you wish to encrypt please press ""e"" if you wish do decrypt press""d""");
                }

            }

        }else if (keyRS==alphabet[0][18]||keyRS==alphabet[1][18]){
            i = 0;
            while (i<1){
                printf("if you wish to encrypt please press E \n if you wish do decrypt pressd D \n :");
                scanf("%c", &keyED);
                if(keyED==alphabet[0][4]||keyED==alphabet[1][4]){
                    i=1;
                    subC(counter2);
                    for (int i= 0;i<=(counter);i++){
                        printf("%c ", outText[i]);
                        fprintf(outputF,"%c", outText[i]);
                        }
                        
                    
                } else if(keyED==alphabet[0][3]||keyED==alphabet[1][3]){
                    i = 1;
                    void subCd(int counter3);
                    
                    for (int i= 0;i<=(counter);i++){
                        printf("%c ", word[i]);
                        //fprintf(outputF,"%c", outText[i]);
                        
                        }
                }

                    
                }

            }
        
        }
  fclose (outputF);
 
  return 0;
}

// rotation cipher

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
                    numberText[z]= ((q+numOfrotation)-25);
                    outText[z]= alphabet[0][(q+numOfrotation)-25];
                }
            }else if((q>=27) && bool1==0){
                outText[z] = text[z];
            }
        }
   }
  
}


//Substitution Cipher encoder 

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




void subCD(int counter2){
    
    //char gKey[25];
    /*
    //FILE * comWordLib;
    //FILE * 
    
    //inputFile = fopen("commonword.txt", "r");
    char word;
    int c = 0;
      while (feof(inputFile) == 0 ){
        fscanf(inputFile, "%s", &word);
        comword[c]= word;
        c++;
        
    }
    */
}






void caps(int counter, int counter2){
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
}


