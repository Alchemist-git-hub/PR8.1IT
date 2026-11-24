#include <iostream>
#include <cstring>

using namespace std;

bool SearchPair(const char* str)
{
    for (int i = 0; str[i + 1] != '\0'; i++)
    {
        if ((str[i] == 'n' && str[i + 1] == 'o') ||
            (str[i] == 'o' && str[i + 1] == 'n'))
        {
            return true;
        }
    }

    return false;
}

char* ReplaceNo(const char* str)
{
    int len = strlen(str);

    // Виділяємо пам'ять для нового рядка
    char* result = new char[len * 2 + 1];

    int i = 0;
    int j = 0;

    while (str[i] != '\0')
    {
        if (str[i] == 'n' && str[i + 1] == 'o')
        {
            result[j++] = '*';
            result[j++] = '*';
            result[j++] = '*';

            i += 2;
        }
        else
        {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';

    return result;
}

int main()
{
    char str[101];

    cout << "Enter string: ";
    cin.getline(str, 101);

    // Перше завдання
    if (SearchPair(str))
        cout << "There is a pair 'no' or 'on'." << endl;
    else
        cout << "There is NOT pair 'no' or 'on'." << endl;

    // Друге завдання
    char* result = ReplaceNo(str);

    cout << "Original string: " << str << endl;
    cout << "Modified string: " << result << endl;

    delete[] result;

    return 0;
}
