#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Count(void);
typedef struct student {
  char name[60];
  int gold;
  int silver;
  int blonde;
} STUDENT;
int Sort_AllMed(STUDENT* argument) {
    int med[200][3];
    char cou[200][50];
    int i,k;
	int column_nuber=Count();
	k=column_nuber;
    int f;
  for(f=0;f<column_nuber;f++){
    strcpy(cou[f],argument[f].name);
    med[f][0]=argument[f].gold;
    med[f][1]=argument[f].silver;
    med[f][2]=argument[f].blonde;
  }
    int sum[256];
    int j,box,l;
	char cbox[50];
    for(j=0;j<k;j++){
		sum[j]=med[j][0]+med[j][1]+med[j][2];
    }
	for(l=0;l<k;l++){
		for(j=0;j<k-l;j++){
	  		if(sum[j]<sum[j+1]){
		  		box=med[j][0]; med[j][0]=med[j+1][0];
		    	med[j+1][0]=box;
		  		box=med[j][1]; med[j][0]=med[j+1][1];
				med[j+1][1]=box;
		  		box=med[j][2]; med[j][2]=med[j+1][2];
		  		med[j+1][2]=box;
				strcpy(cbox,cou[j]); strcpy(cou[j],cou[j+1]);
				strcpy(cou[j+1],cbox);
				box=sum[j]; sum[j]=sum[j+1];
				sum[j+1]=box;
	  		}
		}
    }
	for(i=0;i<k;i++){
		printf("国名:%s 金:%d 銀:%d 銅:%d 総獲得数:%d\n",cou[i],med[i][0],med[i][1],med[i][2],sum[i]);
	}
	return 0;
} 