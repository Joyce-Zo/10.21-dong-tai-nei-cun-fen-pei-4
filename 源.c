#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	double input = 0;
	scanf("%lf", &input);
	printf("%lf ", (input - 0.0463) / 1.3932);
	return 0;
}

				������

			2.1 ��

char* GetMemory(void) 
{
	char p[] = "hello world"; 
	return p;		// �˴��Ǿֲ�����������ջ�ռ䣬��Ϊ����ջ�ռ��ַ������
				pֻ�ڴ˺����ڲ���Ч������������Ȼp�ĵ�ַ�����أ���p�Ŀռ��Ѿ��ͷ��޷��ҵ�
				��������ӡ���ֵ
}
void Test(void)
{
	char* str = NULL; 
	str = GetMemory(); 
	printf(str);
}
int main() 
{
	Test();
	return 0;
}

			2.2	��

int* test()
{
	static int a = 10;// ����staticʹ����ھ�̬�����ӳ���������
	return &a;
}
int main()
{
	int* p = test();
	*p = 20;
	printf("%d ", *p);
	return 0;
}

			2.3 ��

int* test()
{
	int* ptr = malloc(100);// malloc�ڶ�����,��free�������
	return ptr;	// ����������ptrָ�����ڿռ䱻���٣�������ָ���malloc���ٵĿռ����
}
int main()
{
	int* p = test();
	return 0;
}

				3

void GetMemory(char **p,int num)// str��char*,����&strҪ��char**
{
	*p = (char*)malloc(num);// *p��str
}
void Test(void) 
{
	char* str = NULL; 
	GetMemory(&str, 100); 
	strcpy(str, "hello");
	printf(str);// ʹ����û���ͷţ�����ڴ�й©
	free(str);
	str = NULL;
}
int main() 
{
	Test();
	return 0;
}

				4

void Test(void) 
{
	char* str = (char*)malloc(100); 
	strcpy(str, "hello");
	free(str);	// free��str�Ŀռ��ͷţ����ǲ���Ϊ��ָ�룬��Ҫ����������ΪNULL
	str = NULL;
	if (str != NULL) 
	{			// ��������str���Ͳ�����NULL���ٽ���strcpy������ɷǷ�����
		strcpy(str,"wor1d"); 
		printf(str);
	}
}
int main()
{
	Test(); 
	return 0;
}