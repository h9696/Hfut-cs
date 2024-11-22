#include"Bitree1.h" 
#include <stdio.h>
#include <iostream>

using namespace std; 
 
int main(void)
{
	int m;
   
    BiNode *pBT=new BiNode;
    
    while(1){
    	cout<< "******************************必做******************************" << endl;
    	cout<<"二叉树实验任务:  "  <<endl;
    	cout<<"<1>设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数。"  <<endl;
    	cout<<"<2>求二叉树的叶子结点数和1度结点数。"  <<endl;
    	cout<<"<3>键盘输入一个元素x，求其父节点、兄弟结点、子结点的值。"  <<endl;
    	cout<<"<4>键盘输入一个元素x，求其在树中的层次。不存在时给出相应提示信息。" <<endl;
    	cout<<"<5>将按顺序方式存储在数组中的二叉树转换为二叉链表形式。"  <<endl;
    	cout<<"<6>输出二叉树从每个叶子结点到根结点的路径。" <<endl;
    	cout<<"<7>对二叉链表表示的二叉树，按从上到下，从左到右打印结点值，即按层次打印。" <<endl;
    	cout<<"<8>退出" << endl;
		cout<< "*******************************结束******************************" << endl;
        cout<< "输入你所需要验证的题号：" << endl;

        cin>>m;
    switch(m)
    {
        case 1:
        {
        	int high=0;
         	char strLine[100][3];
			int nArrLen=0;
			int nRow=0;
			ReadFileToArray(strLine, nArrLen);
			cout << "文件读取成功" << endl;
			int nLen = nArrLen;
			CreateBiTreeFromFile(pBT, strLine, nLen, nRow);
			cout << "中序序列及对应层数为：" << endl;  //将该功能放在后面时注释部分下面时会出现访问冲突错误
	        nodehigh(pBT, high);
			system("pause");
			system("cls");
			break;

        }
       case 2:
       	{
		   
         	char strLine[100][3];
			int nArrLen=0;
			int nRow=0;
			ReadFileToArray(strLine, nArrLen);
			cout << "文件读取成功" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);
 
            cout << "叶子结点树为:" << leaveNum(pBT) << endl;
            cout << "树度为1的结点数为:" << fullNodeNum(pBT) << endl;
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            char strLine[1000][3];
            char nFile[50];
            char x;
            int nArrLen;
            int nRow = 0;
            BiNode* pBT, * p;
            
			ReadFileToArray(strLine, nArrLen);
			cout << "文件读取成功" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);
            
            cout<<"请输入元素x："<<endl;
            cin >> x;
            
            p = Locate(pBT, x);
            //cout << Parent(pBT, pFound);
            getRelatedNode(pBT,p);
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            char strLine[1000][3];
            char nFile[50];
            char x;
            int nArrLen;
            int nRow = 0;
            BiNode* pBT;
            
			ReadFileToArray(strLine, nArrLen);
			cout << "文件读取成功" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);
            
            cout<<"请输入元素x："<<endl;
            cin >> x;
            
            //nRow = 0;
            foundNode(pBT, &nRow, x);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            char strLine[1000][3];
            char nFile[50];
            char T[1000];
            char x;
            int nRow = 0,i=0,num=0,nArrLen;
            BiNode* pBT,* p;

			ReadFileToArray(strLine, nArrLen);
			cout << "文件读取成功" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);

            num = pow(2, BiTreeHigh(pBT)) - 1;
            while (i <= num)
            {
                T[i] = '^';
                i++;
            }
            treeToArray(pBT, T, 1);
            p = arrayToTree(T, num, 1);              
            preTraverse(p);
            
            system("pause");
            system("cls");
            break;
        }

        case 6:
        {
            char strLine[1000][3];
            char nFile[50];
            char T[1000];
            char x;
            int nRow = 0,i=0,num=0,nArrLen;
            BiNode* pBT,* p;

			ReadFileToArray(strLine, nArrLen);
			cout << "文件读取成功" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);
            TreeRoad(pBT);
            
            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            char strLine[1000][3];
            char nFile[50];
            char T[1000];
            char x;
            int nRow = 0,i=0,num=0,nArrLen;
            BiNode* pBT,* p;

			ReadFileToArray(strLine, nArrLen);
			cout << "文件读取成功" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);

            BinaryTreeLevelOrder(pBT);
            system("pause");
            system("cls");
            break;
        }
        case 8:
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
    //mmo: system("cls");
}

