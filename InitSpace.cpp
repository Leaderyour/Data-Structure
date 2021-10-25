#include<cstdio>
#include<cstdlib> 
#define MAXSIZE 1000	//�������󳤶� 
#define ElemType int 
#define Status int 

using namespace std;
//��̬����Ľṹ���������α꣩ 
typedef struct {
	ElemType data;		//������ 
	int cur;	//�α������ָ����
}component, SLinkList[MAXSIZE];

//���������б� 
void InitSpace_SL(SLinkList& space) {
	//��һά����space�з�������һ�����ñ�������space[0].cur Ϊ����ͷָ��
	//��0����ʾ��ָ��
	for (int i = 0; i < MAXSIZE - 1; i++) {
		space[i].cur = i + 1;		//��ÿ������������ӵ�һ�� 
	}
	//���һ��ָ��Ϊ0
	space[MAXSIZE - 1].cur = 0;
}

//��ȡ����ռ䣨����һ�����н�㣩  
int Malloc_SL(SLinkList& space) {
	//�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

//�ͷſ��н��
void Free_SL(SLinkList& space, int k) {
	//���±�Ϊk�Ŀ��н����յ���������
	space[k].cur = space[0].cur;	//���ս��ġ��αꡱָ���������ͷ���֮��ڵ㣨����һ����㣩 
	space[0].cur = k; 	//���������ͷ���ָ���»��յĽ�� 
}

//������̬�������ϵģ����Ǳ�����һ�������α�Ϊ0�� 
void CreatList_SL(SLinkList& space, int n) {
	InitSpace_SL(space);	//��ʼ�����ÿռ� 
	int S = MAXSIZE - 1;
	//���������һ����㵱����̬�����Ǳ���������ͷ���
	int r = S;		//rָ��ǰ���������� 
	for (int j = 1; j <= n; j++) {		//�������� 
		int i = Malloc_SL(space);	//������ 
		scanf_s("%d", &space[i].data);		//����Ԫ��ֵ
		space[r].cur = i;		//���뵽��β 
		r = i;		//���±�β 
	}
	space[r].cur = 0;		//β����ָ��Ϊ�� 
	printf("�����ɹ�\n");
}

//��ȡ��̬������ 
int LengthList_SL(SLinkList space) {
	int i = space[MAXSIZE - 1].cur, count = 0;
	while (i) {
		i = space[i].cur;
		count++;
	}
	printf("����Ϊ��%d\n", count);
	return count;
}

//������̬����
void TraverseList_SL(SLinkList space) {
	printf("��������");
	int i = space[MAXSIZE - 1].cur;	//iָ����еĵ�1������λ�� 
	while (i) {		//���� 
		printf("%d ", space[i].data);
		i = space[i].cur;	//ָ����һ��Ԫ��	 
	}
	printf("\n");
}

//�ھ�̬�����в��ҵ�1��ֵΪe��Ԫ��
void LocateElem_SL(SLinkList space, ElemType e) {
	int i = space[MAXSIZE - 1].cur;	//iָ����еĵ�1������λ��	
	int local = 1; 		//��ʼ������Ϊ1 
	while (i && (space[i].data != e)) {		//�������ڲ��������򲻵���e 
		i = space[i].cur;	//ָ����һ��Ԫ�� 
		local++;	//λ���1 
	}
	if (i == 0) {		//���i�Ѿ��������һ��Ԫ�ص��α꣨Ϊ0����˵��ǰ��û�з���Ҫ���Ԫ��ֵ 
		printf("��Ԫ�ز�����\n");
	}
	else {
		printf("��һ��ֵΪ%d��λ��Ϊ��%d\n", e, local);
	}
}

//��e�������Ա��е�i��Ԫ�ص�ֵ
void GetList_SL(SLinkList space, int i) {
	int s = space[MAXSIZE - 1].cur;
	int j = 1;
	while (s && j < i) {
		s = space[s].cur;
		j++;
	}
	if (s == 0) {		//���i�Ѿ��������һ��Ԫ�ص��α꣨Ϊ0����˵��ǰ��û�з���Ҫ���Ԫ��ֵ 
		printf("λ�����\n");
	}
	else {
		printf("��%d��Ԫ�ص�ֵΪ��%d\n", i, space[s].data);
	}
}

//�������
void ClearList_SL(SLinkList& space) {
	int i = space[MAXSIZE - 1].cur;
	while (i) {
		int j = i;
		i = space[i].cur;
		Free_SL(space, j);
	}
	space[MAXSIZE - 1].cur = 0;
	printf("�������ɹ�\n");
}

//��L�е�i��Ԫ��֮ǰ��������Ԫ��e
Status ListInsert_SL(SLinkList& space, int i, ElemType e) {
	if (i<1 || i> LengthList_SL(space) + 1) {	//������λ���Ƿ���ȷ 
		printf("����λ�ô���\n");
		return 0;
	}
	int j = Malloc_SL(space);	//�����½��
	int k = MAXSIZE - 1;
	if (j) {	//����������ɹ� 
		space[j].data = e;	//��ֵ�����
		for (int l = 1; l < i; l++) {	//�ҵ���i-1����� 
			k = space[k].cur;	//ָ����һ����� 
		}
		space[j].cur = space[k].cur;	//�½��ָ���i-1��Ԫ�غ��Ԫ��
		space[k].cur = j;		//��i-1��Ԫ��ָ���½�� 
	}
	printf("����ɹ�\n");
	return 0;
}

//ɾ��L�е�i��Ԫ�أ���������ֵ
Status ListDelete_SL(SLinkList& space, int i, ElemType e) {
	if (i<1 || i> LengthList_SL(space)) {	//������λ���Ƿ���ȷ 
		printf("ɾ��λ�ô���\n");
		return 0;
	}
	int k = MAXSIZE - 1;
	for (int l = 1; l < i; l++) {	//�ҵ���i-1����� 
		k = space[k].cur;	//ָ����һ����� 
	}
	int j = space[k].cur;		//jΪ��ɾ���Ľ��
	space[k].cur = space[j].cur;	//��i-1����ָ�����i+1��ָ������������
	e = space[j].data;		//��ֵe
	Free_SL(space, j);
	printf("ɾ��%d��Ԫ��%d�ɹ�\n", i, e);
	return 0;
}

//����ǰ�� cur_e���ǵ�һ��Ԫ��
Status PriorElem_SL(SLinkList space, ElemType cur_e, ElemType pre_e) {
	int i = space[MAXSIZE - 1].cur;
	if (cur_e == space[i].data) {
		printf("��һ��Ԫ��û��ǰ��\n");
		return 0;
	}
	while (i && cur_e != space[i].data) {
		pre_e = space[i].data;	//��ǰ�������Ϊ��ǰ���
		i = space[i].cur;		//ָ����һ����� 
	}
	if (i == 0) {
		printf("��Ԫ�ز�����\n");
	}
	else {
		printf("%d��ǰ����%d\n", cur_e, pre_e);
	}
	return 0;
}

//���Һ��Ԫ��  cur_e�������һ��Ԫ��
Status NextElem_Sq(SLinkList space, ElemType cur_e, ElemType next_e) {
	int i = space[MAXSIZE - 1].cur;
	int j;	//��j��ǲ��ҵĽ�� 
	while (i && cur_e != space[i].data) {
		i = space[i].cur;		//ָ����һ�����
	}
	if (i == 0) {
		printf("��Ԫ�ز�����\n");
	}
	else {
		i = space[i].cur;
		if (i == 0) {
			printf("���һ��Ԫ��û�к��\n");
		}
		else {
			next_e = space[i].data;
			printf("%d�ĺ����%d\n", cur_e, next_e);
		}
	}
	return 0;
}


//�ж��Ƿ�Ϊ��
bool EmptyList_SL(SLinkList space) {
	if (space[MAXSIZE - 1].cur == 0) {	//�ж��������ͷָ����α��Ƿ�Ϊ0 
		printf("����Ϊ��\n");
		return true;
	}
	else {
		printf("����Ϊ��\n");
		return false;
	}
}

int main() {
	SLinkList space;
	int n, a, b, d, e, f, value1, h, value2, j, value3;
	value1 = 0;
	value2 = 0;
	value3 = 0;
	printf("�����뽨�������Ԫ�ظ���:\n");
	scanf_s("%d", &n);		//��������ĸ��� 
	CreatList_SL(space, n);
	EmptyList_SL(space);
	LengthList_SL(space);
	TraverseList_SL(space);
	printf("��������ҵ�Ԫ��ֵ:");
	scanf_s("%d", &a);		//������ҵ�Ԫ��ֵ
	LocateElem_SL(space, a);
	printf("��������ҵ�λ��:");
	scanf_s("%d", &b);		//������ҵ�λ��
	GetList_SL(space, b);
	printf("����������λ���ֵ:");
	scanf_s("%d%d", &d, &e);		//��������λ���ֵ
	ListInsert_SL(space, d, e);
	TraverseList_SL(space);
	LengthList_SL(space);
	printf("������ɾ����λ��:");
	scanf_s("%d", &f);
	ListDelete_SL(space, f, value1);
	TraverseList_SL(space);
	LengthList_SL(space);
	printf("��������ҵ�Ԫ�أ�������ǰ����:");
	scanf_s("%d", &h);
	PriorElem_SL(space, h, value2);
	printf("��������ҵ�Ԫ�أ��������̣�:");
	scanf_s("%d", &j);
	NextElem_Sq(space, j, value3);
	ClearList_SL(space);
	return 0;
}
