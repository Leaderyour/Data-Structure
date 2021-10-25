#include<cstdio>
#include<cstdlib> 
#define ElemType int 
#define LIST_INIT_SIZE	100		//存储空间的初始分配量 
#define LISTINCREMENT 	10		//存储空间的分配量增值 
#define Status int 

using namespace std;
//顺序表的结构 (存储元素的数组和长度)
typedef struct {
	ElemType* elem;		//存储空间基址 
	int length;		//当前长度 
	int listsize;	 //当前分配的存储量 (单位是sizeof(ElemType)) 
}SqList;

//初始化顺序表，构造一个空的顺序表
Status InitList_Sq(SqList& L) {
	//申请动态内存 
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)		//内存分配失败 
		exit(0);
	L.length = 0;		//空表的长度为0
	L.listsize = LIST_INIT_SIZE;	//初始存储容量
	printf("初始化成功\n");
	return 0;
}

//创建顺序表
void CreatList_Sq(SqList& L, int n) {
	InitList_Sq(L);
	if (n >= L.listsize) {
		int* newBase = (ElemType*)realloc(L.elem, (n) * sizeof(ElemType));
		if (!newBase) {
			//内存分配失败 
			printf("新内存分配失败\n");
		}
		L.elem = newBase;		//新基址 
		L.listsize = n;	//增加存储容量 
	}
	int* q;
	q = L.elem;		//q为初始位置
	for (int i = 1; i <= n; i++) {
		int e;
		scanf_s("%d", &e);
		printf("添加元素：%d 成功\n", e);
		*q = e;	//添加e
		q++;
		L.length++;
	}
}

//插入函数 L中第i个位置之前插入新的元素e  
Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	int* newBase, * q, * p;
	// i的合法值为1~length+1
	if (i < 1 || i > L.length + 1) {
		printf("插入位置不合法，请保证位置在1~length+1之间\n");
		return 0;
	}
	//当前存储空间已满，增加分配 
	if (L.length >= L.listsize) {
		newBase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newBase) {		//内存分配失败 
			printf("新内存分配失败\n");
			return 0;
		}
		L.elem = newBase;		//新基址 
		L.listsize += LISTINCREMENT;	//增加存储容量 
	}
	q = &(L.elem[i - 1]);		//q为插入位置
	for (p = &(L.elem[L.length - 1]); p >= q; p--) {
		*(p + 1) = *p;		//插入位置和其之后的值右移 
	}
	*q = e;	//插入e
	L.length++;
	printf("插入元素：%d 成功\n", e);
	return 0;
}

//创建顺序表  初始化n个数据		(利用插入元素) 
Status ListCreat_Sq(SqList& L, int n) {
	for (int i = 1; i <= n; i++) {
		printf("请输入第%d个数：", i);
		int a;
		scanf_s("%d", &a);
		ListInsert_Sq(L, i, a);
	}
	printf("创建成功\n");
	return 0;
}

//判断顺序表是否为空
bool ListEmpty_Sq(SqList L) {
	if (L.length == 0) {
		printf("顺序表为空\n");
		return true;
	}
	else {
		printf("顺序表不为空\n");
		return false;
	}
}

//返回顺序表的长度
Status ListLength_Sq(SqList L) {
	return L.length;
}

//删除顺序表	在L上删除第i个元素并用e返回其值 
Status ListDelete_Sq(SqList& L, int i, ElemType& e) {
	int* p, * q;
	// i的合法值为1~length
	if (i < 1 || i > L.length) {
		printf("插入位置不合法，请保证位置在1~length之间\n");
		return 0;
	}
	p = &(L.elem[i - 1]);		//p为被删除元素的位置 
	e = *p;		//将p的值赋给e 
	q = L.elem + L.length - 1;		//表尾元素的位置
	for (p += 1; p <= q; p++) {
		*(p - 1) = *p;	//被删除元素之后的元素左移 
	}
	printf("删除元素:%d 成功\n", e);
	L.length--;		//表长减一 
	return e;
}

