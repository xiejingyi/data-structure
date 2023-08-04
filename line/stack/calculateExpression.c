#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
  double data[MAX_STACK_SIZE];
  int top;
} Stack;
//初始化栈
void initStack (Stack* stack) {
  stack->top = -1;
}
// 判断栈是否为空
int isEmpty(Stack* stack) {
  return stack->top == -1;
}
// 入栈操作
void push(Stack* stack, double value) {
  if(stack->top < MAX_STACK_SIZE - 1) {
    stack->top++;
    stack->data[stack->top] = value;
  }
}

// 出栈操作
double pop(Stack* stack) {
  if(!isEmpty(stack)) {
    double value = stack->data[stack->top];
    stack->top--;
    return value;
  }
  return 0.0;
}

double calculateExpression (const char* expression) {
  Stack stack;
  initStack(&stack);
  int len = strlen(expression);
  for(int i = 0; i < len; i++) {
    if(isdigit(expression[i])) {
      double num = 0;
      while (i < len && isdigit(expression[i]))
      {
        num = num * 10 + (expression[i] - '0');
        i++;
      }
      i--;
      push(&stack, num);
    } else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
      double operand2 = pop(&stack);
      double operand1 = pop(&stack);

      switch (expression[i])
      {
      case '+':
        push(&stack, operand1 + operand2);
        break;
      case '-':
        push(&stack, operand1 - operand2);
        break;
      case '*':
        push(&stack, operand1 * operand2);
        break;
      case '/':
        if(operand2 != 0) {
          push(&stack, operand1 / operand2);
        } else {
          printf("Error: 除数为0\n");
          return 0.0;
        }
        break;
      default:
        break;
      }
    }
  }
  return pop(&stack);
}

int main() {
  char expression[] = "5 3 4 * +";
  double result = calculateExpression(expression);
  printf("计算结果%.2f ", result);
  return 0;
}
