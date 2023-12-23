#include<iostream>
#include<string>
#include <fstream>
#include <conio.h>
#include"ALGraph.h"

using namespace std;

// �洢�˺�������ļ�·��
const string accountFilePath = "accounts.txt";
const char* Filename = "tool.txt";
ALGraph graph(Filename);
// �ṹ���ʾ�˻���Ϣ
struct Account {
    string account;
    string password;
};
void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}
void enter() {
    char en =1;
    cout << "��������ֵ����...";
    cin >> en;
    while (en) {
        if (en == '1')
            break;
        else
            break;
    }
}
void add(string citys) {
    char city = '1';
    while (city) {
        system("cls");
        cout << endl << "��������ʼ��or��ֹ��" << endl;
        cout << "    1.��ʼ��" << endl << "    2.��ֹ��" << endl;
        cout << "���������֣�";
        cin >> city;
        string ec, rank;
        Time st, et;
        float spt, spm;
        switch (city) {
        case '1':
            cout << "�������յ���У�";
            cin >> ec;
            cout << "�������г����λ򺽰���Ϣ��";
            cin >> rank;
            cout << "�����뷢��ʱ�䣺";
            cin >> st;
            cout << "�����뵽��ʱ�䣺";
            cin >> et;
            cout << "��������Ҫ���ѵĽ�";
            cin >> spm;
            cout << "��������Ҫ���ѵ�ʱ�䣺";
            cin >> spt;
            graph.addLine(citys, ec, st, et, spt, spm, rank);
            break;
        case '2':
            cout << "�����������У�";
            cin >> ec;
            cout << "�������г����λ򺽰���Ϣ��";
            cin >> rank;
            cout << "�����뷢��ʱ�䣺";
            cin >> st;
            cout << "�����뵽��ʱ�䣺";
            cin >> et;
            cout << "��������Ҫ���ѵ�ʱ�䣺";
            cin >> spt;
            cout << "��������Ҫ���ѵĽ�";
            cin >> spm;
            graph.addLine(ec, citys, st, et, spt, spm, rank);
            break;
        }
        break;
    }
}
void del(string citys) {
    char city = '1';
    while (city) {
        system("cls");
        cout << endl << "��������ʼ��or��ֹ��" << endl;
        cout << "    1.��ʼ��" << endl << "    2.��ֹ��" << endl;
        cout << "���������֣�";
        cin >> city;
        string ec, rank;
        switch (city) {
        case '1':
            cout << "�������յ���У�";
            cin >> ec;
            cout << "�������г����λ򺽰���Ϣ��";
            cin >> rank;
            graph.delLine(citys, ec, rank);
            break;
        case '2':
            cout << "�����������У�";
            cin >> ec;
            cout << "�������г����λ򺽰���Ϣ��";
            cin >> rank;
            graph.delLine(ec, citys, rank);
            break;
        }
        break;
    }
}
void adminALG() {
    char func = '1';
    while (func) {
        system("cls");
        cout << "==============�������Աģʽ==============" << endl << endl;
        cout << "��ѡ�����в���֮һ" << endl;
        cout << "    1.��ӳ��к���·" << endl;
        cout << "    2.ɾ�����к���·" << endl;
        cout << "    3.��ѯ�����м䣬�������ٵ�·��" << endl;
        cout << "    4.��ѯ�����м䣬��ʱ���ٵ�·��" << endl;
        cout << "    5.��ѯ�����м䣬��ת�������ٵ�·��" << endl;
        cout << "    6.��ʾ���г���" << endl;
        cout << "    7.��ʾ������·" << endl;
        cout << "    8.�˳�����Աģʽ" << endl;
        cout << "���������֣�";
        cin>>func;
        cout << endl;
        string sc, ec,rank;
        switch (func) {
        case'1':
            cout << "    1.��ӳ�����·" << endl;
            cout << "����Ҫ��ӵĳ��У�";
            cin >> sc;
            switch (graph.ifCityExist(sc)) {
            case 1 or 2:
                cout << "�ó����Ѵ��ڣ������ظ���ӡ�" << endl;
                break;
            default:
                cout << "�ɹ���ӳ��С�" << endl;
                break;
            }
            add(sc);
            cout << "�ɹ������·��" << endl;
            delay(1);
            system("cls");
            break;
        case'2':
            cout << "    2.ɾ��������·" << endl;
            cout << "����Ҫɾ���ĳ�����·��";
            cin >> sc;
            switch (graph.ifCityExist(sc)) {
            case 1 or 2:
                del(sc);
                break;
            default:
                cout << "û�иó��У��޷�ɾ����" << endl;
                break;
            }
            break;
        case'3':
            cout << "    3.��ѯ�����м䣬�������ٵ�·��" << endl;
            cout << "����Ҫ��ѯ�������У�";
            cin >> sc;
            cout << "����Ҫ��ѯ���յ���У�";
            cin >> ec;
            graph.printLeastMoneyPath(sc, ec);
            enter();
            break;
        case'4':
            cout << "    4.��ѯ�����м䣬��ʱ���ٵ�·��" << endl;
            cout << "����Ҫ��ѯ�������У�";
            cin >> sc;
            cout << "����Ҫ��ѯ���յ���У�";
            cin >> ec;
            graph.printLeastTimePath(sc, ec);
            enter();
            break;
        case'5':
            cout << "    5.��ѯ�����м䣬��ת�������ٵ�·��" << endl;
            cout << "����Ҫ��ѯ�������У�";
            cin >> sc;
            cout << "����Ҫ��ѯ���յ���У�";
            cin >> ec;
            graph.printLeastTransferPath(sc, ec);
            enter();
            break;
        case'6':
            cout << "    6.��ʾ���г���" << endl;
            graph.showAllCity();
            enter();
            break;
        case'7':
            cout << "    7.��ʾ������·" << endl;
            graph.showAllLine();
            enter();
            break;
        case'8':
            system("cls");
            cout << "�˳�����Աģʽ�ɹ�" << endl;
            delay(1);
            system("cls");
            break;
        default:
            cout << "��������ȷ����!" << endl;
            system("cls");
            continue;
        }
        if (func == '8') break;
    }
}
void user() {
    char func1 = '1';
    while (func1) {
        system("cls");
        cout << "==============������ͨ�û�ģʽ==============" << endl << endl;
        cout << "    ������ȫ����ͨͼ����Ϣ��ѯ��" << endl;
        cout << "��ѡ�����в���֮һ" << endl;
        cout << "    1.��ѯ�����м䣬�������ٵ�·��" << endl;
        cout << "    2.��ѯ�����м䣬��ʱ���ٵ�·��" << endl;
        cout << "    3.��ѯ�����м䣬��ת�������ٵ�·��" << endl;
        cout << "    4.��ʾ���г���" << endl;
        cout << "    5.��ʾ������·" << endl;
        cout << "    6.�˳���ͨ�û�ģʽ" << endl;
        cout << "���������֣�";
        cin >> func1;
        string sc, ec;
        switch (func1) {
        case'1':
            cout << "    1.��ѯ�����м䣬�������ٵ�·��" << endl;
            cout << "����Ҫ��ѯ�������У�";
            cin >> sc;
            cout << "����Ҫ��ѯ���յ���У�";
            cin >> ec;
            graph.printLeastMoneyPath(sc, ec);
            enter();
            break;
        case'2':
            cout << "    2.��ѯ�����м䣬��ʱ���ٵ�·��" << endl;
            cout << "����Ҫ��ѯ�������У�";
            cin >> sc;
            cout << "����Ҫ��ѯ���յ���У�";
            cin >> ec;
            graph.printLeastTimePath(sc, ec);
            enter();
            continue;
        case'3':
            cout << "    3.��ѯ�����м䣬��ת�������ٵ�·��"  << endl;
            cout << "����Ҫ��ѯ�������У�";
            cin >> sc;
            cout << "����Ҫ��ѯ���յ���У�";
            cin >> ec;
            graph.printLeastTransferPath(sc, ec);
            enter();
            break;
        case'4':
            cout << "    4.��ʾ���г���" << endl;
            graph.showAllCity();
            enter();
            break;
        case'5':
            cout << "    5.��ʾ������·" << endl;
            graph.showAllLine();
            enter();
            break;
        case '6':
            system("cls");
            cout << "�˳���ͨ�û�ģʽ�ɹ�" << endl;
            delay(1);
            system("cls");
            break;
        default:
            cout <<endl<< "��������ȷ����!" << endl;
            delay(1);
            system("cls");
            continue;
        }
        if (func1 == '6') break;
    }
}
bool login() {
    std::ifstream inFile(accountFilePath);
    if (!inFile.is_open()) {
        cerr << "�޷����˻��ļ�"<<endl;
        return false;
    }

    Account inputAccount;
    cout << "�������û���: ";
    cin >> inputAccount.account;
    cout << "����������: ";
    char ch;
    while ((ch = _getch()) != 13) { // 13 �ǻس����� ASCII ֵ
        inputAccount.password.push_back(ch);
        cout << '*';
    }//������������ʾ

    string storedUsername, storedPassword;

    // ���ж�ȡ�˻���Ϣ���ж��Ƿ�ƥ��
    while (inFile >> storedUsername >> storedPassword) {
        if (storedUsername == inputAccount.account&& storedPassword == inputAccount.password) {
            inFile.close();
            return true; 
        }
    }
    inFile.close();
    return false;

}
void changePassword() {
    fstream file(accountFilePath, ios::in | ios::out);
    if (!file.is_open()) {
        cerr << "�޷����˻��ļ���" << endl << endl;
        return;
    }
    Account inputAccount;
    cout << "�������û���: ";
    cin >> inputAccount.account;
    cout << "�����������: ";
    cin >> inputAccount.password;

    string storedUsername, storedPassword;
    streampos position;

    // ���ж�ȡ�˻���Ϣ���ж��Ƿ�ƥ��
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == inputAccount.account && storedPassword == inputAccount.password) {
            cout << "������������: ";
            cin >> inputAccount.password;

            // Ensure the new password doesn't contain spaces
            if (inputAccount.password.find(' ') != string::npos) {
                cerr << "�����벻�ܰ����ո����������롣" << endl << endl;
                file.close();
                return;
            }

            // ��λ���޸������λ��
            position = file.tellg();
            file.seekp(position - static_cast<streampos>(storedPassword.length() + 1));
            file << " "<<inputAccount.password;
            file.flush(); // ˢ���ļ���
            file.close(); // �ر��ļ�
            cout << "�����޸ĳɹ���" << endl << endl;
            return;
        }
    }

    cerr << "�û�������������޷��޸����롣" << endl << endl;
    file.close();
}
void signin() {
    std::ofstream outFile(accountFilePath, ios::out | ios::app);
    if (!outFile.is_open()) {
        cerr << "�޷����˻��ļ�" << endl;
        return;
    }

    cout << "������ע����˺�����" << endl;
    Account newAccount;
    cout << "�������û���: ";
    cin >> newAccount.account;
    cout << "����������: ";
    cin >> newAccount.password;

    // ����Ƿ��Ѵ�����ͬ���û���
    ifstream inFile(accountFilePath);
    string storedUsername;

    while (inFile >> storedUsername) {
        if (storedUsername == newAccount.account) {
            cerr << "�û����Ѵ��ڣ���ѡ�������û�����" << endl << endl;
            inFile.close();
            outFile.close();
            return;
        }
    }

    // ���˻���Ϣд���ļ�
    outFile << newAccount.account << " " << newAccount.password <<"                                " << endl;
    cout << "�˺�ע��ɹ���" << endl;
    delay(1);
    system("cls");
    inFile.close();
    outFile.close();

}
void admit() {
    char option = '1';
    while (option) {
        cout << "���������ѡ�" << endl;
        cout << "    1.��������" << endl << "    2.ȫ����ͨͼ����ز���" << endl << "    3.ע��" << endl;
        cout << "���������֣�" << endl;
        cin >> option;
        switch (option) {
        case '1':
            changePassword();
            system("cls");
            break;
        case '2':
            adminALG();
            system("cls");
            break;
        case '3':
            system("cls");
            cout << "�˳���¼�ɹ�" << endl;
            delay(1);
            system("cls");
            break;
        default:
            cout <<endl<< "��������ȷ���֣�" << endl;
            delay(1);
            system("cls");
            continue;
        }
        if (option == '3')  break;
    }
}
void choice() {
    char controls = '1';
    while (controls) {
        system("cls");
        cout << endl << "��ѡ�����" << endl;
        cout << "    1.��¼" << endl << "    2.ע��" << endl<< "    3.�˳�" << endl;
        cout << "���������֣�";
        cin >> controls;
        switch (controls) {
        case '1':
            if (login()) {
                cout << endl << "��¼�ɹ���" << endl << endl;
                delay(1);
                system("cls");
                admit();
            }
            else {
                cout << endl << "��¼ʧ�ܣ������û���������" << endl << endl;
                delay(1);
                system("cls");
            }
            break;
        case '2':
            signin();
            break;
        case '3':
            break;
        default:
            cout << endl<< "��������ȷ����!" << endl;
            delay(1);
            system("cls");
            continue;
        }
        if (controls == '3') break;
    }
}
void identity() {
    char id = '1';
    while (id) {
        cout << endl << "==============��ӭ����ȫ����ͨ��ѯϵͳ==============" << endl;
        cout << "�������ǣ�" << endl;
        cout << "    1.����Ա" << endl << "    2.��ͨ�û�" << endl << "    3.�˳�ϵͳ" << endl;
        cout << "���������֣�";
        cin >> id;
        switch (id) {
        case '1':
            choice();
            system("cls");
            break;

        case '2':
            user();
            system("cls");
            break;

        case '3':
            break;
        default:
            cout << endl << "��������ȷ����!" << endl;
            delay(1);
            system("cls");
            break;
        }
        if (id == '3') break;
    }
    cout << endl << "==================��л���ʹ��==================" << endl;
}

int main() {

    identity();
    return 0;
}

