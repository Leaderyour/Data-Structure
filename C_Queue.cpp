#include<cstdio>
#include<cstdlib> 
#define QElemType int 
#define Status int 
#define MAXQSIZE 100			//最大队列长度

using namespace std;
/**
	说明：
	下面对MAXQSIZE取模的作用是将尾指针和头指针连接起来，
*/

//队列的结构
typedef struct {
	QElemType* base;		//初始化的动态分配存储空间 
	int front;			//头指针，若队列不空，指向队列头元素 
	int rear;			//尾指针，若队列不空，指向队列尾元素的下一个位置 
}SqQueue;

//初始化
Status InitQueue(SqQueue& Q) {
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base) {
		printf("内存分配失败\n");
		return 0;
	}
	Q.front = Q.rear = 0;
	return 0;
}

//返回队列长度
int QueueLength(SqQueue Q) {
	printf("链表长度为%d\n", (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//入队 
Status EnQueue(SqQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front) {
		printf("队列已满\n");
		return 0;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;	//尾指针加1，当到达尾部时，循环到头指针，返回头指针 
	return 0;
}

//出队
Status DeQueue(SqQueue& Q, QElemType e) {
	//判空
	if (Q.front == Q.rear) {
		printf("队列为空\n");
		return 0;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;  	//头加1，当到达头时，循环到尾指针，返回尾指针 
	printf("元素%d出队\n", e);
	return 0;
}

//遍历
Status QueueTraverse(SqQueue Q) {
	printf("遍历开始：");
	for (int i = Q.front; i < Q.rear; i++) {
		printf("%d ", Q.base[i]);
	}
	printf("\n");
	return 0;
}


//创建栈，就是重复的将元素入栈（当然也可以单独写一个创建的函数）
void CrQueue(SqQueue& Q, int n) {
	InitQueue(Q);
	for (int i = 0; i < n; i++) {
		int e;
		scanf_s("%d", &e);
		EnQueue(Q, e);
	}
	printf("创建成功\n");
}

//判空
Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("队列为空\n");
		return true;
	}
	else {
		printf("队列不为空\n");
		return false;
	}
}

//获取队头元素
Status GetHead(SqQueue Q, QElemType e) {
	if (Q.front == Q.rear) {
		printf("队列为空\n");
		return 0;
	}
	e = Q.base[Q.front];	//队头元素之前有一个空的头结点 
	printf("队头元素为：%d\n", e);
	return 0;
}

//置空
Status ClearQueue(SqQueue& Q) {
	Q.rear = Q.front;
	printf("置空操作成功\n");
	return 0;
}

//销毁
Status DestoryQueue(SqQueue& Q) {
	free(Q.base);	//销毁连续空间 
	Q.front = 0;		//栈底指针赋空 
	Q.rear = 0;		//栈顶指针赋空
	printf("销毁成功");
	return 0;
}
int main() {
	int n;
	QElemType value1, value2;
	value1 = 0;
	value2 = 0;
	SqQueue Q;
	printf("请输入队列元素个数:");
	scanf_s("%d", &n);
	CrQueue(Q, n);
	GetHead(Q, value1);
	DeQueue(Q, value2);
	QueueTraverse(Q);
	ClearQueue(Q);
	QueueTraverse(Q);
	DestoryQueue(Q);
	return 0;
}
