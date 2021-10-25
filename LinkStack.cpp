#include<cstdio>
#include<cstdlib> 
#define MAXSIZE 1000	//�������󳤶� 
#define SElemType int 
#define Status int 
//ջ�Ľṹ
typedef struct LStack {
	SElemType data;		//������
	struct LStack* next;	//ָ���� 
}LStack, * LStackList;

//��ʼ��
Status InitStack(LStackList& S) {
	S = new LStack;
	S->next = NULL;
	return 0;
}

//��ջ
Status Push(LStackList& S, SElemType e) {
	LStackList p = new LStack;		//�����µĽ�� 
	p->data = e;	//�½���������ֵ 
	p->next = S;	//�½���ָ����ָ��ͷ��㣨ջ���� 
	S = p;	//����ı�ͷ����Ϊ�²����Ԫ�أ� 
	printf("ѹ��ջ�ɹ�\n");
	return 0;
}

//��ջ
Status Pop(LStackList& S) {
	if (S->next) {
		LStackList p = S;
		S = S->next;	//ͷָ����� 
		free(p);
		printf("��ջ�ɹ�\n");
	}
	else {
		printf("ջ��\n");
	}
	return 1;
}

//����ջ�������ظ��Ľ�Ԫ����ջ����ȻҲ���Ե���дһ�������ĺ�����
void Creat(LStackList& S, int n) {
	InitStack(S);
	for (int i = 0; i < n; i++) {
		int e;
		scanf_s("%d", &e);
		Push(S, e);
	}
	printf("�����ɹ�\n");
}

//��������Ϊ�Ǵ�ջ������ͷ����ʼ�ı���������������б�������� 
Status StackTraverse(LStackList S) {
	printf("������ʼ��\n");
	LStackList p = S;
	/**
	ע�⣺���һ��������û��Ԫ�ص�
	*/
	while (p->next) {		//���һ��������û��Ԫ�ص� 
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return 1;
}

//��ȡջ��Ԫ�ظ��� 
Status StackLength(LStackList S) {
	LStackList p = S;
	int count = 0;
	while (p) {
		p = p->next;
		count++;
	}
	printf("ջ��Ԫ�ظ���Ϊ��%d\n", count);
	return 1;
}

//�ж�ջ��
bool StackEmpty(LStackList S) {
	if (S->next == NULL) {
		printf("ջ��\n");
		return true;
	}
	else {
		printf("ջ�ǿ�\n");
		return false;
	}
}

//��ȡջ��Ԫ��
Status GetTop(LStackList S, SElemType e) {
	//�ж�ջ�� 
	if (StackEmpty(S)) {
		return 0;
	}
	else {
		e = S->data;
		printf("ջ��Ԫ��Ϊ%d\n", e);
		return 0;
	}
}

//ջ�ÿ�
Status ClearStack(LStackList& S) {
	if (S->next != NULL)
		S->next = NULL;
	printf("�ÿղ����ɹ�\n");
	return 0;
}

//��������
Status DestoryStack(LStackList& S) {
	//�ж��Ƿ�Ϊ�ձ� 
	LStackList p = S;
	LStackList pre = new LStack;
	while (p->next) {
		pre = p;
		p = p->next;
		delete(pre);
	}
	printf("��������ɹ�\n");
	return 0;
}


int main() {
	int n, value1, value2;
	value1 = 0;
	value2 = 0;
	LStackList S;
	printf("������Ԫ�ظ���:");
	scanf_s("%d", &n);
	Creat(S, n);
	StackTraverse(S);
	StackLength(S);
	GetTop(S, value1);
	Pop(S);
	StackTraverse(S);
	GetTop(S, value1);
	ClearStack(S);
	StackTraverse(S);
	DestoryStack(S);
	return 0;
}
