#include<stdio.h>
#include<malloc.h>

typedef struct Num//����ջ��Ԫ�� 
{
	int num; 
	Num *next;
}Num,*pNum;
Num *top;
void push(Num *&top,int x)
{
	Num *p=(Num*)malloc(sizeof(Num));//�����µĽڵ��ڴ� 
	if(p==NULL)//���޷����䣬���� 
	{
		printf("error");
	}
	p->num=x;//����ֵ 
	p->next=top->next;//ָ����һ�ڵ� 
	top->next=p;//ջ��ָ��ָ���µĽڵ� 

}

void pop(Num *&top,int &x)
{
    Num *p; 
	p=top->next;//pΪջ�� 
	x=p->num;//ȡ��p�ڵ��ֵ 
	top->next=p->next;//ջ��ָ����ǰ�ƶ� 
	free(p);//�ͷ�p���ڴ� 
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

