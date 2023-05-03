#include"MyString.h"
using namespace std;

void test()
{
	MyString s1(5, 'w');
	cout<<s1<<endl;
	MyString s2(3, 'e');
	cout<<s2<<endl;
	MyString s3;
	s3 = s1+s2;
	cout<<s3<<endl;
	MyString s4 = s3+"hellow";
	cout<<s4<<endl;
	for(int i=0; i<s4.Size(); i++)
	{
		cout<< s4[i]<<" ";
	}
	cout<<endl;
	MyString s5(2,'l');
	s4 += s5;
	cout<<s4<<endl;
	s4 += "bit";
	cout<<s4<<endl;
	cin>>s4;
	cout<<s4<<endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}