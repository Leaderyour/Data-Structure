#include<cstdio>
#include<cstdlib> 
#define SElemType int 
#define Status int 
#define STACK_INIT_SIZE 100	//��ʼ�ռ������
#define STACKINCREMENT	10		//�洢�ռ�������� 

using namespace std;
//ջ�Ľṹ
typedef struct {
	SElemType* base;	//ջ��ָ�룬��ջ�ṹ������(����֮ǰ������֮��),base��ֵΪNULL
	SElemType* top;		//ջ��ָ�룬�ǿ�ջ��ջ��ָ��ʼ����ջ��Ԫ�صĵ���һ��λ���� 
	int stacksize;		//�ɴ洢����������������洢��Ԫ�ظ��� 
}SqStack;

//��ʼ��ջ
/**
˵��������ʹ��C���Ե�malloc��realloc
����֮�⣬������ʹ��c++��new�����(	S.base = new SElemType[MAXSIZE];)
���ǣ�new������ڸ���һ�����������ʼ���󣬳��ȱ䲻�ܸı�(c++û��realloc����)
�Ľ�������������
(1)���ڳ�ʼ��ʱ��ʹ��vector�䳤�����������
(2)���½�һ����������飬��ԭ�е�Ԫ�ظ��ƹ�ȥ(realloc�������ԭ��)
*/
Status InitStack(SqStack& S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) {	//��̬�ռ����ʧ��
		printf("��̬�ռ����ʧ��\n");
		return 0;
	}
	S.top = S.base;	//ջ��ָ���ֵָ��ջ�ף���top=base��ʾ��ջ
	S.stacksize = STACK_INIT_SIZE;		//��ǿռ��С
	printf("��ʼ���ɹ�\n");
	return 0;
}

//��ջ
Status Push(SqStack& S, SElemType e) {
	//�ж�ջ�Ƿ�����
	if (S.top - S.base >= S.stacksize) {	//ջ����׷�� 
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) {
			printf("��̬�ռ����ʧ��\n");
			return 0;
		}
		S.top = S.base + S.stacksize;		//����ջ��Ԫ��ָ��
		S.stacksize += STACKINCREMENT;	//����������� 
	}
	*S.top++ = e;	//���뵽ջ������ջ��ָ���һ
	printf("����ɹ�\n");
	return 0;
}

//����ջ�������ظ��Ľ�Ԫ����ջ����ȻҲ���Ե���дһ�������ĺ�����
void Creat(SqStack& S, int n) {
	InitStack(S);
	for (int i = 0; i < n; i++) {
		int e;
		scanf_s("%d", &e);
		Push(S, e);
	}
	printf("�����ɹ�\n");
}

//��ȡԪ�ظ���
Status StackLength(SqStack S) {
	int count = S.top - S.base;
	return count;
}
//�ж�ջ��
bool StackEmpty(SqStack S) {
	if (S.base == S.top) {
		printf("ջΪ��\n");
		return true;
	}
	else {
		printf("ջ��Ϊ��\n");
		return false;
	}
}

//��ȡջ��Ԫ��
Status GetTop(SqStack S, SElemType e) {
	//��ջ��Ϊ��
	if (!StackEmpty(S)) {
		e = *(S.top - 1);
		printf("ջ��Ԫ��ֵΪ��%d\n", e);
	}
	return 0;
}

//��ջ
Status Pop(SqStack& S, SElemType e) {
	//�ж�ջ�� 
	if (!StackEmpty(S)) {
		e = *--S.top;
		printf("ջ��Ԫ��%d��ջ�ɹ�\n", e);
	}
	return 0;
}

//����--��ջ�׵�ջ����Ԫ�����
Status StackTraverse(SqStack S) {
	printf("������ʼ��\n");
	for (SElemType* i = S.base; i < S.top; i++) {	//�ӵײ���ʼ����ջ����ǰһ��ֹͣ 
		printf("%d ", *i);
	}
	printf("\n");
	return 1;
}

//�ÿ�
Status ClearStack(SqStack& S) {
	S.top = S.base;		//����д��S.base = S.top;    λ�ò��ܷ��� 
	printf("�ÿճɹ�\n");
	return 0;
}

//����
Status DestoryStack(SqStack& S) {
	free(S.base);	//���������ռ� 
	S.base = NULL;	//��ָ��ָ�븳��
	S.top = NULL;	//ջջ��ָ�븳�� 
	S.stacksize = 0;	//ջ���������Ϊ0 
	printf("���ٳɹ�");
	return 0;
}

int main() {
	int n, value1, value2;
	value1 = 0;
	value2 = 0;
	SqStack S;
	printf("������Ԫ�ظ���");
	scanf_s("%d", &n);
	Creat(S, n);
	printf("ջ��Ԫ�صĸ���Ϊ%d\n", StackLength(S));
	Pop(S, value2);
	GetTop(S, value1);
	StackTraverse(S);
	ClearStack(S);
	StackEmpty(S);
	DestoryStack(S);
	return 0;
}
