
#include<iostream>
#include<string>
#include <fstream>
#include <conio.h>

using namespace std;

// 存储账号密码的文件路径
const string accountFilePath = "accounts.txt";
// 结构体表示账户信息
struct Account {
    string account;
    string password;
};
void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}
void search() {
    char func = '1';
    while (func) {
        system("cls");
        cout << "==============进入查询模式==============" << endl << endl;
        cout << "    现在是全国交通图的信息查询！" << endl;
        cout << "请选择下列操作之一" << endl;
        cout << "    1.查询两城市间，花费最少的路径" << endl;
        cout << "    2.查询两城市间，耗时最少的路径" << endl;
        cout << "    3.显示所有城市" << endl;
        cout << "    4.显示所有线路" << endl;
        cout << "    5.查询两城市间，中转次数最少的路径" << endl;
        cout << "    6.退出查询模式" << endl;
        cout << "请输入数字：";
        cin >> func;
        switch (func) {
        case '6':
            system("cls");
            cout << "退出查询模式成功" << endl;
            delay(1);
            system("cls");
            break;

        default:
            cout << endl << "请输入正确数字!" << endl;
            delay(0.5);
            system("cls");
            continue;
        }
        if (func == '6') break;
    }
}
void adminALG() {
    char func2 = '1';
    while (func2) {
        system("cls");
        cout << "==============进入管理员模式==============" << endl << endl;
        cout << "请选择下列操作之一" << endl;
        cout << "    1.从文件中添加城市" << endl;
        cout << "    2.手动添加城市" << endl;
        cout << "    3.删除城市" << endl;
        cout << "    4.从文件中添加线路" << endl;
        cout << "    5.手动添加线路" << endl;
        cout << "    6.删除线路" << endl;
        cout << "    7.进入查询模式" << endl;
        cout << "    8.退出管理员模式" << endl;
        cout << "请输入数字：";
        cin>>func2;
        cout << endl;
        switch (func2) {
        case '7':
            search();
            system("cls");
            break;
        case '8':
            system("cls");
            cout << "退出管理员模式成功" << endl;
            delay(1);
            system("cls");
            break;
        default:
            cout << "请输入正确数字!" << endl;
            delay(0.5);
            system("cls");
            continue;
        }
        if (func2 == '8') break;
    }
}
void user() {
    char func1 = '1';
    while (func1) {
        system("cls");
        cout << "==============进入普通用户模式==============" << endl << endl;
        cout << "    现在是全国交通图的信息查询！" << endl;
        cout << "请选择下列操作之一" << endl;
        cout << "    1.查询两城市间，花费最少的路径" << endl;
        cout << "    2.查询两城市间，耗时最少的路径" << endl;
        cout << "    3.显示所有城市" << endl;
        cout << "    4.显示所有线路" << endl;
        cout << "    5.查询两城市间，中转次数最少的路径" << endl;
        cout << "    6.退出普通用户模式" << endl;
        cout << "请输入数字：";
        cin >> func1;
        switch (func1) {
        case '6':
            system("cls");
            cout << "退出普通用户模式成功" << endl;
            delay(1);
            system("cls");
            break;
        default:
            cout <<endl<< "请输入正确数字!" << endl;
            delay(0.5);
            system("cls");
            continue;
        }
        if (func1 == '6') break;
    }
}
bool login() {
    std::ifstream inFile(accountFilePath);
    if (!inFile.is_open()) {
        cerr << "无法打开账户文件"<<endl;
        return false;
    }

    Account inputAccount;
    cout << "请输入用户名: ";
    cin >> inputAccount.account;
    cout << "请输入密码: ";
    char ch;
    while ((ch = _getch()) != 13) { // 13 是回车键的 ASCII 值
        inputAccount.password.push_back(ch);
        cout << '*';
    }//将密码隐藏显示

    string storedUsername, storedPassword;

    // 逐行读取账户信息，判断是否匹配
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
        cerr << "无法打开账户文件。" << endl << endl;
        return;
    }
    Account inputAccount;
    cout << "请输入用户名: ";
    cin >> inputAccount.account;
    cout << "请输入旧密码: ";
    cin >> inputAccount.password;

    string storedUsername, storedPassword;
    streampos position;

    // 逐行读取账户信息，判断是否匹配
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == inputAccount.account && storedPassword == inputAccount.password) {
            cout << "请输入新密码: ";
            cin >> inputAccount.password;

            // Ensure the new password doesn't contain spaces
            if (inputAccount.password.find(' ') != string::npos) {
                cerr << "新密码不能包含空格，请重新输入。" << endl << endl;
                file.close();
                return;
            }

            // 定位到修改密码的位置
            position = file.tellg();
            file.seekp(position - static_cast<streampos>(storedPassword.length() + 1));
            file << " "<<inputAccount.password;
            file.flush(); // 刷新文件流
            file.close(); // 关闭文件
            cout << "密码修改成功！" << endl << endl;
            return;
        }
    }

    cerr << "用户名或密码错误，无法修改密码。" << endl << endl;
    file.close();
}
void signin() {
    std::ofstream outFile(accountFilePath, ios::out | ios::app);
    if (!outFile.is_open()) {
        cerr << "无法打开账户文件" << endl;
        return;
    }

    cout << "请输入注册的账号密码" << endl;
    Account newAccount;
    cout << "请输入用户名: ";
    cin >> newAccount.account;
    cout << "请输入密码: ";
    cin >> newAccount.password;

    // 检查是否已存在相同的用户名
    ifstream inFile(accountFilePath);
    string storedUsername;

    while (inFile >> storedUsername) {
        if (storedUsername == newAccount.account) {
            cerr << "用户名已存在，请选择其他用户名。" << endl << endl;
            inFile.close();
            outFile.close();
            return;
        }
    }

    // 将账户信息写入文件
    outFile << newAccount.account << " " << newAccount.password <<"                                " << endl;
    cout << "账号注册成功！" << endl;
    delay(1);
    system("cls");
    inFile.close();
    outFile.close();

}
void admit() {
    char option = '1';
    while (option) {
        cout << "请输入你的选项：" << endl;
        cout << "    1.更改密码" << endl << "    2.全国交通图的相关操作" << endl << "    3.注销" << endl;
        cout << "请输入数字：" << endl;
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
            cout << "退出登录成功" << endl;
            delay(1);
            system("cls");
            break;
        default:
            cout <<endl<< "请输入正确数字！" << endl;
            delay(0.5);
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
        cout << endl << "请选择操作" << endl;
        cout << "    1.登录" << endl << "    2.注册" << endl<< "    3.退出" << endl;
        cout << "请输入数字：";
        cin >> controls;
        switch (controls) {
        case '1':
            if (login()) {
                cout << endl << "登录成功！" << endl << endl;
                delay(1);
                system("cls");
                admit();
            }
            else {
                cout << endl << "登录失败，请检查用户名和密码" << endl << endl;
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
            cout << endl<< "请输入正确数字!" << endl;
            delay(0.5);
            system("cls");
            continue;
        }
        if (controls == '3') break;
    }
}

int main() {
    system("cls");
    char id = '1';
    while (id) {
        cout << endl << "==============欢迎进入全国交通咨询系统==============" << endl;
        cout << "你的身份是？" << endl;
        cout << "    1.管理员" << endl << "    2.普通用户" << endl << "    3.退出系统" << endl;
        cout << "请输入数字：";
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
            cout << endl<< "请输入正确数字!" << endl;
            delay(0.5);
            system("cls");
            break;
        }
        if (id == '3') break;
    }
    cout << endl << "==================感谢你的使用==================" << endl;
    return 0;
}