#include<cstdio>
#include<cstdlib>

#define OK 1;
#define ERROR 0; //为和教材内容贴合，OK的值设为1，ERROR的值设为0
#define Status int
#define TElemType int
#define MAX_TREE_SIZE 100//二叉树最大节点数
#define MAXSIZE 1000	//链表的最大长度 
#define SElemType int 
#define PoniterTag int
#define STACK_INIT_SIZE 100//定义栈的最大节点数
#define STACKINCREMENT 10 //存储空间分配增量
using namespace std;
typedef enum PointerTag{Link,Thread};//Link==0 指针；Thread==0线索
typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode * lchild, * rchild;
	PoniterTag LTag, RTag;//左右标志
}BiThrNode,*BiThrTree;

void Visit(BiThrTree& T) {
	printf("%d", T->data);//输出树的当前节点
}
//遍历该线索二叉树
Status InOderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e)){
	BiThrTree p;
	p = T->lchild;//p指向根节点
	while (p != T) {
		while (p->LTag == Link) p = p->lchild;
		if (!Visit(p->data)) printf("该数据元素的左子树为空节点！"); return ERROR;//访问左子树为空节点
		while (p->RTag == Thread /*&& p->rchild = T*/) {
			while (p->rchild = T) {
				p = p->rchild; Visit(p->data);
			}
			p = p->rchild;
		}
	}
	printf("该线索二叉树遍历完成！\n");
	return OK;
}
//中序遍历建立中序线索化链表
Status InOderThreading(BiThrTree& Thrt, BiThrTree T) {
	BiThrTree pre;
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) printf("空间建立失败！\n"); exit(OVERFLOW);
	Thrt->LTag = Link;
	Thrt->RTag = Thread;//建立头结点
	Thrt->rchild = Thrt;//右指针回指
	if (!T) {
		Thrt->lchild = Thrt;
	}
	else {
		Thrt->lchild = T; pre = Thrt;
		InThreading(T);
		pre->rchild = Thrt; pre->RTag = Thread;
		Thrt->rchild = pre;
	}
	printf("中序线索化链表已完成！\n");
	return OK;
}
void InThreading(BiThrTree p) {
	BiThrTree pre;
	if (p) {
		InThreading(p->lchild);//左子树线索化
		if (!p->lchild) {	   //前驱线索
			p->LTag = Thread;
			p->rchild=pre;
		}
		if (!pre->rchild) {    //后驱线索
			pre->RTag=Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}