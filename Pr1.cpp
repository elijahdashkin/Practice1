#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Menu {
    string name;       
    double price;     
    string cookTime;  

    void print() const {

        cout <<"Название: " << name << "  Цена: " << price << "Руб  Время приготовления: " << cookTime << "мин" << endl;
    }
};

// Функция для разбиения(парсинга) строки и создания объекта Menu
Menu parseMenu(const string& line) {
    istringstream iss(line);
    Menu m;
    iss >> m.name >> m.price >> m.cookTime;
    return m;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    ifstream file("menu_data.txt");//открываем файл с инфой
    if (!file) {

        cout << "Файл не найден!" << endl;//если файла нет выводим ошибку
       return 1;
    }

    vector<Menu> menuItems;//создаем вектор для сохранения инфы из файла
    string line;

    while (getline(file, line)) {//добавление инфы в вектор
        menuItems.push_back(parseMenu(line));
    }
    cout << menuItems.size() << endl;
    file.close();

    cout << "Меню:\n";
    for (const auto& m : menuItems) {
        m.print();//выводим меню на консоль
    }

    return 0;
}
