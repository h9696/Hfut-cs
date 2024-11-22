#include"seqStack.h"
using namespace std;

void test01()
{
    seqStack S;
    int x,m;
    initialStack(&S);
    cout<<"请输入一个十进制数：";
    cin>>x;
    cout<<"转换进制：";
    cin>>m;
	convert(x,m);
}

void test02()
{
	seqStack S;
	initialStack(&S);
	cout<<"请输入表达式："<<endl;
	char str[MAXLEN];
	cin>>str;
	brackeMatch2(str);
}

void test03()
{
      cout<<"请输入1~n共n个数:";
      while(cin>>n)
      {
        res=0;
        clear(in);
        clear(out);
        clear(s);
        for(i=n;i>=1;i--)
              in.push(i);
        dostack(in,s,out);
        cout<<"对应的出栈情况总数="<<res<<endl;
    }
}

int main()
{
	int n;
    cout << "****************************************" << endl;
	cout << "***开始实验测试                      ***" << endl;
	cout << "***0.退出                            ***" << endl;
	cout << "***1.10进制数转换为2-36进制数：      ***" << endl;
	cout << "***2.判断表达式是否匹配              ***" << endl;
	cout << "***3.判断栈输出序列的合法性          ***" << endl;
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
