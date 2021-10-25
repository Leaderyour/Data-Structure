#include<cstdio>
#include<cstdlib> 
#define ElemType int 
#define LIST_INIT_SIZE	100		//�洢�ռ�ĳ�ʼ������ 
#define LISTINCREMENT 	10		//�洢�ռ�ķ�������ֵ 
#define Status int 

using namespace std;
//˳���Ľṹ (�洢Ԫ�ص�����ͳ���)
typedef struct {
	ElemType* elem;		//�洢�ռ��ַ 
	int length;		//��ǰ���� 
	int listsize;	 //��ǰ����Ĵ洢�� (��λ��sizeof(ElemType)) 
}SqList;

//��ʼ��˳�������һ���յ�˳���
Status InitList_Sq(SqList& L) {
	//���붯̬�ڴ� 
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)		//�ڴ����ʧ�� 
		exit(0);
	L.length = 0;		//�ձ�ĳ���Ϊ0
	L.listsize = LIST_INIT_SIZE;	//��ʼ�洢����
	printf("��ʼ���ɹ�\n");
	return 0;
}

//����˳���
void CreatList_Sq(SqList& L, int n) {
	InitList_Sq(L);
	if (n >= L.listsize) {
		int* newBase = (ElemType*)realloc(L.elem, (n) * sizeof(ElemType));
		if (!newBase) {
			//�ڴ����ʧ�� 
			printf("���ڴ����ʧ��\n");
		}
		L.elem = newBase;		//�»�ַ 
		L.listsize = n;	//���Ӵ洢���� 
	}
	int* q;
	q = L.elem;		//qΪ��ʼλ��
	for (int i = 1; i <= n; i++) {
		int e;
		scanf_s("%d", &e);
		printf("���Ԫ�أ�%d �ɹ�\n", e);
		*q = e;	//���e
		q++;
		L.length++;
	}
}

//���뺯�� L�е�i��λ��֮ǰ�����µ�Ԫ��e  
Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	int* newBase, * q, * p;
	// i�ĺϷ�ֵΪ1~length+1
	if (i < 1 || i > L.length + 1) {
		printf("����λ�ò��Ϸ����뱣֤λ����1~length+1֮��\n");
		return 0;
	}
	//��ǰ�洢�ռ����������ӷ��� 
	if (L.length >= L.listsize) {
		newBase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newBase) {		//�ڴ����ʧ�� 
			printf("���ڴ����ʧ��\n");
			return 0;
		}
		L.elem = newBase;		//�»�ַ 
		L.listsize += LISTINCREMENT;	//���Ӵ洢���� 
	}
	q = &(L.elem[i - 1]);		//qΪ����λ��
	for (p = &(L.elem[L.length - 1]); p >= q; p--) {
		*(p + 1) = *p;		//����λ�ú���֮���ֵ���� 
	}
	*q = e;	//����e
	L.length++;
	printf("����Ԫ�أ�%d �ɹ�\n", e);
	return 0;
}

//����˳���  ��ʼ��n������		(���ò���Ԫ��) 
Status ListCreat_Sq(SqList& L, int n) {
	for (int i = 1; i <= n; i++) {
		printf("�������%d������", i);
		int a;
		scanf_s("%d", &a);
		ListInsert_Sq(L, i, a);
	}
	printf("�����ɹ�\n");
	return 0;
}

//�ж�˳����Ƿ�Ϊ��
bool ListEmpty_Sq(SqList L) {
	if (L.length == 0) {
		printf("˳���Ϊ��\n");
		return true;
	}
	else {
		printf("˳���Ϊ��\n");
		return false;
	}
}

//����˳���ĳ���
Status ListLength_Sq(SqList L) {
	return L.length;
}

//ɾ��˳���	��L��ɾ����i��Ԫ�ز���e������ֵ 
Status ListDelete_Sq(SqList& L, int i, ElemType& e) {
	int* p, * q;
	// i�ĺϷ�ֵΪ1~length
	if (i < 1 || i > L.length) {
		printf("����λ�ò��Ϸ����뱣֤λ����1~length֮��\n");
		return 0;
	}
	p = &(L.elem[i - 1]);		//pΪ��ɾ��Ԫ�ص�λ�� 
	e = *p;		//��p��ֵ����e 
	q = L.elem + L.length - 1;		//��βԪ�ص�λ��
	for (p += 1; p <= q; p++) {
		*(p - 1) = *p;	//��ɾ��Ԫ��֮���Ԫ������ 
	}
	printf("ɾ��Ԫ��:%d �ɹ�\n", e);
	L.length--;		//����һ 
	return e;
}

