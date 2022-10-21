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

				笔试题

			2.1 ×

char* GetMemory(void) 
{
	char p[] = "hello world"; 
	return p;		// 此处是局部变量，放在栈空间，即为返回栈空间地址的问题
				p只在此函数内部有效，出函数后虽然p的地址被返回，但p的空间已经释放无法找到
				故下面会打印随机值
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

			2.2	×

int* test()
{
	static int a = 10;// 加上static使其放在静态区，延长生命周期
	return &a;
}
int main()
{
	int* p = test();
	*p = 20;
	printf("%d ", *p);
	return 0;
}

			2.3 √

int* test()
{
	int* ptr = malloc(100);// malloc在堆区上,不free不会回收
	return ptr;	// 函数结束后，ptr指针所在空间被销毁，但其所指向的malloc开辟的空间存在
}
int main()
{
	int* p = test();
	return 0;
}

				3

void GetMemory(char **p,int num)// str是char*,所以&str要用char**
{
	*p = (char*)malloc(num);// *p即str
}
void Test(void) 
{
	char* str = NULL; 
	GetMemory(&str, 100); 
	strcpy(str, "hello");
	printf(str);// 使用完没有释放，造成内存泄漏
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
	free(str);	// free把str的空间释放，但是不置为空指针，需要我们主动赋为NULL
	str = NULL;
	if (str != NULL) 
	{			// 否则这里str本就不等于NULL，再进行strcpy，将造成非法访问
		strcpy(str,"wor1d"); 
		printf(str);
	}
}
int main()
{
	Test(); 
	return 0;
}