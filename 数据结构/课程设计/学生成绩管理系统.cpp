#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ����ɼ��ṹ��
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

// ��ӡ������Ϣ
void printHelp() {
    cout << "-------------------------" << endl;
    cout << "   ѧ���ɼ�����ϵͳ����   " << endl;
    cout << "-------------------------" << endl;
    cout << "2. �������ݲ������ļ�" << endl;
    cout << "3. ����ѧ�Ų�ѯ�ɼ�" << endl;
    cout << "4. ����������ѯ�ɼ�" << endl;
    cout << "5. ����ļ�����" << endl;
    cout << "6. �ɼ�����" << endl;
    cout << "7. ͳ�Ƽ������������" << endl;
    cout << "8. �˳�" << endl;
    cout << endl;
}

// ���ļ��ж�ȡ�ɼ���Ϣ��������һ��Score�ṹ������
//����vector�ڴ˴��������Ǵ洢���ļ��ж�ȡ�����ĳɼ���Ϣ��
//ͨ����ÿ��Score�ṹ�������ӵ�vector�У����Է���ش洢�ʹ������ɼ���Ϣ��
vector<Score> readScoresFromFile() {
    vector<Score> scores;
    ifstream fin("score.txt");
    while (!fin.eof()) {
        Score s;
        fin >> s.id >> s.name >> s.cls >> s.gender >> s.phone
            >> s.math >> s.english >> s.computer >> s.total;
        scores.push_back(s);
    }
    scores.pop_back(); // ɾ�����һ���յ�Score����
    fin.close();
    return scores;
}

// ���ɼ���Ϣ���浽�ļ���
void saveScoresToFile(const vector<Score>& scores) {
    ofstream fout("score.txt");
    for (const Score& s : scores) {
        fout << s.id << " " << s.name << " " << s.cls << " " << s.gender
             << " " << s.phone << " " << s.math << " " << s.english
             << " " << s.computer << " " << s.total << endl;
    }
    fout.close();
}

// ����ѧ�Ų�ѯ�ɼ�
void queryScoreById(const vector<Score>& scores) {
    string id;
    cout << "������ѧ��ѧ��: ";
    cin >> id;
    bool found = false;
    for (const Score& s : scores) {
        if (s.id == id) {
            cout << "ѧ��\t����\t�༶\t�Ա�\t��ϵ�绰\t��ѧ\tӢ��\t�����\t�ܷ�" << endl;
            cout << s.id << "\t" << s.name << "\t" << s.cls << "\t" << s.gender
                 << "\t" << s.phone << "    \t" << s.math << "\t" << s.english
                 << "\t" << s.computer << "\t" << s.total << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "δ�ҵ���ѧ����¼" << endl;
    }
}

// ����������ѯ�ɼ�
void queryScoreByName(const vector<Score>& scores) {
    string name;
    cout << "������ѧ������: ";
    cin >> name;
    bool found = false;
    for (const Score& s : scores) {
        if (s.name == name) {
            cout << "ѧ��\t����\t�༶\t�Ա�\t��ϵ�绰\t��ѧ\tӢ��\t�����\t�ܷ�" << endl;
            cout << s.id << "\t" << s.name << "\t" << s.cls << "\t" << s.gender
                 << "\t" << s.phone << "    \t" << s.math << "\t" << s.english
                 << "\t" << s.computer << "\t" << s.total << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "δ�ҵ���ѧ����¼" << endl;
    }
}

// ����ļ�����
void printScores(const vector<Score>& scores) {
    cout << "ѧ��\t����\t�༶\t�Ա�\t��ϵ�绰\t��ѧ\tӢ��\t�����\t�ܷ�" << endl;
    for (const Score& s : scores) {
        cout << s.id << "\t" << s.name << "\t" << s.cls << "\t" << s.gender
            << "\t" << s.phone << "    \t"<< s.math << "\t" << s.english
        << "\t" << s.computer << "\t" << s.total << endl;
}
}

// ���ݲ�ͬ����ʽ����ѧ����Ϣ
void sortScores(vector<Score>& scores) {
    int choice;
    cout << "��ѡ������ʽ��" << endl;
    cout << "1. �����ִܷӸߵ�������"<< endl;
    cout << "2. ������ѧ�ɼ��Ӹߵ�������" << endl;
    cout << "3. ����Ӣ��ɼ��Ӹߵ�������" << endl;
    cout << "4. ���ռ�����ɼ��Ӹߵ�������" << endl;
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
            cout << "��Ч��ѡ��" << endl;
            return;
        }
        cout << "����ɹ���" << endl;
    printScores(scores);
    saveScoresToFile(scores);
}

// ͳ�Ƽ������������
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
    cout << "��������: " << passed << endl;
    cout << "��������: " << excellent << endl;
    double passedRate = double(passed) / scores.size();
    double excellentRate = double(excellent) / scores.size();
    //setprecision(2) �������������С��λ��Ϊ��λ
    cout << "������: " << fixed << setprecision(2) << passedRate * 100 << "% "<< endl;
    cout << "������: " << fixed << setprecision(2) << excellentRate * 100 << "%" << endl;
}

