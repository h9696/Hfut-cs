#include<iostream>
//#pragma once
using namespace std;
#define MAXLEN 100
typedef int elementType;
typedef struct sList
{
	elementType data[MAXLEN];//���崢����е�Ԫ������
	int listLen;//�����ĳ���
}seqList;
 
 
//��������
void create(seqList* L);//��������
void initList(seqList* L);//�����ʼ��
void print(seqList* L);//����˳��������
void menoprint();//�˵����
int listInsert(seqList* L, int i, elementType x);//1.�ڵ�i�����ǰ����ֵΪx�Ľ��
int listDelete(seqList* L, int i);//2.ɾ��˳����е�i��Ԫ�ؽ�㡣
void OrderlistInsert(seqList* L, int x);//3.��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ��������������������
void  listseparate(seqList* L1, seqList* L2, seqList* L3);//4.��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳����У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������
void listcommon(seqList* L, seqList* L1, seqList* L2); //5.��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�
void listdeleteReapt(seqList* L);//6.ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���
 
 
//����ʵ��
//��������
void create(seqList* L)
{
	int i = 0;
	cin >> i;
	while (i != -1)
	{
		L->data[L->listLen] = i;
		L->listLen++;
		cin >> i;
	}
}
 
//�����ʼ��
void initList(seqList* L)
{
	L->listLen = 0;
}
 
//�������������
void print(seqList* L)
{
	int i;
	for (i = 0; i < L->listLen; i++)
	{
		cout << L->data[i] << " ";
	}
	cout << endl;
}
 
 
//�˵����
void menoprint()
{
	cout << "******************************************************************************************************" << endl;
	cout << "**		����0��-1�˳�����                                                                   **" << endl;
	cout << "**		����1��������                                                                       **" << endl;
	cout << "**		����2��ʼ������                                                                     **" << endl;
	cout << "**		����3��������ʾ����                                                                 **" << endl;
	cout << "**		����4����Ԫ��                                                                       **" << endl;
	cout << "**		����5ɾ����i��λ��Ԫ��                                                              **" << endl;
	cout << "**		����6��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�           **" << endl;
	cout << "**		����7��˳�����е��������ż������ֽ⿪                                         **" << endl;
	cout << "**		����8��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3��                     **" << endl;
	cout << "**		����9ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���                             **" << endl;
	cout << "******************************************************************************************************" << endl;
}
 
//1.�ڵ�i�����ǰ����ֵΪx�Ľ�㡣
int listInsert(seqList* L,int i,elementType x)
{
	int j;
	if (i == MAXLEN)
	{
		cout << "��������" << endl;
		return 0;
	}
		
	else if (i<1 || i>L->listLen + 1)
	{
		cout << "����Ĳ���λ�ò���ȷ" << endl;
		return 1;
	}
		
	else
	{
		for (j = L->listLen - 1; j >= i - 1; j--)
		{
			L->data[j + 1] = L->data[j];
		}
		L->data[i - 1] = x;
		L->listLen++;
		return 2;
	}
}
 
//2.ɾ��˳����е�i��Ԫ�ؽ�㡣
int listDelete(seqList* L, int i)
{
	int j;
	if (L->listLen <= 0)
	{
		cout << "�����λ�ò���ȷ" << endl;
		return 0;
 
	}
		
	else if (i > L->listLen || i <= 0)
	{
		cout << "�����λ�ò���ȷ" << endl;
		return 1;
	}
	else
	{
		for (j = i; j <= L->listLen - 1; j++)
		{
			L->data[j-1] = L->data[j];
		}
		L->listLen--;
		return 2;
	}
}
 
 
//3.��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�
void OrderlistInsert(seqList* L, int x)
{
	int i =0;
	if (L->listLen == MAXLEN)
		cout << "��������" << endl;
	while (L->data[i] <= x)
	{
		if (i == L->listLen)
		{
			break;
		}
		else
		{
			i++;
		}
	}
	listInsert(L, i+1, x);
}
 
 
//4.��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳����У�
//Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������
void  listseparate(seqList* L, seqList* L1, seqList* L2)
{
	int k = 0, i = 0, j = 0;
	for (i = 0; i < L->listLen; i++)
	{
		if (L->data[i] % 2)
		{
			while (j != L->listLen)
			{
				L1->data[j] = L->data[i];
				L1->listLen++;
				j++;
				break;
			}
		}
		else
		{
			while (k != L->listLen)
			{
				L2->data[k] = L->data[i];
				L2->listLen++;
				k++;
				break;
			}
		}
	}
}
 
 
//5.��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�
void listcommon(seqList* L1, seqList* L2, seqList* L3)
{
	int i = 0, p = 0, q = 0;
	while (p != L1->listLen && q != L2->listLen)
	{
		if (L1->data[p] == L2->data[q])
		{
			while (i != L1->listLen)
			{
				L3->data[i] = L1->data[p];
				L3->listLen++;
				break;
			}
			i++;
			q++;
			p++;
		}
		else if (L1->data[p] < L2->data[q])
			p++;
		else
			q++;
	}
}
 
 
//6.ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���
void listdeleteReapt(seqList*L) {
	//ɾ��������ظ�ֵ
	int same = 0;
	for (int i = 0; i < L->listLen; i++)
	{
		for (int j = i + 1; j < L->listLen; j++) {
			if (L->data[i] == L->data[j])
			{
				same++;
			}
			else {
				L->data[j - same] = L->data[j];
			}
		}
		L->listLen = L->listLen- same;
	}
	cout << "�ƶ�����" << same << endl;
}











