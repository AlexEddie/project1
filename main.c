#include <stdio.h>
#include <string.h>

#define CHARNUMBER (31)

//int numberText[500];
//int CHARNUMBER = CHARNUMBER;
char text[500];
//char word[500][16];
char CiphLib[30];
char outText[500];
char wordin[500][16];
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
    
    //char a[16];
    char b[16];
    //char b[16];
    //int counter3 = 0;
    
    FILE * inputFile;
    FILE * cipherLibrary;
    //FILE * wordLib;
    
    //wordLib = fopen("wordLibrary.txt", "r");
    inputFile = fopen("inputStuff.txt", "r");
    cipherLibrary = fopen("SubstitutionCipherLibrary.txt","r");
 
    
    //fclose(wordLib);
    
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
    for (int x = 0;x<500;x++){
        fscanf(inputFile, "%s",b );
        for (int z = 0; z<16;z++){
            wordin[x][z]= b[z];
        }
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
                                print(counter);
                            }   
                        }else if(keyYN==alphabet[0][13]||keyYN==alphabet[1][13]){
                            r=1;
                            rotNK(counter);
                            //print(counter);
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
   // int wordcountinput[500];
   // int wordcountlib[10001];
   // char wordlibsize[10000][16];
    //char a[16];
    //char mostcomletter[27];
    char key[26];
    int letters[27]; 
    //FILE * wordlibsizefile;
    char fhg[2][27]={{"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"},{""}};
    
    //wordlibsizefile = fopen("wordlibaraybysize.txt","r");
        int letterscore = 0;
        for (int p = 0;p<26;p++){
            letterscore = 0;
            for (int y =0; y<counter; y++) {
                if (text[y]==alphabet[0][p]){
                    letterscore=letterscore+1;
                      
            }
            letters[p] = letterscore;
        }
        letterscore =0;
        
    }
  
    for (int n=0; n<26;n++){
        fhg[1][n]=letters[n];
    }
    for (int ig = 0; ig<26 ;ig++){
        for(int jg =0; jg<25;jg++){
            if(fhg[1][jg]<fhg[1][ig]){
                int temp1 = fhg[1][ig];
                fhg[1][ig] = fhg[1][jg];
                fhg[1][jg] = temp1 ;
                char temp2 = fhg[0][ig];
                fhg[0][ig] = fhg[0][jg];
                fhg[0][jg] = temp2 ;
            }
        }
    }
    
    for (int x = 0; x<26; x++){
        //printf("\n%d", fhg[1][x]);
        //printf("____%c.\n ",fhg[0][x]);
    } 
}



//rotation decipher 
void rotNK(int counter){
    char str[16];
    char wordArray[26][CHARNUMBER][16];
    int max;
    int key;
    char tempchar[16];
    char numstring[CHARNUMBER];
    
    FILE * wordLib;
    
    wordLib = fopen("wordLibrary.txt", "r");
    
    for (int n=0; n<10001; n++){
        fscanf(wordLib,"%s", str);
        for (int m =0; m<16;m++){
            wordLibray[n][m]= str[m];
        }
    }
    
    fclose(wordLib);
  int scorebord [27];
    FILE * tempfile;
    for(int t =0; t<26; t++){
        tempfile = fopen("tempdatastore.txt","w+");
        rot(CHARNUMBER,t);
        for (int p=0; p<CHARNUMBER; p++){
            fprintf(tempfile,"%c",outText[p]);
        }
        fclose(tempfile);
        tempfile = fopen("tempdatastore.txt","r");
       fscanf(tempfile,"%s", numstring);
        for (int n=0; n< 7; n++){
            fscanf(tempfile,"%s", tempchar);

            for (int m =0; m<=16;m++){
               wordArray[t][n][m] = tempchar[m];
            }
        }
        fclose(tempfile);
        
    }
    printf("%s\n",wordArray[0][0]);
    if (strcmp(wordArray[0][0], wordLibray[2847] ) == 0) {
                    printf("ok \n" );
                    //score++;
                    
                }
    for (int a=0; a<=25;a++){
        int score=0;
        for (int d=0; d<=9;d++){
            for (int s = 0 ; s<10001; s++){
                
                if (strcmp(wordArray[a][d], wordLibray[s] ) == 0) {
                    score++;
                    
                }
            }
        }
        
        scorebord[a] = score;
        printf("key is: %d score is: %d\n", a+1, scorebord[a]);
        
    }
    max = scorebord[0];
    for(int h = 0; h<25; h++){
        if (scorebord[h]>max){
            max = scorebord[h];
            key = h;
        }
    } 
  printf("\nscore is: %d key is %d\n", max, key);  
  rot(counter, key );
  print(counter);
  
}



// rotation cipher 
void rot(int counter, int numOfrotation){
    for (int z=0; z<=counter; z++){
        int bool1 = 0;
        for(int q = 0; q<=28;q++){
            if (text[z]==alphabet[0][q]){
                bool1 = 1;
                if ((q + numOfrotation)<=25){
                    //numberText[z]=q+numOfrotation;
                    outText[z]= alphabet[0][q+numOfrotation];
                }else {
                    //numberText[z]= ((q+numOfrotation)-26);
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
    for (int i= 0;i<=(counter-3);i++){
        printf("%c", outText[i]);
        fprintf(outputF,"%c", outText[i]);
    }
    printf("\n");
    fprintf(outputF,"\n");
    fclose (outputF);
}
 /*
     for (int x = 0;x<10000;x++){
        fscanf(wordlibsizefile, "%s",a );
        for (int z = 0; z<16;z++){
            wordlibsize[x][z]= a[z];
        }
        wordcountlib[x]= (unsigned)strlen(a);
        //printf ("The sentence entered is %u characters long.\n",(unsigned)strlen(a));
        //printf("\n");
    }
    for (int x= 0; x<500; x++){
        wordcountinput[x] = (unsigned)strlen(wordin[x]); 
    }   
    */