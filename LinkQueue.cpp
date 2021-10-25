#include<cstdio>
#include<cstdlib> 
#define QElemType int 
#define Status int 

using namespace std;
//链队的结构 （数据域和指针域）
typedef struct QNode {
	QElemType data;		//数据域 
	struct QNode* next;		//指针域 
}QNode, * QueuePtr;
//链队头尾指针结构
typedef struct {
	QueuePtr front;		//队头指针（出队） 
	QueuePtr rear;		//队尾指针 （入队） 
}LinkQueue;

//初始化
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;		//新建头结点，队头队尾均指向它
	if (!Q.front) {
		printf("队列分配内存失败");
		return 0;
	}
	Q.front->next = NULL;
	return 0;
}

//入队
Status EnQueue(LinkQueue& Q, QElemType e) {
	QueuePtr p = new QNode;		//新建结点
	if (!p) {
		printf("分配内存失败");
		return 0;
	}
	p->data = e;	//新结点赋值
	p->next = NULL;		//新结点的指针域为空，（队尾插入）
	Q.rear->next = p;		//队尾指针指向p
	Q.rear = p;		//队尾指针后移
	printf("入队成功\n");
	return 0;
}

//创建队列 （重复调用入队操作） 
void CrQueue(LinkQueue& Q, int n) {
	InitQueue(Q);		//初始化队列
	for (int i = 0; i < n; i++) {	//循环n次EnQueue操作
		int e;
		scanf_s("%d", &e);
		EnQueue(Q, e);
	}
	printf("创建成功\n");
}

//出队
Status DeQueue(LinkQueue& Q, QElemType e) {
	if (Q.front == Q.rear) {		//判空 
		printf("队列为空\n");
		return 0;
	}
	QueuePtr p = Q.front->next;		//新建结点获取队头元素 
	e = p->data;		//给e赋值 
	Q.front->next = p->next;		//出队，重新赋值队头结点（Q.front->next）为下一个结点 
	/**队列中的最后一个结点出队，会导致队列尾指针丢失，
		应该将队尾指针重新赋值（指向头指针）
	*/if (Q.rear == p)
	Q.rear = Q.front;
	free(p);
	printf("%d出队成功\n", e);
	return 0;
}

//遍历
Status QueueTraverse(LinkQueue Q) {
	printf("遍历开始：");
	QueuePtr p = Q.front->next;		//队头元素之前有一个空的头结点
	while (p != Q.rear->next) {	//当p没有到达队尾指针 
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}

//判空
Status QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		printf("队列为空\n");
		return true;
	}
	else {
		printf("队列不为空\n");
		return false;
	}
}

//获取队列元素个数
int QueueLength(LinkQueue Q) {
	QueuePtr p = Q.front->next;
	int count = 0;
	while (p != Q.rear->next) {	//当p没有到达队尾指针 
		p = p->next;
		count++;
	}
	printf("队列元素个数为：%d\n", count);
	return 0;
}

//获取队头元素
Status GetHead(LinkQueue Q, QElemType e) {
	if (Q.front == Q.rear) {
		printf("队列为空\n");
		return 0;
	}
	e = Q.front->next->data;	//队头元素之前有一个空的头结点 
	printf("队头元素为：%d\n", e);
	return 0;
}

//置空
Status ClearQueue(LinkQueue& Q) {
	Q.rear = Q.front;
	printf("置空操作成功\n");
	return 0;
}

//销毁
Status DestoryQueue(LinkQueue& Q) {
	while (Q.front) {
		Q.rear = Q.front->next;		//将队尾指针每次都指向队头指针的下一个结点 
		free(Q.front);		//释放队头指针 
		Q.front = Q.rear;	//队头指针重新赋值 
	}
	printf("销毁成功\n");
	return 0;
}


int main() {
	int n;
	QElemType value1, value2;
	value1 = 0;
	value2 = 0;
	LinkQueue Q;
	printf("请输入队列元素个数:");
	scanf_s("%d", &n);
	CrQueue(Q, n);
	GetHead(Q, value1);
	QueueLength(Q);
	QueueTraverse(Q);
	DeQueue(Q, value2);
	QueueTraverse(Q);
	ClearQueue(Q);
	QueueEmpty(Q);
	QueueTraverse(Q);
	DestoryQueue(Q);
	return 0;
}
