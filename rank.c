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
int Count(void);
int irekae(int *num10,int *num11,int *num20,int *num21,int *num30,int *num31){
int exnum[3];
exnum[0]=*num10;
*num10=*num11;
*num11=exnum[0];
exnum[1]=*num20;
*num20=*num21;
*num21=exnum[1];
exnum[2]=*num30;
*num30=*num31;
*num31=exnum[2];
return 0;
}

int Rank(STUDENT* argument,int hantei,char *str){
  int j=0,k=0;

  int num[200][4];
  char cou[200][50];
  char excou[50];

  int column_nuber=Count();
  int i = Count();
  int f;
  for(f=0;f<column_nuber;f++){
    strcpy(cou[f],argument[f].name);
    num[f][0]=argument[f].gold;
    num[f][1]=argument[f].silver;
    num[f][2]=argument[f].blonde;
  }


for (j=0; j<i; j++){
    for (k=1; (j+k)<i; k++)
    {
      if(num[j][0]<num[j+k][0]){
        irekae(&num[j][0],&num[j+k][0],&num[j][1],&num[j+k][1],&num[j][2],&num[j+k][2]);
        strcpy(excou,cou[j]);
        strcpy(cou[j],cou[j+k]);
        strcpy(cou[j+k],excou);
    }else if(num[j][0]==num[j+k][0]&&num[j][1]<num[j+k][1]){
        irekae(&num[j][0],&num[j+k][0],&num[j][1],&num[j+k][1],&num[j][2],&num[j+k][2]);
        strcpy(excou,cou[j]);
        strcpy(cou[j],cou[j+k]);
        strcpy(cou[j+k],excou);
    }else if(num[j][0]==num[j+k][0]&&num[j][1]==num[j+k][1]&&num[j][2]<num[j+k][2]){
        irekae(&num[j][0],&num[j+k][0],&num[j][1],&num[j+k][1],&num[j][2],&num[j+k][2]);
        strcpy(excou,cou[j]);
        strcpy(cou[j],cou[j+k]);
        strcpy(cou[j+k],excou);
    }
  }
    if(num[j][0]==num[j-1][0]&&num[j][1]==num[j-1][1]&&num[j][2]==num[j-1][2]){
        num[j][3]=num[j-1][3];
        }else{
        num[j][3]=j;
        }   
}
  j=0;
  if(hantei==0){
    for(j=0;j<column_nuber;j++){
    printf("\n");
    printf("%d %s 金メダル%d枚 銀メダル%d枚 銅メダル%d枚\n",num[j][3]+1,cou[j], num[j][0],num[j][1],num[j][2]);
    }
  }
  if(hantei==1){
    for(i=0;i<column_nuber;i++){
    if(strcmp(str,argument[i].name)==0)
    {
      printf("順位:%d位 金メダル%d枚 銀メダル%d枚 銅メダル%d枚\n",num[i][3]+1,argument[i].gold,argument[i].silver,argument[i].gold);
    }
  }
  }
    
  printf("\n");
}

