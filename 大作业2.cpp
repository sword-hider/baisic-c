#include<stdio.h>
#include<malloc.h>

typedef struct Num//定义栈的元素 
{
	int num; 
	Num *next;
}Num,*pNum;
Num *top;
void push(Num *&top,int x)
{
	Num *p=(Num*)malloc(sizeof(Num));//分配新的节点内存 
	if(p==NULL)//若无法分配，报错 
	{
		printf("error");
	}
	p->num=x;//输入值 
	p->next=top->next;//指向下一节点 
	top->next=p;//栈顶指针指向新的节点 

}

void pop(Num *&top,int &x)
{
    Num *p; 
	p=top->next;//p为栈顶 
	x=p->num;//取出p节点的值 
	top->next=p->next;//栈顶指针向前移动 
	free(p);//释放p的内存 
}
void show(Num *&top)
{
	if(top==NULL)
	{
		printf("error");
	}
	while(top!=NULL)
	{
		printf("%d",top->next->num);
	    top->next=top->next->next;	
	}
}
int main()
{
	int x;
	int i,n;
    top=(Num*)malloc(sizeof(Num));
    top->next=NULL;
    for(i=0;i<5;++i){
    	scanf("%d",&x);
    	push(top,x);
	}
	
	pop(top,n);
	printf("%d\n",n);
	
	printf("%d\n",top->next->num);
	show(top);
	return 0;
}

