#include <stdio.h>
#include <string.h>

#define CHARNUMBER (31)

int numberText[500];
//int CHARNUMBER = CHARNUMBER;
char text[500];
//char word[500][16];
char CiphLib[30];
char outText[500];
char wordLibray[10001][16];
//char wordArray[26][CHARNUMBER][16];

char  alphabet[2][26] = {{"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"},
     {"a""b""c""d""e""f""g""h""i""j""k""l""m""n""o""p""q""r""s""t""u""v""w""x""y""z"}};
     
char character1;
char character2;
char grb;

void rotNK(int counter);
void print(int counter);
void caps(int counter, int counter2);
void rot(int counter, int numOfrotation);
void subC(int counter2);
void subCD(int counter2);
void subCDN(int counter);

int main(){
    
    int c1 = 0;
    int counter = 0;
    int counter2 = 0; 
    
    char a[16];
    //char b[16];
    //int counter3 = 0;
    
    FILE * inputFile;
    FILE * cipherLibrary;
    FILE * wordLib;
    
    wordLib = fopen("wordLibrary.txt", "r");
    inputFile = fopen("inputStuff.txt", "r");
    cipherLibrary = fopen("SubstitutionCipherLibrary.txt","r");
  
   for (int n=0; n<10001; n++){
        fscanf(wordLib,"%s", a);
        for (int m =0; m<16;m++){
            wordLibray[n][m]= a[m];
        }
    }
    
    fclose(wordLib);
    
    while (feof(cipherLibrary) == 0 ){
        char w;
        fscanf(cipherLibrary, "%c", &w);
        CiphLib[c1]= w;
        c1++;
    }
    fclose (cipherLibrary);
    
    while (feof(inputFile) == 0 ){
        fscanf(inputFile, "%c", &character1);
        text[counter]= character1;
        counter ++;
    }
    fclose (inputFile);

    caps(counter, counter2);
    
    printf("----------------------------------------- \n \nPlease press R if you wish to uses the  rotation cipher \nor S substitution cipher\n:");
    char keyRS;
    char keyED;
    char keyYN;
    scanf("%c", &keyRS);
    int i = 0;
    int h = 0;
    while (i <1){
        if(keyRS==alphabet[0][17]||keyRS==alphabet[1][17]){
            i =1;
            while (h<1){
                printf("----------------------------------------- \n \nif you wish to encrypt please press E \n if you wish do decrypt pressd D \n:");
                scanf("%c", &keyED);
                if(keyED==alphabet[0][4]||keyED==alphabet[1][4]){
                    h=1;
                    printf("----------------------------------------- \n \nplease ender the encryption key this can be between 1 and 26 \n:");
                    int nor;
                    scanf("%d", &nor);
                    if ((nor>0)&&(nor<26)){
                        int numOfrotation = nor-1;
                        rot(counter, numOfrotation);
                        print(counter);
                    }
                }else if(keyED==alphabet[0][3]||keyED==alphabet[1][3]){//decode
                    h = 1;
                    printf("----------------------------------------- \n \nif you have a key press Y if not press N \n:");
                    int r = 0;
                    while (r<1){
                        scanf("%c", &keyYN);
                        if(keyYN==alphabet[0][24]||keyYN==alphabet[1][24]){
                            r=1;
                            printf("----------------------------------------- \n \nplease enter the decryption key this can be between 1 and 26 \n:");
                            int nor;
                            scanf("%d", &nor);
                            if ((nor>0)&&(nor<=26)){
                                int numOfrotation = ((26 - (nor-1)));
                                if (numOfrotation<0){
                                    numOfrotation = numOfrotation+26;
                                }          
                                rot(counter, numOfrotation);
                                //print(counter);
                            }   
                        }else if(keyYN==alphabet[0][13]||keyYN==alphabet[1][13]){
                            r=1;
                            rotNK(counter);
                            print(counter);
                        }   
                    }
                }
            }   // for sub cypher
        } else if (keyRS==alphabet[0][18]||keyRS==alphabet[1][18]){
            i =1;
            printf("----------------------------------------- \n \nif you wish to encrypt please press E \nif you wish do decrypt pressd D \n:");
            while (h<1){
               // printf("if you wish to encrypt please press E \n if you wish do decrypt pressd D \n :");  
                scanf("%c", &keyED);
                //if e is pressed
                if(keyED==alphabet[0][4]||keyED==alphabet[1][4]){
                    h=1;
                    subC(counter);
                    print(counter); 
                        // if d is pressed
                }else if(keyED==alphabet[0][3]||keyED==alphabet[1][3]){
                    h = 1;
                    printf("----------------------------------------- \n \nif you have a key press Y if not press N \n:");
                    int r = 0;
                    while (r<1){
                        scanf("%c", &keyYN);
                        if(keyYN==alphabet[0][24]||keyYN==alphabet[1][24]){
                            r=1;
                            subCD(counter);
                            print(counter);    
                        }else if(keyYN==alphabet[0][13]||keyYN==alphabet[1][13]){
                            r=1;
                            subCDN(counter);
                            print(counter);
                        }   
                    }
                }
            }   
        } 
    }
  return 0;
}


//Substitution Cipher encoder 

void subC(int counter){
     for (int x = 0; x<=counter; x++){
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


//void subCDN(int counter){
    //char gKey[25];
//}

void subCD(int counter2){
    for (int i =0;i<counter2;i++){
        int bool3 = 0;
        for(int d = 0; d<28;d++){
            if (text[i]==CiphLib[d]){
                bool3 = 1;
                outText[i] = alphabet[0][d];
            }else if((d>=27) && bool3==0){
                outText[i] = text[i];
            }
        }
    }

}

void subCDN(int counter){
    printf("hey");
}



//rotation decipher 
void rotNK(int counter){
    char wordArray[26][CHARNUMBER][16];
    //int score=0;
    char tempchar[1000];
    //char wordArray[26][CHARNUMBER][16];
  
   FILE * tempfile;
        
    
    
    for(int t =0; t<26; t++){
        tempfile = fopen("tempdatastore.txt","w+");
        rot(CHARNUMBER,t);
        
        for (int p=0; p<CHARNUMBER; p++){
            //printf("%c",outText[p]);
            fprintf(tempfile,"%c",outText[p]);
        }
       //printf("\n");
        for (int n=0; n<16; n++){
            
            fscanf(tempfile,"%s", tempchar);
            //printf("%s", tempchar);
            for (int m =0; m<16;m++){
               wordArray[t][n][m] = tempchar[m];
            }
        }
    }
    for (int th =0; th<27;th++){
        
        for (int jk =0; jk<CHARNUMBER;jk++){
            for (int i= 0; i<16; i++){
         printf("%s", wordArray[th][jk]);
         //printf("\n heyenhawjdwaijwaidawidwaiwadiaw\n");{
             }
        }
    }
    
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
                    numberText[z]= ((q+numOfrotation)-26);
                    outText[z]= alphabet[0][(q+numOfrotation)-26];
                }
            }else if((q>=27) && bool1==0){
                outText[z] = text[z];
            }
        }
    }
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




void print(int counter){
    FILE * outputF;
    outputF = fopen("output.txt", "w");
    for (int i= 0;i<=(counter-1);i++){
        printf("%c", outText[i]);
        fprintf(outputF,"%c", outText[i]);
    }
    fclose (outputF);
}
