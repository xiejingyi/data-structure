#include <stdio.h>
#include <stdlib.h>

// 定义一个链式栈结点
typedef struct Node {
  int data;
  struct Node *next;
} Node;
// 定义链式栈结构体
typedef struct {
  Node* top;
} linkedStack;

// 初始化一个链式栈
void initLinkedStack(linkedStack* linkStack) {
  linkStack->top = NULL;
}
// 入栈操作
void push(linkedStack* linkStack, int value) {
  Node* newNode= (Node*)malloc(sizeof(Node));
  if(newNode == NULL) {
    printf("内存分配失败，无法入栈");
    return;
  }
  newNode->data = value;
  newNode->next = linkStack->top; // 新结点的下一个是当前栈顶结点
  linkStack->top = newNode; // 更新栈顶结点指向新结点
}

// int pop(linkedStack* linkedStack) {
//   int a ;
//   if(linkedStack->top == NULL) {
//     printf("栈为空，无法出栈");
//     return -1;
//   }
//   return a;
// }
// 依次输出栈内元素
void printStack(linkedStack* stack) {
  printf("栈中的元素：\n");
  Node* current = stack->top;
  while(current != NULL) {
    printf("栈元素%d ", current->data);
    current = current->next;
  }
}

void freeStack(linkedStack* stack) {
  Node* current = stack->top;
  while (current != NULL)
  {
    Node* temp = current;
    current = current->next;
    free(temp);
  }
}
// 出栈操作
void pop(linkedStack* stack) {
  if(stack->top == NULL) {
    printf("栈已空，无法出栈操作");
    return;
  }
  Node* temp = stack->top;
  printf("\n出栈元素%d\n", temp->data);
  stack->top = stack->top->next;
}

int main () {
  linkedStack myLinkStack;
  initLinkedStack(&myLinkStack);
  //入栈操作
  push(&myLinkStack, 10);
  push(&myLinkStack, 20);
  push(&myLinkStack, 30);

  // if(myLinkStack->top == NULL) {
  //   printf("栈为空");
  //   return 1;
  // }
  printStack(&myLinkStack);
  pop(&myLinkStack);
  printStack(&myLinkStack);
  freeStack(&myLinkStack);
  return 0;
}



