// 顺序表的操作
#include <stdio.h>
#define MAX_SIZE 100

//定义顺序表结构体
typedef struct {
  int data[MAX_SIZE];
  int length;
} SeqList;

// 初始化顺序表

void initList(SeqList* list) {
  list->length = 0;
}

// 插入元素
void insert(SeqList* list, int index, int newElem) {
  if(list->length == MAX_SIZE || index < 0 || index > list->length) {
    printf("不能再插入数据啦");
    return;
  }
  list->data[index] = newElem;
  list->length++;
}
// 打印list元素
void display(SeqList* list) {
  printf("输出，顺序表元素：");
  for (int i = 0; i < list->length; i++) {
    printf("%d ", list->data[i]);
  }
  printf("表长度%d\n", list->length);
}

int update(SeqList* list, int index, int newElem) {
  if(index < 0 || index > list->length) {
    return 0;
  }
  list->data[index] = newElem;
  return 1;
}
//删除元素
int delete(SeqList* list, int index) {
  if(index < 0 || index > list->length) {
    return 0;
  }
  for(int i = index; i < list->length - 1; i++) {
    list->data[i] = list->data[i+1];
  }
  list->length--;
  return 1;
}
// 查找元素
int search(SeqList* list, int elem) {
  for(int i = 0; i < list->length; i++) {
    if(list->data[i] == elem) {
      return i+1;
    }
  }
  return -1;
}


int main(){
  SeqList myList;
  initList(&myList);
  insert(&myList, 0 , 10);
  insert(&myList, 1 , 20);
  insert(&myList, 2 , 30);
  insert(&myList, 3 , 40);
  insert(&myList, 4 , 50);
  display(&myList);
  update(&myList, 1, 25);
  display(&myList);
  delete(&myList, 2);
  display(&myList);
  int elem = 25;
  int searchResult = search(&myList, elem);
  if(searchResult != -1) {
    printf("元素 %d 在第%d个\n", elem, searchResult);
  } else {
    printf("没发现，元素 %d\n", elem);
  }
  return 0;
}

