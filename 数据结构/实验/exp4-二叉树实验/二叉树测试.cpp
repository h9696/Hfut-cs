#include"Bitree1.h" 
#include <stdio.h>
#include <iostream>

using namespace std; 
 
int main(void)
{
	int m;
   
    BiNode *pBT=new BiNode;
    
    while(1){
    	cout<< "******************************����******************************" << endl;
    	cout<<"������ʵ������:  "  <<endl;
    	cout<<"<1>����㷨�������������������и�����ֵ��������Ӧ�Ĳ������"  <<endl;
    	cout<<"<2>���������Ҷ�ӽ������1�Ƚ������"  <<endl;
    	cout<<"<3>��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��"  <<endl;
    	cout<<"<4>��������һ��Ԫ��x�����������еĲ�Ρ�������ʱ������Ӧ��ʾ��Ϣ��" <<endl;
    	cout<<"<5>����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ��"  <<endl;
    	cout<<"<6>�����������ÿ��Ҷ�ӽ�㵽������·����" <<endl;
    	cout<<"<7>�Զ��������ʾ�Ķ������������ϵ��£������Ҵ�ӡ���ֵ��������δ�ӡ��" <<endl;
    	cout<<"<8>�˳�" << endl;
		cout<< "*******************************����******************************" << endl;
        cout<< "����������Ҫ��֤����ţ�" << endl;

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
			cout << "�ļ���ȡ�ɹ�" << endl;
			int nLen = nArrLen;
			CreateBiTreeFromFile(pBT, strLine, nLen, nRow);
			cout << "�������м���Ӧ����Ϊ��" << endl;  //���ù��ܷ��ں���ʱע�Ͳ�������ʱ����ַ��ʳ�ͻ����
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
			cout << "�ļ���ȡ�ɹ�" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);
 
            cout << "Ҷ�ӽ����Ϊ:" << leaveNum(pBT) << endl;
            cout << "����Ϊ1�Ľ����Ϊ:" << fullNodeNum(pBT) << endl;
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
			cout << "�ļ���ȡ�ɹ�" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);
            
            cout<<"������Ԫ��x��"<<endl;
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
			cout << "�ļ���ȡ�ɹ�" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);
            
            cout<<"������Ԫ��x��"<<endl;
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
			cout << "�ļ���ȡ�ɹ�" << endl;
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
			cout << "�ļ���ȡ�ɹ�" << endl;
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
			cout << "�ļ���ȡ�ɹ�" << endl;
			int nLen = nArrLen;
            CreateBiTreeFromFile(pBT, strLine,nLen,nRow);

            BinaryTreeLevelOrder(pBT);
            system("pause");
            system("cls");
            break;
        }
        case 8:
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
    //mmo: system("cls");
}

