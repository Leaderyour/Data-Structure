#include<cstdio>
#include<cstdlib> 
#define MAXSIZE 1000	//链表的最大长度 
#define SElemType int 
#define Status int 
//栈的结构
typedef struct LStack {
	SElemType data;		//数据域
	struct LStack* next;	//指针域 
}LStack, * LStackList;

//初始化
Status InitStack(LStackList& S) {
	S = new LStack;
	S->next = NULL;
	return 0;
}

//入栈
Status Push(LStackList& S, SElemType e) {
	LStackList p = new LStack;		//生成新的结点 
	p->data = e;	//新结点的数据域赋值 
	p->next = S;	//新结点的指针域指向头结点（栈顶） 
	S = p;	//链表的表头更新为新插入的元素； 
	printf("压入栈成功\n");
	return 0;
}

//出栈
Status Pop(LStackList& S) {
	if (S->next) {
		LStackList p = S;
		S = S->next;	//头指针后移 
		free(p);
		printf("出栈成功\n");
	}
	else {
		printf("栈空\n");
	}
	return 1;
}

//创建栈，就是重复的将元素入栈（当然也可以单独写一个创建的函数）
void Creat(LStackList& S, int n) {
	InitStack(S);
	for (int i = 0; i < n; i++) {
		int e;
		scanf_s("%d", &e);
		Push(S, e);
	}
	printf("创建成功\n");
}

//遍历，因为是从栈顶（表头）开始的遍历，所以输出的列表是逆序的 
Status StackTraverse(LStackList S) {
	printf("遍历开始：\n");
	LStackList p = S;
	/**
	注意：最后一个链表是没有元素的
	*/
	while (p->next) {		//最后一个链表是没有元素的 
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return 1;
}

//获取栈的元素个数 
Status StackLength(LStackList S) {
	LStackList p = S;
	int count = 0;
	while (p) {
		p = p->next;
		count++;
	}
	printf("栈内元素个数为：%d\n", count);
	return 1;
}

//判断栈空
bool StackEmpty(LStackList S) {
	if (S->next == NULL) {
		printf("栈空\n");
		return true;
	}
	else {
		printf("栈非空\n");
		return false;
	}
}

//获取栈顶元素
Status GetTop(LStackList S, SElemType e) {
	//判断栈空 
	if (StackEmpty(S)) {
		return 0;
	}
	else {
		e = S->data;
		printf("栈顶元素为%d\n", e);
		return 0;
	}
}

//栈置空
Status ClearStack(LStackList& S) {
	if (S->next != NULL)
		S->next = NULL;
	printf("置空操作成功\n");
	return 0;
}

//销毁链表
Status DestoryStack(LStackList& S) {
	//判断是否为空表 
	LStackList p = S;
	LStackList pre = new LStack;
	while (p->next) {
		pre = p;
		p = p->next;
		delete(pre);
	}
	printf("销毁链表成功\n");
	return 0;
}


int main() {
	int n, value1, value2;
	value1 = 0;
	value2 = 0;
	LStackList S;
	printf("请输入元素个数:");
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
