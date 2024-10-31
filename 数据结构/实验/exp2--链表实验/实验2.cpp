#include<iostream>
//#pragma once
using namespace std;
typedef int elementType;
struct slNode
{
    int data;        //数据域
    struct slNode *next;   //指针域，结构（结点）自身引用
};
typedef struct slNode node, *linkList;

 
 
//函数声明
void createList(node * &L);//创建链表
void initialList(linkList &L);//链表初始化
void print(node * head);//遍历单链表，并输出
void menoprint();//菜单输出
bool listInsert(node * L, int i, elementType x);//1.在第i个结点前插入值为x的结点
bool listDelete(node * L, int i);//2.删除单链表中第i个元素结点。
void OrderlistInsert(node * L, int x);//3.在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性
void listSeperate(linkList& L);//4.将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），
                                                    //分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。
void listcommon(linkList &L1, linkList &L2,linkList &L3); //5.求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中。
void listdeleteReapt(linkList &L);//6.删除递增有序单链表中的重复元素，并统计移动元素次数

//函数实现
//创建链表
void createList(node * &L) //尾插法 
{
	elementType x; 
	node *u,*R;
	L=new node; 
	
	R=L;
	cin>>x;
	while(x!=-1){
		u=new node;
		u->data=x;
		u->next=NULL;
		R->next=u;
		R=u;
		cin>>x;
	}
	
}

//链表初始化
void initialList(linkList &L)
{
    L=new node;
    L->next=NULL;
}
 
//遍历链表，并输出
void print(node * head)
{
	node *p=head;
	if(head=NULL){
		cout<<"error"<<endl;
	}
	else{
		cout<<p->data<<" ";
		while(p->next!=NULL)
		{
			p=p->next;
			cout<<p->data<<" ";
		}
	}
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
	cout << "**		输入6在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性。           **" << endl;
	cout << "**		输入7将单链表Ｌ中的奇数项和偶数项结点分解开                                         **" << endl;
	cout << "**		输入8求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中                     **" << endl;
	cout << "**		输入9删除递增有序单链表中的重复元素，并统计移动元素次数                             **" << endl;
	cout << "******************************************************************************************************" << endl;
}

//1.在第i个结点前插入值为x的结点。
bool listInsert(node * L, int i, elementType x)
{
	node *p=L;  //p指向头结点 
	node *S;
	int k=0;
	while(k!=i-1&&p!=NULL) //搜索e（i-1）节点，并取得指向e（i-1）的指针p 
	{
		p=p->next;    //p指向下一个节点 
		k++;
	}
	
	if(p==NULL){
		return false;
	}
	
	else
	{
		//此时，k=i-1，p为e（i-1）节点的指针 
		S=new node;   //动态申请内存，创建一个新的节点，即要插入的节点 
		S->data=x;   //装入数据 
		S->next=p->next;
		p->next=S;
		return true; //正确插入返回true 
	}
 } 

//2.删除顺序表中第i个元素结点。
bool listDelete(node * L, int i)
{
    node *u;
	node *p=L;
	int k=0;
	while(k!=i-1&&p!=NULL) //搜索e（i-1）节点 
	{
		p=p->next;    //p指向下一个节点 
		k++;
	}
	if(p==NULL||p->next==NULL)	
	{
		return false;   
	}
	else{
		u=p->next;
		p->next=u->next;
		//dalete u;
		return true;
	}	
}

//3.在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性
void OrderlistInsert(node * L, int x)
{
    node* u;
    node* p = L;
    while (p->next != NULL && p->next->data < x)  //搜索插入位置p
    {
        p = p->next;
    }
    if (p->next == NULL || p->next->data > x)     //p后移一个结点
    {
        u = new node;
        u->data = x;
        u->next = p->next;
        p->next = u;
    }
}

