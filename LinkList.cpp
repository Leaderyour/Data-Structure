#include<cstdio>
#include<cstdlib> 
#define ElemType int 
#define Status int 

using namespace std;
//����Ľṹ ���������ָ����
typedef struct LNode {
	ElemType data;		//������
	struct LNode* next;		//ָ���� 
}LNode, * LinkList;

//��ʼ��
Status InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return 0;
}

//�������� (����) 
void CreatList_RL(LinkList& L, int n) {
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	InitList(L);	//��ʼ������ 
	for (int i = 0; i < n; i++) {	//ѭ������Ԫ�ص�ֵ (����) 
		LinkList p = new LNode;		//�½�һ����� 
		scanf_s("%d", &p->data);	//����Ԫ��ֵ 
		p->next = L->next; 		//����ǰ����ָ��������Ϊͷ����ָ����
		L->next = p;		//��Ԫ�ز嵽��ͷ 
	}
	printf("�½�����ɹ�\n");
}

//�������� (����) 
void CreatList_PL(LinkList& L, int n) {
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	InitList(L);	//��ʼ������ 
	LinkList pre = L;	//�½�ǰ����㲢��ֵΪͷ��� 
	for (int i = 0; i < n; i++) {	//ѭ������Ԫ�ص�ֵ (����) 
		LinkList p = new LNode;		//�½�һ����ǰ��� 
		scanf_s("%d", &p->data);	//����Ԫ��ֵ 
		p->next = NULL;		//�½�����ָ����Ϊ�� 
		pre->next = p;	//ǰ������ָ����Ϊ��ǰ�½��Ľ��ĵ�ַ������������������ 
		pre = p; 	//��pre��Ϊp����Ϊ��һ������ǰ����� 
	}
	printf("�½�����ɹ�\n");
}

//��������
void ListTraverse_L(LinkList L) {
	printf("��ʼ��������:\n");
	LinkList p = L->next;	//�½����p����ö��Ԫ�أ�ָ���һ����㣩 
	while (p != NULL) {		//��Ԫ�ش��� 
		printf("%d ", p->data);		//��ȡ�����򲢴�ӡ 
		p = p->next;		//������ 
	}
	printf("\n");
}

//��ȡ������
void ListLength_L(LinkList L) {
	int count = 0;
	LinkList p = L->next;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	printf("������Ϊ%d\n", count);
}

//��ȡ��i��Ԫ�ص�ָ����
Status GetElem_L(LinkList L, int i, ElemType e) {
	LinkList p = L->next;	//��ʼ����p����ָ���һ�����
	int j = 1;		//������
	while (p && j < i) {	//�ָ������ѯ��ֱ��pָ���i��Ԫ�ػ���pΪ�� 
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		printf("Ԫ�ز�����\n");
		return 0;
	}
	e = p->data;
	printf("��%d��Ԫ��ֵΪ%d\n", i, e);
	return 0;
}

//����L�е�һ������e��Ԫ��λ��
Status LocateElem_L(LinkList L, ElemType e) {
	LinkList p = L->next;	//��ʼ����p����ָ���һ�����
	int j = 1;		//���ڱ��λ�� 
	int flag = 0;		//���ڱ���Ƿ���ҵ� 
	while (p != NULL) {
		if (p->data == e) {
			flag = 1;
			break;
		}
		p = p->next;
		j++;
	}
	if (flag) {
		printf("Ԫ��%d��λ��Ϊ%d\n", e, j);
	}
	else {
		printf("û���ҵ���Ԫ��\n");
	}
	return 0;
}

//����ǰ��	cur_e�����ǵ�һ��Ԫ�� 
Status PriorElem_L(LinkList L, ElemType cur_e, ElemType pre_e) {
	printf("����%d��ǰ��\n", cur_e);
	LinkList p = L->next;		//��ʼ����p����ָ���һ�����
	if (p->data == cur_e) {
		printf("��һ��Ԫ��û��ǰ�����\n");
		return 0;
	}
	while (p && p->data != cur_e) {
		pre_e = p->data;
		p = p->next;
	}
	printf("%d��ǰ����%d\n", cur_e, pre_e);
	return 0;
}

