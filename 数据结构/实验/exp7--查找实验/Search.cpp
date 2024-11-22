#include<iostream>
#include"Search.h"
#include<stdlib.h>
#include <cstring>

using namespace std;


int main()
{
    int j,a[100],n,x;
    BiNode *T,*S;
    cout<<"1.���ö��ֲ����㷨ʵ�ֲ��ң��������ҹ����������Ƚϵ�Ԫ�أ����±꣩ "<<endl;
    cout<<"2.�ڶ����������в����㣬�ڴ˻�����ʵ�ֹ����������������㷨��"<<endl;
    cout<<"3.�ڶ����������в���ָ��ֵ�Ľ�㡣"<<endl;
    cout<<"4.�ڶ�����������ɾ���ض�ֵ�Ľ�㡣"<<endl;
    cout<<"5.�Ը����Ķ���������������ڵȸ�������µ�ƽ�����ҳ��ȡ�"<<endl;
    cout<<"6.�Ը����Ķ��������������и�����ֵ������ͬ������㷨���жϸö������Ƿ��Ƕ�����������"<<endl;
    cout<<"��������ţ�����0�˳���"<<endl;
    cin>>j;
    if(j<0||j>7)
    {
        cout<<"ѡ�����������ѡ��"<<endl;
        cin>>j;
    }
    if(j == 0) {
        exit(0);
    }
    system("cls");
    switch(j)
    {
        case 1 :
            {
                create(a,n);
                while(1){
                    cout<<"��������Ҫ���ҵ�����,����-1ֹͣ����:";
                    cin>>x;
                    if(x == -1){
                        exit(0);
                    }
                    j = bin_search(a,n,x);
                    if(j == -1)  cout<<"�����ݲ����ڣ�"<<endl;
                    else  cout<<"�����������±�Ϊ��"<<j<<endl;
                }
                system("pause");
                break;

            }
        case 2 :
            {
                createBst(T);
                cout<<"��������Ϊ��"<<endl;
                inOrderPrint(T);
                cout<<endl;

                    cout<<"������Ҫ��������ݣ�";
                    cin>>x;
                    S = new BiNode;
                    S->data = x;
                    S->lChild = NULL;
                    S->rChild = NULL;
                    insert(T, S);
                    cout<<"������������Ϊ��"<<endl;
                    inOrderPrint(T);
                    cout << endl;
                    system("pause");
                    break;

            }
        case 3 :
            {
                createBst(T);
                cout<<"��������Ϊ��"<<endl;
                inOrderPrint(T);
                cout<<endl;
                while(1){
                    cout<<"��������Ҫ���ҵ�����,����-1ֹͣ����:";
                    cin>>x;
                    if(x == -1){
                        exit(0);
                    }
                    S = bes_search(T,x);
                    if(S == NULL)  cout<<"���ݲ����ڣ�"<<endl;
                    else  cout<<"������Ϊ "<<S->data<<endl;
                }
                system("pause");
                break;
            }
        case 4 :
            {
                createBst(T);
                cout<<"��������Ϊ��"<<endl;
                inOrderPrint(T);
                cout<<endl;
                cout<<"������Ҫɾ�������ݣ�";
                cin>>x;
                deleteBiNode(T,x);
                cout<<"ɾ�������������Ϊ��"<<endl;
                inOrderPrint(T);
                cout << endl;
                system("pause");
                break;
            }
        case 5 :
            {
            	double a;
            	int b;
                createBst(T);
                cout<<"��������Ϊ��"<<endl;
                inOrderPrint(T);
                cout<<endl;
				CalcASL(T,a,b,1);
				cout<<"������������ƽ�����ҳ���Ϊ��"<<(a/b)<<endl; 
                system("pause");
                break;
            } 
		case 6 :
            {
                createBst(T);
				isBinarySearchTree(T);
				if(isBinarySearchTree(T)==true)
				{ 
				    cout<<"���������������"<<endl;
				}
                if(isBinarySearchTree(T)==false)
                    cout<<"�����������������"<<endl;
                system("pause");
                break;
            }
            
        default :
        exit(0);
    }
}







