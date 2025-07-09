//
// Created by Thanh on 7/9/2025.
//

#include <stdio.h>
#include <stdlib.h>

// Định nghĩa Node của danh sách liên kết (đơn)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm khởi tạo Stack (ban đầu là NULL)
Node* initialStack() {
    return NULL;
}

// Thêm phần tử vào đầu Stack
Node* push (int value, Node* top){
    // Cần sử dụng cấp phát bộ nhớ
    Node* newNode = (Node*) malloc(sizeof (Node));

    // Kiểm tra xem bộ nhớ còn đủ để cấp phát không?
    if (newNode == NULL){
        printf("Khong du bo nho de cap phat!");
        exit(1);
    }

    newNode->data = value;
    newNode->next = top;

    // newNode trở thành top mới
    return newNode;
}

// Kiểm tra xem Stack có rỗng không
int isEmpty(Node* top) {
    return top == NULL;
}

// In ra toàn bộ Stack
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

// Hàm giải phóng bộ nhớ
void freeStack(Node* top) {
    Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

// Hàm yêu cầu người dùng nhập số và thêm vào stack
Node* addElement(Node* top) {
    int n;
    printf("Nhap so nguyen duong can them vao stack: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Chi chap nhan so nguyen duong!\n");
        return top;
    }
    top = push(n, top);
    return top;
}

// MAIN DEMO
int main() {
    Node* stack = initialStack();

    stack = push(5, stack);
    stack = push(4, stack);
    stack = push(3, stack);
    stack = push(2, stack);
    stack = push(1, stack);

    printStack(stack); // In ra stack hiện tại

    // Thêm phần tử từ người dùng nhập
    stack = addElement(stack);

    // In lại sau khi thêm
    printStack(stack);

    freeStack(stack);
    return 0;
}

