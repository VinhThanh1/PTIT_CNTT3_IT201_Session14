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

// Thêm phần tử vào stack (đầu danh sách)
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

// Kiểm tra stack rỗng
int isEmpty(Node* top) {
    return top == NULL;
}

void printStack(Node* top) {
    printf("stack = {\n    ");
    if (isEmpty(top)) {
        printf("NULL\n}\n");
        return;
    }

    Node* temp = top;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n}\n");
}


// Hàm duyệt toàn bộ phần tử trong stack
void traverseStack(Node* top) {
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

// Giải phóng bộ nhớ stack
void freeStack(Node* top) {
    Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

// =============================

int main() {
    Node* stack = initialStack();

    stack = push(5, stack);
    stack = push(4, stack);
    stack = push(3, stack);
    stack = push(2, stack);
    stack = push(1, stack);

    // In cấu trúc stack
    printStack(stack);

    // Duyệt và in từng phần tử (LIFO)
    traverseStack(stack);

    // Giải phóng bộ nhớ
    freeStack(stack);

    return 0;
}