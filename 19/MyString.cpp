//
//  MyString.cpp
//  19
//
//  Created by Егор Джемлиханов on 01.11.2024.
//

#include "MyString.hpp"
#include <iostream>

using namespace std;

int MyString::countLiveObj = 0;
int MyString::countCreatedObj = 0;

MyString::MyString()
{
    length = 80;
    str = new char[length + 1];
    for (size_t i = 0; i <= length; ++i)
    {
        str[i] = '\0';
    }

    countCreatedObj++;
    countLiveObj++;
}

MyString::MyString(int size)
{
    if (size < 0) size = 0;
    length = size;
    str = new char[length + 1];
    for (int i = 0U; i <= length; ++i)  //0U unsigned
    {
        str[i] = '\0';
    }

    countCreatedObj++;
    countLiveObj++;
}

MyString::MyString(const char* initStr)
{
    if (initStr == nullptr)
    {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        length = strlen(initStr);
        str = new char[length + 1];
        strcpy(str, initStr);
    }

    countCreatedObj++;
    countLiveObj++;
}

MyString::MyString(const MyString& other)
{
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);

    countCreatedObj++;
    countLiveObj++;
}

MyString::MyString(MyString&& obj)
{
    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;
}

MyString& MyString::operator=(MyString&& obj)
{
    if (str != nullptr) delete[] str;

    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;

    return *this;
}

MyString::MyString(initializer_list<char> a)
{
    length = a.size();
    str = new char[length + 1];

    for (auto x = a.begin(); x != a.end(); ++x)
    {
        *str = *x;
        str++;
    }

    *str = '\0';
    str -= length;
}


MyString::~MyString()
{
    delete[] str;
    countLiveObj--;
}


void MyString::MyStrcpy(MyString& obj)
{
    if (str == nullptr) return;
    delete[] obj.str;

    obj.length = length;
    obj.str = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        obj.str[i] = str[i];
    }

    obj.str[length] = '\0';
}

bool MyString::MyStrStr(const char* substr)
{
    if (str == nullptr or substr == nullptr) return false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        int j = 0;

        while (substr[j] != '\0' and str[i + j] != '\0' and str[i + j] == substr[j])
        {
            j++;
        }

        if (substr[j] == '\0') return true;
    }

    return false;
}

int MyString::MyChr(char c)
{
    if (str == nullptr) return -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

int MyString::MyStrLen()
{
    if (str == nullptr) return 0;

    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

void MyString::MyStrCat(MyString& b)
{
    if (str == nullptr) return;
    if (b.str == nullptr) return;

    int newLength = MyStrLen() + b.MyStrLen();
    char* newStr = new char[newLength + 1];

    int i = 0;
    for (; str[i] != '\0'; i++)
    {
        newStr[i] = str[i];
    }

    for (int j = 0; b.str[j] != '\0'; j++, i++)
    {
        newStr[i] = b.str[j];
    }

    newStr[newLength] = '\0';
    delete[] str;
    str = newStr;
    length = newLength;
}

void MyString::MyDelChr(char c)
{
    if (str == nullptr) return;

    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != c) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
    length = j;
}

int MyString::MyStrCmp(MyString& b)
{
    if (str == nullptr && b.str == nullptr) return 0;
    if (str == nullptr) return -1;
    if (b.str == nullptr) return 1;

    int i = 0;
    while (str[i] != '\0' && b.str[i] != '\0')
    {
        if (str[i] < b.str[i]) return -1;
        if (str[i] > b.str[i]) return 1;
        i++;
    }

    if (str[i] == '\0' && b.str[i] == '\0') return 0;
    if (str[i] == '\0') return -1;
    return 1;
}

MyString& MyString::operator+=(const char* appendStr)
{
    if (appendStr == nullptr) return *this;

    MyString temp(appendStr);

    MyStrCat(temp);

    return *this;
}

MyString operator+(const char* prefixStr, const MyString& myStr)
{
    if (prefixStr == nullptr) return myStr;

    MyString result(prefixStr);

    MyString temp(myStr);
    result.MyStrCat(temp);

    return result;
}


void MyString::Print()
{
    if (str == nullptr)
    {
        cout << "(null)" << endl;
    }
    else
    {
        cout << str << endl;
    }
}

void MyString::Input()
{
    char buffer[1024];
    cout << "напишите строку: ";

    cin.getline(buffer, 1024);

    delete[] str;

    length = strlen(buffer);
    str = new char[length + 1];
    strcpy(str, buffer);
}

void MyString::Save(char* filename)
{
    if (filename == nullptr or str == nullptr) return;

    ofstream file(filename);
    file << str;

    file.close();
}

void MyString::GetCountLiveObj()
{
    cout << "Количество живых объектов: " << countLiveObj << endl;
}

void MyString::GetCountCreatedObj()
{
    cout << "Общее количество созданных объектов: " << countCreatedObj << endl;
}

MyString MyString::operator=(const MyString& obj)
{
    if (this == &obj) return *this;
    delete[] str;

    length = obj.length;
    str = new char[length + 1];
    strcpy(str, obj.str);

    return *this;
}

MyString MyString::operator[](int index)
{
    return str[index];
}

void MyString::operator()()
{
    Print();
}

ostream& operator<<(ostream& os, MyString obj)
{
    obj.Print();
    return os;
}

istream& operator>>(istream& is, MyString& obj)
{
    obj.Input();
    return is;
}
