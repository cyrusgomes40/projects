#include <stdio.h>
#include <string.h>
#include <ctype.h>

void left(char word[]);
void right(char word[]);
void inc(char word[]);
void dec(char word[]);

int main(int argc, char *argv[])
{

   if (argc != 3)
      printf("Invalid number of arguments\n");

   else
   {
      FILE*input = NULL;
      input = fopen(argv[1], "r");
      char words[100];
      int flag = 0;
      if (input == NULL)
      {
         printf("Could not open file '%s'", argv[1]);
      }
      else
      {  while (fscanf(input, "%s", words) == 1) {
         for (int i = 0; i < strlen(argv[2]); i++){
            if (argv[2][i] == 'L'){
                  left(words);
            }
            else if (argv[2][i] == 'R'){
                  right(words);
            }
            else if (argv[2][i] == 'I'){
                  inc(words);
            }
            else if (argv[2][i] == 'D'){
                  dec(words);
            }
            else {
               printf("You threw off my schwiftiness with schwifty '%c'!", argv[2][i]);
               flag++;
               break;
            }
         }
         if (flag) break;
         else printf("%s\n", words);  
     }
      fclose(input);
      }
   }
   return 0;
}

void left(char word[])
{
   char a = word[0];
    for (int i = 1; i < strlen(word); i++){
        word[i-1] = word[i];
    }
    word [strlen(word)-1] = a;
}

void right(char word[])
{
   char a = word[strlen(word)-1];
    for (int i = strlen(word)-1; i > 0; i--){
        word[i] = word[i-1];
    }
    word [0] = a;
}

void inc(char word[])
{
   for(int i = 0; i < strlen(word); i++){
      if(!ispunct(word[i])){
         if (word[i] == 'z') word[i] = 'a';
         else if (word[i] == 'Z') word[i] = 'A';
         else if (word[i] == '9') word[i] = '0';   // have to wrap values
         else word[i] = word[i] +1;
      }
   }
}

void dec(char word[])
{
   for(int i = 0; i < strlen(word); i++){
      if(!ispunct(word[i])){
         if (word[i] == 'a') word[i] = 'z';
         else if (word[i] == 'A') word[i] = 'Z';
         else if (word[i] == '0') word[i] = '9';
         else word[i] = word[i] -1;
      }
   }
}
