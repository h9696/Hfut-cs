#include"graph.h"
 
using namespace std;
 
int main(void){
	char strLine[100][3];
	char fileName_1[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\udg8.grp"}; 
	char fileName_2[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\udg115.grp"}; 
	char fileName_3[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\dg6.grp"}; //�� 
	char fileName_4[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\f14.grp"}; 
	char fileName_5[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\udn6.grp"}; //�� 
	char fileName_6[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\dn10.grp"}; 
	char fileName_7[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\un8.grp"};  //�� 
	char fileName_8[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\dn8.grp"};//�� 
	char fileName_9[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\Top6dg1.grp"};
	char fileName_10[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\Top7dg1.grp"};
	char fileName_11[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\dag11.grp"};
	char fileName_12[100] = {"C:\\Users\\����Ծ\\Desktop\\ʵ��\\������\\dag12.grp"};
	
	Graph G;
	Graph1 G1;
	csNode *T; 
	int v0;
	int vID;
	char v;
	
	int choice; 
	while(1){
		cout << "***************************����***************************" << endl;
		cout << "1.��ӡ��ͼ�����������ֱ����� "<< endl;
		cout << "2.�����ͼ�еıߣ��򻡣�����Ŀ��" << endl;
		cout << "3.�Ը�����ͼG��������v0������㷨��V0������" << endl;
		cout << "  �����ȱ���ͼG�����������Ӧ��������������ɭ�֡� " << endl;
		cout << "4.�Ը�����ͼG��������v0������㷨��V0������" << endl;
		cout << "  �����ȱ���ͼG�����������Ӧ��������������ɭ�֡� " << endl;
		cout << "5.ʵ��Prim�㷨��������и���ͼG����С��������" << endl;
		cout << "6.ʵ��Kruskal�㷨��������и���ͼG����С��������" << endl;
		cout << "7.ʵ��Dijkstra�㷨��������и���ͼGָ������" << endl;
		cout << "  �����ඥ��֮������·����" << endl;
		cout << "8.ʵ��Floyd�㷨��������и���ͼG������֮������·����" << endl;
		cout << "9.����㷨������и���ͼG���������С�" << endl;
		cout << "10.����㷨������и���AOE���Ĺؼ�·����" << endl;
		cout << "11.�˳�" << endl;
		cout << "***************************����***************************" << endl;
		cout << "����������Ҫ��֤����ţ�" << endl;
		cin >> choice;
		switch(choice){
			case 1:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�udg8.grp" << endl;
				if(CreateGraphFromFile(fileName_1, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					DFSTraverse(G, 1);	
					cout << "\n���������������" << endl;
					BFSTraverse(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "�ڶ������ݣ�udg115.grp" << endl;
				if(CreateGraphFromFile(fileName_2, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					DFSTraverse(G, 1);	
					cout << "\n���������������" << endl;
					BFSTraverse(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�dg6.grp" << endl;
				if(CreateGraphFromFile(fileName_3, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					DFSTraverse(G, 1);	
					cout << "\n���������������" << endl;
					BFSTraverse(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "���������ݣ�f14.grp" << endl;
				if(CreateGraphFromFile(fileName_4, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					DFSTraverse(G, 1);	
					cout << "\n���������������" << endl;
					BFSTraverse(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << endl; 
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�udg8.grp" << endl;
				if(CreateGraphFromFile(fileName_1, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "����ͼ�ıߵ���ĿΪ��" << endl; 
					cout << G.ArcNum << endl;
					cout << Enum(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "�ڶ������ݣ�udg115.grp" << endl;
				if(CreateGraphFromFile(fileName_2, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "����ͼ�ıߵ���ĿΪ��" << endl; 
					cout << G.ArcNum << endl;
					cout << Enum(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�dg6.grp" << endl;
				if(CreateGraphFromFile(fileName_3, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "����ͼ�ıߵ���ĿΪ��" << endl; 
					cout << G.ArcNum << endl;
					cout << Enum(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "���������ݣ�f14.grp" << endl;
				if(CreateGraphFromFile(fileName_4, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "����ͼ�ıߵ���ĿΪ��" << endl; 
					cout << G.ArcNum << endl;
					cout << Enum(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << endl; 
				system("pause");
				system("cls");
				break;	
			case 3:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�udg8.grp" << endl;
				if(CreateGraphFromFile(fileName_1, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					cout << "�����������v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					DFS_Traverse(G, T, v0);
					cout << "\nɭ�ֵ��������Ϊ��" << endl; 
					Fist(T);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "�ڶ������ݣ�dg6.grp" << endl;
				if(CreateGraphFromFile(fileName_3, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					cout << "�����������v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					DFS_Traverse(G, T, v0);
					cout << "\nɭ�ֵ��������Ϊ��" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					cout << "�����������v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					DFS_Traverse(G, T, v0);
					cout << "\nɭ�ֵ��������Ϊ��" << endl; 
					Fist(T);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "���������ݣ�dn10.grp" << endl;
				if(CreateGraphFromFile(fileName_6, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					cout << "�����������v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					DFS_Traverse(G, T, v0);
					cout << "\nɭ�ֵ��������Ϊ��" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << endl; 
				system("pause");
				system("cls");
				break;	
			case 4:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�udg8.grp" << endl;
				if(CreateGraphFromFile(fileName_1, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					cout << "�����������v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					BFSForest(G, T, v0);
					cout << "\nɭ�ֵ��������Ϊ��" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "�ڶ������ݣ�dg6.grp" << endl;
				if(CreateGraphFromFile(fileName_3, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					cout << "�����������v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					BFSForest(G, T, v0);
					cout << "\nɭ�ֵ��������Ϊ��" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					cout << "�����������v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					BFSForest(G, T, v0);
					cout << "\nɭ�ֵ��������Ϊ��" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "���������ݣ�dn10.grp" << endl;
				if(CreateGraphFromFile(fileName_6, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout << "���������������" << endl;
					cout << "�����������v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					BFSForest(G, T, v0);
					cout << "\nɭ�ֵ��������Ϊ��" << endl; 
					Fist(T);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << endl; 
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�udn6.grp" << endl;
				if(CreateGraphFromFile(fileName_5, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout<<"������Prim�㷨����ʼ���㣺\n";
					cin >> v; 
					vID=LocateVertex(G, v);
					if(vID==-1){
						cout<<endl<<"����ѡ���������ʼ���㲻��ͼ�ϣ��㷨ʧ�ܡ�"<<endl<<endl;
					}else{
						//��ʼ���Ѿ�ѡ����������
						for(int i=1;i<=G.VerNum;i++)
							inTree[i]=0;  //��ʾȫ��û��ѡ��
			
						Prim(G,vID); //ִ��Prim�㷨������minEdges[]����
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "�ڶ������ݣ�un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout<<"������Prim�㷨����ʼ���㣺\n";
					cin >> v; 
					vID=LocateVertex(G, v);
					if(vID==-1){
						cout<<endl<<"����ѡ���������ʼ���㲻��ͼ�ϣ��㷨ʧ�ܡ�"<<endl<<endl;
					}else{
						//��ʼ���Ѿ�ѡ����������
						for(int i=1;i<=G.VerNum;i++)
							inTree[i]=0;  //��ʾȫ��û��ѡ��
			
						Prim(G,vID); //ִ��Prim�㷨������minEdges[]����
					}
					DestroyGraph(G);
				}
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 6:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�udn6.grp" << endl;
				if(CreateGraphFromFile(fileName_5, G)){
					cout << "ͼ�����ɹ�" << endl;
					Kruskal(G);
					DestroyGraph(G);
				}
				cout << "*************************************************************" << endl; 
				cout << "�ڶ������ݣ�un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "ͼ�����ɹ�" << endl;
					Kruskal(G);
					DestroyGraph(G);
				}
				system("pause");
				system("cls");
				break;
			case 7:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�udn6.grp" << endl;
				if(CreateGraphFromFile(fileName_5, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout<<"������ Dijkstra �㷨����ʼ���㣺";
					cin>>v;
					vID=LocateVertex(G, v);
					if(vID==-1)
					{
						cout<<endl<<"����ѡ�����ʼ���㲻��ͼ�ϣ�����ʧ�ܡ�"<<endl<<endl;
					}else{
						int path[MaxVerNum+1];
						int dist[MaxVerNum+1];
						Dijkstra(G, path, dist, vID);
						PrintDijkstra(G, path, dist, vID);  //��ӡ���·��
					}
					DestroyGraph(G);
				}
				cout << "*************************************************************" << endl; 
				cout << "�ڶ������ݣ�un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout<<"������ Dijkstra �㷨����ʼ���㣺";
					cin>>v;
					vID=LocateVertex(G,v);
					if(vID==-1)
					{
						cout<<endl<<"����ѡ�����ʼ���㲻��ͼ�ϣ�����ʧ�ܡ�"<<endl<<endl;
					}else{
						int path[MaxVerNum+1];
						int dist[MaxVerNum+1];
						Dijkstra(G, path, dist, vID);
						PrintDijkstra(G, path, dist, vID);  //��ӡ���·��
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�dn8.grp" << endl;
				if(CreateGraphFromFile(fileName_8, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout<<"������ Dijkstra �㷨����ʼ���㣺";
					cin>>v;
					vID=LocateVertex(G,v);
					if(vID==-1)
					{
						cout<<endl<<"����ѡ�����ʼ���㲻��ͼ�ϣ�����ʧ�ܡ�"<<endl<<endl;
					}else{
						int path[MaxVerNum+1];
						int dist[MaxVerNum+1];
						Dijkstra(G, path, dist, vID);
						PrintDijkstra(G, path, dist, vID);  //��ӡ���·��
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�dn10.grp" << endl;
				if(CreateGraphFromFile(fileName_6, G)){
					cout << "ͼ�����ɹ�" << endl;
					cout<<"������ Dijkstra �㷨����ʼ���㣺";
					cin>>v;
					vID=LocateVertex(G,v);
					if(vID==-1)
					{
						cout<<endl<<"����ѡ�����ʼ���㲻��ͼ�ϣ�����ʧ�ܡ�"<<endl<<endl;
					}else{
						int path[MaxVerNum+1];
						int dist[MaxVerNum+1];
						Dijkstra(G, path, dist, vID);
						PrintDijkstra(G, path, dist, vID);  //��ӡ���·��
					}
					DestroyGraph(G);
				}
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 8:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�udn6.grp" << endl;
				if(CreateGrpFromFile1(fileName_5, G1)){
					cout << "ͼ�����ɹ�" << endl;
					cellType dist1[MaxVerNum][MaxVerNum];  //��ά�������
					int path1[MaxVerNum][MaxVerNum];       //��ά·������
					Floyd(G1, dist1, path1);  //ִ��Floyd�㷨
					PrintFloyd(G1, dist1, path1);
				}
				cout << "*************************************************************" << endl; 
				cout << "�ڶ������ݣ�un8.grp" << endl;
				if(CreateGrpFromFile1(fileName_7, G1)){
					cout << "ͼ�����ɹ�" << endl;
					cellType dist1[MaxVerNum][MaxVerNum];  //��ά�������
					int path1[MaxVerNum][MaxVerNum];       //��ά·������
					cout << "ͼ�����ɹ�" << endl;
					Floyd(G1, dist1, path1);  //ִ��Floyd�㷨
					PrintFloyd(G1, dist1, path1);
				}
				cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�dn8.grp" << endl;
				if(CreateGrpFromFile1(fileName_8, G1)){
					cout << "ͼ�����ɹ�" << endl;
					cellType dist1[MaxVerNum][MaxVerNum];  //��ά�������
					int path1[MaxVerNum][MaxVerNum];       //��ά·������
					cout << "ͼ�����ɹ�" << endl;
					Floyd(G1, dist1, path1);  //ִ��Floyd�㷨
					PrintFloyd(G1, dist1, path1);
				}
				cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�dn10.grp" << endl;
				if(CreateGrpFromFile1(fileName_6, G1)){
					cout << "ͼ�����ɹ�" << endl;
					cellType dist1[MaxVerNum][MaxVerNum];  //��ά�������
					int path1[MaxVerNum][MaxVerNum];       //��ά·������
					cout << "ͼ�����ɹ�" << endl;
					Floyd(G1, dist1, path1);  //ִ��Floyd�㷨
					PrintFloyd(G1, dist1, path1);
				}
				cout << endl;
				system("pause");
				system("cls");
				break;	
			case 9:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�top6dg1.grp" << endl;
				if(CreateGraphFromFile(fileName_9, G)){
					cout << "ͼ�����ɹ�" << endl;
					int topoList[MaxVerNum+1];  //�����������е�����
					if(TopologicalSort(G, topoList)) //�������������㷨--ʹ��ջ
					{
						cout<<endl;
						cout<<"��ͼ��������ɹ����������У�"<<endl;
						for(int i=1;i<=G.VerNum;i++)  //�Զ���Ԫ�������������
							cout<<G.VerList[topoList[i]].data<<"\t";
						cout<<endl<<endl;
					}
					else
					{
						cout<<endl<<"��ͼ���л�·����������ʧ�ܡ�"<<endl<<endl;
					}
					DestroyGraph(G);
				}
				cout << "*************************************************************" << endl; 
				cout << "�ڶ������ݣ�top7dg1.grp" << endl;
				if(CreateGraphFromFile(fileName_10, G)){
					cout << "ͼ�����ɹ�" << endl;
					int topoList[MaxVerNum+1];  //�����������е�����
					if(TopologicalSort(G, topoList)) //�������������㷨--ʹ��ջ
					{
						cout<<endl;
						cout<<"��ͼ��������ɹ����������У�"<<endl;
						for(int i=1;i<=G.VerNum;i++)  //�Զ���Ԫ�������������
							cout<<G.VerList[topoList[i]].data<<"\t";
						cout<<endl<<endl;
					}
					else
					{
						cout<<endl<<"��ͼ���л�·����������ʧ�ܡ�"<<endl<<endl;
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�dn8.grp" << endl;
				if(CreateGraphFromFile(fileName_8, G)){
					cout << "ͼ�����ɹ�" << endl;
					int topoList[MaxVerNum+1];  //�����������е�����
					if(TopologicalSort(G, topoList)) //�������������㷨--ʹ��ջ
					{
						cout<<endl;
						cout<<"��ͼ��������ɹ����������У�"<<endl;
						for(int i=1;i<=G.VerNum;i++)  //�Զ���Ԫ�������������
							cout<<G.VerList[topoList[i]].data<<"\t";
						cout<<endl<<endl;
					}
					else
					{
						cout<<endl<<"��ͼ���л�·����������ʧ�ܡ�"<<endl<<endl;
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "���������ݣ�dn10.grp" << endl;
				if(CreateGraphFromFile(fileName_6, G)){
					cout << "ͼ�����ɹ�" << endl;
					int topoList[MaxVerNum+1];  //�����������е�����
					if(TopologicalSort(G, topoList)) //�������������㷨--ʹ��ջ
					{
						cout<<endl;
						cout<<"��ͼ��������ɹ����������У�"<<endl;
						for(int i=1;i<=G.VerNum;i++)  //�Զ���Ԫ�������������
							cout<<G.VerList[topoList[i]].data<<"\t";
						cout<<endl<<endl;
					}
					else
					{
						cout<<endl<<"��ͼ���л�·����������ʧ�ܡ�"<<endl<<endl;
					}				
				cout << endl;
				system("pause");
				system("cls");
				break;	
			case 10:
				cout << "��������Ϊ��" << endl;
				cout << "��һ�����ݣ�dag11.grp" << endl;
				if(CreateGraphFromFile(fileName_11, G)){
					cout << "ͼ�����ɹ�" << endl;
					
					CreateGrpFromFile1(fileName_11, G1);
					
					int topoList[MaxVerNum + 1];  //�����������е�����
					
					TopologicalSort(G, topoList);
					cout<<endl;
					cout<<"��ͼ��������ɹ����������У�"<<endl;
					
					for(int i=1;i<=G.VerNum;i++)  //�Զ���Ԫ�������������
					cout<<G.VerList[topoList[i]].data<<"\t";
					cout<<endl;
						
					KeyPath(G1,topoList);//�������������㷨--ʹ��ջ
				}
				cout << "\n*************************************************************" << endl;
				cout << "��������Ϊ��" << endl;
				cout << "�ڶ������ݣ�dag12.grp" << endl;
				if(CreateGraphFromFile(fileName_12, G)){
					cout << "ͼ�����ɹ�" << endl;
					
					CreateGrpFromFile1(fileName_12, G1);
					
					int topoList[MaxVerNum + 1];  //�����������е�����
					
					TopologicalSort(G, topoList);
					cout<<endl;
					cout<<"��ͼ��������ɹ����������У�"<<endl;
					
					for(int i=1;i<=G.VerNum;i++)  //�Զ���Ԫ�������������
					cout<<G.VerList[topoList[i]].data<<"\t";
					cout<<endl;
						
					KeyPath(G1,topoList);//�������������㷨--ʹ��ջ
				}
				cout << endl;
				system("pause");
				system("cls");
				break;	
			case 11:
				cout << "�ټ���" << endl;
				return 0;	
		}
	}
	
  }
	return 0;

   
}
//�ļ����Լ�ע���У�ע����//��ʼ���ұ��붥ͷ��ʼ�������пո�
//�ļ������п���
//GraphΪͼ��־�������ж���ʽ����
//��־�к󣬵�һ��Ϊͼ�����͡�UDG--����ͼ��UDN--��������DG--����ͼ��DN--������
//��־�к󣬵ڶ���Ϊ����Ԫ��
//����������ͼ�ı߻򻡡��ö����ʾ����һ���Զ��������У��ڶ���Ϊ�ڽӵ㣻����������һ�б�ʾȨֵ��

//��ͼΪһ��11�����㡢15���ߵ���������

//��ʶΪͼ����
                     //Graph

//��ʶ������
//DN

//���������б���Ӧ�ı��ΪA B C D E F G H I J K 
//A B C D E F G H I J K 


//����Ϊ�����ݣ���15����
