#include<cstdio>
#include<cstdlib> 
#define QElemType int 
#define Status int 

using namespace std;
//���ӵĽṹ ���������ָ����
typedef struct QNode {
	QElemType data;		//������ 
	struct QNode* next;		//ָ���� 
}QNode, * QueuePtr;
//����ͷβָ��ṹ
typedef struct {
	QueuePtr front;		//��ͷָ�루���ӣ� 
	QueuePtr rear;		//��βָ�� ����ӣ� 
}LinkQueue;

//��ʼ��
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;		//�½�ͷ��㣬��ͷ��β��ָ����
	if (!Q.front) {
		printf("���з����ڴ�ʧ��");
		return 0;
	}
	Q.front->next = NULL;
	return 0;
}

//���
Status EnQueue(LinkQueue& Q, QElemType e) {
	QueuePtr p = new QNode;		//�½����
	if (!p) {
		printf("�����ڴ�ʧ��");
		return 0;
	}
	p->data = e;	//�½�㸳ֵ
	p->next = NULL;		//�½���ָ����Ϊ�գ�����β���룩
	Q.rear->next = p;		//��βָ��ָ��p
	Q.rear = p;		//��βָ�����
	printf("��ӳɹ�\n");
	return 0;
}

//�������� ���ظ�������Ӳ����� 
void CrQueue(LinkQueue& Q, int n) {
	InitQueue(Q);		//��ʼ������
	for (int i = 0; i < n; i++) {	//ѭ��n��EnQueue����
		int e;
		scanf_s("%d", &e);
		EnQueue(Q, e);
	}
	printf("�����ɹ�\n");
}

//����
Status DeQueue(LinkQueue& Q, QElemType e) {
	if (Q.front == Q.rear) {		//�п� 
		printf("����Ϊ��\n");
		return 0;
	}
	QueuePtr p = Q.front->next;		//�½�����ȡ��ͷԪ�� 
	e = p->data;		//��e��ֵ 
	Q.front->next = p->next;		//���ӣ����¸�ֵ��ͷ��㣨Q.front->next��Ϊ��һ����� 
	/**�����е����һ�������ӣ��ᵼ�¶���βָ�붪ʧ��
		Ӧ�ý���βָ�����¸�ֵ��ָ��ͷָ�룩
	*/if (Q.rear == p)
	Q.rear = Q.front;
	free(p);
	printf("%d���ӳɹ�\n", e);
	return 0;
}

//����
Status QueueTraverse(LinkQueue Q) {
	printf("������ʼ��");
	QueuePtr p = Q.front->next;		//��ͷԪ��֮ǰ��һ���յ�ͷ���
	while (p != Q.rear->next) {	//��pû�е����βָ�� 
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}

//�п�
Status QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		printf("����Ϊ��\n");
		return true;
	}
	else {
		printf("���в�Ϊ��\n");
		return false;
	}
}

//��ȡ����Ԫ�ظ���
int QueueLength(LinkQueue Q) {
	QueuePtr p = Q.front->next;
	int count = 0;
	while (p != Q.rear->next) {	//��pû�е����βָ�� 
		p = p->next;
		count++;
	}
	printf("����Ԫ�ظ���Ϊ��%d\n", count);
	return 0;
}

//��ȡ��ͷԪ��
Status GetHead(LinkQueue Q, QElemType e) {
	if (Q.front == Q.rear) {
		printf("����Ϊ��\n");
		return 0;
	}
	e = Q.front->next->data;	//��ͷԪ��֮ǰ��һ���յ�ͷ��� 
	printf("��ͷԪ��Ϊ��%d\n", e);
	return 0;
}

//�ÿ�
Status ClearQueue(LinkQueue& Q) {
	Q.rear = Q.front;
	printf("�ÿղ����ɹ�\n");
	return 0;
}

//����
Status DestoryQueue(LinkQueue& Q) {
	while (Q.front) {
		Q.rear = Q.front->next;		//����βָ��ÿ�ζ�ָ���ͷָ�����һ����� 
		free(Q.front);		//�ͷŶ�ͷָ�� 
		Q.front = Q.rear;	//��ͷָ�����¸�ֵ 
	}
	printf("���ٳɹ�\n");
	return 0;
}


int main() {
	int n;
	QElemType value1, value2;
	value1 = 0;
	value2 = 0;
	LinkQueue Q;
	printf("���������Ԫ�ظ���:");
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
