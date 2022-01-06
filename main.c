#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Count(void);
void Add(void);
typedef struct student {
  char name[60];
  int gold;
  int silver;
  int blonde;
} STUDENT;
int Sort_AllMed(STUDENT* argument);
void Sort_country(STUDENT* argument);
int Rank(STUDENT* argument,int hantei,char *str);
void Print(STUDENT* argument,char *str);
void Write(STUDENT* hikisu);
int Found(STUDENT* argument,char *str);
int main(){
  STUDENT people[256];
  int column_nuber=Count();
  int next=1;
  int i;
  FILE *fp;
  char *fname = "sample.csv";
  int ret;
  char name[256][256];
  char gold[256][256];
  char shilver[256][256];
  char blonde[256][256];
  double data[3];

  fp = fopen( fname, "r" );
  if( fp == NULL ){
    printf( "%sファイルが開けません\n", fname );
    return -1;
  }

  printf("\n");
for(i=0;i<column_nuber;i++){
  char buf[256];
  fgets(buf,255,fp);
  sscanf(buf," %[^,],%[^,],%[^,],%s",name[i],gold[i],shilver[i],blonde[i]);
}
printf("\n");
fclose( fp );
char input_name[256];
int nuber_golde;
int nuber_silver;
int nuber_blonde;
  for(i=0;i<column_nuber;i++){
    nuber_golde=atoi(gold[i]);
    nuber_silver=atoi(shilver[i]);
    nuber_blonde=atoi(blonde[i]);
    people[i].gold=nuber_golde;
    people[i].silver=nuber_silver;
    people[i].blonde=nuber_blonde;
    strcpy(people[i].name, name[i]);
    }
      puts("数字を入力してください");
      puts("国名を追加する場合は1を入力してください");
       puts("メダル獲得数順に表示する場合は2を入力してください");
      puts("総獲得数順に表示する場合は3を入力してください");
      puts("国の情報を出力したい場合は4を入力して下さい");
      puts("国名順に表示する場合は5を入力してください");
      scanf("%d",&next); fflush(stdin);
      if(next==1){
        Add();
      }
      if(next==2){
        Rank(people,0,NULL);
      }
       if(next==3){
        Sort_AllMed(people);
      }
      if(next==4){
        printf("国名を入力してください\n");
        gets(input_name);
        Rank(people,1,input_name);
      }
      if(next==5){
        Sort_country(people);
      }
    
}
