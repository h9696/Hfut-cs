#include"seqStack.h"
using namespace std;

void test01()
{
    seqStack S;
    int x,m;
    initialStack(&S);
    cout<<"������һ��ʮ��������";
    cin>>x;
    cout<<"ת�����ƣ�";
    cin>>m;
	convert(x,m);
}

void test02()
{
	seqStack S;
	initialStack(&S);
	cout<<"��������ʽ��"<<endl;
	char str[MAXLEN];
	cin>>str;
	brackeMatch2(str);
}

void test03()
{
      cout<<"������1~n��n����:";
      while(cin>>n)
      {
        res=0;
        clear(in);
        clear(out);
        clear(s);
        for(i=n;i>=1;i--)
              in.push(i);
        dostack(in,s,out);
        cout<<"��Ӧ�ĳ�ջ�������="<<res<<endl;
    }
}

int main()
{
	int n;
    cout << "****************************************" << endl;
	cout << "***��ʼʵ�����                      ***" << endl;
	cout << "***0.�˳�                            ***" << endl;
	cout << "***1.10������ת��Ϊ2-36��������      ***" << endl;
	cout << "***2.�жϱ��ʽ�Ƿ�ƥ��              ***" << endl;
	cout << "***3.�ж�ջ������еĺϷ���          ***" << endl;
	cout << "****************************************" << endl;
	cout << endl << "������0-3��";
	
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
		    cout<<"��������ȷ��ѡ�"<<endl; 	
	}
	
	
	return 0;
}
