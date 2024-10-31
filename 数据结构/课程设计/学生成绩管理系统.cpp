#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 定义成绩结构体
struct Score {
    string id;
    string name;
    string cls;
    string gender;
    string phone;
    double math;
    double english;
    double computer;
    double total;
};

// 打印帮助信息
void printHelp() {
    cout << "-------------------------" << endl;
    cout << "   学生成绩管理系统帮助   " << endl;
    cout << "-------------------------" << endl;
    cout << "2. 输入数据并存入文件" << endl;
    cout << "3. 根据学号查询成绩" << endl;
    cout << "4. 根据姓名查询成绩" << endl;
    cout << "5. 输出文件内容" << endl;
    cout << "6. 成绩排序" << endl;
    cout << "7. 统计及格和优秀人数" << endl;
    cout << "8. 退出" << endl;
    cout << endl;
}

// 从文件中读取成绩信息，并返回一个Score结构体向量
//容器vector在此处的作用是存储从文件中读取出来的成绩信息。
//通过将每个Score结构体对象添加到vector中，可以方便地存储和处理多个成绩信息。
vector<Score> readScoresFromFile() {
    vector<Score> scores;
    ifstream fin("score.txt");
    while (!fin.eof()) {
        Score s;
        fin >> s.id >> s.name >> s.cls >> s.gender >> s.phone
            >> s.math >> s.english >> s.computer >> s.total;
        scores.push_back(s);
    }
    scores.pop_back(); // 删除最后一个空的Score对象
    fin.close();
    return scores;
}

// 将成绩信息保存到文件中
void saveScoresToFile(const vector<Score>& scores) {
    ofstream fout("score.txt");
    for (const Score& s : scores) {
        fout << s.id << " " << s.name << " " << s.cls << " " << s.gender
             << " " << s.phone << " " << s.math << " " << s.english
             << " " << s.computer << " " << s.total << endl;
    }
    fout.close();
}

