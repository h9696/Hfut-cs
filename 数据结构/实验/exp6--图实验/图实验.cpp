#include"graph.h"
 
using namespace std;
 
int main(void){
	char strLine[100][3];
	char fileName_1[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\udg8.grp"}; 
	char fileName_2[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\udg115.grp"}; 
	char fileName_3[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\dg6.grp"}; //无 
	char fileName_4[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\f14.grp"}; 
	char fileName_5[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\udn6.grp"}; //无 
	char fileName_6[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\dn10.grp"}; 
	char fileName_7[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\un8.grp"};  //无 
	char fileName_8[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\dn8.grp"};//无 
	char fileName_9[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\Top6dg1.grp"};
	char fileName_10[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\Top7dg1.grp"};
	char fileName_11[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\dag11.grp"};
	char fileName_12[100] = {"C:\\Users\\侯腾跃\\Desktop\\实验\\第六次\\dag12.grp"};
	
	Graph G;
	Graph1 G1;
	csNode *T; 
	int v0;
	int vID;
	char v;
	
	int choice; 
	while(1){
		cout << "***************************必做***************************" << endl;
		cout << "1.打印出图（网）的两种遍历序。 "<< endl;
		cout << "2.求给定图中的边（或弧）的数目。" << endl;
		cout << "3.对给定的图G及出发点v0，设计算法从V0出发深" << endl;
		cout << "  度优先遍历图G，并构造出相应的生成树或生成森林。 " << endl;
		cout << "4.对给定的图G及出发点v0，设计算法从V0出发广" << endl;
		cout << "  度优先遍历图G，并构造出相应的生成树或生成森林。 " << endl;
		cout << "5.实现Prim算法，求解下列给定图G的最小生成树。" << endl;
		cout << "6.实现Kruskal算法，求解下列给定图G的最小生成树。" << endl;
		cout << "7.实现Dijkstra算法，求解下列给定图G指定顶点" << endl;
		cout << "  到其余顶点之间的最短路径。" << endl;
		cout << "8.实现Floyd算法，求解下列给定图G各顶点之间的最短路径。" << endl;
		cout << "9.设计算法求解下列给定图G的拓扑序列。" << endl;
		cout << "10.设计算法求解下列给定AOE网的关键路径。" << endl;
		cout << "11.退出" << endl;
		cout << "***************************结束***************************" << endl;
		cout << "输入你所需要验证的题号：" << endl;
		cin >> choice;
		switch(choice){
			case 1:
				cout << "测试数据为：" << endl;
				cout << "第一组数据：udg8.grp" << endl;
				if(CreateGraphFromFile(fileName_1, G)){
					cout << "图创建成功" << endl;
					cout << "深度优先搜索遍历" << endl;
					DFSTraverse(G, 1);	
					cout << "\n广度优先搜索遍历" << endl;
					BFSTraverse(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "第二组数据：udg115.grp" << endl;
				if(CreateGraphFromFile(fileName_2, G)){
					cout << "图创建成功" << endl;
					cout << "深度优先搜索遍历" << endl;
					DFSTraverse(G, 1);	
					cout << "\n广度优先搜索遍历" << endl;
					BFSTraverse(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "第三组数据：dg6.grp" << endl;
				if(CreateGraphFromFile(fileName_3, G)){
					cout << "图创建成功" << endl;
					cout << "深度优先搜索遍历" << endl;
					DFSTraverse(G, 1);	
					cout << "\n广度优先搜索遍历" << endl;
					BFSTraverse(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "第四组数据：f14.grp" << endl;
				if(CreateGraphFromFile(fileName_4, G)){
					cout << "图创建成功" << endl;
					cout << "深度优先搜索遍历" << endl;
					DFSTraverse(G, 1);	
					cout << "\n广度优先搜索遍历" << endl;
					BFSTraverse(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << endl; 
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "测试数据为：" << endl;
				cout << "第一组数据：udg8.grp" << endl;
				if(CreateGraphFromFile(fileName_1, G)){
					cout << "图创建成功" << endl;
					cout << "给定图的边的数目为：" << endl; 
					cout << G.ArcNum << endl;
					cout << Enum(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "第二组数据：udg115.grp" << endl;
				if(CreateGraphFromFile(fileName_2, G)){
					cout << "图创建成功" << endl;
					cout << "给定图的边的数目为：" << endl; 
					cout << G.ArcNum << endl;
					cout << Enum(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}cout << "\n*************************************************************" << endl;
				cout << "第三组数据：dg6.grp" << endl;
				if(CreateGraphFromFile(fileName_3, G)){
					cout << "图创建成功" << endl;
					cout << "给定图的边的数目为：" << endl; 
					cout << G.ArcNum << endl;
					cout << Enum(G, 1);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "第四组数据：f14.grp" << endl;
				if(CreateGraphFromFile(fileName_4, G)){
					cout << "图创建成功" << endl;
					cout << "给定图的边的数目为：" << endl; 
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
				cout << "测试数据为：" << endl;
				cout << "第一组数据：udg8.grp" << endl;
				if(CreateGraphFromFile(fileName_1, G)){
					cout << "图创建成功" << endl;
					cout << "深度优先搜索遍历" << endl;
					cout << "请输入出发点v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					DFS_Traverse(G, T, v0);
					cout << "\n森林的先序遍历为：" << endl; 
					Fist(T);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "第二组数据：dg6.grp" << endl;
				if(CreateGraphFromFile(fileName_3, G)){
					cout << "图创建成功" << endl;
					cout << "深度优先搜索遍历" << endl;
					cout << "请输入出发点v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					DFS_Traverse(G, T, v0);
					cout << "\n森林的先序遍历为：" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "第三组数据：un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "图创建成功" << endl;
					cout << "深度优先搜索遍历" << endl;
					cout << "请输入出发点v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					DFS_Traverse(G, T, v0);
					cout << "\n森林的先序遍历为：" << endl; 
					Fist(T);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "第四组数据：dn10.grp" << endl;
				if(CreateGraphFromFile(fileName_6, G)){
					cout << "图创建成功" << endl;
					cout << "深度优先搜索遍历" << endl;
					cout << "请输入出发点v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					DFS_Traverse(G, T, v0);
					cout << "\n森林的先序遍历为：" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << endl; 
				system("pause");
				system("cls");
				break;	
			case 4:
				cout << "测试数据为：" << endl;
				cout << "第一组数据：udg8.grp" << endl;
				if(CreateGraphFromFile(fileName_1, G)){
					cout << "图创建成功" << endl;
					cout << "广度优先搜索遍历" << endl;
					cout << "请输入出发点v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					BFSForest(G, T, v0);
					cout << "\n森林的先序遍历为：" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "第二组数据：dg6.grp" << endl;
				if(CreateGraphFromFile(fileName_3, G)){
					cout << "图创建成功" << endl;
					cout << "广度优先搜索遍历" << endl;
					cout << "请输入出发点v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					BFSForest(G, T, v0);
					cout << "\n森林的先序遍历为：" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "第三组数据：un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "图创建成功" << endl;
					cout << "广度优先搜索遍历" << endl;
					cout << "请输入出发点v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					BFSForest(G, T, v0);
					cout << "\n森林的先序遍历为：" << endl; 
					Fist(T);	
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "第四组数据：dn10.grp" << endl;
				if(CreateGraphFromFile(fileName_6, G)){
					cout << "图创建成功" << endl;
					cout << "广度优先搜索遍历" << endl;
					cout << "请输入出发点v0(1 <= v0 <= " << G.VerNum << ")\n";
					cin >> v0; 
					BFSForest(G, T, v0);
					cout << "\n森林的先序遍历为：" << endl; 
					Fist(T);
					//printGraph(G);
					DestroyGraph(G);
				}
				cout << endl; 
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "测试数据为：" << endl;
				cout << "第一组数据：udn6.grp" << endl;
				if(CreateGraphFromFile(fileName_5, G)){
					cout << "图创建成功" << endl;
					cout<<"请输入Prim算法的起始顶点：\n";
					cin >> v; 
					vID=LocateVertex(G, v);
					if(vID==-1){
						cout<<endl<<"错误：选择遍历的起始顶点不在图上，算法失败。"<<endl<<endl;
					}else{
						//初始化已经选定顶点数组
						for(int i=1;i<=G.VerNum;i++)
							inTree[i]=0;  //表示全部没有选定
			
						Prim(G,vID); //执行Prim算法，产生minEdges[]数组
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl; 
				cout << "第二组数据：un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "图创建成功" << endl;
					cout<<"请输入Prim算法的起始顶点：\n";
					cin >> v; 
					vID=LocateVertex(G, v);
					if(vID==-1){
						cout<<endl<<"错误：选择遍历的起始顶点不在图上，算法失败。"<<endl<<endl;
					}else{
						//初始化已经选定顶点数组
						for(int i=1;i<=G.VerNum;i++)
							inTree[i]=0;  //表示全部没有选定
			
						Prim(G,vID); //执行Prim算法，产生minEdges[]数组
					}
					DestroyGraph(G);
				}
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 6:
				cout << "测试数据为：" << endl;
				cout << "第一组数据：udn6.grp" << endl;
				if(CreateGraphFromFile(fileName_5, G)){
					cout << "图创建成功" << endl;
					Kruskal(G);
					DestroyGraph(G);
				}
				cout << "*************************************************************" << endl; 
				cout << "第二组数据：un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "图创建成功" << endl;
					Kruskal(G);
					DestroyGraph(G);
				}
				system("pause");
				system("cls");
				break;
			case 7:
				cout << "测试数据为：" << endl;
				cout << "第一组数据：udn6.grp" << endl;
				if(CreateGraphFromFile(fileName_5, G)){
					cout << "图创建成功" << endl;
					cout<<"请输入 Dijkstra 算法的起始顶点：";
					cin>>v;
					vID=LocateVertex(G, v);
					if(vID==-1)
					{
						cout<<endl<<"错误：选择的起始顶点不在图上，搜索失败。"<<endl<<endl;
					}else{
						int path[MaxVerNum+1];
						int dist[MaxVerNum+1];
						Dijkstra(G, path, dist, vID);
						PrintDijkstra(G, path, dist, vID);  //打印最短路径
					}
					DestroyGraph(G);
				}
				cout << "*************************************************************" << endl; 
				cout << "第二组数据：un8.grp" << endl;
				if(CreateGraphFromFile(fileName_7, G)){
					cout << "图创建成功" << endl;
					cout<<"请输入 Dijkstra 算法的起始顶点：";
					cin>>v;
					vID=LocateVertex(G,v);
					if(vID==-1)
					{
						cout<<endl<<"错误：选择的起始顶点不在图上，搜索失败。"<<endl<<endl;
					}else{
						int path[MaxVerNum+1];
						int dist[MaxVerNum+1];
						Dijkstra(G, path, dist, vID);
						PrintDijkstra(G, path, dist, vID);  //打印最短路径
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "第三组数据：dn8.grp" << endl;
				if(CreateGraphFromFile(fileName_8, G)){
					cout << "图创建成功" << endl;
					cout<<"请输入 Dijkstra 算法的起始顶点：";
					cin>>v;
					vID=LocateVertex(G,v);
					if(vID==-1)
					{
						cout<<endl<<"错误：选择的起始顶点不在图上，搜索失败。"<<endl<<endl;
					}else{
						int path[MaxVerNum+1];
						int dist[MaxVerNum+1];
						Dijkstra(G, path, dist, vID);
						PrintDijkstra(G, path, dist, vID);  //打印最短路径
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "第四组数据：dn10.grp" << endl;
				if(CreateGraphFromFile(fileName_6, G)){
					cout << "图创建成功" << endl;
					cout<<"请输入 Dijkstra 算法的起始顶点：";
					cin>>v;
					vID=LocateVertex(G,v);
					if(vID==-1)
					{
						cout<<endl<<"错误：选择的起始顶点不在图上，搜索失败。"<<endl<<endl;
					}else{
						int path[MaxVerNum+1];
						int dist[MaxVerNum+1];
						Dijkstra(G, path, dist, vID);
						PrintDijkstra(G, path, dist, vID);  //打印最短路径
					}
					DestroyGraph(G);
				}
				cout << endl;
				system("pause");
				system("cls");
				break;
			case 8:
				cout << "测试数据为：" << endl;
				cout << "第一组数据：udn6.grp" << endl;
				if(CreateGrpFromFile1(fileName_5, G1)){
					cout << "图创建成功" << endl;
					cellType dist1[MaxVerNum][MaxVerNum];  //二维距离矩阵
					int path1[MaxVerNum][MaxVerNum];       //二维路径矩阵
					Floyd(G1, dist1, path1);  //执行Floyd算法
					PrintFloyd(G1, dist1, path1);
				}
				cout << "*************************************************************" << endl; 
				cout << "第二组数据：un8.grp" << endl;
				if(CreateGrpFromFile1(fileName_7, G1)){
					cout << "图创建成功" << endl;
					cellType dist1[MaxVerNum][MaxVerNum];  //二维距离矩阵
					int path1[MaxVerNum][MaxVerNum];       //二维路径矩阵
					cout << "图创建成功" << endl;
					Floyd(G1, dist1, path1);  //执行Floyd算法
					PrintFloyd(G1, dist1, path1);
				}
				cout << "\n*************************************************************" << endl;
				cout << "第三组数据：dn8.grp" << endl;
				if(CreateGrpFromFile1(fileName_8, G1)){
					cout << "图创建成功" << endl;
					cellType dist1[MaxVerNum][MaxVerNum];  //二维距离矩阵
					int path1[MaxVerNum][MaxVerNum];       //二维路径矩阵
					cout << "图创建成功" << endl;
					Floyd(G1, dist1, path1);  //执行Floyd算法
					PrintFloyd(G1, dist1, path1);
				}
				cout << "\n*************************************************************" << endl;
				cout << "第四组数据：dn10.grp" << endl;
				if(CreateGrpFromFile1(fileName_6, G1)){
					cout << "图创建成功" << endl;
					cellType dist1[MaxVerNum][MaxVerNum];  //二维距离矩阵
					int path1[MaxVerNum][MaxVerNum];       //二维路径矩阵
					cout << "图创建成功" << endl;
					Floyd(G1, dist1, path1);  //执行Floyd算法
					PrintFloyd(G1, dist1, path1);
				}
				cout << endl;
				system("pause");
				system("cls");
				break;	
			case 9:
				cout << "测试数据为：" << endl;
				cout << "第一组数据：top6dg1.grp" << endl;
				if(CreateGraphFromFile(fileName_9, G)){
					cout << "图创建成功" << endl;
					int topoList[MaxVerNum+1];  //保存拓扑序列的数组
					if(TopologicalSort(G, topoList)) //调用拓扑排序算法--使用栈
					{
						cout<<endl;
						cout<<"本图拓扑排序成功。拓扑序列："<<endl;
						for(int i=1;i<=G.VerNum;i++)  //以顶点元素输出拓扑序列
							cout<<G.VerList[topoList[i]].data<<"\t";
						cout<<endl<<endl;
					}
					else
					{
						cout<<endl<<"本图具有回路，拓扑排序失败。"<<endl<<endl;
					}
					DestroyGraph(G);
				}
				cout << "*************************************************************" << endl; 
				cout << "第二组数据：top7dg1.grp" << endl;
				if(CreateGraphFromFile(fileName_10, G)){
					cout << "图创建成功" << endl;
					int topoList[MaxVerNum+1];  //保存拓扑序列的数组
					if(TopologicalSort(G, topoList)) //调用拓扑排序算法--使用栈
					{
						cout<<endl;
						cout<<"本图拓扑排序成功。拓扑序列："<<endl;
						for(int i=1;i<=G.VerNum;i++)  //以顶点元素输出拓扑序列
							cout<<G.VerList[topoList[i]].data<<"\t";
						cout<<endl<<endl;
					}
					else
					{
						cout<<endl<<"本图具有回路，拓扑排序失败。"<<endl<<endl;
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "第三组数据：dn8.grp" << endl;
				if(CreateGraphFromFile(fileName_8, G)){
					cout << "图创建成功" << endl;
					int topoList[MaxVerNum+1];  //保存拓扑序列的数组
					if(TopologicalSort(G, topoList)) //调用拓扑排序算法--使用栈
					{
						cout<<endl;
						cout<<"本图拓扑排序成功。拓扑序列："<<endl;
						for(int i=1;i<=G.VerNum;i++)  //以顶点元素输出拓扑序列
							cout<<G.VerList[topoList[i]].data<<"\t";
						cout<<endl<<endl;
					}
					else
					{
						cout<<endl<<"本图具有回路，拓扑排序失败。"<<endl<<endl;
					}
					DestroyGraph(G);
				}
				cout << "\n*************************************************************" << endl;
				cout << "第四组数据：dn10.grp" << endl;
				if(CreateGraphFromFile(fileName_6, G)){
					cout << "图创建成功" << endl;
					int topoList[MaxVerNum+1];  //保存拓扑序列的数组
					if(TopologicalSort(G, topoList)) //调用拓扑排序算法--使用栈
					{
						cout<<endl;
						cout<<"本图拓扑排序成功。拓扑序列："<<endl;
						for(int i=1;i<=G.VerNum;i++)  //以顶点元素输出拓扑序列
							cout<<G.VerList[topoList[i]].data<<"\t";
						cout<<endl<<endl;
					}
					else
					{
						cout<<endl<<"本图具有回路，拓扑排序失败。"<<endl<<endl;
					}				
				cout << endl;
				system("pause");
				system("cls");
				break;	
			case 10:
				cout << "测试数据为：" << endl;
				cout << "第一组数据：dag11.grp" << endl;
				if(CreateGraphFromFile(fileName_11, G)){
					cout << "图创建成功" << endl;
					
					CreateGrpFromFile1(fileName_11, G1);
					
					int topoList[MaxVerNum + 1];  //保存拓扑序列的数组
					
					TopologicalSort(G, topoList);
					cout<<endl;
					cout<<"本图拓扑排序成功。拓扑序列："<<endl;
					
					for(int i=1;i<=G.VerNum;i++)  //以顶点元素输出拓扑序列
					cout<<G.VerList[topoList[i]].data<<"\t";
					cout<<endl;
						
					KeyPath(G1,topoList);//调用拓扑排序算法--使用栈
				}
				cout << "\n*************************************************************" << endl;
				cout << "测试数据为：" << endl;
				cout << "第二组数据：dag12.grp" << endl;
				if(CreateGraphFromFile(fileName_12, G)){
					cout << "图创建成功" << endl;
					
					CreateGrpFromFile1(fileName_12, G1);
					
					int topoList[MaxVerNum + 1];  //保存拓扑序列的数组
					
					TopologicalSort(G, topoList);
					cout<<endl;
					cout<<"本图拓扑排序成功。拓扑序列："<<endl;
					
					for(int i=1;i<=G.VerNum;i++)  //以顶点元素输出拓扑序列
					cout<<G.VerList[topoList[i]].data<<"\t";
					cout<<endl;
						
					KeyPath(G1,topoList);//调用拓扑排序算法--使用栈
				}
				cout << endl;
				system("pause");
				system("cls");
				break;	
			case 11:
				cout << "再见！" << endl;
				return 0;	
		}
	}
	
  }
	return 0;

   
}
//文件可以加注释行，注释以//开始，且必须顶头开始，不能有空格
//文件不能有空行
//Graph为图标志，否则判定格式不对
//标志行后，第一行为图的类型。UDG--无向图；UDN--无向网；DG--有向图；DN--有向网
//标志行后，第二行为顶点元素
//顶点行以下图的边或弧。用顶点表示，第一列以顶点编号排列；第二列为邻接点；在网中增加一列表示权值。

//此图为一个11个顶点、15条边的有向网。

//标识为图数据
                     //Graph

//标识有向网
//DN

//顶点数据列表，对应的编号为A B C D E F G H I J K 
//A B C D E F G H I J K 


//以下为边数据，共15条边
