#include "OS.h"

char buf[100], path[100], path1[100], path2[100]; // ȫ�ֱ�����buf���ڻ������ݣ�3��path���ڱ���·��

/*cd����*/
void cd_cmd(char* route) {
    if (!SetCurrentDirectory(route)) {
        printf("·��������!\n");
        printf("%s>", path);
    }
    else {
        SetCurrentDirectory(route);
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
}


/*ls����*/
void ls_cmd(char* array) {
    HANDLE handle;
    int filenum = 0;
    FILETIME lpCreationTime, lpLastAccessTime, lpLastWriteTime;
    SYSTEMTIME stime;
    WIN32_FIND_DATA* path2 = (WIN32_FIND_DATA*)malloc(sizeof(WIN32_FIND_DATA));
    if (!GetCurrentDirectory(50, path1)) {
        printf("·��������!\n");
        return;
    }

    strcat(path1, "\\*.*"); // DOSͨ���
    if ((handle = FindFirstFile(path1, path2)) != INVALID_HANDLE_VALUE) {
        do {
            HANDLE hDir = CreateFile(path2->cFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_DELETE,
                                     NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
            if (GetFileTime(hDir, &lpCreationTime, &lpLastAccessTime, &lpLastWriteTime)) {
                FILETIME ftime;
                FileTimeToLocalFileTime(&lpLastWriteTime, &ftime); // ת���ɱ���ʱ��
                FileTimeToSystemTime(&ftime, &stime); // ת����ϵͳʱ���ʽ
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



/*mkdir����*/
void mkdir_cmd(char* array) {
    GetCurrentDirectory(100, path);
    strcat(path, "\\");
    strcat(path, array);
    WIN32_FIND_DATA wfd;
    HANDLE hFind;
    hFind = FindFirstFile(path, &wfd);
    if (hFind != INVALID_HANDLE_VALUE) {
        printf("��Ŀ¼�Ѵ��ڣ�����ʧ��!\n");
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
    else {
        CreateDirectory(array, NULL);
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
}


/*rmdir����*/
void rmdir_cmd(char* array) {
    GetCurrentDirectory(100, path);
    strcat(path, "\\");
    strcat(path, array);
    WIN32_FIND_DATA wfd;
    HANDLE hFind;
    hFind = FindFirstFile(path, &wfd);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("��Ŀ¼�����ڣ�ɾ��ʧ��!\n");
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
    else {
        RemoveDirectory(array);
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    }
}



/*cp����*/
void cp_cmd(char* array1, char* array2) {
    char fullSourcePath[100], fullDestPath[100];
    GetCurrentDirectory(100, fullSourcePath);
    strcat(fullSourcePath, "\\");
    strcat(fullSourcePath, array1);

    GetCurrentDirectory(100, fullDestPath);
    strcat(fullDestPath, "\\");
    strcat(fullDestPath, array2);

    if (!CopyFile(fullSourcePath, fullDestPath, FALSE)) {
        printf("����ʧ�ܣ�����·�����ļ��Ƿ���ڣ��������: %lu\n", GetLastError());
    } else {
        printf("�ļ����Ƴɹ�: %s -> %s\n", fullSourcePath, fullDestPath);
    }

    GetCurrentDirectory(100, path);
    printf("%s>", path);

}


/*cat����*/
void cat_cmd1(char* array) { // ������ʾ�ļ�
    char ch[1000];
    GetCurrentDirectory(100, path);
    strcat(path, "\\");
    strcat(path, array);
    FILE* infile = fopen(path, "r");
    if (!infile) {
        printf("�޷����ļ�%s\n", path);
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
    GetCurrentDirectory(100, path); // ����cat����֮ǰ��·��
    strcpy(path1, path); // ���Ƶ�ǰ·����path1
    strcat(path1, "\\");
    strcpy(path2, path); // ���Ƶ�ǰ·����path2
    strcat(path2, "\\");
    strcat(path1, array1); // ���������ļ�������·��
    strcat(path2, array2); // ��������ļ�������·��

    FILE *infile1 = fopen(path1, "r");
    if (!infile1) {
        printf("�޷����ļ�%s\n", path1);
        GetCurrentDirectory(100, path1);
        printf("%s>", path1);
    } else {
        FILE *outfile2 = fopen(path2, "a"); // ��׷��ģʽ������ļ�
        if (!outfile2) {
            printf("�޷����ļ�%s\n", path2);
            GetCurrentDirectory(100, path2);
            printf("%s>", path2);
        } else {
            while (fgets(ch, 1000, infile1) != NULL) { // ��ȡ�����ļ���д������ļ�
                fputs(ch, outfile2);
            }
            fclose(infile1);
            fclose(outfile2);

            FILE *infile2 = fopen(path2, "r"); // ���´�����ļ��Զ�ȡ����
            if (infile2) {
                while (fgets(ch, 1000, infile2) != NULL) { // ��ȡ����ӡ����ļ�������
                    printf("%s", ch);
                }
                fclose(infile2);
            }
        }
    }
    printf("%s>", path);
}

/*sort����*/
void cmd_sort(char *array) {
    int lnum = 0, min;
    char line[100][100], tmp[100]; // ������ÿ���ַ���

    // ��ȡ��ǰĿ¼��ƴ���ļ���
    GetCurrentDirectory(100, path);
    strcat(path, "\\");
    strcat(path, array);

    FILE *infile = fopen(path, "r");
    if (!infile) {
        printf("�޷����ļ�%s\n", array);
        GetCurrentDirectory(100, path);
        printf("%s>", path);
    } else {
        // ��ȡ�ļ����ݲ���¼����
        while (fgets(line[lnum], 100, infile) != NULL) {
            lnum++; // ��¼������
        }
        fclose(infile);

        // �򵥵�ð������
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

        // ������������д���ļ�
        FILE *outfile = fopen(path, "w");
        if (!outfile) {
            printf("�ļ���ʧ��\n");
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
    printf("    �˳��������Linux��ls,cat,cp,mkdir,rmdir,cd,sort�����ӭʹ��!    \n\n");
    printf("*******************************************************************************\n");

    // ��Ĭ��·����Ϊc�̸�Ŀ¼
    SetCurrentDirectoryA("C:\\");

    // ��ȡ��ǰ����Ŀ¼���洢��path������
    char path[100];
    GetCurrentDirectoryA(100, path);

    // ��ӡ��ǰ����Ŀ¼
    printf("%s>", path);

    while (1) {
        for (i = 0; i < 2; i++) {
            arg[i] = NULL;
        }

        while ((c = getchar()) == ' ' || c == '\t' || c == EOF); // ��������

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
        strcpy(input, buf); // ������ӻ��渴�Ƶ�input��

        /********************����������ɣ�����+[����]����ʽ**********************/
        for (i = 0, j = 0, k = 0; i < input_len; i++) {
            if ((input[i] == ' ' || input[i] == '\0') && (k == 0)) {
                if (j != 0) { // ȥ������һ��Ķ���ո�
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

        /****************************cd����****************************/
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
                for (int m = i, j = 0; m <= input_len; m++) { // ��ȡcd����Ĳ���
                    buf[j++] = input[m];
                }
                buf[j] = '\0';
                arg[1] = (char *)malloc(j + 1); // ʹ��malloc�����ڴ�
                strcpy(arg[1], buf); // �������浽arg[1]��
                cd_cmd(arg[1]);
            }
            free(arg[0]);
            free(arg[1]); // �ͷŷ�����ڴ�
            free(input);
            input_len = 0;
        }

            /*****************************ls����***************************/
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
                    printf("��Ч������!\n");
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

            /****************************mkdir����****************************/
        else  if (strcmp(arg[0], "mkdir") == 0) {
            for (i = 6; (input[i] == ' ') && (i < input_len); i++) {
                continue;
            }
            if (i == input_len) { // mkdir�޲�
                printf("mkdir������̫��\n�볢��ִ��mkdir --help����ȡ������Ϣ\n");
                GetCurrentDirectory(100, path);
                printf("%s>", path);
            } else {
                for (int m = i, j = 0; m < input_len; m++) { // ��ȡmkdir����Ĳ���
                    if (input[m] != ' ') {
                        buf[j++] = input[m];
                    }
                }
                buf[j] = '\0'; // ȷ���ַ�����NULL��β
                arg[1] = (char *)malloc((j + 1) * sizeof(char)); // ʹ��malloc�����ڴ�
                if (arg[1] != NULL) {
                    strcpy(arg[1], buf); // �������浽arg[1]��
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
            free(arg[0]); // ���arg[0]�Ƕ�̬����ģ�����Ҫ�ͷ�
            free(arg[1]); // �ͷŷ�����ڴ�
            input_len = 0;
        }

            /************************rmdir����************************/
        else if (strcmp(arg[0], "rmdir") == 0) {
            for (i = 6; (input[i] == ' ') && (i <= input_len); i++) {
                continue;
            }
            if (i == input_len) { // rmdir�޲�
                printf("rmdir������̫��\n�볢��ִ��rmdir --help����ȡ������Ϣ\n");
                GetCurrentDirectory(100, path);
                printf("%s>", path);
            } else {
                for (int m = i, j = 0; m <= input_len; m++) { // ��ȡrmdir����Ĳ���
                    buf[j++] = input[m];
                }
                buf[j] = '\0'; // ȷ���ַ�����NULL��β
                arg[1] = (char *)malloc(j + 1); // ʹ��malloc�����ڴ�
                strcpy(arg[1], buf); // �������浽arg[1]��
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
            free(input); // ���input�Ƕ�̬����ģ�����Ҫ�ͷ�
            free(arg[0]); // ���arg[0]�Ƕ�̬����ģ�����Ҫ�ͷ�
            free(arg[1]); // �ͷŷ�����ڴ�
            input_len = 0;
        }


            /***************************cp����*************************/
        else  if (strcmp(arg[0], "cp") == 0) {
            int m,n;
            for (i = 3; (input[i] == ' ') && (i <= input_len); i++) {
                continue;
            }
            if (i == input_len) { // cp�޲�
                printf("cp��ȱ�����ļ�����\n�볢��ִ��cp --help����ȡ������Ϣ\n");
                GetCurrentDirectory(100, path);
                printf("%s>", path);
            } else {
                for (m = i, j = 0; (input[m] != ' ') && (m <= input_len); m++) {
                    buf[j++] = input[m];
                }
                buf[j] = '\0';
                arg[1] = (char *)malloc(j + 1); // ʹ��malloc�����ڴ�
                if (arg[1] != NULL) {
                    strcpy(arg[1], buf); // �������浽arg[1]��
                    if (m == input_len + 1) { // cpֻ��һ������
                        if (strcmp(arg[1], "--help") == 0) {
                            printf(PRINTCPHELP);
                        } else {
                            printf("cp��ȱ����Ŀ���ļ�\n�볢��ִ��cp --help����ȡ������Ϣ\n");
                        }
                        GetCurrentDirectory(100, path);
                        printf("%s>", path);
                    } else { // cp����������
                        for (n = m + 1, j = 0; n <= input_len; n++) {
                            buf[j++] = input[n];
                        }
                        buf[j] = '\0';
                        arg[2] = (char *)malloc(j + 1); // ʹ��malloc�����ڴ�
                        if (arg[2] != NULL) {
                            strcpy(arg[2], buf); // �������浽arg[2]��
                            cp_cmd(arg[1], arg[2]);
                            free(arg[2]); // �ͷŷ�����ڴ�
                        } else {
                            printf("Memory allocation failed\n");
                        }
                    }
                    free(arg[1]); // �ͷŷ�����ڴ�
                }
            }
            //free(input); // ���input�Ƕ�̬����ģ�����Ҫ�ͷ�
            //free(arg[0]); // ���arg[0]�Ƕ�̬����ģ�����Ҫ�ͷ�
            input_len = 0;
        }

            /***********************cat����************************/
        else if (strcmp(arg[0], "cat") == 0) {
            int m,n;
            for (i = 4; (input[i] == ' ') && (i <= input_len); i++) {
                continue;
            }
            if (i == input_len) { // cat�޲�
                printf("cat��ȱ�����ļ�����\n�볢��ִ��cat --help����ȡ������Ϣ\n");
                GetCurrentDirectory(100, path);
                printf("%s>", path);
            } else { // cat�в�
                for (m = i, j = 0; (input[m] != ' ') && (m <= input_len); m++) {
                    buf[j++] = input[m];
                }
                buf[j] = '\0';
                arg[1] = (char *)malloc(j + 1); // ʹ��malloc�����ڴ�
                if (arg[1] != NULL) {
                    strcpy(arg[1], buf); // �������浽arg[1]��
                    if (m == input_len + 1) { // catֻ��һ������
                        if (strcmp(arg[1], "--help") == 0) {
                            printf(PRINTCATHELP);
                        } else {
                            cat_cmd1(arg[1]);
                        }
                        GetCurrentDirectory(100, path);
                        printf("%s>", path);
                    } else { // cat��ֹһ������
                        for (n = m + 1, j = 0; (input[n] != ' ') && (n <= input_len); n++) {
                            buf[j++] = input[n];
                        }
                        buf[j] = '\0';
                        arg[2] = (char *)malloc(j + 1); // ʹ��malloc�����ڴ�
                        if (arg[2] != NULL) {
                            strcpy(arg[2], buf); // �������浽arg[2]��
                            if (n == input_len + 1) { // catֻ����������
                                printf("��Ч������!\n");
                            } else { // cat����������
                                if (strcmp(arg[2], ">>") == 0) {
                                    for (int p = n + 1, j = 0; p <= input_len; p++) {
                                        buf[j++] = input[p];
                                    }
                                    buf[j] = '\0';
                                    arg[3] = (char *)malloc(j + 1); // ʹ��malloc�����ڴ�
                                    if (arg[3] != NULL) {
                                        strcpy(arg[3], buf); // �������浽arg[3]��
                                        cat_cmd2(arg[1], arg[3]);
                                        free(arg[3]); // �ͷŷ�����ڴ�
                                    } else {
                                        printf("Memory allocation failed\n");
                                    }
                                } else {
                                    printf("��Ч������!\n");
                                }
                            }
                            free(arg[2]); // �ͷŷ�����ڴ�
                        } else {
                            printf("Memory allocation failed\n");
                        }
                    }
                    free(arg[1]); // �ͷŷ�����ڴ�
                }
            }
            // ע�⣺���ﲻӦ���ͷ�input����Ϊ��������ջ�ϵľֲ�������ȫ�ֱ���
            //free(input); // ���input�Ƕ�̬����ģ�����Ҫ�ͷ�
            input_len = 0;
        }


            /************************sort����***********************/
        else if (strcmp(arg[0], "sort") == 0) {
            for(i=5;(input[i]==' ')&&(i<=input_len);i++)
            {
                continue;
            }
            if (i == input_len) {
                printf("sort:��Ч������\n�볢��ִ��sort --help����ȡ������Ϣ\n");
                GetCurrentDirectory(100,path);
                printf("%s>",path);
            }
            else			//sort�в�
            {
                for(int m=i,j=0;m<=input_len;m++)//��ȡsort����Ĳ���
                    buf[j++]=input[m];
                buf[j]='\0';
                arg[1]=(char *)malloc(j + 1);
                strcpy(arg[1],buf);//�������浽arg[1]��
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
            printf("��Ч������!\n");
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


