#include<cstdio>
#include<cstdlib>

#define OK 1;
#define ERROR 0; //为和教材内容贴合，OK的值设为1，ERROR的值设为0
#define Status int
#define TElemType int
#define MAX_TREE_SIZE 100//二叉树最大节点数
#define MAXSIZE 1000	//链表的最大长度 
#define SElemType int 
#define STACK_INIT_SIZE 100//定义栈的最大节点数
#define STACKINCREMENT 10 //存储空间分配增量
using namespace std;
typedef TElemType SqBiTree[MAX_TREE_SIZE];
SqBiTree bt;

typedef struct BiTNode {
	TElemType data;		//数据域
	struct BiTNode* lchild, * rchild;//指针域（左右孩子指针）
}BiTNode, *BiTree;
/*------所需要的的栈的存储空间及函数------*/
typedef struct {
	SElemType* base;//栈底指针
	SElemType* top;//栈顶指针
	int stacksize;//栈的长度
}SqStack;
//栈的初始化
Status InitStack(SqStack& S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));//分配存储空间
	if (!S.base) printf("存储分配失败！"); exit(OVERFLOW);
	S.top = S.base;//栈顶=栈底
	S.stacksize = STACK_INIT_SIZE;
	printf("栈初始化成功！");
	return OK;
}
//入栈
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base > S.stacksize) {//判断栈的大小是否够用，不够用的话重新分配存储空间
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
	}
	if (!S.base) printf("存储分配失败！"); exit(OVERFLOW);
	S.top = S.base + S.stacksize;
	S.stacksize += STACKINCREMENT;
	return OK;
}
//出栈
Status Pop(SqStack& S,SElemType &e) {
	if (S.top = S.base) printf("这是一个空栈！"); return 0;
	e = *--S.top;
	printf("出栈成功！");
	return OK;
}
//判断栈空
bool StackEmpty(SqStack S) {
	if (S.top=S.base) {
		printf("栈空\n");
		return true;
	}
	else {
		printf("栈非空\n");
		return false;
	}
}
//获取栈顶元素
Status GetTop(SqStack S, SElemType e) {
	//判断栈空 
	if (StackEmpty(S)) {
		return 0;
	}
	else {
		e = *(S.top - 1);
		printf("栈顶元素为%d\n", e);
		return 0;
	}
	return OK;
}
/*--------------------------------------------------------*/
void visit(BiTree &T) {
	printf("%d", T->data);//输出树的当前节点
}

