#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5

// 사용자 정의 파일 관리 구조체
typedef struct file_info {
    char *file_name;      // 파일 이름
    FILE *file_ptr;       // 파일 포인터
    int is_open;          // 파일이 열려 있는지 여부
} FileInfo;

// 상품 정보를 나타내는 구조체
typedef struct price {
    int ID;
    char names[20];
    int dlq;  // 재고량
    int mo;   // 판매 가격
} Price;

// 파일에서 상품 정보를 불러오는 함수
void initializeProducts(Price p1[], int b[], int c[], FileInfo *file_info) {
    file_info->file_ptr = fopen(file_info->file_name, "r");
    if (file_info->file_ptr != NULL) {
        file_info->is_open = 1;  // 파일이 열렸음을 표시
        // 파일이 존재하면 기존 파일에서 상품 정보와 판매량 읽기
        for (int i = 0; i < MAX_PRODUCTS; i++) {
            int res = fscanf(file_info->file_ptr, "%d %s %d %d %d", &p1[i].ID, p1[i].names, &p1[i].dlq, &p1[i].mo, &c[i]);
            if (res != 5) {
                printf("파일 형식에 문제가 있습니다. 파일을 다시 확인하세요.\n");
                fclose(file_info->file_ptr);
                return;
            }
            b[i] = p1[i].dlq;  // 재고량은 파일에서 불러오기
        }
        fclose(file_info->file_ptr);
        printf("상품 정보가 파일에서 불러와졌습니다.\n");
        return;
    }

    // 파일이 존재하지 않으면 기본 값으로 파일 생성
    file_info->file_ptr = fopen(file_info->file_name, "w");
    if (file_info->file_ptr == NULL) {
        printf("파일을 생성할 수 없습니다.\n");
        return;
    }

    // 기본값으로 파일에 빈 상품 정보와 판매량 저장
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        fprintf(file_info->file_ptr, "%d %s %d %d %d\n", p1[i].ID, p1[i].names, p1[i].dlq, p1[i].mo, 0);
    }

    fclose(file_info->file_ptr);
    printf("기본 상품 정보가 파일에 저장되었습니다.\n");
}

// 상품 정보를 파일에 저장하는 함수
void saveProducts(Price p1[], int b[], int c[], FileInfo *file_info) {
    file_info->file_ptr = fopen(file_info->file_name, "w");
    if (file_info->file_ptr == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        // 판매량도 함께 저장
        fprintf(file_info->file_ptr, "%d %s %d %d %d\n", p1[i].ID, p1[i].names, b[i], p1[i].mo, c[i]);
    }

    fclose(file_info->file_ptr);
    printf("상품 정보가 저장되었습니다.\n");
}

// 상품 정보를 파일에서 불러오는 함수
void loadProducts(Price p1[], int b[], int c[], FileInfo *file_info) {
    file_info->file_ptr = fopen(file_info->file_name, "r");
    if (file_info->file_ptr != NULL) {
        // 파일이 존재하면 기존 파일에서 상품 정보와 판매량 읽기
        for (int i = 0; i < MAX_PRODUCTS; i++) {
            int res = fscanf(file_info->file_ptr, "%d %s %d %d %d", &p1[i].ID, p1[i].names, &p1[i].dlq, &p1[i].mo, &c[i]);
            if (res != 5) {
                printf("파일 형식에 문제가 있습니다. 파일을 다시 확인하세요.\n");
                fclose(file_info->file_ptr);
                return;
            }
            b[i] = p1[i].dlq;  // 재고량은 파일에서 불러오기
        }
        fclose(file_info->file_ptr);
        printf("상품 정보가 파일에서 불러와졌습니다.\n");
    } else {
        printf("파일이 존재하지 않습니다.\n");
    }
}

// 상품 재고 입력 함수
void stockInput(int b[], Price p1[]) {
    int id;
    printf("상품 ID (0-4) 입력: ");
    scanf("%d", &id);

    if (id >= 0 && id < MAX_PRODUCTS) {
        printf("입고량 입력: ");
        scanf("%d", &b[id]);

        printf("상품명 입력: ");
        getchar();  // 개행 문자 제거
        fgets(p1[id].names, 20, stdin);
        p1[id].names[strcspn(p1[id].names, "\n")] = '\0';  // 개행 문자 제거

        printf("판매 가격 입력: ");
        scanf("%d", &p1[id].mo);

        p1[id].dlq = b[id]; // 재고량을 'dlq'에 저장
    } else {
        printf("잘못된 상품 ID입니다.\n");
    }
}

// 판매량 입력 함수
void salesInput(int c[], int b[]) {
    int id;
    printf("상품 ID (0-4) 입력: ");
    scanf("%d", &id);

    if (id >= 0 && id < MAX_PRODUCTS) {
        int sale;
        printf("판매량 입력: ");
        scanf("%d", &sale);

        // 판매량이 입고량을 넘지 않도록 확인
        if (sale <= b[id]) {
            c[id] += sale;  // 기존 판매량에 추가
            b[id] -= sale;  // 입고량(재고량)에서 판매된 만큼 차감
        } else {
            printf("입고량을 초과할 수 없습니다. 최대 판매량은 %d입니다.\n", b[id]);
        }
    } else {
        printf("잘못된 상품 ID입니다.\n");
    }
}

// 개별 상품 현황 출력 함수
void Product(Price p1[], int b[], int c[]) {
    int id;
    printf("ID를 입력하세요: ");
    scanf("%d", &id);

    if (id >= 0 && id < MAX_PRODUCTS) {
        printf("상품명: %s\n", p1[id].names);
        printf("판매 가격: %d\n", p1[id].mo);
        printf("현재 재고량: %d\n", b[id]);
        printf("판매량: %d\n", c[id]);
    } else {
        printf("잘못된 ID입니다.\n");
    }
}

// 전체 상품 현황 출력 함수
void inventoryStatus(int b[], int c[], Price p1[]) {
    printf("\n== 전체 상품 현황 ==\n");
    printf("%-5s %-20s %-10s %-10s %-10s\n", "ID", "상품명", "입고량", "판매 가격", "판매량");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%-5d %-20s %-10d %-10d %-10d\n", 
               p1[i].ID, p1[i].names, b[i], p1[i].mo, c[i]);
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
        if (b[i] <= 2) {
            printf("상품 ID %d: 상품명: %s: 재고 부족 (%d)\n", i, p1[i].names, b[i]);
        }
    }
}

int main() {
    Price p1[MAX_PRODUCTS] = {0}; // 상품 정보
    int b[MAX_PRODUCTS] = {0};    // 재고
    int c[MAX_PRODUCTS] = {0};    // 판매량

    FileInfo file_info = { "products.txt", NULL, 0 }; // 파일 관리 구조체 초기화

    initializeProducts(p1, b, c, &file_info); // 상품 정보 초기화

    while (1) {
        int choice;
        printf("원하는 메뉴를 선택하세요(1.입고, 2.판매, 3.개별현황, 4.전체 상품 현황, 5.상품정보 저장, 6.상품정보 가져오기, 7.종료): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: stockInput(b, p1); break;
            case 2: salesInput(c, b); break;
            case 3: Product(p1, b, c); break;
            case 4: inventoryStatus(b, c, p1); break;
            case 5: saveProducts(p1, b, c, &file_info); break;
            case 6: loadProducts(p1, b, c, &file_info); break;
            case 7: saveProducts(p1, b, c, &file_info); return 0;
            default: printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
