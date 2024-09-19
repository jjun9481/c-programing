#include <stdio.h>

int main()
{
    
    int b[5]={0};
    int ID = 0;
    int c[5] = {0};
    float sale= 0;
    float e = 0;
    int n =1;
    int m = 1;
    
    
    while(1){
        int a = 0; 
        printf("원하는 메뉴를 선택하세요(1.입고, 2.판매, 상품현황, 종료)");
        scanf("%d",&a);
        if(a == 1){
            printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 2를 선택");
            scanf("%d",&a);
            if(a==1){
                for (int i = 0; i < 5; i++) {
                    scanf("%d", &b[i]);
                }
            }
            if(a==2){
                printf("상품 ID : ");
                scanf("%d", &ID);
                if(ID >= 0 && ID < 5) {
                    printf("입고수량: ");
                    scanf("%d", &b[ID]);
                }
            
            }
        }
        
        if(a==2){
            printf("판매 수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택");
            scanf("%d",&a);
            if(a==1){
                for (int i = 0; i < 5; i++) {
                    scanf("%d", &c[i]);
                }
            }
            if(a==2){
                printf("상품 ID : ");
                scanf("%d", &ID);
                if(ID >= 0 && ID < 5) {
                    printf("입고수량: ");
                    scanf("%d", &c[ID]);
                }
            
            }
        }
        
        if(a==3){
            printf("재고 수량");
            for (int i = 0; i < 5; i++) {
                printf("%d ", b[i] - c[i]);
            }
            printf("\n");
            for(int i = 0;i<5;i++) {
                sale +=c[i];
            }

            for(int i = 0;i<5;i++) {
                e += b[i];
            }
            double f =(sale/e)*100;
   
            printf("총 판매량 %.0f(판매율 %.2lf%) \n",sale,f);
    
            for(int i = 0;i<a;i++){
                if(c[i]>c[n])
                    n = i;
                if(c[i]<c[m])
                    m = i;
            }       
            printf("가장 많이 팔린 상품 ID : %d, 판매량 : %d\n",n,c[n]);
            printf("가장 적게 팔린 상품 ID : %d, 판매량 : %d\n",m,c[m]);
    
            for(int i=1;i<=a;i++){
                if( b[i]-c[i]<=2)
                printf("상품ID %d:재고부족(%d)\n",i,b[i]-c[i]);
            }
    
            return 0;
        }
            
        if(a==4)
            break;
        


   
    
    
    
    }
}
    

    



