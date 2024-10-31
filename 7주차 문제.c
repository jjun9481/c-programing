#include <stdio.h>
#include <string.h>

typedef struct price {
    int ID;
    char names[5][20];
    int dlq;
    int mo; // 판매 가격
} Price;

typedef struct sell {
    int ID;
    int se;
} Sell;

void stockInput(int b[], Price p1[]) {
    printf("상품 ID (0-4): ");
    int id;
    scanf("%d", &id);
    
    if (id >= 0 && id < 5) {
        printf("입고량 : ");
        scanf("%d", &b[id]);
        printf("상품명: ");
        getchar(); 
        fgets(p1[id].names[id], 20, stdin);
        p1[id].names[id][strcspn(p1[id].names[id], "\n")] = '\0'; 
        printf("판매 가격 : ");
        scanf("%d", &p1[id].mo);
        p1[id].dlq = 0; // 초기화
    } else {
        printf("잘못된 ID입니다.\n");
    }
}

void salesInput(int c[]) {
    printf("상품 ID (0-4): ");
    int id;
    scanf("%d", &id);
    
    if (id >= 0 && id < 5) {
        printf("판매량 : ");
        scanf("%d", &c[id]);
    } else {
        printf("잘못된 ID입니다.\n");
    }
}

void Product(Price p1[], int b[], int c[]) {
    int id;
    printf("ID를 입력하세요: ");
    scanf("%d", &id);

    if (id >= 0 && id < 5) {
        printf("상품명: %s\n", p1[id].names[id]);
        printf("판매 가격: %d\n", p1[id].mo);
        printf("현재 재고량: %d\n", b[id] - c[id]);
        printf("판매량: %d\n", c[id]);
    } else {
        printf("잘못된 ID입니다.\n");
    }
}

void inventoryStatus(int b[], int c[], Price p1[]) {
    printf("재고 수량: ");
    for (int i = 0; i < 5; i++) {
        printf("%s: %d ", p1[i].names[i], b[i] - c[i]);
    }
    printf("\n");

    float sale = 0, e = 0;
    for (int i = 0; i < 5; i++) {
        sale += c[i];
        e += b[i];
    }

    double f = (sale / e) * 100;
    printf("총 판매량: %.0f (판매율: %.2lf%%)\n", sale, e ? f : 0.0);

    int n = 0, m = 0;
    for (int i = 0; i < 5; i++) {
        if (c[i] > c[n]) n = i;
        if (c[i] < c[m]) m = i;
    }
    
    printf("가장 많이 팔린 상품 ID: %d, 상품명: %s, 판매량: %d\n", n, p1[n].names[n], c[n]);
    printf("가장 적게 팔린 상품 ID: %d, 상품명: %s, 판매량: %d\n", m, p1[m].names[m], c[m]);

    for (int i = 0; i < 5; i++) {
        if (b[i] - c[i] <= 2) {
            printf("상품 ID %d: 상품명: %s: 재고 부족 (%d)\n", i, p1[i].names[i], b[i] - c[i]);
        }
    }
}

int main() {
    Price p1[5] = {
        {.ID = 1, .names = "상품1", .dlq = 0, .mo = 0},
        {.ID = 2, .names = "상품2", .dlq = 0, .mo = 0},
        {.ID = 3, .names = "상품3", .dlq = 0, .mo = 0},
        {.ID = 4, .names = "상품4", .dlq = 0, .mo = 0},
        {.ID = 5, .names = "상품5", .dlq = 0, .mo = 0}
    };
    
    int b[5] = {0}; // 재고
    int c[5] = {0}; // 판매량

    while (1) {
        int choice;
        printf("원하는 메뉴를 선택하세요(1.입고, 2.판매, 3.개별현황, 4.전체 상품 현황, 5.종료): ");
        scanf("%d", &choice);

        if (choice == 1) {
            stockInput(b, p1);
        } else if (choice == 2) {
            salesInput(c);
        } else if (choice == 3) {
            Product(p1, b, c);
        } else if (choice == 4) {
            inventoryStatus(b, c, p1);
        } else if (choice == 5) {
            break;
        } else {
            printf("잘못된 선택입니다.\n");
        }
    }
    return 0;
}
