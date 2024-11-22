#include<iostream>
#include"Search.h"
#include<stdlib.h>
#include <cstring>

using namespace std;


int main()
{
    int j,a[100],n,x;
    BiNode *T,*S;
    cout<<"1.采用二分查找算法实现查找，给出查找过程依次所比较的元素（的下标） "<<endl;
    cout<<"2.在二叉排序树中插入结点，在此基础上实现构建二叉排序树的算法。"<<endl;
    cout<<"3.在二叉排序树中查找指定值的结点。"<<endl;
    cout<<"4.在二叉排序树中删除特定值的结点。"<<endl;
    cout<<"5.对给定的二叉排序树，求出在等概论情况下的平均查找长度。"<<endl;
    cout<<"6.对给定的二叉树，假设其中各结点的值均不相同，设计算法以判断该二叉树是否是二叉排序树。"<<endl;
    cout<<"请输入序号（输入0退出）"<<endl;
    cin>>j;
    if(j<0||j>7)
    {
        cout<<"选项错误，请重新选择"<<endl;
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
                    cout<<"请输入需要查找的数据,输入-1停止查找:";
                    cin>>x;
                    if(x == -1){
                        exit(0);
                    }
                    j = bin_search(a,n,x);
                    if(j == -1)  cout<<"该数据不存在！"<<endl;
                    else  cout<<"该数据所在下标为："<<j<<endl;
                }
                system("pause");
                break;

            }
        case 2 :
            {
                createBst(T);
                cout<<"中序排列为："<<endl;
                inOrderPrint(T);
                cout<<endl;

                    cout<<"输入需要插入的数据：";
                    cin>>x;
                    S = new BiNode;
                    S->data = x;
                    S->lChild = NULL;
                    S->rChild = NULL;
                    insert(T, S);
                    cout<<"插入后中序输出为："<<endl;
                    inOrderPrint(T);
                    cout << endl;
                    system("pause");
                    break;

            }
        case 3 :
            {
                createBst(T);
                cout<<"中序排列为："<<endl;
                inOrderPrint(T);
                cout<<endl;
                while(1){
                    cout<<"请输入需要查找的数据,输入-1停止查找:";
                    cin>>x;
                    if(x == -1){
                        exit(0);
                    }
                    S = bes_search(T,x);
                    if(S == NULL)  cout<<"数据不存在！"<<endl;
                    else  cout<<"该数据为 "<<S->data<<endl;
                }
                system("pause");
                break;
            }
        case 4 :
            {
                createBst(T);
                cout<<"中序排列为："<<endl;
                inOrderPrint(T);
                cout<<endl;
                cout<<"输入需要删除的数据：";
                cin>>x;
                deleteBiNode(T,x);
                cout<<"删除后的中序排列为："<<endl;
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
                cout<<"中序排列为："<<endl;
                inOrderPrint(T);
                cout<<endl;
				CalcASL(T,a,b,1);
				cout<<"二叉排序树的平均查找长度为："<<(a/b)<<endl; 
                system("pause");
                break;
            } 
		case 6 :
            {
                createBst(T);
				isBinarySearchTree(T);
				if(isBinarySearchTree(T)==true)
				{ 
				    cout<<"满足二叉排序树。"<<endl;
				}
                if(isBinarySearchTree(T)==false)
                    cout<<"不满足二叉排序树。"<<endl;
                system("pause");
                break;
            }
            
        default :
        exit(0);
    }
}







