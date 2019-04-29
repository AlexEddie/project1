#include <stdio.h>
#include <string.h>

#define MAXWORDSIZE 16
#define CHARNUMBER (31)

// all public array that can be call for thoughout the program.

char text[500];// make an array that store 500 charitors. it is used to save the input text to.
char CiphLib[30];// make an array that store 30 charitors. it is used to save the cyper key to.
char outText[500];//  make an array that store 500 charitors. it is used to save the text befor output to a text file.
char wordin[500][MAXWORDSIZE];//  make an array that stores 500 string that can be of lenth MAXWORDSIZE. it is used for saving word from input text as strings.
char wordLibray[10001][MAXWORDSIZE];//  make an array that stores 500 string that can be of lenth MAXWORDSIZE. is used to save word as string from the top 10000 most common word text doc.
char  alphabet[2][26] = {{"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"},
     {"a""b""c""d""e""f""g""h""i""j""k""l""m""n""o""p""q""r""s""t""u""v""w""x""y""z"}};// make an array of 2 array that hold upper case and lower case version of the alphabet.
     // it is used as reference though out the code
     

void rotNK(int counter);// a function used to find the most likly key and output for a given rotation cipher.
void print(int counter);// this  fuction called to print to output to the terminal and output.txt doc.
void caps(int counter, int counter2); // this fuction make input array and CiphLib array only contain capital letters.
void rot(int counter, int numOfrotation);// this function is call to decriped and encriped rotation ciphers.
void subC(int counter2);// this function is called to encriped using a substitution Cypher.
void subCD(int counter2);// this function is called to decriped using a substitution Cypher and a key.
void subCDN(int counter);// this function is called to decriped using a substitution Cypher and a key. it not finished. 