//二叉树初始化
void InitBiTree(BiTree &T) {
	T->lchild = NULL;
	T->rchild = NULL;
}
//创建二叉树
Status CreateBiTree(BiTree &T) {
	int ch;
	scanf_s("%d", & ch);
	if (ch == ' ') {//出入空格表示当前结束
		T = NULL;
	}
	else {
		if (!(T = (BiTNode * )malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}
Status PrintElement(TElemType e) {
	printf(" ");
	return OK;
}
/*------书中的一种先序遍历方法以及两种中序遍历方法------*/
//先序遍历
Status preOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {

}
// 中序遍历1
Status inOrderTraverse_1(BiTree T, Status(*Visit)(TElemType e)){
	SqStack S;//定义S为SqStack类型的值
	BiTNode p;
	InitStack(S); Push(S, T->data);//初始化栈，并且将T节点入栈
	while (!StackEmpty(S)) {
		while (GetTop(S, T->data) && T) {//取栈顶元素
			Push(S, p->lchild);
		}
		Pop(S, T->data);
		if (!StackEmpty(S)) {
			Pop(S, T->data);
			if (!Visit(T->data)) return 0;
			Push(S, T->lchild);
		}
	}
	return 1;
}
// 中序遍历2
Status inOrderTraverse_2(BiTree T, Status(*Visit)(TElemType e)) {
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, p->data);
			p = p->lchild;
		}
		else {
			Pop(S, p->data); if (!Visit(p->data)) return 0;
			p = p->rchild;
		}
	}
	return 1;
}
/*--------------------------------------------------------*/
//先序遍历
Status PreOrderTraverse(BiTree T) {
	if (T) {
		if (T->data) {
			visit(T);
			PreOrderTraverse(T->lchild);
			PreOrderTraverse(T->rchild);
			return T->data;
		}
		return ERROR;
	}
	else return ERROR;
	return OK;
}
// 中序遍历
Status InOrderTraverse(BiTree T) {
	if (T) {
		if (T->data) {
			InOrderTraverse(T->lchild);
			visit(T);
			InOrderTraverse(T->lchild);
			return T->data;
		}
	}
}
// 后序遍历
Status PostOrderTraverse(BiTree T) {
	if (T) {
		if (T->data) {
			PostOrderTraverse(T->lchild);
			PostOrderTraverse(T->rchild);
			visit(T);
			return T->data;
		}
	}
}
//清空二叉树
Status ClearBiTree(BiTree& T) {
	PreOrderTraverse(T);
	T->lchild = NULL;
	T->rchild = NULL;
}
//销毁二叉树
Status DestroyBiTree(BiTree &T) {
	if (T->data != NULL) {
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->lchild);
		delete T;
	}
	else {
		printf("这本来就是一颗空树！");
	}
	return 1;
}
//判空
bool BiTreeEmpty(BiTree &T) {
	if (T->data == NULL) {
		printf("这是一个空的二叉树！");
		return true;
	}
	else {
		printf("这不是一个空的二叉树！");
		return false;
	}
}
//查询该树的深度
Status BiTreeDepth(BiTree T) {
	int leftDepth, rightDepth, maxDepth;
	if (T != NULL) {
		leftDepth = BiTreeDepth(T->lchild);
		rightDepth = BiTreeDepth(T->rchild);
		maxDepth = leftDepth > rightDepth ? leftDepth : rightDepth;
		printf("该二叉树的深度为：%d", maxDepth + 1);
		return maxDepth + 1;
	}
}
//返回该树的根
Status Root(BiTree& T) {
	int root = T->data;
	if (!T || BiTreeEmpty(T)) {
		printf("该树不存在！");
		return ERROR;
	}
	else {
		int root = T->data;
		printf("该树的根为：%d", root);
	}
	return root;
}
//返回节点的双亲
BiTree Parent(BiTree T, BiTree ch) {
	int parent, c;
	parent = T->data;
	printf("请输入所需查找双亲的元素：");
	scanf_s("%d", &ch);
	if (T->data == NULL || T->rchild == ch || T->lchild == ch) return ch;
	BiTree left = Parent(T->lchild, ch);
	if (left != NULL) return left;
	BiTree right = Parent(T->lchild, ch);
	if (right != NULL) return right;
	return left;
}

//该节点的左孩子
Status LeftChild(BiTree T) {
	int ch;
	int leftchild;
	scanf_s("%d", &ch);
	if (PreOrderTraverse(T) == ch) {
		leftchild = T->data;
	}
	printf("结点%d的双亲是%d",leftchild);
}
//该节点的右孩子
Status RightChild(BiTree T) {
	int ch;
	int leftchild;
	scanf_s("%d", &ch);
	if (PreOrderTraverse(T) == ch) {
		leftchild = T->data;
	}
	printf("结点%d的双亲是%d", leftchild);
}
//该节点的左兄弟
Status LeftSibling() {

}
//该节点的右兄弟
Status RightSibling() {

}
//插入元素
Status InsertChild(BiTree &T,TElemType e,int ch) {



}
//删除该节点的左子树或右子树
Status DeleteChild(BiTree T) {
	int ch;
	scanf_s("%d", &ch);
	if (PreOrderTraverse(T) == ch) {
		DestroyBiTree(T);
	}
	printf("结点%d的左右子树销毁成功！", ch);
	return OK;
}

