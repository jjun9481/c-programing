#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define FILE_NAME "products.txt"

typedef struct price {
    int ID;
    char names[20];
    int dlq;
    int mo; // 판매 가격
} Price;

typedef struct sell {
    int ID;
    int se;
} Sell;

void initializeProducts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file != NULL) {
        fclose(file); // 파일이 존재하면 그냥 반환
        return;
    }

    // 파일이 존재하지 않으면 기본 값을 사용하여 파일 생성
    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("파일을 생성할 수 없습니다.\n");
        return;
    }

    // 기본 상품 정보 입력 (예시)
    fprintf(file, "0 상품1 10 1000\n");
    fprintf(file, "1 상품2 20 2000\n");
    fprintf(file, "2 상품3 30 3000\n");
    fprintf(file, "3 상품4 40 4000\n");
    fprintf(file, "4 상품5 50 5000\n");

    fclose(file);
}


void saveProducts(Price p1[]) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        fprintf(file, "%d %s %d %d\n", p1[i].ID, p1[i].names, p1[i].dlq, p1[i].mo);
    }
    fclose(file);
}

void stockInput(int b[], Price p1[]) {
    printf("상품 ID (0-4): ");
    int id;
    scanf("%d", &id);
    
    if (id >= 0 && id < MAX_PRODUCTS) {
        printf("입고량: ");
        scanf("%d", &b[id]);
        
        printf("상품명: ");
        getchar();  // 개행 문자 제거
        fgets(p1[id].names, 20, stdin);
        p1[id].names[strcspn(p1[id].names, "\n")] = '\0'; 
        
        printf("판매 가격: ");
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
    
    if (id >= 0 && id < MAX_PRODUCTS) {
        printf("판매량: ");
        scanf("%d", &c[id]);
    } else {
        printf("잘못된 ID입니다.\n");
    }
}

void Product(Price p1[], int b[], int c[]) {
    int id;
    printf("ID를 입력하세요: ");
    scanf("%d", &id);

    if (id >= 0 && id < MAX_PRODUCTS) {
        printf("상품명: %s\n", p1[id].names);
        printf("판매 가격: %d\n", p1[id].mo);
        printf("현재 재고량: %d\n", b[id] - c[id]);
        printf("판매량: %d\n", c[id]);
    } else {
        printf("잘못된 ID입니다.\n");
    }
}

void inventoryStatus(int b[], int c[], Price p1[]) {
    printf("\n== 전체 상품 현황 ==\n");
    printf("%-5s %-20s %-10s %-10s %-10s\n", "ID", "상품명", "판매 가격", "재고량", "판매량");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%-5d %-20s %-10d %-10d %-10d\n", 
               p1[i].ID, p1[i].names, p1[i].mo, b[i] - c[i], c[i]);
    }

    float sale = 0, e = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        sale += c[i];
        e += b[i];
    }

    double f = (e > 0) ? (sale / e) * 100 : 0;
    printf("-------------------------------------------------------\n");
    printf("총 판매량: %.0f (판매율: %.2lf%%)\n", sale, f);
    
    int n = 0, m = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (c[i] > c[n]) n = i;
        if (c[i] < c[m]) m = i;
    }
    
    printf("가장 많이 팔린 상품 ID: %d, 상품명: %s, 판매량: %d\n", n, p1[n].names, c[n]);
    printf("가장 적게 팔린 상품 ID: %d, 상품명: %s, 판매량: %d\n", m, p1[m].names, c[m]);

    printf("-------------------------------------------------------\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (b[i] - c[i] <= 2) {
            printf("상품 ID %d: 상품명: %s: 재고 부족 (%d)\n", i, p1[i].names, b[i] - c[i]);
        }
    }
}


int main() {
    Price p1[MAX_PRODUCTS] = {0}; // 재고 정보
    int b[MAX_PRODUCTS] = {0}; // 재고
    int c[MAX_PRODUCTS] = {0}; // 판매량

    loadProducts(p1); // 파일에서 상품 정보 불러오기

    while (1) {
        int choice;
        printf("원하는 메뉴를 선택하세요(1.입고, 2.판매, 3.개별현황, 4.전체 상품 현황, 5.종료): ");
        scanf("%d", &choice);

        if (choice == 1) {
            stockInput(b, p1);
            saveProducts(p1); // 상품 정보 파일에 저장
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
