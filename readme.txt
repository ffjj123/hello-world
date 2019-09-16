操作系统第0次实验：Linux初识

## 实验环境
在VMware Workstation Pro环境下的Centos6开发


步骤：1、先在电脑的Dev-c++里编写程序，最终能正确的显示出结果。
         2、将c程序文件和数据文本导入虚拟机中
         3、编译好shell脚本：Compile.sh(编译脚本)和Run.sh（执行脚本），并在终端中对两脚本赋予权限。
         4、执行Compile.sh文件，生成汇编语言文本Sourcecode.o文本。之后执行Run.sh文本，生成结果。

问题：1、在linux终端中编写好shell脚本后无法运行。造成此原因是因为没有在终端中对其赋予相应读写权限，因此之后在利用chmod的相关命令授予shell脚本权限。
         2、部分代码兼容性问题，在windows下编写没问题而在linux下却出现错误。

编译和运行方式：先把文件传入虚拟机，打开虚拟机的终端，输入chmod 777 Compile.sh 和 chmod 777 Run.sh对shell文件授权，
然后输入./Compile.sh 运行编译脚本，然后输入执行脚本./Run.sh customer.txt orders.txt lineitem.txt 1 BUILDING 1995-03-29 1995-03-27 5
最终得到
l_orderkey|o_orderdate|revenue
450       |1995-03-05 |166262.09
359       |1994-12-19 |58329.62
577       |1994-12-19 |41811.50

输入customer.txt orders.txt lineitem.txt 3 BUILDING 1995-03-29 1995-03-27 5 BUILDING 1995-02-29 1995-04-27 10 BUILDING 1995-03-28 1995-04-27 2

最终得到
3       mktsegment:BUILDING     order_date:1995-03-29   ship_date:1995-03-27    limit:5
l_orderkey|o_orderdate|revenue
450       |1995-03-05 |166262.09
359       |1994-12-19 |58329.62
577       |1994-12-19 |41811.50
2       mktsegment:BUILDING     order_date:1995-02-29   ship_date:1995-04-27    limit:10
l_orderkey|o_orderdate|revenue