//4.将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），
//分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。
void listSeperate(linkList& L)
{
    linkList L1, L2;
    initialList(L1);   //奇数表
    initialList(L2);   //偶数表
    node* p;       //原单链表的指针
    node* u;       //奇偶新链表的结点指针
    node* q1, *q2;	   //奇数表、偶数表的指针
    p = L->next;       //p开始指向首元素结点
    q1 = L1;
    q2 = L2;
    while (p != NULL)
    {
    //原表数据尾插插入新表元素
    if (p->data % 2 != 0)   //奇数表
    {
        u = new node;
        u->data = p->data;
        u-> next = NULL;
        q1->next = u;
        q1 = q1->next;
        //q1 = u;
    }
    else                    //偶数表
    {
        u = new node;
        u->data = p->data;
        u->next = NULL;
        q2->next = u;
        q2 = q2->next;
        // q2 = u;
    }
    p = p->next;
}
}

//5.求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中。
void listcommon(linkList &L1, linkList &L2,linkList &L3)
{
	node* p1, * p2, * p3;
	node* q;       //创立存放公共元素的新结点
	p1 = L1->next;
	p2 = L2->next;
	p3 = L3;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data == p2->data)
		{
			q = new node;
			q->data = p1->data;
			q->next = NULL;
			p3->next = q;
			p3 = p3->next;  //新表的指针后移一个

			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->data < p2->data)
		{
			p1 = p1->next;
		}
		else if (p1->data > p2->data)
		{
			p2 = p2->next;
		}
    }
}

//6.删除递增有序单链表中的重复元素，并统计移动元素次数
void listdeleteReapt(linkList &L)
{
	node* p, * q;
	p = L->next;
	q = L->next->next;
	while (q)
	{
		if (p->data == q->data)
		{
			q = q->next;
			p->next = q;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
}


int main()
{
	int j, i = 100;
	int x;
	linkList L, L1, L2, L3;
	initialList(L);
	initialList(L1);
	initialList(L2);
	initialList(L3);
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
			print(L);
			break;
		case 4:
			cout << "请输入插入的位置" << endl;
			cin >> j;
			cout << "请输入插入元素：" << endl;
			cin >> x;
			if (listInsert(L, j, x)!=2)
			{
 
			}
			else
			{
				cout << "插入后的链表" << endl;
				print(L);
			}
			break;
		case 5:
			cout << "请输入要删除的元素位置" << endl;
			cin >> j;
			if (listDelete(L, j)!=2)
			{
 
			}
			else
			{
				cout << "删除元素的链表为" << endl;
				print(L);
			}
			break;
		case 6:
			/*initList(&L);
			cout << "提示  输入-1结束" << endl;
			cout << "请输入单链表数据" << endl;
			create( & L);*/
			cout << "原表为：" << endl;
			print(L);
			cout << "请输入插入的元素" << endl;
			cin >> x;
			OrderlistInsert(L, x);
			cout << "插入后的链表" << endl;
			print(L);
			//initList(&L);
			break;
		case 7:
			//initList(&L);
			initialList(L1);
			initialList(L2);
			//cout << "提示  输入-1结束" << endl;
			//cout << "请输入单链表L数据：(提示  输入-1结束)" << endl;
			//create(&L);
			cout << "表L为：" << endl;
			//print(&L);
			listSeperate(L);
			cout << "链表L1为：";
			print(L1);
			cout << "链表L2为：";
			print(L2);
			//initList(&L);
			break;
		case 8:
			initialList(L1);
			initialList(L2);
			initialList(L3);
			cout << "请输入递增有序单链表L1数据：(提示  输入-1结束)" << endl;
			createList(L1);
			cout << "请输入递增有序单链表L2数据：(提示  输入-1结束)" << endl;
			createList(L2);
			listcommon(L1, L2, L3);
			cout << "表L3" << endl;
			print(L3);
			break;
		case 9:
			/*cout << "提示  输入-1结束" << endl;
			cout << "请输入递增有序单链表L数据：" << endl;
			create(&L);*/
			cout << "原表为：";
			print(L);
			listdeleteReapt(L);
			cout << "删除重复的元素后表" << endl;
			print(L);
			break;
		case 1:
			cout << "请输入递增有序单链表L数据：(提示  输入-1结束)" << endl;
			createList(L);
			cout << "数据成功录入" << endl;
			break;
		case 2:
		{
			initialList(L);
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


