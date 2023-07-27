#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 定义栈的最大容量

// 定义栈结构体
typedef struct {
  int data[MAX_SIZE];
  int top;
} Stack;

//初始化栈
void initStack(Stack *stack) {
  stack->top = -1; //栈顶初始化为-1，表示栈为空
}

// 入栈操作
int push(Stack *stack, int value) {
  if(stack->top >= MAX_SIZE - 1) {
    printf("栈已满，无法入栈\n");
    return 0;
  }
  stack->top++; // 栈顶指针加1
  stack->data[stack->top] = value; //将元素压入栈顶
  return 1; //入栈成功
}
// 出栈操作
int pop(Stack *stack) {
  int elem;
  if(stack->top == -1) {
    printf("栈已空，无法出栈\n");
    return -1;
  }
  elem = stack->data[stack->top--];
  return elem;
}

int main() {
  Stack myStack;
  initStack(&myStack);
  // int operator;
  // printf("请输入对栈的操作");
  // scanf("%d", &operator);
  // if(operator == -1) {
  //   pop(&myStack);
  //   return 0;
  // }
  int numElemnets;
  printf("请输入要入栈的元素个数：");
  scanf("%d", &numElemnets);

  if(numElemnets <= 0) {
    printf("输入元素个数应为正整数。\n");
    return 1;
  } 

  int element;
  printf("请依次输入要入栈的元素:\n");
  for(int i = 0; i < numElemnets; i++) {
    scanf("%d", &element);
    if(!push(&myStack, element)) {
      printf("入栈失败。\n");
      return 1;
    }
  }
  printf("入栈成功！现在栈中的元素为：\n");
  for(int i = myStack.top; i >=0; i--) {
    printf("%d\n", myStack.data[i]);
  }
  int n;
  n = pop(&myStack);
  printf("出栈元素：%d", n);
  return 0;
}

