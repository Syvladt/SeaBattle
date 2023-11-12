// SeaBattle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// 1 - обозначает корабль в одну клетку
// 2 - обозначает корабль в две клетки
// 3 - обозначсет корабль в три клетки
// 4 - обозначает корабль четыре клетки 

#include <iostream>
#include <string>

void clear_arr(char arr[][10])
{
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            arr[i][j] = '~';
}

void print_arr(char arr_1[][10], char arr_2[][10], char player)
{
    std::cout << "     Поле игрока 1\t     Поле игрока 2\n";
    std::cout << "  0 1 2 3 4 5 6 7 8 9\t  0 1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " ";
        for (int j = 0; j < 10; ++j)
            if (player == '1' || player == '0')
                std::cout << arr_1[i][j] << ' ';
            else if (arr_1[i][j] == char(15) or arr_1[i][j] == 'X')
                std::cout << arr_1[i][j] << ' ';
            else
                std::cout << '~' << ' ';
        std::cout << "\t" << i << " ";
        for (int j = 0; j < 10; ++j)
            if (player == '2' || player == '0')
            std::cout << arr_2[i][j] << ' ';
            else if (arr_2[i][j] == char(15) or arr_2[i][j] == 'X')
                std::cout << arr_2[i][j] << ' ';
            else 
                std::cout << '~' << ' ';
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool set_ship(int x, int y, char pivot, int size, char arr[][10])
{
    bool result = true;
    if (pivot == 'X')
    {
        for (int i = x; (i < x + size) && result; ++i)
        {
            if (arr[y][i] == '~' && (x + size) < 10)
            {
                arr[y][i] = size + 48;
                result = true;
            }
            else
            {
                std::cout << "\nКорабль так не разместить\n";
                result = false;
            }
        }
    } else if (pivot == 'Y')
    {
        for (int i = y; (i < y + size) && result; ++i)
        {
            if (arr[i][x] == '~' && (y + size) < 10)
            {
                arr[i][x] = size + 48;
                result = true;
            }
            else
            {
                std::cout << "\nКорабль так не разместить\n";
                result = false;
            }
        }
    }
    return result;
}

void set_army(char field[][10])
{
    int x, y;
    std::string xy;
    char pivot;
// Раставляем однопалубные корабли
    std::cout << "\n";
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "Введите координаты (x, y) однопалубного корабля #" << i + 1 << " через пробел: ";
        std::cin >> x >> y;
        if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
            if (!set_ship(x, y, 'X', 1, field))
            {
                std::cout << "Установить однопалубный корабль #" << i + 1 << " не получлось. Возможно там уже стоит другой корабль\n";
                --i;
            }
    }
// Раставляем двухпалубные корабли
    std::cout << "\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Введите координаты двухпалубного корабля #" << i + 1 <<" (Например: 0,1-0,3): ";
        std::cin >> xy;
        if (xy.substr(0, 1) == xy.substr(4, 1))
        {
            pivot = 'Y';
            if (std::stoi(xy.substr(6, 1)) - std::stoi(xy.substr(2, 1)) != 1)
            {
                std::cout << "Введены неправильные координаты\n";
                --i;
            }
            else
            {
                x = std::stoi(xy.substr(0, 1));
                y = std::stoi(xy.substr(2, 1));
                if (!set_ship(x, y, pivot, 2, field))
                {
                    std::cout << "Установить двухпалубный корабль #" << i + 1 <<" не получлось. Возможно там уже стоит другой корабль\n";
                    --i;
                }
            }
        }
        else if (xy.substr(2, 1) == xy.substr(6, 1)) {
            pivot = 'X';
            if (std::stoi(xy.substr(4, 1)) - std::stoi(xy.substr(0, 1)) != 1)
                std::cout << "Введены неправильные координаты\n";
            else
            {
                x = std::stoi(xy.substr(0, 1));
                y = std::stoi(xy.substr(2, 1));
                if (!set_ship(x, y, pivot, 2, field))
                {
                    std::cout << "Установить двухпалубный корабль #" << i + 1 << " не получлось. Возможно там уже стоит другой корабль\n";
                    --i;
                }
            }
        }
        else
            std::cout << "Корабль не может быть расположен по диагонали\n";
    }
