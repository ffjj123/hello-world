����ϵͳ��0��ʵ�飺Linux��ʶ

## ʵ�黷��
��VMware Workstation Pro�����µ�Centos6����


���裺1�����ڵ��Ե�Dev-c++���д������������ȷ����ʾ�������
         2����c�����ļ��������ı������������
         3�������shell�ű���Compile.sh(����ű�)��Run.sh��ִ�нű����������ն��ж����ű�����Ȩ�ޡ�
         4��ִ��Compile.sh�ļ������ɻ�������ı�Sourcecode.o�ı���֮��ִ��Run.sh�ı������ɽ����

���⣺1����linux�ն��б�д��shell�ű����޷����С���ɴ�ԭ������Ϊû�����ն��ж��丳����Ӧ��дȨ�ޣ����֮��������chmod�������������shell�ű�Ȩ�ޡ�
         2�����ִ�����������⣬��windows�±�дû�������linux��ȴ���ִ���

��������з�ʽ���Ȱ��ļ����������������������նˣ�����chmod 777 Compile.sh �� chmod 777 Run.sh��shell�ļ���Ȩ��
Ȼ������./Compile.sh ���б���ű���Ȼ������ִ�нű�./Run.sh customer.txt orders.txt lineitem.txt 1 BUILDING 1995-03-29 1995-03-27 5
���յõ�
l_orderkey|o_orderdate|revenue
450       |1995-03-05 |166262.09
359       |1994-12-19 |58329.62
577       |1994-12-19 |41811.50

����customer.txt orders.txt lineitem.txt 3 BUILDING 1995-03-29 1995-03-27 5 BUILDING 1995-02-29 1995-04-27 10 BUILDING 1995-03-28 1995-04-27 2

���յõ�
3       mktsegment:BUILDING     order_date:1995-03-29   ship_date:1995-03-27    limit:5
l_orderkey|o_orderdate|revenue
450       |1995-03-05 |166262.09
359       |1994-12-19 |58329.62
577       |1994-12-19 |41811.50
2       mktsegment:BUILDING     order_date:1995-02-29   ship_date:1995-04-27    limit:10
l_orderkey|o_orderdate|revenue