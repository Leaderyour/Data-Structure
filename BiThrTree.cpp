#include<cstdio>
#include<cstdlib>

#define OK 1;
#define ERROR 0; //Ϊ�ͽ̲��������ϣ�OK��ֵ��Ϊ1��ERROR��ֵ��Ϊ0
#define Status int
#define TElemType int
#define MAX_TREE_SIZE 100//���������ڵ���
#define MAXSIZE 1000	//�������󳤶� 
#define SElemType int 
#define PoniterTag int
#define STACK_INIT_SIZE 100//����ջ�����ڵ���
#define STACKINCREMENT 10 //�洢�ռ��������
using namespace std;
typedef enum PointerTag{Link,Thread};//Link==0 ָ�룻Thread==0����
typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode * lchild, * rchild;
	PoniterTag LTag, RTag;//���ұ�־
}BiThrNode,*BiThrTree;

void Visit(BiThrTree& T) {
	printf("%d", T->data);//������ĵ�ǰ�ڵ�
}
//����������������
Status InOderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e)){
	BiThrTree p;
	p = T->lchild;//pָ����ڵ�
	while (p != T) {
		while (p->LTag == Link) p = p->lchild;
		if (!Visit(p->data)) printf("������Ԫ�ص�������Ϊ�սڵ㣡"); return ERROR;//����������Ϊ�սڵ�
		while (p->RTag == Thread /*&& p->rchild = T*/) {
			while (p->rchild = T) {
				p = p->rchild; Visit(p->data);
			}
			p = p->rchild;
		}
	}
	printf("������������������ɣ�\n");
	return OK;
}
//�������������������������
Status InOderThreading(BiThrTree& Thrt, BiThrTree T) {
	BiThrTree pre;
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) printf("�ռ佨��ʧ�ܣ�\n"); exit(OVERFLOW);
	Thrt->LTag = Link;
	Thrt->RTag = Thread;//����ͷ���
	Thrt->rchild = Thrt;//��ָ���ָ
	if (!T) {
		Thrt->lchild = Thrt;
	}
	else {
		Thrt->lchild = T; pre = Thrt;
		InThreading(T);
		pre->rchild = Thrt; pre->RTag = Thread;
		Thrt->rchild = pre;
	}
	printf("������������������ɣ�\n");
	return OK;
}
void InThreading(BiThrTree p) {
	BiThrTree pre;
	if (p) {
		InThreading(p->lchild);//������������
		if (!p->lchild) {	   //ǰ������
			p->LTag = Thread;
			p->rchild=pre;
		}
		if (!pre->rchild) {    //��������
			pre->RTag=Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}