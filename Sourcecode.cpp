#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
	int c_custkey;    	   
	char c_mkgsegment[20]; 
}customer;				   

typedef struct
{
	int o_orderkey;    	 //������ 
	int o_custkey;    	 //�˿ͱ��
	char o_orderdate[10];//�������� 
}orders;				 

typedef struct
{
	int l_orderkey;//������
	double l_extendedprice;//����۸�
	char l_shipdate[10];//�������� 
}lineitem; 

typedef struct
{
	int l_orderkey;//������
	char o_orderdate[10];//�������� 
	double l_extendedprice;//����۸�
}select_result;


customer * read_customer_txt() 
{
	FILE * fp;
	customer *a=NULL;
	a = (customer *)malloc(105*sizeof(customer));
	int i=0;
	char b;
	fp = fopen("C:\\Users\\78332\\Desktop\\���ǿ4042017004\\Sourcecode\\customer.txt","r");
	if(NULL==fp)
	{
		printf("cannot open customer.txt!");
		return NULL;
	}
	while(!feof(fp))
	{	
		//printf("%d  ",i);
		fscanf(fp,"%d%c%s",&a[i].c_custkey,&b,&a[i].c_mkgsegment);
		//printf("%d%c%s\n",a[i].c_custkey,b,a[i].c_mkgsegment);
		i++;
	}
	fclose(fp);
	return a;
}
orders * read_orders_txt()
{
	int i =0; 
	orders * a=NULL;
	a = (orders * )malloc(4005*sizeof(orders));
	char b,c;
	long d;
	FILE *fp;
	fp = fopen("C:\\Users\\78332\\Desktop\\���ǿ4042017004\\Sourcecode\\orders.txt","r");
	if(fp == NULL)
	{
		printf("cannot open orders.txt!");
		return NULL;
	}
	while(!feof(fp))
	{	
		//printf("%d!",i);
		fscanf(fp,"%d%c%lld%c%s",&a[i].o_orderkey,&b,&d,&c,&a[i].o_orderdate);
		a[i].o_custkey=d%100;
		//printf("%d %c	%lld %c	%s\n",a[i].o_orderkey,b,a[i].o_custkey,c,a[i].o_orderdate);
		i++;
	}
	fclose(fp);
	return a;
}

lineitem * read_lineitem_txt()
{
	FILE * fp;
	lineitem * l=NULL;
	l = (lineitem *)malloc(1005*sizeof(lineitem));
	int i=0;
	char b,c;
	fp = fopen("C:\\Users\\78332\\Desktop\\���ǿ4042017004\\Sourcecode\\lineitem.txt","r");
	if(fp==NULL)
	{
		printf("cannot open lineitem.txt!");
		return NULL;
	}
	while(!feof(fp))
	{
		//printf("%d!",i);
		fscanf(fp,"%d%c%lf%c%s",&l[i].l_orderkey,&c,&l[i].l_extendedprice,&b,&l[i].l_shipdate);
		//printf("%d,%lf,%s\n",l[i].l_orderkey,l[i].l_extendedprice,l[i].l_shipdate);
		i++;
	}
	fclose(fp);
	return l; 
}

