#include"linkedStack.h"
using namespace std;

void test01()
{
	int i=0;
	char x;
	sNode *top;
	initialStack(top);
	elementType a,b;
	cout<<"请输入十进制数：";
	cin>>a;
	cout<<"请输入要转化的进制：";
	cin>>b;
	linkedStack S=ChangeSystemLinked(a,b);
	
	displayLinked(S);
	//cout<<"转换成功的数为："<<top->data;
}

void test02()
{
	sNode *top;
	initialStack(top);
	cout<<"请输入表达式："<<endl;
	char str[MAXLEN];
	cin>>str;
	if(bracketMatch2Linked(str))
		cout << "表达式" << str << "中的括号是匹配的" << endl;
	else
		cout << "表达式" << str << "中的括号是不匹配的" << endl;
}

void test03()
{
    int num;
    cout << "请输入链栈的元素个数：" << endl;
    cin >> num;
    cout << "输入栈的序列：" << endl;
    char b[MAXLEN];
    cin >> b;  //输入的时候不能有空格 
    cout << "输出序列可能为：" << endl;
    print_all_Stack(b, 0, num-1);
}

int main()
{
    int n;
	cout << "****************************************" << endl;
	cout << "***开始实验测试                      ***" << endl;
	cout << "***0.退出                            ***" << endl;
	cout << "***1.10进制数转换为2-36进制数：      ***" << endl;
	cout << "***2.判断表达式是否匹配              ***" << endl;
	cout << "***3.输出所有可能的出栈序列          ***" << endl;
	cout << "****************************************" << endl;
	cout << endl << "请输入0-3：";
	
	cin>>n;
		switch(n){
		case 1:
			test01();
			break;
		case 2:
		    test02();
		    break;
		case 3:
		 	test03();
		 	break;
		
		default:
		    cout<<"请输入正确的选项！"<<endl; 	
	}
	
	return 0;
}
