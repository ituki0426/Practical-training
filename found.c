
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define BUF_SIZE 256
 typedef struct student {
  char name[60];
  int gold;
  int silver;
  int blonde;
} STUDENT;
int Rank(STUDENT* argument);
int Count(void);
int Found(STUDENT* argument,char *str){
 int i;
 int j;
 j=Count();
  for(i=0;i<j;i++){
  
    if(strcmp(str,argument[i].name)==0)
    {
      printf("順位:金メダル%d枚 銀メダル%d枚 銅メダル%d枚\n",argument[i].gold,argument[i].silver,argument[i].gold);
    }
  }
return 0;
}