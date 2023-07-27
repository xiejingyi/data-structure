#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 定义栈最大值

typedef struct {
  int data[MAX_SIZE];
  int top;
} Stack;

// 初始化栈
void initStack (Stack *stack) {
  stack->top = -1;
}

int push (Stack *stack, int value) {
  if(stack->top == MAX_SIZE - 1) {
    printf("栈已满，无法push\n");
    return 0;
  }
  stack->top++;
  stack->data[stack->top] = value;
  return 1;
}
int pop (Stack *stack) {
  if(stack->top == -1) {
    printf("栈已空，无法出栈\n");
    return -1;
  }
  int n = stack->data[stack->top--];
  return n;
}

int main () {
  Stack myStack;
  initStack(&myStack);
  push(&myStack, 1);
  push(&myStack, 2);
  push(&myStack, 3);

  int a = pop(&myStack);
  printf("出栈元素%d\n", a);

  printf("现在栈中的元素为：\n");
  for (int i = myStack.top; i >=0; i--) {
    printf("%d\n", myStack.data[i]);
  }
  int top = myStack.top;
  printf("top指针%d\n", top);
  return 0;
}

