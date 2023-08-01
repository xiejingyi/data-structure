// 链表相关操作
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
} LinkedList;

// 初始化链表
void initList(LinkedList* list) {
  list->head = NULL;
}

// 插入元素
void insert (LinkedList* list, int newElem) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = newElem;
  newNode->next = list->head;
  list->head = newNode;
}
// 展示列表元素
void display (LinkedList* list) {
  Node* current = list->head;
  printf("链表元素：");
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
  
}
// 修改元素
int update(LinkedList* list, int target, int newElem){
  Node* current = list->head;
  while (current != NULL)
  {
    if(current->data == target) {
      current->data = newElem;
      return 1;
    }
    current = current->next;
  }
  return 0;
}
//删除元素
int delete (LinkedList* list, int target) {
  Node* current = list->head;
  Node* previous = NULL;
  while (current != NULL)
  {
    /* code */
    if(current->data == target) {
      if(previous != NULL) {
        previous->next = current->next;
      } else {
        list->head = current->next;
      }
      free(current);
      return 1;
    }
    previous = current;
    current = current->next;
  }
  
  return 0;
}
// 查找元素
int search(LinkedList* list, int elem) {
  Node* current = list->head;
  int i = 0;
  while (current != NULL)
  {
    if(current->data == elem) {
      return i;
    }
    i++;
    current = current->next;
  }
  return -1;
}
//释放链表内存
void freeList (LinkedList* list) {
  Node* current = list->head;
  Node* nextNode;
  while (current != NULL)
  {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
  list->head = NULL;
}
int main () {
  LinkedList myList;
  initList(&myList);
  insert(&myList, 40);
  insert(&myList, 30);
  insert(&myList, 20);
  insert(&myList, 10);
  display(&myList);
  update(&myList, 20, 25);
  display(&myList);
  delete(&myList, 30);
  display(&myList);
  int searchElem = 25;
  int searchResult = search(&myList, searchElem);
  if(searchResult != -1) {
    printf("元素%d在第%d个\n",searchElem, searchResult);
  } else {
    printf("没找到元素%d\n", searchElem);
  }
  freeList(&myList);
  return 0;
}