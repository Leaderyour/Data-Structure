#include<cstdio>
#include<cstdlib> 
#define SElemType int 
#define Status int 
#define STACK_INIT_SIZE 100	//初始空间分配量
#define STACKINCREMENT	10		//存储空间分配增量 

using namespace std;
//栈的结构
typedef struct {
	SElemType* base;	//栈底指针，在栈结构不存在(构造之前和销毁之后),base的值为NULL
	SElemType* top;		//栈顶指针，非空栈的栈顶指针始终在栈顶元素的的下一个位置上 
	int stacksize;		//可存储的最大容量，即最多存储的元素个数 
}SqStack;

//初始化栈
/**
说明，这里使用C语言的malloc和realloc
除此之外，还可以使用c++的new运算符(	S.base = new SElemType[MAXSIZE];)
但是，new运算符在给定一个定长数组初始化后，长度变不能改变(c++没有realloc函数)
改进有两个方法，
(1)、在初始化时，使用vector变长数组代替数组
(2)、新建一个更大的数组，将原有的元素复制过去(realloc就是这个原理)
*/
Status InitStack(SqStack& S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) {	//动态空间分配失败
		printf("动态空间分配失败\n");
		return 0;
	}
	S.top = S.base;	//栈顶指针初值指向栈底，即top=base表示空栈
	S.stacksize = STACK_INIT_SIZE;		//标记空间大小
	printf("初始化成功\n");
	return 0;
}

//入栈
Status Push(SqStack& S, SElemType e) {
	//判断栈是否满；
	if (S.top - S.base >= S.stacksize) {	//栈满，追加 
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) {
			printf("动态空间分配失败\n");
			return 0;
		}
		S.top = S.base + S.stacksize;		//更新栈顶元素指针
		S.stacksize += STACKINCREMENT;	//更新最大容量 
	}
	*S.top++ = e;	//插入到栈顶并将栈顶指针加一
	printf("插入成功\n");
	return 0;
}

//创建栈，就是重复的将元素入栈（当然也可以单独写一个创建的函数）
void Creat(SqStack& S, int n) {
	InitStack(S);
	for (int i = 0; i < n; i++) {
		int e;
		scanf_s("%d", &e);
		Push(S, e);
	}
	printf("创建成功\n");
}

//获取元素个数
Status StackLength(SqStack S) {
	int count = S.top - S.base;
	return count;
}
//判断栈空
bool StackEmpty(SqStack S) {
	if (S.base == S.top) {
		printf("栈为空\n");
		return true;
	}
	else {
		printf("栈不为空\n");
		return false;
	}
}

//获取栈顶元素
Status GetTop(SqStack S, SElemType e) {
	//若栈不为空
	if (!StackEmpty(S)) {
		e = *(S.top - 1);
		printf("栈顶元素值为：%d\n", e);
	}
	return 0;
}

//出栈
Status Pop(SqStack& S, SElemType e) {
	//判断栈空 
	if (!StackEmpty(S)) {
		e = *--S.top;
		printf("栈顶元素%d出栈成功\n", e);
	}
	return 0;
}

//遍历--从栈底到栈顶的元素输出
Status StackTraverse(SqStack S) {
	printf("遍历开始：\n");
	for (SElemType* i = S.base; i < S.top; i++) {	//从底部开始，到栈顶的前一个停止 
		printf("%d ", *i);
	}
	printf("\n");
	return 1;
}

//置空
Status ClearStack(SqStack& S) {
	S.top = S.base;		//不能写成S.base = S.top;    位置不能反了 
	printf("置空成功\n");
	return 0;
}

//销毁
Status DestoryStack(SqStack& S) {
	free(S.base);	//销毁连续空间 
	S.base = NULL;	//底指针指针赋空
	S.top = NULL;	//栈栈顶指针赋空 
	S.stacksize = 0;	//栈最大容量置为0 
	printf("销毁成功");
	return 0;
}

int main() {
	int n, value1, value2;
	value1 = 0;
	value2 = 0;
	SqStack S;
	printf("请输入元素个数");
	scanf_s("%d", &n);
	Creat(S, n);
	printf("栈中元素的个数为%d\n", StackLength(S));
	Pop(S, value2);
	GetTop(S, value1);
	StackTraverse(S);
	ClearStack(S);
	StackEmpty(S);
	DestoryStack(S);
	return 0;
}