//����L�е�i��Ԫ�ص�ֵ
Status GetList_Sq(SqList& L, int i, ElemType e) {
	int* q;
	// i�ĺϷ�ֵΪ1~length
	if (i < 1 || i > L.length) {
		printf("����λ�ò��Ϸ����뱣֤λ����1~length֮��\n");
		return 0;
	}
	q = &(L.elem[i - 1]);
	e = *q;
	printf("��%d��Ԫ��ֵΪ%d\n", i, e);
	return e;
}

//����L�е�һ������e��Ԫ��λ�� 
Status LocateElem_Sq(SqList L, ElemType e) {
	//���ҵ����򷵻����λ�򣬷��򷵻�0
	int i = 1;		//i�ĳ�ʼֵΪ��һ��Ԫ�ص�λ�� 1
	int* p;			//����p����ֵΪ��һ��Ԫ�ص�λ�ã�����ʼλ�� 
	p = L.elem;
	while (i <= L.length && *p != e) {		//��i�ڷ�Χ�ڲ���p������e��ѭ�� 
		i++;
		*p++;
	}
	if (i <= L.length) {
		printf("����Ϊ%d\n", i);
		return i;
	}
	else {
		printf("û���ҵ�����Ҫ�����");
		return 0;
	}
}
//����˳��� 
void ListTraverse_Sq(SqList L) {
	printf("������ʼ��\n");
	int* p;
	p = L.elem;
	for (int i = 1; i <= L.length; i++) {
		printf("%d ", *p);
		*p++;
	}
	printf("\n");
}

//�ÿ�	��˳���L��Ϊ�ձ� 
Status ClearEmpty_Sq(SqList& L) {
	//��������Ϊ�ռ��� 
	if (L.length > 0)
		L.length = 0;
	printf("�ÿղ����ɹ�\n");
	return 0;
}

//�������Ա�
Status DestoryList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	printf("˳������ٳɹ�\n");
	return 0;
}

//����ǰ��	cur_e�����ǵ�һ��Ԫ�� 
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType pre_e) {
	printf("����%d��ǰ��\n", cur_e);
	int* p;
	p = L.elem;
	if (cur_e == *p) {
		printf("���󣬵�һ��Ԫ��û��ǰ��\n");
	}
	for (int i = 2; i <= L.length; i++) {
		pre_e = *p;
		*p++;
		if (cur_e == *p) {
			printf("%d��ǰ����%d\n", cur_e, pre_e);
			break;
		}
	}
	return 0;
}

//���Һ��Ԫ��  cur_e�������һ��Ԫ��
Status NextElem_Sq(SqList& L, ElemType cur_e, ElemType next_e) {
	printf("����%d�ĺ��\n", cur_e);
	int* p;
	p = &(L.elem[L.length - 1]);
	if (cur_e == *p) {
		printf("�������һ��Ԫ��û�к��\n");
	}
	for (; p > L.elem;) {
		next_e = *p;
		*p--;
		if (*p == cur_e) {
			printf("%d�ĺ����%d\n", cur_e, next_e);
			break;
		}
	}
	return 0;
}

int main() {
	SqList L;
	InitList_Sq(L);
	int n, m, o, l, k, j, z, value1, value2, value3, value4, value5;
	value2 = 0;
	value3 = 0;
	value4 = 0;
	value5 = 0;
	printf("������Ԫ�ظ�����");
	scanf_s("%d", &n);
	//	ListCreat_Sq(L,n);
	CreatList_Sq(L, n);
	ListTraverse_Sq(L);
	ListEmpty_Sq(L);
	printf("�������ѯԪ�����ڵ�λ�ã�������ֵ����");
	scanf_s("%d", &o);
	GetList_Sq(L, o, value2);
	printf("���������Ԫ�ص�ֵ��");
	scanf_s("%d", &l);
	LocateElem_Sq(L, l);
	printf("��������ҵ�Ԫ��ֵ��������ǰ������");
	scanf_s("%d", &k);
	PriorElem_Sq(L, k, value3);
	printf("��������ҵ�Ԫ��ֵ���������̣���");
	scanf_s("%d", &j);
	NextElem_Sq(L, j, value4);
	printf("��������Ҫ�����Ԫ��λ�ú���ֵ��");
	scanf_s("%d%d", &z, &value5);
	ListInsert_Sq(L, z, value5);
	ListTraverse_Sq(L);
	printf("������ɾ��Ԫ�����ڵ�λ�ã�");
	scanf_s("%d", &m);
	ListDelete_Sq(L, m, value1);
	ListTraverse_Sq(L);
	ClearEmpty_Sq(L);
	DestoryList(L);
	return 0;
}