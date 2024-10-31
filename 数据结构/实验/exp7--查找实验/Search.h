#include<iostream>
using namespace std;

typedef struct lBNode
{
	int data;
	struct lBNode *lChild, *rChild;
}BiNode,*BiTree;


//先序遍历--递归
void preOrderPrint(BiNode *T)  
{
	if(T)
	{
		cout<<T->data<<" ";         //访问根结点。打印当前结点元素值，替代visit(T)函数
		preOrderPrint(T->lChild);   //先序遍历左子树
		preOrderPrint(T->rChild);   //先序遍历右子树
	}
}

//中序遍历--递归
void inOrderPrint(BiNode *T)
{
	if(T)
	{
		inOrderPrint(T->lChild);    //中序遍历左子树
		cout<<T->data<<" ";         //访问根结点。打印当前结点元素值，替代visit(T)函数
		inOrderPrint(T->rChild);    //中序遍历右子树
	}
}

//后序遍历--递归
void postOrderPrint(BiNode *T)
{
	if(T)
	{
		postOrderPrint(T->lChild);   //后序遍历左子树
		postOrderPrint(T->rChild);   //后序遍历右子树
		cout<<T->data<<" ";          //访问根结点。打印当前结点元素值，替代visit(T)函数
	}
}

void create(int A[],int &n)   //1.向数组写入数据下标从 0 开始写入数据， n 为数据个数
{
	cout<<"请输入数据，-1结束："<<endl;
	int i = 0,j;
	cin>>j;
	while(j != -1)
	{
	    A[i] = j;
	    i++;
		cin>>j;
	}
	n = i;
}

int bin_search(int A[],int n,int x)   //1.采用二分查找算法实现查找
{
	int mid,low = 0,high = n-1;
	while(low <= high)
	{
		mid = (high + low) / 2;
		cout<<"当前值为"<<A[mid];
		if(A[mid] == x)
		{
			cout<<"    当前值为目标数据"<<endl;
			return mid;
		}
		else if(A[mid] < x)
		{
			cout<<"    当前值小于待查数据，转右子树"<<endl;
			low = mid + 1;
		}
		else
		{
			cout<<"    当前值大于待查数据，转左子树"<<endl;
			high = mid - 1;
		}
	}
	return -1;
}

void insert(BiNode *&T,BiNode *S)  //2.二叉树插入
{
	if(T == NULL)  T = S;
	else if(S->data < T->data)  insert(T->lChild,S);
	else if(S->data > T->data)  insert(T->rChild,S);
}


void createBst(BiNode *&T)    //2.插入法创建二叉树
{
	T = NULL;
	int x;
	BiNode *S;

	cout<<"输入数据，-1结束"<<endl;
	cin>>x;
	while(x != -1)
	{
		S = new BiNode;
		S->data = x;
		S->lChild = NULL;
		S->rChild = NULL;
		insert(T, S);
		cin>>x;
	}
}


BiNode *bes_search(BiNode *T,int x)  //3.二叉树查找
{
	BiNode *p = T;
	while(p != NULL)
	    if(x == p->data)  return p;
	    else if(x < p->data)  p = p->lChild;
	    else  p = p->rChild;
	return p;
}

void deleteBiNode(BiNode *&T, int x)    //4.二叉树删除
{
	if(T)
	{
		if(T->data == x)
		{
			if(T->lChild == NULL && T->rChild == NULL)
			{
				delete T;
				T = NULL;
				return;
			}
			else if(T->lChild == NULL && T->rChild)
			{
				BiNode *p;
				p = T;
				T = T->rChild;
				delete p;
			}
			else if(T->lChild && T->rChild == NULL)
			{
				BiNode *p;
				p = T;
				T = T->lChild;
				delete p;
			}
			else
			{
				BiNode *sf = T, *s = T->lChild;
				while(s->rChild)
				{
					sf = s;
					s = s->rChild;
				}
				T->data = s->data;
				if(sf == T)
				{
					sf->lChild = s->lChild;
				}
				else
				{
					sf->rChild = s->lChild;
				}
				delete s;
			}
		}

        deleteBiNode(T->lChild, x);
        deleteBiNode(T->rChild, x);

	}
	else return;
}

int get_depth(BiNode *T, int data, int depth)  //计算某个节点的深度
{      
    if (T == NULL) {
        return 0;
    } else if (T->data == data) {
        return depth;
    } else if (T->data > data) {
        return get_depth(T->lChild, data, depth + 1);
    } else {
        return get_depth(T->rChild, data, depth + 1);
    }
}

double get_avg_length(BiNode *T){   //5.计算整棵树的平均查找长度
    if (T == NULL)
	{
        return 0;
    }
	else{
        int sum = 0, n = 0;
        for(int i = 1; i <= n; i++)
		    {
                sum += get_depth(T, i, 1);
            }
        return (double)sum/n;
    }
}

//5.计算平均查找长度
void CalcASL(BiNode* root, double& sEi, int& sCi, int level)
{
    if (root == NULL) {
        sCi = 0; // 当前节点为空时，Ci设为0
        return;
    }

    // 中序遍历左子树
    int lCi = 0, rCi = 0, lsCi = 0, rsCi = 0;
    double lsEi = 0, rsEi = 0;
    CalcASL(root->lChild, lsEi, lsCi, level + 1);

    // 中序遍历当前节点：对于二叉排序树来说，当前节点对应的关键字有一个单独的查找次数，因此 Ci 为 1
    double cur_Ei = level; // 当前节点对应的查找长度为 level
    sEi += cur_Ei;
    sCi += 1;

    // 中序遍历右子树
    CalcASL(root->rChild, rsEi, rsCi, level + 1);

    // 计算当前节点的 Ci 和 Ei
    lCi = lsCi + 1; // 左子树中的关键字在查找当前节点时都要向右查找（包括当前节点的一个单独的查找次数），因此 Ci 为左子树中关键字的总数加上1
    rCi = rsCi + 1; // 右子树中的关键字在查找当前节点都要向左查找（包括当前节点的一个单独的查找次数），因此 Ci 为右子树中关键字的总数加上1
    if (lCi == 0) {
        lCi = 1;
    } // 如果左子树中没有关键字，则左子树中的关键字在查找当前节点时不需要进行查找，因此 Ci 应该为1

    cur_Ei += (lsCi + rsCi) * cur_Ei; // 当前节点对应的查找长度等于左子树和右子树中所有关键字的 Ci 之和再乘以 level
    cur_Ei /= (lCi + rCi); // 当前节点对应的查找长度除以总的查找次数，得到当前节点的 Ei

    sEi += lsEi + rsEi + cur_Ei; // 累加每个关键字的 Ei
    sCi += lCi + rCi; // 累加每个关键字
}
    
bool isBST(BiNode* root, int min, int max) {  //6.判断当前节点是否满足二叉排序树的条件，并递归判断左右子树是否也满足二叉排序树的条件
    if (root == NULL) {
        return true;
    }
    if (root->data < min || root->data > max) {
        return false;
    }
    return isBST(root->lChild, min, root->data - 1) && 
           isBST(root->rChild, root->data + 1, max);
}

bool isBinarySearchTree(BiNode* root) {    //6.判断整棵二叉树是否为二叉排序树
    return isBST(root, INT_MIN, INT_MAX);
}
