#include"linkedStack.h"
using namespace std;

void test01()
{
	int i=0;
	char x;
	sNode *top;
	initialStack(top);
	elementType a,b;
	cout<<"������ʮ��������";
	cin>>a;
	cout<<"������Ҫת���Ľ��ƣ�";
	cin>>b;
	linkedStack S=ChangeSystemLinked(a,b);
	
	displayLinked(S);
	//cout<<"ת���ɹ�����Ϊ��"<<top->data;
}

void test02()
{
	sNode *top;
	initialStack(top);
	cout<<"��������ʽ��"<<endl;
	char str[MAXLEN];
	cin>>str;
	if(bracketMatch2Linked(str))
		cout << "���ʽ" << str << "�е�������ƥ���" << endl;
	else
		cout << "���ʽ" << str << "�е������ǲ�ƥ���" << endl;
}

void test03()
{
    int num;
    cout << "��������ջ��Ԫ�ظ�����" << endl;
    cin >> num;
    cout << "����ջ�����У�" << endl;
    char b[MAXLEN];
    cin >> b;  //�����ʱ�����пո� 
    cout << "������п���Ϊ��" << endl;
    print_all_Stack(b, 0, num-1);
}

int main()
{
    int n;
	cout << "****************************************" << endl;
	cout << "***��ʼʵ�����                      ***" << endl;
	cout << "***0.�˳�                            ***" << endl;
	cout << "***1.10������ת��Ϊ2-36��������      ***" << endl;
	cout << "***2.�жϱ��ʽ�Ƿ�ƥ��              ***" << endl;
	cout << "***3.������п��ܵĳ�ջ����          ***" << endl;
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
