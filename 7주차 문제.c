#include <stdio.h>
#include <string.h>



typedef struct price {
    int ID;
    char names[5][20];
    int dlq;
    int mo;
} Price;

typedef struct sell{
    int ID;
    int se;
} Sell;

void stockInput(int b[]) {
    Price p1 = {
    .ID = 1,
    .names = {"상품1", "상품2", "상품3", "상품4", "상품5"}, // 초기화
    .dlq = 0,
    .mo = 0
};

    printf("상품 ID : ");
    scanf("%d", &p1.ID);
    if (p1.ID >= 0 && p1.ID < 5) {
        scanf("%d", &b[p1.ID]);
    
    for(int i = 0; i<5;i++){
        if(p1.ID == i){
            printf("상품명: ");
            getchar(); 
            fgets(p1.names[i], 20, stdin);
            p1.names[i][strcspn(p1.names[i], "\n")] = '\0'; 
        }
    }
    for(int i = 0; i<5;i++){
        if(p1.ID == i){
            printf("입고량 : ");
            scanf("%d", &p1.dlq);
        }
    }
    for(int i = 0;i<5;i++){
        if(p1.ID == i){
            printf("판매 가격 : ");
            scanf("%d",&p1.mo);
        }
    }
    
    
    
    }
}

void salesInput(int c[]) {
    Sell s1 = {
        .ID = 0,
        .se = 1
    };
    printf("상품 ID : ");
    scanf("%d", &s1.ID);
    if (s1.ID >= 0 && s1.ID < 5) {
        scanf("%d", &c[s1.ID]);
    }
    for(int i = 0; i<5;i++){
        if(s1.ID == i){
            printf("판매량 : ");
            scanf("%d",&s1.se);
        }
    }
    
    
}

void inventoryStatus(int b[], int c[]) {
    Price p1 = {
    .ID = 1,
    .names = {"상품1", "상품2", "상품3", "상품4", "상품5"}, // 초기화
    .dlq = 0,
    .mo = 0
};
    float sale = 0, e = 0;
    int n = 0, m = 0;

    printf("재고 수량: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", b[i] - c[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        sale += c[i];
        e += b[i];
    }

    double f = (sale / e) * 100;
    printf("총 판매량 %.0f (판매율 %.2lf%%)\n", sale, f);

    for (int i = 0; i < 5; i++) {
        if (c[i] > c[n]) n = i;
        if (c[i] < c[m]) m = i;
    }
    
    printf("가장 많이 팔린 상품 ID : %d, 상품명 %s : 판매량 : %d\n", n,p1.names[n], c[n]);
    printf("가장 적게 팔린 상품 ID : %d, 상품명 %s : 판매량 : %d\n", m, p1.names[m], c[m]);

    for (int i = 0; i < 5; i++) {
    if (b[i] - c[i] <= 2) {
        printf("상품ID %d: 상품명: %s: 재고부족 (%d)\n", i + 1, p1.names[i], b[i] - c[i]);
    }
}

}



int main() {
    Price p1 = {
    .ID = 1,
    .names = {"상품1", "상품2", "상품3", "상품4", "상품5"}, // 초기화
    .dlq = 0,
    .mo = 0
};
    int b[5] = {0};
    int c[5] = {0};

    while (1) {
        int choice;
        printf("원하는 메뉴를 선택하세요(1.입고, 2.판매, 3.상품현황, 4. 개발현황,  5.종료): ");
        scanf("%d", &choice);

        if (choice == 1) {
            stockInput(b);
        } else if (choice == 2) {
            salesInput(c);
        } else if (choice == 3) {
            inventoryStatus(b, c);
        } else if (choice == 4) {
            ProductName(p1.names);
        } else if(choice == 5){
            break;
        }
        
    }
    return 0;
}