int main() {
    vector<Score> scores = readScoresFromFile();
    cout << "************************************" << endl;
    cout << "**        ѧ���ɼ�����ϵͳ        **" << endl;
    cout << "************************************" << endl;
    cout << "************************************" << endl;
    cout << "**      1) ����                   **" << endl;
    cout << "**      2) �������ݲ������ļ�     **" << endl;
    cout << "**      3) ����ѧ�Ų�ѯ�ɼ�       **" << endl;
    cout << "**      4) ����������ѯ�ɼ�       **" << endl;
    cout << "**      5) ����ļ�����           **" << endl;
    cout << "**      6) �ɼ�����               **" << endl;
    cout << "**      7) ͳ�Ƽ������������     **" << endl;
    cout << "**      8) �˳�                   **" << endl;
    cout << "************************************" << endl;
    while (true) {
        int choice;
        cout << "��ӭʹ��ѧ���ɼ�����ϵͳ����ѡ���ܣ�" << endl;
        cin >> choice;
        switch (choice) {
        	case 1: 
        	    printHelp();
        	    break;
            case 2:
            // �������ݲ������ļ�
            {
                string id, name, cls, gender, phone;
                double math, english, computer;
                cout << "������ѧ��ѧ�ţ�";
                cin >> id;
                cout << "������ѧ��������";
                cin >> name;
                cout << "������ѧ���༶��";
                cin >> cls;
                cout << "������ѧ���Ա�";
                cin >> gender;
                cout << "������ѧ����ϵ�绰��";
                cin >> phone;
                cout << "������ѧ����ѧ�ɼ���";
                cin >> math;
                cout << "������ѧ��Ӣ��ɼ���";
                cin >> english;
                cout << "������ѧ��������ɼ���";
                cin >> computer;
                Score s = {id, name, cls, gender, phone, math, english, computer, math + english + computer};
                scores.push_back(s);
                saveScoresToFile(scores);
                cout << "ѧ���ɼ���Ϣ�ѳɹ����浽�ļ��У�" << endl;
                }
                break;
            case 3:
            // ����ѧ�Ų�ѯ�ɼ�
                  queryScoreById(scores);
                  break;
            case 4:
             // ����������ѯ�ɼ�
                 queryScoreByName(scores);
                   break;
            case 5:
            // ����ļ�����
                printScores(scores);
                break;
            case 6:
            // �ɼ�����
                sortScores(scores);
                break;
            case 7:
            // ͳ�Ƽ������������
                countPassedAndExcellent(scores);
                break;
            case 8:
            // �˳�
                cout << "��лʹ��ѧ���ɼ�����ϵͳ���ټ���" << endl;
                return 0;
            default:
                cout << "��Ч��ѡ��" << endl;
            }
        cout << endl;

    }
    return 0;
}