select_result * Select(customer * cus,orders * ord,lineitem * item,char * order_date,char * ship_date,char * mktsegment)
{
	int i,j,k,l=0,m=0;
	select_result * result1=NULL;
	select_result * result2=NULL;
	select_result  temp;
	result1 = (select_result *)malloc(1005*sizeof(select_result));
	result2 = (select_result *)malloc(1005*sizeof(select_result));
	for(i=0;i<100;i++)
	{
		for(j=0;j<4000;j++)
		{
			for(k=0;k<1000;k++)
			if(cus[i].c_custkey==ord[j].o_custkey&&ord[j].o_orderkey==item[k].l_orderkey&&(strcmp(ord[j].o_orderdate,order_date)<0)&&(strcmp(item[k].l_shipdate,ship_date)>0)&&(strcmp(cus[i].c_mkgsegment,mktsegment)==0))
			{
				result1[l].l_orderkey=item[k].l_orderkey;
				strcpy(result1[l].o_orderdate,ord[j].o_orderdate);
				result1[l].l_extendedprice=item[k].l_extendedprice;
				l++;
			}
		}
	}
	for(i=0;i<l;i++)
	{
		if(i==0)
		{
			result2[m].l_orderkey = result1[i].l_orderkey;
			strcpy(result2[m].o_orderdate,result1[i].o_orderdate);
			result2[m].l_extendedprice = result1[i].l_extendedprice;
			continue;
		}
		if(result1[i].l_orderkey==result1[i-1].l_orderkey)
		{
			result2[m].l_extendedprice = result2[m].l_extendedprice + result1[i].l_extendedprice;
			
		}
		else
		{
			
			m++;
			result2[m].l_orderkey = result1[i].l_orderkey;
			strcpy(result2[m].o_orderdate,result1[i].o_orderdate);
			result2[m].l_extendedprice = result1[i].l_extendedprice;
			
		}
	}
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<m-1-i;j++)
		{
			if(result2[j].l_extendedprice<result2[j+1].l_extendedprice)
			{
				temp.l_extendedprice=result2[j].l_extendedprice;
				temp.l_orderkey=result2[j].l_orderkey;
				strcpy(temp.o_orderdate,result2[j].o_orderdate);
				result2[j].l_extendedprice=result2[j+1].l_extendedprice;
				result2[j].l_orderkey=result2[j+1].l_orderkey;
				strcpy(result2[j].o_orderdate,result2[j+1].o_orderdate);
				result2[j+1].l_extendedprice=temp.l_extendedprice;
				result2[j+1].l_orderkey=temp.l_orderkey;
				strcpy(result2[j+1].o_orderdate,temp.o_orderdate);
			}
		}
	}
 
	return result2;
}


int change_argv_to_number(char s[])//�������������������ַ���ת��Ϊ�������� 
{
	int i=0;
	int number=0;
	while(s[i]!='\0')
	{
		if(i==0)
			number = (s[i]-48);
		else
			number = number*10 + (s[i]-48);
		//printf("%d,%d\n",i,number);
		i++;
	}
	return number;
}


int main(int argc,char * argv[])
{
	int i,j;
	int num;
	//for(i=0;i<argc;i++)       printf("%d		%s\n",i,argv[i]);
	int limit=3;
	char order_date[10];
	char ship_date[10];
	char mktsegment[20];
	select_result *result=NULL;
	customer * cus = NULL;
	orders * ord = NULL;//ָ�򶩵����ָ�� 
	lineitem * item = NULL;//ָ�� ��Ʒ���ָ�� 
	cus = read_customer_txt();
	ord = read_orders_txt();/
	item = read_lineitem_txt(); 
	num = change_argv_to_number(argv[4]);//�ܹ�����Ĵ���
	
	for(i=0;num>0;num--,i=i+4)
	{
		limit = change_argv_to_number(argv[8+i]);
		strcpy(order_date,argv[6+i]);
		strcpy(ship_date,argv[7+i]);
		strcpy(mktsegment,argv[5+i]);
		printf("%d	mktsegment:%s	order_date:%s	ship_date:%s	limit:%d\n",num,mktsegment,order_date,ship_date,limit);
		result=Select(cus,ord,item,order_date,ship_date,mktsegment);
		printf("l_orderkey|o_orderdate|revenue\n");
		for(j=0;j<limit;j++)
		{
			if(result[j].l_extendedprice==0)
				printf("null      |null       |null   \n");
			else
			{
				if(result[j].l_orderkey!=-842150451)
					printf("%-10d|%-11s|%-20.2lf\n",result[j].l_orderkey,result[j].o_orderdate,result[j].l_extendedprice);
			}
		}
		free(result);
		result = NULL;
	} 
	return 0;
}