//#include"squlist.h"
int main()
{
	int j, i = 100;
	int x;
	seqList L, L1, L2, L3;
	initList(&L);
	initList(&L1);
	initList(&L2);
	initList(&L3);
	while (i != -1)
	{
		menoprint();
		cin >> i;
		switch (i)
		{
		case 0:
			exit(0);
		case 3:
			cout << "����Ϊ��";
			print(&L);
			break;
		case 4:
			cout << "����������λ��" << endl;
			cin >> j;
			cout << "���������Ԫ�أ�" << endl;
			cin >> x;
			if (listInsert(&L, j, x)!=2)
			{
 
			}
			else
			{
				cout << "����������" << endl;
				print(&L);
			}
			break;
		case 5:
			cout << "������Ҫɾ����Ԫ��λ��" << endl;
			cin >> j;
			if (listDelete(&L, j)!=2)
			{
 
			}
			else
			{
				cout << "ɾ��Ԫ�ص�����Ϊ" << endl;
				print(&L);
			}
			break;
		case 6:
			/*initList(&L);
			cout << "��ʾ  ����-1����" << endl;
			cout << "������˳�������" << endl;
			create( & L);*/
			cout << "ԭ��Ϊ��" << endl;
			print(&L);
			cout << "����������Ԫ��" << endl;
			cin >> x;
			OrderlistInsert(&L, x);
			cout << "����������" << endl;
			print(&L);
			//initList(&L);
			break;
		case 7:
			//initList(&L);
			initList(&L1);
			initList(&L2);
			//cout << "��ʾ  ����-1����" << endl;
			//cout << "������˳���L���ݣ�(��ʾ  ����-1����)" << endl;
			//create(&L);
			cout << "��LΪ��" << endl;
			//print(&L);
			listseparate(&L, &L1, &L2);
			cout << "����L1Ϊ��";
			print(&L1);
			cout << "����L2Ϊ��";
			print(&L2);
			//initList(&L);
			break;
		case 8:
			initList(&L1);
			initList(&L2);
			initList(&L3);
			cout << "�������������˳���L1���ݣ�(��ʾ  ����-1����)" << endl;
			create(&L1);
			cout << "�������������˳���L2���ݣ�(��ʾ  ����-1����)" << endl;
			create(&L2);
			listcommon(&L1, &L2, &L3);
			cout << "��L3" << endl;
			print(&L3);
			break;
		case 9:
			/*cout << "��ʾ  ����-1����" << endl;
			cout << "�������������˳���L���ݣ�" << endl;
			create(&L);*/
			cout << "ԭ��Ϊ��";
			print(&L);
			listdeleteReapt(&L);
			cout << "ɾ���ظ���Ԫ�غ��" << endl;
			print(&L);
			break;
		case 1:
			cout << "�������������˳���L���ݣ�(��ʾ  ����-1����)" << endl;
			create(&L);
			cout << "���ݳɹ�¼��" << endl;
			break;
		case 2:
		{
			initList(&L);
			cout << "\n��ʼ��\n" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}
	return 0;
	system("pause");
}
