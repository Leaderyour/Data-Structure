#include<cstdio>
#include<cstdlib> 
#define MAXSIZE 1000	//链表的最大长度 
#define ElemType int 
#define Status int 

using namespace std;
//静态链表的结构（数据域、游标） 
typedef struct {
	ElemType data;		//数据域 
	int cur;	//游标域或者指针域
}component, SLinkList[MAXSIZE];

//创建备用列表 
void InitSpace_SL(SLinkList& space) {
	//将一维数组space中分量链成一个备用备用链表，space[0].cur 为备用头指针
	//“0”表示空指针
	for (int i = 0; i < MAXSIZE - 1; i++) {
		space[i].cur = i + 1;		//将每个数组分量链接到一起 
	}
	//最后一个指针为0
	space[MAXSIZE - 1].cur = 0;
}

//提取分配空间（申请一个空闲结点）  
int Malloc_SL(SLinkList& space) {
	//若备用空间链表非空，则返回分配的结点下标，否则返回0
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

//释放空闲结点
void Free_SL(SLinkList& space, int k) {
	//将下标为k的空闲结点回收到备用链表
	space[k].cur = space[0].cur;	//回收结点的“游标”指向备用链表的头结点之后节点（即第一个结点） 
	space[0].cur = k; 	//备用链表的头结点指向新回收的结点 
}

//创建静态链表（书上的，就是标记最后一个结点的游标为0） 
void CreatList_SL(SLinkList& space, int n) {
	InitSpace_SL(space);	//初始化备用空间 
	int S = MAXSIZE - 1;
	//将数组最后一个结点当做静态链表（非备用链表）的头结点
	int r = S;		//r指向当前链表的最后结点 
	for (int j = 1; j <= n; j++) {		//建立链表 
		int i = Malloc_SL(space);	//分配结点 
		scanf_s("%d", &space[i].data);		//输入元素值
		space[r].cur = i;		//插入到表尾 
		r = i;		//更新表尾 
	}
	space[r].cur = 0;		//尾结点的指针为空 
	printf("创建成功\n");
}

//获取静态链表长度 
int LengthList_SL(SLinkList space) {
	int i = space[MAXSIZE - 1].cur, count = 0;
	while (i) {
		i = space[i].cur;
		count++;
	}
	printf("长度为：%d\n", count);
	return count;
}

//遍历静态链表
void TraverseList_SL(SLinkList space) {
	printf("遍历链表：");
	int i = space[MAXSIZE - 1].cur;	//i指向表中的第1个结点的位序 
	while (i) {		//遍历 
		printf("%d ", space[i].data);
		i = space[i].cur;	//指向下一个元素	 
	}
	printf("\n");
}

//在静态链表中查找第1个值为e的元素
void LocateElem_SL(SLinkList space, ElemType e) {
	int i = space[MAXSIZE - 1].cur;	//i指向表中的第1个结点的位序	
	int local = 1; 		//初始化其序为1 
	while (i && (space[i].data != e)) {		//当结点存在并且数据域不等于e 
		i = space[i].cur;	//指向下一个元素 
		local++;	//位序加1 
	}
	if (i == 0) {		//如果i已经到了最后一个元素的游标（为0）则说明前面没有符合要求的元素值 
		printf("该元素不存在\n");
	}
	else {
		printf("第一个值为%d的位序为：%d\n", e, local);
	}
}

//用e返回线性表中第i个元素的值
void GetList_SL(SLinkList space, int i) {
	int s = space[MAXSIZE - 1].cur;
	int j = 1;
	while (s && j < i) {
		s = space[s].cur;
		j++;
	}
	if (s == 0) {		//如果i已经到了最后一个元素的游标（为0）则说明前面没有符合要求的元素值 
		printf("位序错误\n");
	}
	else {
		printf("第%d个元素的值为：%d\n", i, space[s].data);
	}
}

//清空链表
void ClearList_SL(SLinkList& space) {
	int i = space[MAXSIZE - 1].cur;
	while (i) {
		int j = i;
		i = space[i].cur;
		Free_SL(space, j);
	}
	space[MAXSIZE - 1].cur = 0;
	printf("清空链表成功\n");
}

//在L中第i个元素之前插入数据元素e
Status ListInsert_SL(SLinkList& space, int i, ElemType e) {
	if (i<1 || i> LengthList_SL(space) + 1) {	//检查插入位置是否正确 
		printf("插入位置错误\n");
		return 0;
	}
	int j = Malloc_SL(space);	//申请新结点
	int k = MAXSIZE - 1;
	if (j) {	//如果结点申请成功 
		space[j].data = e;	//赋值给结点
		for (int l = 1; l < i; l++) {	//找到第i-1个结点 
			k = space[k].cur;	//指向下一个结点 
		}
		space[j].cur = space[k].cur;	//新结点指向第i-1个元素后的元素
		space[k].cur = j;		//第i-1个元素指向新结点 
	}
	printf("插入成功\n");
	return 0;
}

//删除L中第i个元素，并返回其值
Status ListDelete_SL(SLinkList& space, int i, ElemType e) {
	if (i<1 || i> LengthList_SL(space)) {	//检查插入位置是否正确 
		printf("删除位置错误\n");
		return 0;
	}
	int k = MAXSIZE - 1;
	for (int l = 1; l < i; l++) {	//找到第i-1个结点 
		k = space[k].cur;	//指向下一个结点 
	}
	int j = space[k].cur;		//j为将删除的结点
	space[k].cur = space[j].cur;	//将i-1结点的指针域和i+1的指针域连接起来
	e = space[j].data;		//赋值e
	Free_SL(space, j);
	printf("删除%d个元素%d成功\n", i, e);
	return 0;
}

//查找前驱 cur_e不是第一个元素
Status PriorElem_SL(SLinkList space, ElemType cur_e, ElemType pre_e) {
	int i = space[MAXSIZE - 1].cur;
	if (cur_e == space[i].data) {
		printf("第一个元素没有前驱\n");
		return 0;
	}
	while (i && cur_e != space[i].data) {
		pre_e = space[i].data;	//将前驱结点置为当前结点
		i = space[i].cur;		//指向下一个结点 
	}
	if (i == 0) {
		printf("该元素不存在\n");
	}
	else {
		printf("%d的前驱是%d\n", cur_e, pre_e);
	}
	return 0;
}

//查找后继元素  cur_e不是最后一个元素
Status NextElem_Sq(SLinkList space, ElemType cur_e, ElemType next_e) {
	int i = space[MAXSIZE - 1].cur;
	int j;	//用j标记查找的结点 
	while (i && cur_e != space[i].data) {
		i = space[i].cur;		//指向下一个结点
	}
	if (i == 0) {
		printf("该元素不存在\n");
	}
	else {
		i = space[i].cur;
		if (i == 0) {
			printf("最后一个元素没有后继\n");
		}
		else {
			next_e = space[i].data;
			printf("%d的后继是%d\n", cur_e, next_e);
		}
	}
	return 0;
}


//判断是否为空
bool EmptyList_SL(SLinkList space) {
	if (space[MAXSIZE - 1].cur == 0) {	//判断其链表的头指针的游标是否为0 
		printf("链表为空\n");
		return true;
	}
	else {
		printf("链表不为空\n");
		return false;
	}
}

int main() {
	SLinkList space;
	int n, a, b, d, e, f, value1, h, value2, j, value3;
	value1 = 0;
	value2 = 0;
	value3 = 0;
	printf("请输入建立链表的元素个数:\n");
	scanf_s("%d", &n);		//输入链表的个数 
	CreatList_SL(space, n);
	EmptyList_SL(space);
	LengthList_SL(space);
	TraverseList_SL(space);
	printf("请输入查找的元素值:");
	scanf_s("%d", &a);		//输入查找的元素值
	LocateElem_SL(space, a);
	printf("请输入查找的位序:");
	scanf_s("%d", &b);		//输入查找的位序
	GetList_SL(space, b);
	printf("请输入插入的位序和值:");
	scanf_s("%d%d", &d, &e);		//输入插入的位序和值
	ListInsert_SL(space, d, e);
	TraverseList_SL(space);
	LengthList_SL(space);
	printf("请输入删除的位序:");
	scanf_s("%d", &f);
	ListDelete_SL(space, f, value1);
	TraverseList_SL(space);
	LengthList_SL(space);
	printf("请输入查找的元素（返回其前驱）:");
	scanf_s("%d", &h);
	PriorElem_SL(space, h, value2);
	printf("请输入查找的元素（返回其后继）:");
	scanf_s("%d", &j);
	NextElem_Sq(space, j, value3);
	ClearList_SL(space);
	return 0;
}