// Раставляем трёхпалубные корабли
    std::cout << "\n";
    for (int i = 0; i < 2; ++i)
    {
        std::cout << "Введите координаты трёхпалубного корабля #" << i + 1 << " (Например: 0,1-0,3): ";
        std::cin >> xy;
        if (xy.substr(0, 1) == xy.substr(4, 1))
        {
            pivot = 'Y';
            if (std::stoi(xy.substr(6, 1)) - std::stoi(xy.substr(2, 1)) != 2)
                std::cout << "Введены неправильные координаты\n";
            else
            {
                x = std::stoi(xy.substr(0, 1));
                y = std::stoi(xy.substr(2, 1));
                if (!set_ship(x, y, pivot, 3, field))
                {
                    std::cout << "Установить трёхпалубный корабль #" << i + 1 << " не получлось. Возможно там уже стоит другой корабль\n";
                    --i;
                }
            }
        }
        else if (xy.substr(2, 1) == xy.substr(6, 1)) {
            pivot = 'X';
            if (std::stoi(xy.substr(4, 1)) - std::stoi(xy.substr(0, 1)) != 2)
                std::cout << "Введены неправильные координаты\n";
            else
            {
                x = std::stoi(xy.substr(0, 1));
                y = std::stoi(xy.substr(2, 1));
                if(!set_ship(x, y, pivot, 3, field))
                {
                    std::cout << "Установить трёхпалубный корабль #" << i + 1 << " не получлось. Возможно там уже стоит другой корабль\n";
                    --i;
                }
            }
        }
        else
            std::cout << "Корабль не может быть расположен по диагонали\n";
    }

// Ставим четырёхпалубный корабль
    std::cout << "\n";
    while (true)
    {
        std::cout << "Введите координаты четырёхпалубного корабля (Например: 0,1-0,3): ";
        std::cin >> xy;
        if (xy.substr(0, 1) == xy.substr(4, 1))
        {
            pivot = 'Y';
            if (std::stoi(xy.substr(6, 1)) - std::stoi(xy.substr(2, 1)) != 3)
                std::cout << "Введены неправильные координаты\n";
            else
            {
                x = std::stoi(xy.substr(0, 1));
                y = std::stoi(xy.substr(2, 1));
                if (!set_ship(x, y, pivot, 4, field))
                    std::cout << "Установить четырёхпалубный корабль не получлось. Возможно там уже стоит другой корабль\n";
                else
                    break;
            }
        }
        else if (xy.substr(2, 1) == xy.substr(6, 1)) {
            pivot = 'X';
            if (std::stoi(xy.substr(4, 1)) - std::stoi(xy.substr(0, 1)) != 3)
                std::cout << "Введены неправильные координаты\n";
            else
            {
                x = std::stoi(xy.substr(0, 1));
                y = std::stoi(xy.substr(2, 1));
                if (!set_ship(x, y, pivot, 4, field))
                    std::cout << "Установить четырёхпалубный корабль не получлось. Возможно там уже стоит другой корабль\n";
                else
                    break;
            }
        }
        else
            std::cout << "Корабль не может быть расположен по диагонали\n";
    }
}

int attack(int x, int y, char arr[][10])
{
    if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
    {
        if (arr[y][x] == '~' || arr[y][x] == char(15))
        {
            arr[y][x] = char(15);
            return 0;
        }
        else
        {
            arr[y][x] = 'X';
            return 1;
        }
    }
    else
        return -1;
}

int main()
{
    setlocale(LC_ALL, "RU_ru");
    std::cout << "\nПрограмма морского месива.\n\n";
    int hit_player_1 = 0, hit_player_2 = 0, x, y, hit;
    char player_1[10][10], player_2[10][10], player = '1';
    clear_arr(player_1);
    clear_arr(player_2);
    print_arr(player_1, player_2, '0');
    std::cout << "\nРасставляем корабли игрока 1:\n";
    set_army(player_1);
    std::cout << "\nРасставляем корабли игрока 2:\n";
    set_army(player_2);

    while (hit_player_1 < 20 && hit_player_2 < 20)
    {
        std::cout << "Ход игрока " << player << ".\nВведите координаты точки атаки через пробел: ";
        std::cin >> x >> y;
        if (player == '1')
        {
            hit = attack(x, y, player_2);
            if (hit == -1)
            {
                std::cout << "Вы не попали в поле. Переход хода.\n";
                player = '2';
            }
            else if (hit == 0)
            {
                std::cout << "Вы НЕ попали в корабль. Переход хода.\n";
                player = '2';
            }
            else
            {
                std::cout << "Вы попали в корабль. У вас ещё одна попытка.\n";
                player = '1';
                ++hit_player_1;
            }
        }
        else
        {
            hit = attack(x, y, player_1);
            if (hit == -1)
            {
                std::cout << "Вы не попали в поле. Переход хода.\n";
                player = '1';
            }
            else if (hit == 0)
            {
                std::cout << "Вы НЕ попали в корабль. Переход хода.\n";
                player = '1';
            }
            else
            {
                std::cout << "Вы попали в корабль. У вас ещё одна попытка.\n";
                player = '2';
                ++hit_player_2;
            }
        }
        print_arr(player_1, player_2, player);
    }
    if (hit_player_1 == 20)
        std::cout << "Победил ИГРОК #1!\n";
    else if (hit_player_2 == 20)
        std::cout << "Победил ИГРОК #2!\n";
    print_arr(player_1, player_2, '0');
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
