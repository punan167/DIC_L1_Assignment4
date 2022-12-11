#include "stdio.h"
void wordFinder(char name[]);
int main()
{
    wordFinder("winhtut");
    wordFinder("NationalCyberCity");
    return 0;
}
void wordFinder(char name[])
{
    char words[4755];
    int n = 0;
    int wordCount = 0;
    int decivalueofName = 0;
    int nameLen=sizeof (name);
    int decivalueofNameTxt = 0;
    int nameCount = 0;
    FILE *fptr;
    fptr = fopen("words.txt","r+");

    if ( fptr == NULL )
    {
        printf( "Failed to open." ) ;
    }
    else {
        printf("The file is now opened.\n");
        while (fscanf(fptr, "%c", &words[n]) != EOF) {
            n++;
            wordCount += 1;
        }
        fclose(fptr);
        nameLen--;
        for(int a=0;a<nameLen;a++){
            decivalueofName += name[a];
        }
        for(n=0;n<=wordCount;n++){
            if (words[n] == name[0]) {
                decivalueofNameTxt = 0;
                for(int a=0; a<7; a++){
                    decivalueofNameTxt += words[n];
                    n++;
                    if(decivalueofNameTxt==decivalueofName){
                        printf("I found %s at index : %d \n",name,n);
                        nameCount++;
                    }
                }
            }
        }
    }
    printf("Total ( %s ) : %d\n",name,nameCount);
    printf("\n");
    printf("Data successfully read from file\n");
    printf("The file is now closed.\n") ;
    printf("************************************\n");
}