int main(){// function start when theprogram start.
    printf("\n\n\nplease enter text into |inputStuff.txt text must have less that 500 chartor\n");
// all varable are used in the main function.

    char character1;// makes a character called character1. 
    char keyRS;// make a char charactor called keyRS. used to sore user input to select if they will uses rotation Cypher or substitution Cypher.
    char keyED;// make a char charactor called keyED. for the user to select encrypt or decrypt.
    char keyYN;// make a char charactor called keyED. used for the user to input a yes or no question.
    
    char b[MAXWORDSIZE];//makes an array called b which is used as a temporary string. this is used for the making an array for words from the input file.
    
    int counter = 0;// makes an int called counter and make it equal 0. used as a counter to save the number of charactor int he text libary.
    int counter2 = 0; // makes an int called counter2 and make it equal 0. used as a counter to save the number of charactor int he cipher libary.
    int i = 0;// used as a bool to check if the user had inputed the correct charactor
    int h = 0;// used as a bool to check if the user had inputed the correct charactor
    
    
    FILE * inputFile;// make a file pointer called inputFile. used to read inputStuff.txt.
    FILE * cipherLibrary;// make a file pointer called cipherLibrary. used to read SubstitutionCipherLibrary.txt.
    
    
    inputFile = fopen("inputStuff.txt", "r");//opens the file inputStuff.txt and say we are going to read from it make set the inputFile a pointer to it.
    cipherLibrary = fopen("SubstitutionCipherLibrary.txt","r");//opens the file SubstitutionCipherLibrary.txt and say we are going to read from it make set the cipherLibrary a pointer to it
 
 
    //while loop make CiphLib array store all the charactors from SubstitutionCipherLibrary.txt.
    while (feof(cipherLibrary) == 0 ){// make a loop that end when all charactor of SubstitutionCipherLibrary.txt have been read.
        char w;//make a char called w. used to store the charactor form SubstitutionCipherLibrary.txt
        fscanf(cipherLibrary, "%c", &w);// scans and copy each charactor from SubstitutionCipherLibrary.txt and make "w" equal it
        CiphLib[counter2]= w;// call the array CiphLib. store the charactor form "w".
        counter2++;// adds one to counter2.
    }// end while loop.
    
    fclose (cipherLibrary);// closes the file SubstitutionCipherLibrary.txt
    
    
    //while loop make text array store all the charactors from inputStuff.txt.
    while (feof(inputFile) == 0 ){// make a loop that end when all charactor of inputStuff.txt have been read.
        fscanf(inputFile, "%c", &character1);// scans and copy each charactor from inputStuff.txt and make "character1" equal it.
        text[counter]= character1;// call the array text. store the charactor form "character1".
        counter ++;// adds one to counter.
    } // end while loop
    
    
    //make the 2d array wordin store string of words form inputStuff.txt.
    for (int x = 0;x<500;x++){// make a loop the repeat 500 time
        fscanf(inputFile, "%s",b );// scans and copy each string which end when a space is detected from inputStuff.txt and make the array "b" equal it.
        for (int z = 0; z<MAXWORDSIZE;z++){// make a loop the repeats MAXWORDSIZE time to go though each letter stored in array b
            wordin[x][z]= b[z];//set wordin equal to b at the poistion x
        }// end for loop
    }// end for loop
    
    
    fclose (inputFile);// closes the file inputStuff.txt
    
    
    caps(counter, counter2);// call the function caps to make the arrays text and CiphLib contain all caps


    printf("----------------------------------------- \n \nPlease press R if you wish to uses the  rotation cipher \nor S substitution cipher\n:");//print a message to tell the uses to select substitution Cypher or rotation Cypher
    
    scanf("%c", &keyRS);// scans for a keybord input and make keyRS equal it 
   
    while (i <1){// make a loop so that if the user input a invaled answer it will re-ask them
    
    
    
        if(keyRS==alphabet[0][17]||keyRS==alphabet[1][17]){// chech if the user inputed and upper case or lower case "r"
            i =1;// set i to 1 and stop the while loop
            
            while (h<1){// make a loop so that if the user input a invaled answer it will re-ask them
                printf("----------------------------------------- \n \nif you wish to encrypt please press E \n if you wish do decrypt pressd D \n:");//print a message to tell the uses to select encrypt or decrypt the input
                scanf("%c", &keyED);// scans for a keybord charactor input and make keyED equal it 
                
                
                
                //rotation Cypher encryptor
                if(keyED==alphabet[0][4]||keyED==alphabet[1][4]){// chech if the user inputed and upper case or lower case "e"
                    h=1;//stops the loop
                    printf("----------------------------------------- \n \nplease ender the encryption key this can be between 1 and 26 \n:");//print a message to tell the uses to input a encryption key between 1 and 26
                    int nor;// make an int call nor. used to check if the user input a number in the correct range
                    scanf("%d", &nor);//make nor equal user input
                    
                    if ((nor>0)&&(nor<26)){//check if the user input a number that greater than 0 and less than 26
                        int numOfrotation = nor-1;//make an int called numOfrotation and make it equal nor minus 1. this is done because the array start at 0 and not 1
                        rot(counter, numOfrotation);//calls the function rot and input the size of the array the need to be rotated and the amount it need to rotated by
                        print(counter);//calles the print function to out put the result for the user
                    }//end the if stament 

                    
                    
                //rotation Cypher decrypter
                }else if(keyED==alphabet[0][3]||keyED==alphabet[1][3]){// chech if the user inputed and upper case or lower case "d"
                    h = 1;// end the while loop
                    printf("----------------------------------------- \n \nif you have a key press Y if not press N \n:");//prints a message to ask the user if they have and decryption key
                    int r = 0;// used as a bool to check if the user had inputed the correct charactor
                    
                    while (r<1){// make a loop so that if the user input a invaled answer it will re-ask them
                        scanf("%c", &keyYN);// scans for a keybord charactor input and make keyYN equal it
                        
                        
                        
                        if(keyYN==alphabet[0][24]||keyYN==alphabet[1][24]){// chech if the user inputed and upper case or lower case "y"
                            r=1;// end the while loop
                            printf("----------------------------------------- \n \nplease enter the decryption key this can be between 1 and 26 \n:");//print a message to tell the user to input a decryption key between 1 and 26
                            int nor;// make an int call nor. used to check if the user input a number in the correct range
                            scanf("%d", &nor);// scans for a keybord charactor input and make keyYN equal it
                            
                            if ((nor>0)&&(nor<=26)){//check if the user input a number that greater than 0 and less than 26
                            
                                int numOfrotation = ((26 - (nor-1)));// this is used to inverse the decripption key so so the text rotates the correct amout to decript the message
                                
                                if (numOfrotation<0){//this is used to make the decripption key positive if when inverting made it negative
                                    numOfrotation = numOfrotation+26;//make the decripption key positive
                                }//end if
                                
                                rot(counter, numOfrotation);//calls the function rot and input the size of the array the need to be rotated and the amount it need to rotated by
                                print(counter);//calles the print function to out put the result for the user
                            }//end if  
                            
                            
                        }else if(keyYN==alphabet[0][13]||keyYN==alphabet[1][13]){// chech if the user inputed and upper case or lower case "n"
                            r=1;// end the while loop
                            rotNK(counter);// call the funtion rotNK which is used to guess the rotation cypher key
                            print(counter);//calles the print function to out put the result for the user
                        }// end else if
                    }//while loop
                }// end else if
            }//while loop
            
            
            
        // for sub cypher
        } else if (keyRS==alphabet[0][18]||keyRS==alphabet[1][18]){// chech if the user inputed and upper case or lower case "s"
            i =1;//end while loop
            printf("----------------------------------------- \n \nif you wish to encrypt please press E \nif you wish do decrypt pressd D \n:");//print a message to tell the uses to select encrypt or decrypt the input
            
            while (h<1){// make a loop so that if the user input a invaled answer it will re-ask them
               
                scanf("%c", &keyED);// scans for a keybord input and make keyED equal it
                if(keyED==alphabet[0][4]||keyED==alphabet[1][4]){// chech if the user inputed and upper case or lower case "e"
                    h=1;//end while loop
                    subC(counter);//call the function subC. this will encrypt the input with a substitution Cypher
                    print(counter); //calles the print function to out put the result for the user
                     
                     
                     
                }else if(keyED==alphabet[0][3]||keyED==alphabet[1][3]){// chech if the user inputed and upper case or lower case "d"
                    h = 1;// end while loop
                    printf("----------------------------------------- \n \nif you have a key press Y if not press N \n:");
                    int r = 0;// used as a bool to check if the user had inputed the correct charactor 
                    
                    while (r<1){// make a loop so that if the user input a invaled answer it will re-ask them
                        scanf("%c", &keyYN);// scans for a keybord charactor input and make keyYN equal it
                        if(keyYN==alphabet[0][24]||keyYN==alphabet[1][24]){// chech if the user inputed and upper case or lower case "y"
                            r=1;//end while loop
                            subCD(counter);//calls the subCD function. this is used to decrypt a substitution Cypher with a key
                            print(counter);//calles the print function to out put the result for the user
                            
                            
                        }else if(keyYN==alphabet[0][13]||keyYN==alphabet[1][13]){// chech if the user inputed and upper case or lower case "n"
                            r=1;// end while loop
                            subCDN(counter);//calls the subCD function. this is used to decrypt a substitution Cypher with no key. "not commplete"
                            print(counter);//calles the print function to out put the result for the user
                        }//end else if
                    }//end while loop
                }//end else if
            }//end while loop
        }//end else if
    }//end while loop
  return 0;// end program
}// end main function


