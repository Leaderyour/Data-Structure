#include<cstdio>
#include<cstdlib>

#define Status char
#define MAXSTRLEN 255     //�û�����255���ڶ�����󴮳�
#define TRUE 0
#define FALSE 1
#define OK 0
#define ERROR 1
typedef unsigned char SString[MAXSTRLEN + 1];//0�ŵ�Ԫ��Ŵ��ĳ���
//����S1��S2�ϲ���T
Status Concat(SString& T, SString S1, SString S2) {
	char uncut;
	S1[0] = sizeof(S1);
	S2[0]=sizeof(S2);
	int length = S1[0] + S2[0];
	if (S1[0] + S2[0] <= MAXSTRLEN) {
		T[0] = S1[0] + S2[0];
		for (int i = 1; i < S1[0]; i++) {
			T[i] = S1[i];
		}
		for (int j = S1[0] + 1; j <= length; j++) {
			int k = 1;
			T[j] = S2[k];
			k++;
		}
		printf("δ�ضϣ���\n");
		uncut = TRUE;
	}
	else if (S1[0] < MAXSTRLEN) {
		for (int i = 1; i < S1[0]; i++) {
			T[i] = S1[i];
		}
		for (int j = S1[0] + 1; j <= MAXSTRLEN; j++) {
			int k = 1;
			T[j] = S2[k];
			k++;
		}
		T[0] = MAXSTRLEN;
		printf("��S2�нضϣ���\n");
		uncut = FALSE;
	}
	else {
		for (int i = 1; i < S1[0]; i++) {
			T[i] = S1[i];
		}
		T[0] = S1[0];
		uncut = FALSE;
	}
}
//ȡ�Ӵ��ӵ�pos��λ���𳤶�Ϊlen
Status SunString(SString& Sub, SString S, int pos, int len) {
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1) {
		return ERROR;
	}
	for (int i = 1; i < len; i++) {
		Sub[i] = S[pos];
		pos++;
	}
	Sub[0] = len;
}