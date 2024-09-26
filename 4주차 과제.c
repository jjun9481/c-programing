#include <stdio.h>
#include <string.h>

char names[5][20] = {
    "상품1", "상품2", "상품3", "상품4", "상품5"
};

void stockInput(int b[]) {
    int choice;
    printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 2를 선택: ");
    scanf("%d", &choice);
    if (choice == 1) {
        for (int i = 0; i < 5; i++) {
            scanf("%d", &b[i]);
        }
    } else if (choice == 2) {
        int ID;
        printf("상품 ID : ");
        scanf("%d", &ID);
        if (ID >= 0 && ID < 5) {
            scanf("%d", &b[ID]);
        }
    }
}

void salesInput(int c[]) {
    int choice;
    printf("판매 수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택: ");
    scanf("%d", &choice);
    if (choice == 1) {
        for (int i = 0; i < 5; i++) {
            scanf("%d", &c[i]);
        }
    } else if (choice == 2) {
        int ID;
        printf("상품 ID : ");
        scanf("%d", &ID);
        if (ID >= 0 && ID < 5) {
            scanf("%d", &c[ID]);
        }
    }
}

void inventoryStatus(int b[], int c[]) {
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
    
    printf("가장 많이 팔린 상품 ID : %d, 상품명 %s : 판매량 : %d\n", n,names[n], c[n]);
    printf("가장 적게 팔린 상품 ID : %d, 상품명 %s : 판매량 : %d\n", m, names[m], c[m]);

    for (int i = 0; i < 5; i++) {
    if (b[i] - c[i] <= 2) {
        printf("상품ID %d: 상품명: %s: 재고부족 (%d)\n", i + 1, names[i], b[i] - c[i]);
    }
}

}

void ProductName(char names[][20]) {
    for (int i = 0; i < 5; i++) {
        printf("ID %d 상품명: ", i + 1);
        getchar(); // 버퍼 비우기
        fgets(names[i], 20, stdin); // 문자열 입력
        names[i][strcspn(names[i], "\n")] = '\0'; // 개행 문자 제거
    }
}

int main() {
    int b[5] = {0}; // 재고
    int c[5] = {0}; // 판매량

    while (1) {
        int choice;
        printf("원하는 메뉴를 선택하세요(1.입고, 2.판매, 3.상품현황, 4.상품명 입력,  5.종료): ");
        scanf("%d", &choice);

        if (choice == 1) {
            stockInput(b);
        } else if (choice == 2) {
            salesInput(c);
        } else if (choice == 3) {
            inventoryStatus(b, c);
        } else if (choice == 4) {
            ProductName(names);
        } else if(choice == 5){
            break;
        }
        
    }
    return 0;
}
