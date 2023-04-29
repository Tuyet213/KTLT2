#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
int main()
{
   char sentence[1000];
   FILE *fptr;
 
   fptr = fopen("program.txt", "w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   
   printf("Enter a sentence:\n");
   gets(sentence);
 
   fprintf(fptr,"%s", sentence);
   fclose(fptr);
 
   return 0;
}



#include <stdio.h>
#include <stdlib.h> // For exit() function
int main()
{
    char c[1000];
    FILE *fptr;
 
    if ((fptr = fopen("program.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }
 
    // reads text until newline 
    fscanf(fptr,"%[^\n]", c);
 
    printf("Data from the file:\n%s", c);
    fclose(fptr);
    
    return 0;
}


C programming is awesome.
I love C programming.
How are you doing?

==>Data from the file: C programming is awesome.




