// 根据学号查询成绩
void queryScoreById(const vector<Score>& scores) {
    string id;
    cout << "请输入学生学号: ";
    cin >> id;
    bool found = false;
    for (const Score& s : scores) {
        if (s.id == id) {
            cout << "学号\t姓名\t班级\t性别\t联系电话\t数学\t英语\t计算机\t总分" << endl;
            cout << s.id << "\t" << s.name << "\t" << s.cls << "\t" << s.gender
                 << "\t" << s.phone << "    \t" << s.math << "\t" << s.english
                 << "\t" << s.computer << "\t" << s.total << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "未找到该学生记录" << endl;
    }
}

// 根据姓名查询成绩
void queryScoreByName(const vector<Score>& scores) {
    string name;
    cout << "请输入学生姓名: ";
    cin >> name;
    bool found = false;
    for (const Score& s : scores) {
        if (s.name == name) {
            cout << "学号\t姓名\t班级\t性别\t联系电话\t数学\t英语\t计算机\t总分" << endl;
            cout << s.id << "\t" << s.name << "\t" << s.cls << "\t" << s.gender
                 << "\t" << s.phone << "    \t" << s.math << "\t" << s.english
                 << "\t" << s.computer << "\t" << s.total << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "未找到该学生记录" << endl;
    }
}

// 输出文件内容
void printScores(const vector<Score>& scores) {
    cout << "学号\t姓名\t班级\t性别\t联系电话\t数学\t英语\t计算机\t总分" << endl;
    for (const Score& s : scores) {
        cout << s.id << "\t" << s.name << "\t" << s.cls << "\t" << s.gender
            << "\t" << s.phone << "    \t"<< s.math << "\t" << s.english
        << "\t" << s.computer << "\t" << s.total << endl;
}
}

// 根据不同排序方式排序学生信息
void sortScores(vector<Score>& scores) {
    int choice;
    cout << "请选择排序方式：" << endl;
    cout << "1. 按照总分从高到低排序"<< endl;
    cout << "2. 按照数学成绩从高到低排序" << endl;
    cout << "3. 按照英语成绩从高到低排序" << endl;
    cout << "4. 按照计算机成绩从高到低排序" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            sort(scores.begin(), scores.end(), [](const Score& a, const Score& b) {
            return a.total > b.total;});
            break;
        case 2:
            sort(scores.begin(), scores.end(), [](const Score& a, const Score& b) {
            return a.math > b.math;});
            break;
         case 3:
            sort(scores.begin(), scores.end(), [](const Score& a, const Score& b) {
            return a.english > b.english;});
            break;
        case 4:
            sort(scores.begin(), scores.end(), [](const Score& a, const Score& b) {
            return a.computer > b.computer;});
            break;
        default:
            cout << "无效的选项" << endl;
            return;
        }
        cout << "排序成功！" << endl;
    printScores(scores);
    saveScoresToFile(scores);
}

// 统计及格和优秀人数
void countPassedAndExcellent(const vector<Score>& scores) {
    int passed = 0;
    int excellent = 0;
    for (const Score& s : scores) {
        if (s.math >= 60 && s.english >= 60 && s.computer >= 60) {
            passed++;
        }     
        if (s.math >= 80 && s.english >= 80 && s.computer >= 80) {
            excellent++;
        }
    }
    cout << "及格人数: " << passed << endl;
    cout << "优秀人数: " << excellent << endl;
    double passedRate = double(passed) / scores.size();
    double excellentRate = double(excellent) / scores.size();
    //setprecision(2) 用于限制输出的小数位数为两位
    cout << "及格率: " << fixed << setprecision(2) << passedRate * 100 << "% "<< endl;
    cout << "优秀率: " << fixed << setprecision(2) << excellentRate * 100 << "%" << endl;
}

int main() {
    vector<Score> scores = readScoresFromFile();
    cout << "************************************" << endl;
    cout << "**        学生成绩管理系统        **" << endl;
    cout << "************************************" << endl;
    cout << "************************************" << endl;
    cout << "**      1) 帮助                   **" << endl;
    cout << "**      2) 输入数据并存入文件     **" << endl;
    cout << "**      3) 根据学号查询成绩       **" << endl;
    cout << "**      4) 根据姓名查询成绩       **" << endl;
    cout << "**      5) 输出文件内容           **" << endl;
    cout << "**      6) 成绩排序               **" << endl;
    cout << "**      7) 统计及格和优秀人数     **" << endl;
    cout << "**      8) 退出                   **" << endl;
    cout << "************************************" << endl;
    while (true) {
        int choice;
        cout << "欢迎使用学生成绩管理系统，请选择功能：" << endl;
        cin >> choice;
        switch (choice) {
        	case 1: 
        	    printHelp();
        	    break;
            case 2:
            // 输入数据并存入文件
            {
                string id, name, cls, gender, phone;
                double math, english, computer;
                cout << "请输入学生学号：";
                cin >> id;
                cout << "请输入学生姓名：";
                cin >> name;
                cout << "请输入学生班级：";
                cin >> cls;
                cout << "请输入学生性别：";
                cin >> gender;
                cout << "请输入学生联系电话：";
                cin >> phone;
                cout << "请输入学生数学成绩：";
                cin >> math;
                cout << "请输入学生英语成绩：";
                cin >> english;
                cout << "请输入学生计算机成绩：";
                cin >> computer;
                Score s = {id, name, cls, gender, phone, math, english, computer, math + english + computer};
                scores.push_back(s);
                saveScoresToFile(scores);
                cout << "学生成绩信息已成功保存到文件中！" << endl;
                }
                break;
            case 3:
            // 根据学号查询成绩
                  queryScoreById(scores);
                  break;
            case 4:
             // 根据姓名查询成绩
                 queryScoreByName(scores);
                   break;
            case 5:
            // 输出文件内容
                printScores(scores);
                break;
            case 6:
            // 成绩排序
                sortScores(scores);
                break;
            case 7:
            // 统计及格和优秀人数
                countPassedAndExcellent(scores);
                break;
            case 8:
            // 退出
                cout << "感谢使用学生成绩管理系统，再见！" << endl;
                return 0;
            default:
                cout << "无效的选项" << endl;
            }
        cout << endl;

    }
    return 0;
}
