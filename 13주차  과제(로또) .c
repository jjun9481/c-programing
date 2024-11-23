#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _lotto{
    int number[6];
    int bonus;
    int NO;
}LOTTO;

void initLotto(LOTTO*l){
    for(int i =0;i<6;i++) l->number[i]=0;
    l->bonus = 0;
    l->NO=0;
}

int dup(LOTTO l, int num, int n){
    for(int i = 0; i<=n; i++){
        if(l.number[i] == num) return 1;
    }
    return 0;
}

LOTTO creatAuto(int NO){
    LOTTO l;
    int num;
    initLotto(&l);
    l.NO=NO;
    for(int i=0;i<6;i++){
        num = rand()% 45 + 1;
        if(i==0) l.number[i] =num;
        else if(i>0 && !dup(l,num,i-1) ) l.number[i] =num;
        else {
            i--;
            printf("중복발생.. 다시 뽑으세요\n");
        }
    }
    return l;
}

LOTTO creatManual(int NO){
    LOTTO l;
    int num;
    initLotto(&l);
    l.NO=NO;
    for(int i=0;i<6;i++){
        printf("input number #%d : ", i+1);
        scanf("%d",&num);
        if(i==0)    l.number[i] =num;
        else if(i>0 && !dup(l,num,i-1) ) l.number[i] =num;
        else {
            i--;
            printf("중복발생.. 다시 뽑으세요\n");
        }
    }
    return l;
}
void printLOTTO(LOTTO l){
    printf("#3d lotto number : %2d %2d %2d %2d %2d %2d\n",l.NO, l.number[0],l.number[1],l.number[2],l.number[3],l.number[4],l.number[5],l.number[6]);
    printf("BONUS : %d",l.bonus);
}

LOTTO drawingLOTTO(){
    LOTTO l;
    int num;
    initLotto(&l);

    for(int i=0;i<6;i++){
        printf("input number #%d : ", i+1);
        scanf("%d",&num);
        if(i==0)    l.number[i] =num;
        else if(i>0 && !dup(l,num,i-1) ) l.number[i] =num;
        else {
            i--;
        }
    }
    do{
        l.bonus = rand()%45+1;
    }while(dup(l,l.bonus,5));

    return l;
}

int matchcount(LOTTO l1, LOTTO l2){
    int mcount = 0;
    for (int i = 0; i<6;i++){
        for(int j = 0; j <6; j++){
            if(l1.number[i] == l2.number[j]) mcount ++;
        }
    }
    return mcount;
}


int main(){ 
    LOTTO l, l2;
    FILE *fp;
    fp = fopen("20241035.bin","wb");
    if(fp == NULL) exit(1);

    srand(time(NULL));
    l = creatAuto(20241035);
    fwrite(&l, sizeof(LOTTO),1,fp);
    printLOTTO(l);
    return 0;
}