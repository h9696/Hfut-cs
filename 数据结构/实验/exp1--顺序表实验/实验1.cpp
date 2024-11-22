#include<iostream>
//#pragma once
using namespace std;
#define MAXLEN 100
typedef int elementType;
typedef struct sList
{
	elementType data[MAXLEN];//定义储存表中的元素数组
	int listLen;//定义表的长度
}seqList;
 
 
//函数声明
void create(seqList* L);//创建链表
void initList(seqList* L);//链表初始化
void print(seqList* L);//遍历顺序表，并输出
void menoprint();//菜单输出
int listInsert(seqList* L, int i, elementType x);//1.在第i个结点前插入值为x的结点
int listDelete(seqList* L, int i);//2.删除顺序表中第i个元素结点。
void OrderlistInsert(seqList* L, int x);//3.在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性
void  listseparate(seqList* L1, seqList* L2, seqList* L3);//4.将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。
void listcommon(seqList* L, seqList* L1, seqList* L2); //5.求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。
void listdeleteReapt(seqList* L);//6.删除递增有序顺序表中的重复元素，并统计移动元素次数
 
 
//函数实现
//创建链表
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
 
//链表初始化
void initList(seqList* L)
{
	L->listLen = 0;
}
 
//遍历链表，并输出
void print(seqList* L)
{
	int i;
	for (i = 0; i < L->listLen; i++)
	{
		cout << L->data[i] << " ";
	}
	cout << endl;
}
 
 
//菜单输出
void menoprint()
{
	cout << "******************************************************************************************************" << endl;
	cout << "**		输入0或-1退出程序                                                                   **" << endl;
	cout << "**		输入1创建链表                                                                       **" << endl;
	cout << "**		输入2初始化链表                                                                     **" << endl;
	cout << "**		输入3遍历并显示链表                                                                 **" << endl;
	cout << "**		输入4插入元素                                                                       **" << endl;
	cout << "**		输入5删除第i个位置元素                                                              **" << endl;
	cout << "**		输入6在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性。           **" << endl;
	cout << "**		输入7将顺序表Ｌ中的奇数项和偶数项结点分解开                                         **" << endl;
	cout << "**		输入8求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中                     **" << endl;
	cout << "**		输入9删除递增有序顺序表中的重复元素，并统计移动元素次数                             **" << endl;
	cout << "******************************************************************************************************" << endl;
}
 
//1.在第i个结点前插入值为x的结点。
int listInsert(seqList* L,int i,elementType x)
{
	int j;
	if (i == MAXLEN)
	{
		cout << "链表已满" << endl;
		return 0;
	}
		
	else if (i<1 || i>L->listLen + 1)
	{
		cout << "输入的插入位置不正确" << endl;
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
 
//2.删除顺序表中第i个元素结点。
int listDelete(seqList* L, int i)
{
	int j;
	if (L->listLen <= 0)
	{
		cout << "输入的位置不正确" << endl;
		return 0;
 
	}
		
	else if (i > L->listLen || i <= 0)
	{
		cout << "输入的位置不正确" << endl;
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
 
 
//3.在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性。
void OrderlistInsert(seqList* L, int x)
{
	int i =0;
	if (L->listLen == MAXLEN)
		cout << "链表已满" << endl;
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
 
 
//4.将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中，
//然后原表和新表元素同时输出到屏幕上，以便对照求解结果。
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
 
 
//5.求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。
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
 
 
//6.删除递增有序顺序表中的重复元素，并统计移动元素次数
void listdeleteReapt(seqList*L) {
	//删除有序表重复值
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
	cout << "移动次数" << same << endl;
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
			cout << "链表为：";
			print(&L);
			break;
		case 4:
			cout << "请输入插入的位置" << endl;
			cin >> j;
			cout << "请输入插入元素：" << endl;
			cin >> x;
			if (listInsert(&L, j, x)!=2)
			{
 
			}
			else
			{
				cout << "插入后的链表" << endl;
				print(&L);
			}
			break;
		case 5:
			cout << "请输入要删除的元素位置" << endl;
			cin >> j;
			if (listDelete(&L, j)!=2)
			{
 
			}
			else
			{
				cout << "删除元素的链表为" << endl;
				print(&L);
			}
			break;
		case 6:
			/*initList(&L);
			cout << "提示  输入-1结束" << endl;
			cout << "请输入顺序表数据" << endl;
			create( & L);*/
			cout << "原表为：" << endl;
			print(&L);
			cout << "请输入插入的元素" << endl;
			cin >> x;
			OrderlistInsert(&L, x);
			cout << "插入后的链表" << endl;
			print(&L);
			//initList(&L);
			break;
		case 7:
			//initList(&L);
			initList(&L1);
			initList(&L2);
			//cout << "提示  输入-1结束" << endl;
			//cout << "请输入顺序表L数据：(提示  输入-1结束)" << endl;
			//create(&L);
			cout << "表L为：" << endl;
			//print(&L);
			listseparate(&L, &L1, &L2);
			cout << "链表L1为：";
			print(&L1);
			cout << "链表L2为：";
			print(&L2);
			//initList(&L);
			break;
		case 8:
			initList(&L1);
			initList(&L2);
			initList(&L3);
			cout << "请输入递增有序顺序表L1数据：(提示  输入-1结束)" << endl;
			create(&L1);
			cout << "请输入递增有序顺序表L2数据：(提示  输入-1结束)" << endl;
			create(&L2);
			listcommon(&L1, &L2, &L3);
			cout << "表L3" << endl;
			print(&L3);
			break;
		case 9:
			/*cout << "提示  输入-1结束" << endl;
			cout << "请输入递增有序顺序表L数据：" << endl;
			create(&L);*/
			cout << "原表为：";
			print(&L);
			listdeleteReapt(&L);
			cout << "删除重复的元素后表" << endl;
			print(&L);
			break;
		case 1:
			cout << "请输入递增有序顺序表L数据：(提示  输入-1结束)" << endl;
			create(&L);
			cout << "数据成功录入" << endl;
			break;
		case 2:
		{
			initList(&L);
			cout << "\n初始化\n" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}
	return 0;
	system("pause");
}