//返回L中第i个元素的值
Status GetList_Sq(SqList& L, int i, ElemType e) {
	int* q;
	// i的合法值为1~length
	if (i < 1 || i > L.length) {
		printf("插入位置不合法，请保证位置在1~length之间\n");
		return 0;
	}
	q = &(L.elem[i - 1]);
	e = *q;
	printf("第%d个元素值为%d\n", i, e);
	return e;
}

//查找L中第一个等于e的元素位序 
Status LocateElem_Sq(SqList L, ElemType e) {
	//若找到，则返回其的位序，否则返回0
	int i = 1;		//i的初始值为第一个元素的位序 1
	int* p;			//定义p，初值为第一个元素的位置，即起始位置 
	p = L.elem;
	while (i <= L.length && *p != e) {		//当i在范围内并且p不等于e，循环 
		i++;
		*p++;
	}
	if (i <= L.length) {
		printf("次序为%d\n", i);
		return i;
	}
	else {
		printf("没有找到符合要求的数");
		return 0;
	}
}
//遍历顺序表 
void ListTraverse_Sq(SqList L) {
	printf("遍历开始：\n");
	int* p;
	p = L.elem;
	for (int i = 1; i <= L.length; i++) {
		printf("%d ", *p);
		*p++;
	}
	printf("\n");
}

//置空	将顺序表L置为空表 
Status ClearEmpty_Sq(SqList& L) {
	//将长度置为空即可 
	if (L.length > 0)
		L.length = 0;
	printf("置空操作成功\n");
	return 0;
}

//销毁线性表
Status DestoryList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	printf("顺序表销毁成功\n");
	return 0;
}

//查找前驱	cur_e不能是第一个元素 
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType pre_e) {
	printf("查找%d的前驱\n", cur_e);
	int* p;
	p = L.elem;
	if (cur_e == *p) {
		printf("错误，第一个元素没有前驱\n");
	}
	for (int i = 2; i <= L.length; i++) {
		pre_e = *p;
		*p++;
		if (cur_e == *p) {
			printf("%d的前驱是%d\n", cur_e, pre_e);
			break;
		}
	}
	return 0;
}

//查找后继元素  cur_e不是最后一个元素
Status NextElem_Sq(SqList& L, ElemType cur_e, ElemType next_e) {
	printf("查找%d的后继\n", cur_e);
	int* p;
	p = &(L.elem[L.length - 1]);
	if (cur_e == *p) {
		printf("错误，最后一个元素没有后继\n");
	}
	for (; p > L.elem;) {
		next_e = *p;
		*p--;
		if (*p == cur_e) {
			printf("%d的后继是%d\n", cur_e, next_e);
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
	printf("请输入元素个数：");
	scanf_s("%d", &n);
	//	ListCreat_Sq(L,n);
	CreatList_Sq(L, n);
	ListTraverse_Sq(L);
	ListEmpty_Sq(L);
	printf("请输入查询元素所在的位置（返回其值）：");
	scanf_s("%d", &o);
	GetList_Sq(L, o, value2);
	printf("请输入查找元素的值：");
	scanf_s("%d", &l);
	LocateElem_Sq(L, l);
	printf("请输入查找的元素值（返回其前驱）：");
	scanf_s("%d", &k);
	PriorElem_Sq(L, k, value3);
	printf("请输入查找的元素值（返回其后继）：");
	scanf_s("%d", &j);
	NextElem_Sq(L, j, value4);
	printf("请输入需要插入的元素位置和其值：");
	scanf_s("%d%d", &z, &value5);
	ListInsert_Sq(L, z, value5);
	ListTraverse_Sq(L);
	printf("请输入删除元素所在的位置：");
	scanf_s("%d", &m);
	ListDelete_Sq(L, m, value1);
	ListTraverse_Sq(L);
	ClearEmpty_Sq(L);
	DestoryList(L);
	return 0;
}