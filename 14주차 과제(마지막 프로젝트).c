#include<stdio.h>
#include<string.h>
#include<math.h>

#define WORD 16

// 문자열을 2진수로 변환
void getBinary(char bin[], char str[], int n) {
    int num = atoi(str); // 문자열을 정수로 변환
    for (int i = n - 1; i >= 0; i--) {
        bin[i] = (num % 2) + '0'; // 2진수로 변환
        num /= 2;
    }
    bin[n] = '\0'; // 문자열 끝에 NULL 추가
}

// 2의 보수를 계산
void complement2(char bin[], int n) {
    int carry = 1; // 1을 더해야 함
    for (int i = n - 1; i >= 0; i--) {
        if (bin[i] == '0') {
            bin[i] = carry ? '1' : '0';
            carry = 0;
        }
        else {
            bin[i] = carry ? '0' : '1';
        }
    }
}

// 2진수를 10진수로 변환
int bin2dec(char bin[], int n) {
    int result = 0;
    int isNegative = (bin[0] == '1'); // 부호 비트 확인

    if (isNegative) {
        complement2(bin, n); // 음수면 2의 보수로 원래 값을 복구
    }

    for (int i = 0; i < n; i++) {
        result = result * 2 + (bin[i] - '0');
    }

    if (isNegative) {
        result = -result; // 음수 처리
        complement2(bin, n); // 원래 이진수 복구
    }

    return result;
}

int main()
{
    char input1[100];
    char input2[100];
    char op[10];

    char binary1[WORD + 1] = { 0 };
    char binary2[WORD + 1] = { 0 };

    int result;
    int num1, num2;

    printf("<<<<<input>>>>>\n");
    gets(input1); // 첫 번째 입력
    gets(op);     // 연산자 입력
    gets(input2); // 두 번째 입력

    getBinary(binary1, input1, WORD);
    getBinary(binary2, input2, WORD);

    num1 = bin2dec(binary1, WORD);
    num2 = bin2dec(binary2, WORD);

    switch (op[0]) {
    case '+': result = num1 + num2; break;
    case '-': result = num1 - num2; break;
    case '*': result = num1 * num2; break;
    case '/': result = num1 / num2; break;
    case '%': result = num1 % num2; break;
    }

    printf("%s(%d) %c %s(%d)=%d\n", binary1, num1, op[0], binary2, num2, result);
    return 0;
}
