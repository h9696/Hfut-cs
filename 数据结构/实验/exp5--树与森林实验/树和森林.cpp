#include "treeChildSibling.h"

int main(void)
{
	int m;
   
    while(1){
    	cout<< "*************************必做***********************" << endl;
    	cout<<"树和森林实验任务:  "  <<endl;
    	cout<<"<1>按先序、后序、层次遍历森林。"  <<endl;
    	cout<<"<2>求森林的高度。"  <<endl;
    	cout<<"<3>森林叶子结点数。"  <<endl;
    	cout<<"<4>求森林的度。" <<endl;
    	cout<<"<5>先序输出结点值及其层次号。"  <<endl;
    	cout<<"<6>输出广义表表示的树。" <<endl;
    	cout<<"<7>退出" << endl;
		cout<< "************************结束************************" << endl;
        cout<< "输入你所需要验证的题号：" << endl;

        cin>>m;
        switch(m)
        {
            case 1:
            {
        	    pTree* T = new pTree;
                char tree[50];
                cout << "输入需要打开的树文件:";
                cin >> tree;  
                CreateTreeFromFile(tree, T);

                csNode* N = new csNode;
                createCsTree(&N, T);
 
                cout << "先序遍历：" << endl;
                PreOrderTraverse(N);
                cout << endl;

                cout << "后序遍历：" << endl;
                LastOrderTraverse(N);
                cout << endl;

                cout << "层序遍历：" << endl;
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
                cout << "输入需要打开的树文件:";
                cin >> tree;
                CreateTreeFromFile(tree, T);
 
                csNode* N = new csNode;
                createCsTree(&N, T);

                cout << "森林的高度为:" << TreeHigh(N) << endl;
         	
                system("pause");
                system("cls");
                break;
            }
            case 3:
            {
                pTree* T = new pTree;
                char tree[50];
                cout << "输入需要打开的树文件:";
                cin >> tree;
                CreateTreeFromFile(tree, T);

                csNode* N = new csNode;
                createCsTree(&N, T);

                cout << "森林的叶子结点数为:" << GetLeavesNum(N) << endl;
                
                system("pause");
                system("cls");
                break;
            }
            case 4:
            {
                pTree* T = new pTree;
                char tree[50];
                cout << "输入需要打开的树文件:";
                cin >> tree;
                CreateTreeFromFile(tree, T);

                csNode* N = new csNode;
                createCsTree(&N, T);

                cout << "森林的度为:" << GetTreeDegree(N) << endl;
                
                system("pause");
                system("cls");
                break;
            }
            case 5:
            {
                pTree* T = new pTree;
                char tree[50];
                cout << "输入需要打开的树文件:";
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
                cout << "输入需要打开的树文件:";
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
		    	cout << "再见！" << endl;
		    	return 0;	 
            default:
            {
                cout<<"输入错误。"<<endl;
                system("pause");
                system("cls");

            }

        }
    } 

}
