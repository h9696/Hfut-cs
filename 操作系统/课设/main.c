#include "OS.h"

char buf[100], path[100], path1[100], path2[100]; // 全局变量，buf用于缓存数据，3个path用于保存路径

/*cd命令*/
void cd_cmd(char* route) {
    if (!SetCurrentDirectory(route)) {
        printf("路径不存在!\n");
        printf("%s>", path);
    }
    else {
        SetCurrentDirectory(route);
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
}


/*ls命令*/
void ls_cmd(char* array) {
    HANDLE handle;
    int filenum = 0;
    FILETIME lpCreationTime, lpLastAccessTime, lpLastWriteTime;
    SYSTEMTIME stime;
    WIN32_FIND_DATA* path2 = (WIN32_FIND_DATA*)malloc(sizeof(WIN32_FIND_DATA));
    if (!GetCurrentDirectory(50, path1)) {
        printf("路径不存在!\n");
        return;
    }

    strcat(path1, "\\*.*"); // DOS通配符
    if ((handle = FindFirstFile(path1, path2)) != INVALID_HANDLE_VALUE) {
        do {
            HANDLE hDir = CreateFile(path2->cFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_DELETE,
                                     NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
            if (GetFileTime(hDir, &lpCreationTime, &lpLastAccessTime, &lpLastWriteTime)) {
                FILETIME ftime;
                FileTimeToLocalFileTime(&lpLastWriteTime, &ftime); // 转换成本地时间
                FileTimeToSystemTime(&ftime, &stime); // 转换成系统时间格式
            }
            // printf("%04d-%02d-%02d %02d:%02d %s\n", stime.wYear, stime.wMonth, stime.wDay, stime.wHour, stime.wMinute, path2->cFileName);
            if (strcmp(array, "ls") == 0) {
                printf("%-20s", path2->cFileName);
                if (filenum % 3 == 2) {
                    printf("\n");
                }
                filenum++;
            }
            else {
                printf("%04d-%02d-%02d %02d:%02d %s\n", stime.wYear, stime.wMonth, stime.wDay, stime.wHour, stime.wMinute, path2->cFileName);
            }

            CloseHandle(hDir);
        } while (FindNextFile(handle, path2));
    }
    FindClose(handle);
    printf("\n");
    GetCurrentDirectory(100, path1);
    printf("%s>", path1);
}



/*mkdir命令*/
void mkdir_cmd(char* array) {
    GetCurrentDirectory(100, path);
    strcat(path, "\\");
    strcat(path, array);
    WIN32_FIND_DATA wfd;
    HANDLE hFind;
    hFind = FindFirstFile(path, &wfd);
    if (hFind != INVALID_HANDLE_VALUE) {
        printf("该目录已存在，创建失败!\n");
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
    else {
        CreateDirectory(array, NULL);
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
}


/*rmdir命令*/
void rmdir_cmd(char* array) {
    GetCurrentDirectory(100, path);
    strcat(path, "\\");
    strcat(path, array);
    WIN32_FIND_DATA wfd;
    HANDLE hFind;
    hFind = FindFirstFile(path, &wfd);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("该目录不存在，删除失败!\n");
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
    else {
        RemoveDirectory(array);
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
}



/*cp命令*/
void cp_cmd(char* array1, char* array2) {
    char fullSourcePath[100], fullDestPath[100];
    GetCurrentDirectory(100, fullSourcePath);
    strcat(fullSourcePath, "\\");
    strcat(fullSourcePath, array1);

    GetCurrentDirectory(100, fullDestPath);
    strcat(fullDestPath, "\\");
    strcat(fullDestPath, array2);

    if (!CopyFile(fullSourcePath, fullDestPath, FALSE)) {
        printf("复制失败，请检查路径和文件是否存在！错误代码: %lu\n", GetLastError());
    } else {
        printf("文件复制成功: %s -> %s\n", fullSourcePath, fullDestPath);
    }

    GetCurrentDirectory(100, path);
    printf("%s>", path);

}


/*cat命令*/
void cat_cmd1(char* array) { // 用于显示文件
    char ch[1000];
    GetCurrentDirectory(100, path);
    strcat(path, "\\");
    strcat(path, array);
    FILE* infile = fopen(path, "r");
    if (!infile) {
        printf("无法打开文件%s\n", path);
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
    else {
        while (fgets(ch, 1000, infile)) {
            printf("%s", ch);
        }
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
    fclose(infile);
}
void cat_cmd2(char *array1, char *array2) {
    char ch[1000];
    GetCurrentDirectory(100, path); // 保存cat操作之前的路径
    strcpy(path1, path); // 复制当前路径到path1
    strcat(path1, "\\");
    strcpy(path2, path); // 复制当前路径到path2
    strcat(path2, "\\");
    strcat(path1, array1); // 构造输入文件的完整路径
    strcat(path2, array2); // 构造输出文件的完整路径

    FILE *infile1 = fopen(path1, "r");
    if (!infile1) {
        printf("无法打开文件%s\n", path1);
        GetCurrentDirectory(100, path1);
        printf("%s>", path1);
    } else {
        FILE *outfile2 = fopen(path2, "a"); // 以追加模式打开输出文件
        if (!outfile2) {
            printf("无法打开文件%s\n", path2);
            GetCurrentDirectory(100, path2);
            printf("%s>", path2);
        } else {
            while (fgets(ch, 1000, infile1) != NULL) { // 读取输入文件并写入输出文件
                fputs(ch, outfile2);
            }
            fclose(infile1);
            fclose(outfile2);

            FILE *infile2 = fopen(path2, "r"); // 重新打开输出文件以读取内容
            if (infile2) {
                while (fgets(ch, 1000, infile2) != NULL) { // 读取并打印输出文件的内容
                    printf("%s", ch);
                }
                fclose(infile2);
            }
        }
    }
    printf("%s>", path);
}

/*sort命令*/
void cmd_sort(char *array) {
    int lnum = 0, min;
    char line[100][100], tmp[100]; // 行数、每行字符数

    // 获取当前目录并拼接文件名
    GetCurrentDirectory(100, path);
    strcat(path, "\\");
    strcat(path, array);

    FILE *infile = fopen(path, "r");
    if (!infile) {
        printf("无法打开文件%s\n", array);
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    } else {
        // 读取文件内容并记录行数
        while (fgets(line[lnum], 100, infile) != NULL) {
            lnum++; // 记录总行数
        }
        fclose(infile);

        // 简单的冒泡排序
        for (int x = 0; x < lnum - 1; x++) {
            min = x;
            for (int y = x + 1; y < lnum; y++) {
                if (strcmp(line[y], line[min]) < 0) {
                    min = y;
                }
            }
            if (min != x) {
                strcpy(tmp, line[x]);
                strcpy(line[x], line[min]);
                strcpy(line[min], tmp);
            }
        }

        // 将排序后的内容写回文件
        FILE *outfile = fopen(path, "w");
        if (!outfile) {
            printf("文件打开失败\n");
        } else {
            for (int c = 0; c < lnum; c++) {
                fprintf(outfile, "%s\n", line[c]);
            }
            fclose(outfile);
        }
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
}

int main() {
    int i, j, k, input_len = 0;
    char c;
    char* arg[4];

    printf("*******************************************************************************\n\n");
    printf("    此程序兼容了Linux的ls,cat,cp,mkdir,rmdir,cd,sort命令，欢迎使用!    \n\n");
    printf("*******************************************************************************\n");

    // 把默认路径设为c盘根目录
    SetCurrentDirectoryA("C:\\");

    // 获取当前工作目录并存储到path变量中
    char path[100];
    GetCurrentDirectoryA(100, path);

    // 打印当前工作目录
    printf("%s>", path);

    while (1) {
        for (i = 0; i < 2; i++) {
            arg[i] = NULL;
        }

        while ((c = getchar()) == ' ' || c == '\t' || c == EOF); // 读入命令

        if (c == '\n') {
            continue;
        }

        input_len = 0;
        while (c != '\n') {
            buf[input_len++] = c;
            c = getchar();
        }
        buf[input_len] = '\0';

        char* input = (char*)malloc(input_len + 1);
        strcpy(input, buf); // 将命令从缓存复制到input中

        /********************把命令解析成：命令+[参数]的形式**********************/
        for (i = 0, j = 0, k = 0; i < input_len; i++) {
            if ((input[i] == ' ' || input[i] == '\0') && (k == 0)) {
                if (j != 0) { // 去掉连在一起的多个空格
                    buf[j] = '\0';
                    arg[k] = (char*)malloc((j + 1) * sizeof(char));
                    strcpy(arg[k], buf);
                    j = 0;
                    k++;
                }
            }
            else {
                buf[j++] = input[i];
            }
        }
        if (j != 0) {
            arg[k] = (char*)malloc((j + 1) * sizeof(char));
            strcpy(arg[k], buf);
        }

        /****************************cd命令****************************/
        if (strcmp(arg[0], "cd") == 0) {
            for (i = 3; (input[i] == ' ') && (i <= input_len); i++) {
                continue;
            }
            if (i == input_len) {
                SetCurrentDirectory("C:\\");
                GetCurrentDirectory(100, path);
                printf("%s>", path);
            }
            else {
                for (int m = i, j = 0; m <= input_len; m++) { // 获取cd命令的参数
                    buf[j++] = input[m];
                }
                buf[j] = '\0';
                arg[1] = (char *)malloc(j + 1); // 使用malloc分配内存
                strcpy(arg[1], buf); // 将参数存到arg[1]中
                cd_cmd(arg[1]);
            }
            free(arg[0]);
            free(arg[1]); // 释放分配的内存
            free(input);
            input_len = 0;
        }

            /*****************************ls命令***************************/
        else if (strcmp(arg[0], "ls") == 0) {
            if (arg[1] == NULL) {
                ls_cmd(arg[0]);
            }
            else {
                if (strcmp(arg[1], "--help") == 0) {
                    printf(PRINTLSHELP);
                }
                else if (strcmp(arg[1], "-l") == 0) {
                    ls_cmd(arg[1]);
                }
                else {
                    printf("无效的命令!\n");
                }
            }
            for (i = 0; i < 2; i++) {
                if (arg[i] != NULL) {
                    free(arg[i]);
                }
            }
            free(input);
            continue;
        }

            /****************************mkdir命令****************************/
        else  if (strcmp(arg[0], "mkdir") == 0) {
            for (i = 6; (input[i] == ' ') && (i < input_len); i++) {
                continue;
            }
            if (i == input_len) { // mkdir无参
                printf("mkdir：参数太少\n请尝试执行mkdir --help来获取更多信息\n");
                GetCurrentDirectory(100, path);
                printf("%s>", path);
            } else {
                for (int m = i, j = 0; m < input_len; m++) { // 获取mkdir命令的参数
                    if (input[m] != ' ') {
                        buf[j++] = input[m];
                    }
                }
                buf[j] = '\0'; // 确保字符串以NULL结尾
                arg[1] = (char *)malloc((j + 1) * sizeof(char)); // 使用malloc分配内存
                if (arg[1] != NULL) {
                    strcpy(arg[1], buf); // 将参数存到arg[1]中
                    if (strcmp(arg[1], "--help") == 0) {
                        printf(PRINTMKDIRHELP);
                        GetCurrentDirectory(100, path);
                        printf("%s>", path);
                    } else {
                        mkdir_cmd(arg[1]);
                    }
                }
            }
            free(input);
            free(arg[0]); // 如果arg[0]是动态分配的，才需要释放
            free(arg[1]); // 释放分配的内存
            input_len = 0;
        }

            /************************rmdir命令************************/
        else if (strcmp(arg[0], "rmdir") == 0) {
            for (i = 6; (input[i] == ' ') && (i <= input_len); i++) {
                continue;
            }
            if (i == input_len) { // rmdir无参
                printf("rmdir：参数太少\n请尝试执行rmdir --help来获取更多信息\n");
                GetCurrentDirectory(100, path);
                printf("%s>", path);
            } else {
                for (int m = i, j = 0; m <= input_len; m++) { // 获取rmdir命令的参数
                    buf[j++] = input[m];
                }
                buf[j] = '\0'; // 确保字符串以NULL结尾
                arg[1] = (char *)malloc(j + 1); // 使用malloc分配内存
                strcpy(arg[1], buf); // 将参数存到arg[1]中
                if (strcmp(arg[1], "--help") == 0) {
                    printf(PRINTRMDIRHELP);
                    GetCurrentDirectory(100, path);
                    printf("%s>", path);
                }
                else
                {
                    rmdir_cmd(arg[1]);
                }

            }
            free(input); // 如果input是动态分配的，才需要释放
            free(arg[0]); // 如果arg[0]是动态分配的，才需要释放
            free(arg[1]); // 释放分配的内存
            input_len = 0;
        }


            /***************************cp命令*************************/
        else  if (strcmp(arg[0], "cp") == 0) {
            int m,n;
            for (i = 3; (input[i] == ' ') && (i <= input_len); i++) {
                continue;
            }
            if (i == input_len) { // cp无参
                printf("cp：缺少了文件参数\n请尝试执行cp --help来获取更多信息\n");
                GetCurrentDirectory(100, path);
                printf("%s>", path);
            } else {
                for (m = i, j = 0; (input[m] != ' ') && (m <= input_len); m++) {
                    buf[j++] = input[m];
                }
                buf[j] = '\0';
                arg[1] = (char *)malloc(j + 1); // 使用malloc分配内存
                if (arg[1] != NULL) {
                    strcpy(arg[1], buf); // 将参数存到arg[1]中
                    if (m == input_len + 1) { // cp只有一个参数
                        if (strcmp(arg[1], "--help") == 0) {
                            printf(PRINTCPHELP);
                        } else {
                            printf("cp：缺少了目的文件\n请尝试执行cp --help来获取更多信息\n");
                        }
                        GetCurrentDirectory(100, path);
                        printf("%s>", path);
                    } else { // cp有两个参数
                        for (n = m + 1, j = 0; n <= input_len; n++) {
                            buf[j++] = input[n];
                        }
                        buf[j] = '\0';
                        arg[2] = (char *)malloc(j + 1); // 使用malloc分配内存
                        if (arg[2] != NULL) {
                            strcpy(arg[2], buf); // 将参数存到arg[2]中
                            cp_cmd(arg[1], arg[2]);
                            free(arg[2]); // 释放分配的内存
                        } else {
                            printf("Memory allocation failed\n");
                        }
                    }
                    free(arg[1]); // 释放分配的内存
                }
            }
            //free(input); // 如果input是动态分配的，才需要释放
            //free(arg[0]); // 如果arg[0]是动态分配的，才需要释放
            input_len = 0;
        }

            /***********************cat命令************************/
        else if (strcmp(arg[0], "cat") == 0) {
            int m,n;
            for (i = 4; (input[i] == ' ') && (i <= input_len); i++) {
                continue;
            }
            if (i == input_len) { // cat无参
                printf("cat：缺少了文件参数\n请尝试执行cat --help来获取更多信息\n");
                GetCurrentDirectory(100, path);
                printf("%s>", path);
            } else { // cat有参
                for (m = i, j = 0; (input[m] != ' ') && (m <= input_len); m++) {
                    buf[j++] = input[m];
                }
                buf[j] = '\0';
                arg[1] = (char *)malloc(j + 1); // 使用malloc分配内存
                if (arg[1] != NULL) {
                    strcpy(arg[1], buf); // 将参数存到arg[1]中
                    if (m == input_len + 1) { // cat只有一个参数
                        if (strcmp(arg[1], "--help") == 0) {
                            printf(PRINTCATHELP);
                        } else {
                            cat_cmd1(arg[1]);
                        }
                        GetCurrentDirectory(100, path);
                        printf("%s>", path);
                    } else { // cat不止一个参数
                        for (n = m + 1, j = 0; (input[n] != ' ') && (n <= input_len); n++) {
                            buf[j++] = input[n];
                        }
                        buf[j] = '\0';
                        arg[2] = (char *)malloc(j + 1); // 使用malloc分配内存
                        if (arg[2] != NULL) {
                            strcpy(arg[2], buf); // 将参数存到arg[2]中
                            if (n == input_len + 1) { // cat只有两个参数
                                printf("无效的命令!\n");
                            } else { // cat有三个参数
                                if (strcmp(arg[2], ">>") == 0) {
                                    for (int p = n + 1, j = 0; p <= input_len; p++) {
                                        buf[j++] = input[p];
                                    }
                                    buf[j] = '\0';
                                    arg[3] = (char *)malloc(j + 1); // 使用malloc分配内存
                                    if (arg[3] != NULL) {
                                        strcpy(arg[3], buf); // 将参数存到arg[3]中
                                        cat_cmd2(arg[1], arg[3]);
                                        free(arg[3]); // 释放分配的内存
                                    } else {
                                        printf("Memory allocation failed\n");
                                    }
                                } else {
                                    printf("无效的命令!\n");
                                }
                            }
                            free(arg[2]); // 释放分配的内存
                        } else {
                            printf("Memory allocation failed\n");
                        }
                    }
                    free(arg[1]); // 释放分配的内存
                }
            }
            // 注意：这里不应该释放input，因为它可能是栈上的局部变量或全局变量
            //free(input); // 如果input是动态分配的，才需要释放
            input_len = 0;
        }


            /************************sort命令***********************/
        else if (strcmp(arg[0], "sort") == 0) {
            for(i=5;(input[i]==' ')&&(i<=input_len);i++)
            {
                continue;
            }
            if (i == input_len) {
                printf("sort:无效的命令\n请尝试执行sort --help来获取更多信息\n");
                GetCurrentDirectory(100,path);
                printf("%s>",path);
            }
            else			//sort有参
            {
                for(int m=i,j=0;m<=input_len;m++)//获取sort命令的参数
                    buf[j++]=input[m];
                buf[j]='\0';
                arg[1]=(char *)malloc(j + 1);
                strcpy(arg[1],buf);//将参数存到arg[1]中
                if(strcmp(arg[1], "--help" )==0)
                {
                    printf(PRINTSORTHELP);
                    GetCurrentDirectory(100,path);
                    printf("%s>",path);
                }
                else
                {
                    cmd_sort(arg[1]);
                }
            }
            free(arg[0]);
            free(arg[1]);
            free(input);
            continue;
        }


        else {
            printf("无效的命令!\n");
            GetCurrentDirectory(100,path);
            printf("%s>",path);
            for (i = 0; i < 2; i++) {
                if (arg[i] != NULL) {
                    free(arg[i]);
                }
            }
            free(input);
            input_len = 0;
            continue;
        }
    }
}