//���Һ��Ԫ��  cur_e�������һ��Ԫ��
Status NextElem_L(LinkList L, ElemType cur_e, ElemType next_e) {
	printf("����%d�ĺ��\n", cur_e);
	LinkList p = L->next;		//��ʼ����p����ָ���һ�����
	while (p && p->data != cur_e) {
		p = p->next;
	}
	if (p->next == NULL) {
		printf("���һ��Ԫ��û�к�̽��\n");
	}
	else {
		next_e = p->next->data;
		printf("%d�ĺ����%d\n", cur_e, next_e);
	}
	return 0;
}

//���룬������L�е�iλ�ò���Ԫ��e
Status ListInsert_L(LinkList& L, int i, ElemType e) {
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1) {		//Ѱ��i��ǰһ����㣨��i-1����㣩 
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) {		//iС��1���ߴ��ڱ�+1 
		printf("���󣬲���λ�ò���ȷ\n");
		return 0;
	}
	LinkList s = new LNode;		//�����½�����ڲ��� 
	s->data = e;		//�½��ָ����ֵ 
	s->next = p->next;		//���� 
	p->next = s;
	printf("����ɹ�\n");
	ListTraverse_L(L); 		//�������� 
	return 0;
}

//ɾ������L��ɾ����i��Ԫ�ز���e������ֵ 
Status ListDelete_L(LinkList& L, int i, ElemType e) {
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1) {		//Ѱ��i��ǰһ����㣨��i-1����㣩 
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1) {
		printf("����ɾ��λ�ò���ȷ\n");
		return 0;
	}
	LinkList q = p->next;	//�½���㣬����Ҫɾ����Ԫ��
	p->next = q->next;		//ɾ�����Ͽ���ǰ������� 
	e = q->data;
	delete(q);
	printf("ɾ����Ԫ��Ϊ%d\n", e);
	ListTraverse_L(L); 		//�������� 
	return 0;
}

//�ÿ�	��˳���L��Ϊ�ձ� 
Status ClearEmpty_L(LinkList& L) {
	//��ͷ������һ�����������NULL���� 
	if (L->next != NULL)
		L->next = NULL;
	printf("�ÿղ����ɹ�\n");
	return 0;
}

//�ж������Ƿ�Ϊ��
bool ListEmpty_L(LinkList L) {
	if (L->next == NULL) {
		printf("����Ϊ��\n");
		return true;
	}
	else {
		printf("����Ϊ��\n");
		return false;
	}
}

//��������
Status DestoryList_L(LinkList& L) {
	//�ж��Ƿ�Ϊ�ձ� 
	LinkList p = L;
	LinkList pre = new LNode;
	while (p) {
		pre = p;
		p = p->next;
		delete(pre);
	}
	printf("��������ɹ�\n");
	return 0;
}


int main() {
	int n, a, b, c, d, e, f, g, value1, value2, value3, value4;
	value1 = 0;
	value2 = 0;
	value3 = 0;
	value4 = 0;
	LinkList L = new LNode;
	printf("�½�һ����������������Ԫ�ظ�����");
	scanf_s("%d", &n);
	//	CreatList_RL(L,n);
	CreatList_PL(L, n);
	ListTraverse_L(L);
	ListLength_L(L);
	printf("��������Ҫ���ҵ�λ��	");
	scanf_s("%d", &a);
	GetElem_L(L, a, value1);
	printf("��������Ҫ���ҵ�Ԫ�أ�");
	scanf_s("%d", &b);
	LocateElem_L(L, b);
	printf("��������Ҫ���ҵ�Ԫ��(������ǰ��)��");
	scanf_s("%d", &c);
	PriorElem_L(L, c, value2);
	printf("��������Ҫ���ҵ�Ԫ��(��������)��");
	scanf_s("%d", &d);
	NextElem_L(L, d, value3);
	printf("��������Ҫ�����Ԫ��λ�ú���ֵ��");
	scanf_s("%d%d", &e, &f);
	ListInsert_L(L, e, f);
	printf("��������Ҫɾ����Ԫ��λ��(������ֵ)��");
	scanf_s("%d", &g);
	ListDelete_L(L, g, value4);
	ListEmpty_L(L);
	ClearEmpty_L(L);
	ListEmpty_L(L);
	DestoryList_L(L);
	return 0;
}