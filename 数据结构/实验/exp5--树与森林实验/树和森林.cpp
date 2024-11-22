#include "treeChildSibling.h"

int main(void)
{
	int m;
   
    while(1){
    	cout<< "*************************����***********************" << endl;
    	cout<<"����ɭ��ʵ������:  "  <<endl;
    	cout<<"<1>�����򡢺��򡢲�α���ɭ�֡�"  <<endl;
    	cout<<"<2>��ɭ�ֵĸ߶ȡ�"  <<endl;
    	cout<<"<3>ɭ��Ҷ�ӽ������"  <<endl;
    	cout<<"<4>��ɭ�ֵĶȡ�" <<endl;
    	cout<<"<5>����������ֵ�����κš�"  <<endl;
    	cout<<"<6>���������ʾ������" <<endl;
    	cout<<"<7>�˳�" << endl;
		cout<< "************************����************************" << endl;
        cout<< "����������Ҫ��֤����ţ�" << endl;

        cin>>m;
        switch(m)
        {
            case 1:
            {
        	    pTree* T = new pTree;
                char tree[50];
                cout << "������Ҫ�򿪵����ļ�:";
                cin >> tree;  
                CreateTreeFromFile(tree, T);

                csNode* N = new csNode;
                createCsTree(&N, T);
 
                cout << "���������" << endl;
                PreOrderTraverse(N);
                cout << endl;

                cout << "���������" << endl;
                LastOrderTraverse(N);
                cout << endl;

                cout << "���������" << endl;
                LevelOrderTraverse(N);
                cout << endl;
             
			    system("pause");
			    system("cls");
			    break;

            }
           case 2:
         	{
		        pTree* T = new pTree;
                char tree[50];
                cout << "������Ҫ�򿪵����ļ�:";
                cin >> tree;
                CreateTreeFromFile(tree, T);
 
                csNode* N = new csNode;
                createCsTree(&N, T);

                cout << "ɭ�ֵĸ߶�Ϊ:" << TreeHigh(N) << endl;
         	
                system("pause");
                system("cls");
                break;
            }
            case 3:
            {
                pTree* T = new pTree;
                char tree[50];
                cout << "������Ҫ�򿪵����ļ�:";
                cin >> tree;
                CreateTreeFromFile(tree, T);

                csNode* N = new csNode;
                createCsTree(&N, T);

                cout << "ɭ�ֵ�Ҷ�ӽ����Ϊ:" << GetLeavesNum(N) << endl;
                
                system("pause");
                system("cls");
                break;
            }
            case 4:
            {
                pTree* T = new pTree;
                char tree[50];
                cout << "������Ҫ�򿪵����ļ�:";
                cin >> tree;
                CreateTreeFromFile(tree, T);

                csNode* N = new csNode;
                createCsTree(&N, T);

                cout << "ɭ�ֵĶ�Ϊ:" << GetTreeDegree(N) << endl;
                
                system("pause");
                system("cls");
                break;
            }
            case 5:
            {
                pTree* T = new pTree;
                char tree[50];
                cout << "������Ҫ�򿪵����ļ�:";
                cin >> tree;
                CreateTreeFromFile(tree, T);

                csNode* N = new csNode;
                createCsTree(&N, T);

                PreOrderAndLeveal(N, 1);
                system("pause");
                system("cls");
                break;
            }

            case 6:
            {
                pTree* T = new pTree;
                char tree[50];
                cout << "������Ҫ�򿪵����ļ�:";
                cin >> tree;
                CreateTreeFromFile(tree, T);

                csNode* N = new csNode;
                createCsTree(&N, T);

                PrintTree(N);
            
                system("pause");
                system("cls");
                break;
            }
            case 7:
		    	cout << "�ټ���" << endl;
		    	return 0;	 
            default:
            {
                cout<<"�������"<<endl;
                system("pause");
                system("cls");

            }

        }
    } 

}
