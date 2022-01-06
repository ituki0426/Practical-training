#include <stdio.h>
#include <string.h>

#define STR_MAX 256
int Count(void);

typedef struct student {
  char name[60];
  int gold;
  int silver;
  int blonde;
} STUDENT;

void printArray(char a[][STR_MAX], int num,int gold[],int shilber[],int blonde[]){
    int i;
    for (i = 0; i < num; i++) {
        printf("国名: %s 金メダル: %d 銀メダル: %d 銅メダル: %d \n",a[i],gold[i],shilber[i],blonde[i]);
    }
}

void selectionSort(char data[][STR_MAX], int left, int right,int gold[],int shilber[],int blonde[]) {
    int start;
    int i;
    char min[STR_MAX];
    int i_min;
    char tmp[STR_MAX];
    int gold_tmp;
    int gold_min;
    int shilber_tmp;
    int shilber_min;
    int blonde_tmp;
    int blonde_min;

    if (left == right) {
        return;
    }

    start = left;

    for (start = left; start < right; start++) {

        i_min = start;
        strcpy(min, data[i_min]);
        gold_min=gold[i_min];
        shilber_min=shilber[i_min];
        blonde_min=blonde[i_min];
        for (i = start; i <= right; i++) {
            if (strcmp(min, data[i]) > 0) {
                strcpy(min, data[i]);
                gold_min=gold[i];
                shilber_min=shilber[i];
                blonde_min=blonde[i];
                i_min = i;
            }
        }

        if (start != i_min) {

            strcpy(tmp, data[start]);
            gold_tmp=gold[start];
            shilber_tmp=shilber[start];
            blonde_tmp=blonde[start];
            strcpy(data[start], data[i_min]);
            gold[start]=gold[i_min];
            shilber[start]=shilber[i_min];
            blonde[start]=blonde[i_min];
            strcpy(data[i_min], tmp);
            gold[i_min]=gold_tmp;
            shilber[i_min]=shilber_tmp;
            gold[i_min]=blonde_tmp;
        }
    }
}

void Sort_country(STUDENT* argument){	
  int column_nuber=Count();
  int i;
  char array[256][256];
  int gold[256];
  int shilber[256];
  int blonde[256];
   for(int j=0;j<column_nuber;j++){
	  strcpy(array[j],argument[j].name);
	  gold[j]=argument[j].gold;
	  shilber[j]=argument[j].silver;
	  blonde[j]=argument[j].blonde;
  }
    int data_num = Count();
    selectionSort(array, 0, data_num - 1,gold,shilber,blonde);
    printArray(array, data_num,gold,shilber,blonde);
}