//Substitution Cipher encoder 

void subC(int counter){//used to encrypt input with a substitution Cypher. start the function and inputs couter in it

     for (int x = 0; x<=counter; x++){//make a loop that repeate the size of the input text size"couter"
         int bool2 = 0;//make an int and calls it bool1. used as bool
         
         for (int z = 0; z<=28; z++){//make a loop larger 
         
             if (text[x]==alphabet[0][z]){//chech if the text is on the alphabet
             
                 bool2 = 1;//make bool2 equal 1.
                 outText[x] = CiphLib[z];// make the textout equal the cipher libary key for it persion relitive to input
                 
            }else if((z>=27) && bool2==0){// used to make anything not in alphabet to be this allows any charactor that isnt in the alphabet to not be changed 
                outText[x] = text[x];
            }
        }
    }
}


void subCD(int counter2){//used to decrypt input with a substitution Cypher. start the function and inputs couter in it
    for (int i =0;i<counter2;i++){
        int bool3 = 0;
        for(int d = 0; d<28;d++){
            if (text[i]==CiphLib[d]){
                bool3 = 1;
                outText[i] = alphabet[0][d];
            }else if((d>=27) && bool3==0){
                outText[i] = text[i];
            }// same as the subC but coparse with CiphLib insted of alphabet
        }
    }

}

void subCDN(int counter){
   // int wordcountinput[500];
   // int wordcountlib[10001];
   // char wordlibsize[10000][MAXWORDSIZE];
    //char a[MAXWORDSIZE];
    //char mostcomletter[27];
    //char key[26];
    int letters[27]; //make an array of int called letters. used to store the number of time a letter is called
    //FILE * wordlibsizefile;
    char fhg[2][27]={{"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"},{""}};// make and array that is used to sort the letter an  the number of time they are used and sort them
    
    //wordlibsizefile = fopen("wordlibaraybysize.txt","r");
        int letterscore = 0;// make and int ant set it to 0. used to count the number of time a letter was used
        
        for (int p = 0;p<26;p++){//make a loop that repeat 25 time. used to count the number of time a letter been used in the input text
            letterscore = 0;// resets letterscore to zero if it wasent alread
            
            for (int y =0; y<counter; y++) {// make a loop that repeats the same number of time as text size
            
                if (text[y]==alphabet[0][p]){// check if the letter is ina the alphabet
                    letterscore=letterscore+1;// add 1 to number of time a letter has been used
            }
            letters[p] = letterscore;// set store the number of time a letter has been used to letters array
        }
        letterscore =0;// resets number of time a letter has been used to zero
        
    }
  
    for (int n=0; n<26;n++){//used to input number of time a letter has been used to fhg[1]
        fhg[1][n]=letters[n];//input number of time a letter has been used to fhg[1]
    }
    for (int ig = 0; ig<26 ;ig++){// used to sort the fhg from most used letter to least
        for(int jg =0; jg<25;jg++){//
            if(fhg[1][jg]<fhg[1][ig]){// 
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
    char str[MAXWORDSIZE];
    char wordArray[26][CHARNUMBER][MAXWORDSIZE];
    int max;
    int key;
    char tempchar[MAXWORDSIZE];
    char numstring[CHARNUMBER];
    
    FILE * wordLib;
    
    wordLib = fopen("wordLibrary.txt", "r");
    
    for (int n=0; n<10001; n++){
        fscanf(wordLib,"%s", str);
        for (int m =0; m<MAXWORDSIZE;m++){
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

            for (int m =0; m<=MAXWORDSIZE;m++){
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
        for (int z = 0; z<MAXWORDSIZE;z++){
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