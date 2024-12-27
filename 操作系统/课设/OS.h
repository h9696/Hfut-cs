
#ifndef WORK_OS_H
#define WORK_OS_H
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

/***************************************************以下为各命令的帮助文档***********************************************/
#define PRINTLSHELP "用法：ls  [选项]\n\
列出文件信息(默认为当前目录)\n\
ls无参         显示一个目录中的文件和子目录\n\
ls -l          每行仅显示一个目录或名称\n\
ls --help      显示此帮助信息并离开"
#define PRINTMKDIRHELP "用法：mkdir  目录\n\
若目录不存在则创建目录\n\
mkdir --help   显示此帮助信息并离开"
#define PRINTRMDIRHELP "用法：rmdir  目录\n\
若目录没有数据则删除目录\n\
rmdir --help   显示此帮助信息并离开"
#define PRINTCPHELP "用法：cp  来源文件 目的文件\n\
将来源文件复制到目的文件\n\
cp --help   显示此帮助信息并离开"
#define PRINTCATHELP "用法：cat  文件\n\
  或：cat  文件1 >> 文件2\n\
显示文件内容或连接两个文件，并将结果输出到显示屏上\n\
cat 文件            将文件的内容输出到显示屏上\n\
cat 文件1 >> 文件2  将文件1连接到文件2的结尾，并输出到显示屏上\n\
cat --help          显示此帮助信息并离开"
#define PRINTSORTHELP "用法：sort 文件\n\
将文本文件内容加以排序\n\
sort --help       显示此帮助信息并离开"

#endif //WORK_OS_H
