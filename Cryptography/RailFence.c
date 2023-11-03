#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void encrypt(char msg[], int key)
{
    int msglen = strlen(msg), i, j, k = -1, row = 0, col = 0;
    char railmat[key][msglen];
    for(i = 0; i < key; ++i)
        for(j = 0; j < msglen; ++j)
            railmat[i][j] = '\n';

    for(i = 0; i < msglen; ++i)
    {
        railmat[row][col++] = msg[i];

        if(row == 0 || row == key-1)
            k= k * (-1);

        row = row + k;
    }

    printf("\nEncrypted Message: ");

    for(i = 0; i < key; ++i)
        for(j = 0; j < msglen; ++j)
            if(railmat[i][j] != '\n')
                printf("%c", railmat[i][j]);
    printf("\n");
}

void decrypt(char msg[], int key)
{
    int msglen = strlen(msg ), i, j, k = -1, row = 0, col = 0, m = 0;
    char railmat[key][msglen];

    for(i = 0; i < key; ++i)
        for(j = 0; j < msglen; ++j)
            railmat[i][j] = '\n';

    for(i = 0; i < msglen; ++i)
    {
        railmat[row][col++] = '*';
        if(row == 0 || row == key-1)
            k= k * (-1);
        row = row + k;
    }
    for(i = 0; i < key; ++i)
        for(j = 0; j < msglen; ++j)
            if(railmat[i][j] == '*')
                railmat[i][j] = msg[m++];
    row = col = 0;
    k = -1;
    printf("\nDecrypted Message: ");

    for(i = 0; i < msglen; ++i){
        printf("%c", railmat[row][col++]);
        if(row == 0 || row == key-1)
            k= k * (-1);
        row = row + k;
    }
    printf("\n");
}

int main()
{
    char msg[200];
    int k,choice;
    for(;;)
    {
    	printf("\n\nEnter your choice 1:Encrypt 2:Decrypt 3:Exit :  ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1 : printf("\n---------Encryption----------");
    				 printf("\nEnter the text : ");
    				 scanf("%s",msg);
   					 printf("\nEnter the key : ");
   					 scanf("%d",&k);
    				 encrypt(msg,k);
    				 break;
    		case 2 : printf("\n---------Decryption----------");
    				 printf("\nEnter the text : ");
    				 scanf("%s",msg);
 				   	 printf("\nEnter the key : ");
   					 scanf("%d",&k);
    				 decrypt(msg,k);
    				 break;
    		case 3 : printf("\nExiting........\n\n");
    				 exit(0);
    				 break;
    		case 4 : default:printf("\nEnter valid coice or enter 3 to exit");
    	}
    }
        return 0;
}