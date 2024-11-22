#include<iostream>
//#pragma once
using namespace std;
typedef int elementType;
struct slNode
{
    int data;        //������
    struct slNode *next;   //ָ���򣬽ṹ����㣩��������
};
typedef struct slNode node, *linkList;

 
 
//��������
void createList(node * &L);//��������
void initialList(linkList &L);//�����ʼ��
void print(node * head);//���������������
void menoprint();//�˵����
bool listInsert(node * L, int i, elementType x);//1.�ڵ�i�����ǰ����ֵΪx�Ľ��
bool listDelete(node * L, int i);//2.ɾ���������е�i��Ԫ�ؽ�㡣
void OrderlistInsert(node * L, int x);//3.��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ��������������������
void listSeperate(linkList& L);//4.����������е��������ż������ֽ⿪��Ԫ��ֵΪ������ż������
                                                    //�ֱ�����µ�˳����У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������
void listcommon(linkList &L1, linkList &L2,linkList &L3); //5.������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3�С�
void listdeleteReapt(linkList &L);//6.ɾ���������������е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���

//����ʵ��
//��������
void createList(node * &L) //β�巨 
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

//�����ʼ��
void initialList(linkList &L)
{
    L=new node;
    L->next=NULL;
}
 
//�������������
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
	cout << "**		����6��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�           **" << endl;
	cout << "**		����7����������е��������ż������ֽ⿪                                         **" << endl;
	cout << "**		����8������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3��                     **" << endl;
	cout << "**		����9ɾ���������������е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���                             **" << endl;
	cout << "******************************************************************************************************" << endl;
}

//1.�ڵ�i�����ǰ����ֵΪx�Ľ�㡣
bool listInsert(node * L, int i, elementType x)
{
	node *p=L;  //pָ��ͷ��� 
	node *S;
	int k=0;
	while(k!=i-1&&p!=NULL) //����e��i-1���ڵ㣬��ȡ��ָ��e��i-1����ָ��p 
	{
		p=p->next;    //pָ����һ���ڵ� 
		k++;
	}
	
	if(p==NULL){
		return false;
	}
	
	else
	{
		//��ʱ��k=i-1��pΪe��i-1���ڵ��ָ�� 
		S=new node;   //��̬�����ڴ棬����һ���µĽڵ㣬��Ҫ����Ľڵ� 
		S->data=x;   //װ������ 
		S->next=p->next;
		p->next=S;
		return true; //��ȷ���뷵��true 
	}
 } 

//2.ɾ��˳����е�i��Ԫ�ؽ�㡣
bool listDelete(node * L, int i)
{
    node *u;
	node *p=L;
	int k=0;
	while(k!=i-1&&p!=NULL) //����e��i-1���ڵ� 
	{
		p=p->next;    //pָ����һ���ڵ� 
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

//3.��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ��������������������
void OrderlistInsert(node * L, int x)
{
    node* u;
    node* p = L;
    while (p->next != NULL && p->next->data < x)  //��������λ��p
    {
        p = p->next;
    }
    if (p->next == NULL || p->next->data > x)     //p����һ�����
    {
        u = new node;
        u->data = x;
        u->next = p->next;
        p->next = u;
    }
}

//4.����������е��������ż������ֽ⿪��Ԫ��ֵΪ������ż������
//�ֱ�����µ�˳����У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������
void listSeperate(linkList& L)
{
    linkList L1, L2;
    initialList(L1);   //������
    initialList(L2);   //ż����
    node* p;       //ԭ�������ָ��
    node* u;       //��ż������Ľ��ָ��
    node* q1, *q2;	   //������ż�����ָ��
    p = L->next;       //p��ʼָ����Ԫ�ؽ��
    q1 = L1;
    q2 = L2;
    while (p != NULL)
    {
    //ԭ������β������±�Ԫ��
    if (p->data % 2 != 0)   //������
    {
        u = new node;
        u->data = p->data;
        u-> next = NULL;
        q1->next = u;
        q1 = q1->next;
        //q1 = u;
    }
    else                    //ż����
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

//5.������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3�С�
void listcommon(linkList &L1, linkList &L2,linkList &L3)
{
	node* p1, * p2, * p3;
	node* q;       //������Ź���Ԫ�ص��½��
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
			p3 = p3->next;  //�±��ָ�����һ��

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

//6.ɾ���������������е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���
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
			cout << "����Ϊ��";
			print(L);
			break;
		case 4:
			cout << "����������λ��" << endl;
			cin >> j;
			cout << "���������Ԫ�أ�" << endl;
			cin >> x;
			if (listInsert(L, j, x)!=2)
			{
 
			}
			else
			{
				cout << "����������" << endl;
				print(L);
			}
			break;
		case 5:
			cout << "������Ҫɾ����Ԫ��λ��" << endl;
			cin >> j;
			if (listDelete(L, j)!=2)
			{
 
			}
			else
			{
				cout << "ɾ��Ԫ�ص�����Ϊ" << endl;
				print(L);
			}
			break;
		case 6:
			/*initList(&L);
			cout << "��ʾ  ����-1����" << endl;
			cout << "�����뵥��������" << endl;
			create( & L);*/
			cout << "ԭ��Ϊ��" << endl;
			print(L);
			cout << "����������Ԫ��" << endl;
			cin >> x;
			OrderlistInsert(L, x);
			cout << "����������" << endl;
			print(L);
			//initList(&L);
			break;
		case 7:
			//initList(&L);
			initialList(L1);
			initialList(L2);
			//cout << "��ʾ  ����-1����" << endl;
			//cout << "�����뵥����L���ݣ�(��ʾ  ����-1����)" << endl;
			//create(&L);
			cout << "��LΪ��" << endl;
			//print(&L);
			listSeperate(L);
			cout << "����L1Ϊ��";
			print(L1);
			cout << "����L2Ϊ��";
			print(L2);
			//initList(&L);
			break;
		case 8:
			initialList(L1);
			initialList(L2);
			initialList(L3);
			cout << "�����������������L1���ݣ�(��ʾ  ����-1����)" << endl;
			createList(L1);
			cout << "�����������������L2���ݣ�(��ʾ  ����-1����)" << endl;
			createList(L2);
			listcommon(L1, L2, L3);
			cout << "��L3" << endl;
			print(L3);
			break;
		case 9:
			/*cout << "��ʾ  ����-1����" << endl;
			cout << "�����������������L���ݣ�" << endl;
			create(&L);*/
			cout << "ԭ��Ϊ��";
			print(L);
			listdeleteReapt(L);
			cout << "ɾ���ظ���Ԫ�غ��" << endl;
			print(L);
			break;
		case 1:
			cout << "�����������������L���ݣ�(��ʾ  ����-1����)" << endl;
			createList(L);
			cout << "���ݳɹ�¼��" << endl;
			break;
		case 2:
		{
			initialList(L);
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


