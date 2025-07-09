//
// Created by Thanh on 7/9/2025.
//

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

// Hàm khởi tạo Stack rỗng
Node* initialStack() {
    return NULL;
}

// Thêm phần tử vào đầu Stack
Node* push(int value, Node* top) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Khong du bo nho de cap phat!");
        exit(1);
    }

    newNode->data = value;
    newNode->next = top;
    return newNode;
}

// Kiểm tra Stack có rỗng không
int isEmpty(Node* top) {
    return top == NULL;
}

// Hàm xem phần tử đầu ngăn xếp
int peek(Node* top) {
    if (isEmpty(top)) {
        printf("Ngăn xếp trống\n");
        return -1;
    }
    return top->data;
}

// In ra toàn bộ Stack
void printStack(Node* top) {
    printf("Cac phan tu co trong Stack hien tai la:\n");

    if (isEmpty(top)) {
        printf("Ngăn xếp trống\n");
        return;
    }

    Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Giải phóng bộ nhớ Stack
void freeStack(Node* top) {
    Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

// Hàm main để kiểm thử
int main() {
    Node* stack = initialStack();

    // Thêm dữ liệu vào stack
    stack = push(1, stack);
    stack = push(2, stack);
    stack = push(3, stack);
    stack = push(4, stack);
    stack = push(5, stack);

    printStack(stack);
    printf("Phan tu tren dinh stack la: %d\n\n", peek(stack));

    freeStack(stack);
    return 0;
}

