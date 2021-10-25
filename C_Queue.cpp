#include<cstdio>
#include<cstdlib> 
#define QElemType int 
#define Status int 
#define MAXQSIZE 100			//�����г���

using namespace std;
/**
	˵����
	�����MAXQSIZEȡģ�������ǽ�βָ���ͷָ������������
*/

//���еĽṹ
typedef struct {
	QElemType* base;		//��ʼ���Ķ�̬����洢�ռ� 
	int front;			//ͷָ�룬�����в��գ�ָ�����ͷԪ�� 
	int rear;			//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� 
}SqQueue;

//��ʼ��
Status InitQueue(SqQueue& Q) {
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base) {
		printf("�ڴ����ʧ��\n");
		return 0;
	}
	Q.front = Q.rear = 0;
	return 0;
}

//���ض��г���
int QueueLength(SqQueue Q) {
	printf("������Ϊ%d\n", (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//��� 
Status EnQueue(SqQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front) {
		printf("��������\n");
		return 0;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;	//βָ���1��������β��ʱ��ѭ����ͷָ�룬����ͷָ�� 
	return 0;
}

//����
Status DeQueue(SqQueue& Q, QElemType e) {
	//�п�
	if (Q.front == Q.rear) {
		printf("����Ϊ��\n");
		return 0;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;  	//ͷ��1��������ͷʱ��ѭ����βָ�룬����βָ�� 
	printf("Ԫ��%d����\n", e);
	return 0;
}

//����
Status QueueTraverse(SqQueue Q) {
	printf("������ʼ��");
	for (int i = Q.front; i < Q.rear; i++) {
		printf("%d ", Q.base[i]);
	}
	printf("\n");
	return 0;
}


//����ջ�������ظ��Ľ�Ԫ����ջ����ȻҲ���Ե���дһ�������ĺ�����
void CrQueue(SqQueue& Q, int n) {
	InitQueue(Q);
	for (int i = 0; i < n; i++) {
		int e;
		scanf_s("%d", &e);
		EnQueue(Q, e);
	}
	printf("�����ɹ�\n");
}

//�п�
Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("����Ϊ��\n");
		return true;
	}
	else {
		printf("���в�Ϊ��\n");
		return false;
	}
}

//��ȡ��ͷԪ��
Status GetHead(SqQueue Q, QElemType e) {
	if (Q.front == Q.rear) {
		printf("����Ϊ��\n");
		return 0;
	}
	e = Q.base[Q.front];	//��ͷԪ��֮ǰ��һ���յ�ͷ��� 
	printf("��ͷԪ��Ϊ��%d\n", e);
	return 0;
}

//�ÿ�
Status ClearQueue(SqQueue& Q) {
	Q.rear = Q.front;
	printf("�ÿղ����ɹ�\n");
	return 0;
}

//����
Status DestoryQueue(SqQueue& Q) {
	free(Q.base);	//���������ռ� 
	Q.front = 0;		//ջ��ָ�븳�� 
	Q.rear = 0;		//ջ��ָ�븳��
	printf("���ٳɹ�");
	return 0;
}
int main() {
	int n;
	QElemType value1, value2;
	value1 = 0;
	value2 = 0;
	SqQueue Q;
	printf("���������Ԫ�ظ���:");
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
