#include<iostream>
using namespace std;

typedef struct lBNode
{
	int data;
	struct lBNode *lChild, *rChild;
}BiNode,*BiTree;


//�������--�ݹ�
void preOrderPrint(BiNode *T)  
{
	if(T)
	{
		cout<<T->data<<" ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
		preOrderPrint(T->lChild);   //�������������
		preOrderPrint(T->rChild);   //�������������
	}
}

//�������--�ݹ�
void inOrderPrint(BiNode *T)
{
	if(T)
	{
		inOrderPrint(T->lChild);    //�������������
		cout<<T->data<<" ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
		inOrderPrint(T->rChild);    //�������������
	}
}

//�������--�ݹ�
void postOrderPrint(BiNode *T)
{
	if(T)
	{
		postOrderPrint(T->lChild);   //�������������
		postOrderPrint(T->rChild);   //�������������
		cout<<T->data<<" ";          //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
	}
}

void create(int A[],int &n)   //1.������д�������±�� 0 ��ʼд�����ݣ� n Ϊ���ݸ���
{
	cout<<"���������ݣ�-1������"<<endl;
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

int bin_search(int A[],int n,int x)   //1.���ö��ֲ����㷨ʵ�ֲ���
{
	int mid,low = 0,high = n-1;
	while(low <= high)
	{
		mid = (high + low) / 2;
		cout<<"��ǰֵΪ"<<A[mid];
		if(A[mid] == x)
		{
			cout<<"    ��ǰֵΪĿ������"<<endl;
			return mid;
		}
		else if(A[mid] < x)
		{
			cout<<"    ��ǰֵС�ڴ������ݣ�ת������"<<endl;
			low = mid + 1;
		}
		else
		{
			cout<<"    ��ǰֵ���ڴ������ݣ�ת������"<<endl;
			high = mid - 1;
		}
	}
	return -1;
}

void insert(BiNode *&T,BiNode *S)  //2.����������
{
	if(T == NULL)  T = S;
	else if(S->data < T->data)  insert(T->lChild,S);
	else if(S->data > T->data)  insert(T->rChild,S);
}


void createBst(BiNode *&T)    //2.���뷨����������
{
	T = NULL;
	int x;
	BiNode *S;

	cout<<"�������ݣ�-1����"<<endl;
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


BiNode *bes_search(BiNode *T,int x)  //3.����������
{
	BiNode *p = T;
	while(p != NULL)
	    if(x == p->data)  return p;
	    else if(x < p->data)  p = p->lChild;
	    else  p = p->rChild;
	return p;
}

void deleteBiNode(BiNode *&T, int x)    //4.������ɾ��
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

int get_depth(BiNode *T, int data, int depth)  //����ĳ���ڵ�����
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

double get_avg_length(BiNode *T){   //5.������������ƽ�����ҳ���
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

//5.����ƽ�����ҳ���
void CalcASL(BiNode* root, double& sEi, int& sCi, int level)
{
    if (root == NULL) {
        sCi = 0; // ��ǰ�ڵ�Ϊ��ʱ��Ci��Ϊ0
        return;
    }

    // �������������
    int lCi = 0, rCi = 0, lsCi = 0, rsCi = 0;
    double lsEi = 0, rsEi = 0;
    CalcASL(root->lChild, lsEi, lsCi, level + 1);

    // ���������ǰ�ڵ㣺���ڶ�����������˵����ǰ�ڵ��Ӧ�Ĺؼ�����һ�������Ĳ��Ҵ�������� Ci Ϊ 1
    double cur_Ei = level; // ��ǰ�ڵ��Ӧ�Ĳ��ҳ���Ϊ level
    sEi += cur_Ei;
    sCi += 1;

    // �������������
    CalcASL(root->rChild, rsEi, rsCi, level + 1);

    // ���㵱ǰ�ڵ�� Ci �� Ei
    lCi = lsCi + 1; // �������еĹؼ����ڲ��ҵ�ǰ�ڵ�ʱ��Ҫ���Ҳ��ң�������ǰ�ڵ��һ�������Ĳ��Ҵ���������� Ci Ϊ�������йؼ��ֵ���������1
    rCi = rsCi + 1; // �������еĹؼ����ڲ��ҵ�ǰ�ڵ㶼Ҫ������ң�������ǰ�ڵ��һ�������Ĳ��Ҵ���������� Ci Ϊ�������йؼ��ֵ���������1
    if (lCi == 0) {
        lCi = 1;
    } // �����������û�йؼ��֣����������еĹؼ����ڲ��ҵ�ǰ�ڵ�ʱ����Ҫ���в��ң���� Ci Ӧ��Ϊ1

    cur_Ei += (lsCi + rsCi) * cur_Ei; // ��ǰ�ڵ��Ӧ�Ĳ��ҳ��ȵ����������������������йؼ��ֵ� Ci ֮���ٳ��� level
    cur_Ei /= (lCi + rCi); // ��ǰ�ڵ��Ӧ�Ĳ��ҳ��ȳ����ܵĲ��Ҵ������õ���ǰ�ڵ�� Ei

    sEi += lsEi + rsEi + cur_Ei; // �ۼ�ÿ���ؼ��ֵ� Ei
    sCi += lCi + rCi; // �ۼ�ÿ���ؼ���
}
    
bool isBST(BiNode* root, int min, int max) {  //6.�жϵ�ǰ�ڵ��Ƿ�������������������������ݹ��ж����������Ƿ�Ҳ�������������������
    if (root == NULL) {
        return true;
    }
    if (root->data < min || root->data > max) {
        return false;
    }
    return isBST(root->lChild, min, root->data - 1) && 
           isBST(root->rChild, root->data + 1, max);
}

bool isBinarySearchTree(BiNode* root) {    //6.�ж����ö������Ƿ�Ϊ����������
    return isBST(root, INT_MIN, INT_MAX);
}
