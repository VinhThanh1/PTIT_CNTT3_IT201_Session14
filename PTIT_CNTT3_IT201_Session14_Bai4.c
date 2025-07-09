//
// Created by Thanh on 7/9/2025.
//

#include <stdio.h>
#include <stdlib.h>

// Định nghĩa Node của danh sách liên kết đơn
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm khởi tạo stack rỗng
Node* initialStack() {
    return NULL;
}

// Hàm kiểm tra stack rỗng
int isEmpty(Node* top) {
    return top == NULL;
}

// Hàm thêm phần tử vào đầu stack
Node* push(int value, Node* top) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

// Hàm lấy phần tử và loại bỏ khỏi stack (giống cú pháp mảng)
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Ngăn xếp trống\n");
        return -1;
    }

    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Hàm in toàn bộ phần tử trong stack
void printStack(Node* top) {
    printf("Cac phan tu trong stack (tu dinh -> day):\n");
    if (isEmpty(top)) {
        printf("Ngăn xếp trống\n");
        return;
    }

    Node* temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Hàm giải phóng bộ nhớ stack
void freeStack(Node* top) {
    Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

// ============================

int main() {
    Node* stack = initialStack();

    // Thêm phần tử vào stack
    stack = push(5, stack);
    stack = push(4, stack);
    stack = push(3, stack);
    stack = push(2, stack);
    stack = push(1, stack);

    // In ngăn xếp ban đầu
    printf("Stack ban dau:\n");
    printStack(stack);

    // Pop phần tử
    printf("\nPop: %d\n", pop(&stack));

    // In ngăn xếp sau khi pop
    printf("Stack sau khi pop:\n");
    printStack(stack);

    // Giải phóng bộ nhớ
    freeStack(stack);

    return 0;
}

