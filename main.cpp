#include "lib/game.hpp"
#include <iostream>
#include <limits>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    createFiles();

    while (true) {
        std::cout << "Привет! Это крестики-нолики. <3\n";
        std::cout << "1. Начать игру\n";
        std::cout << "2. Настройки\n";
        std::cout << "3. История игр\n";
        std::cout << "4. Выход\n";
        std::cout << "Ваши действия: ";

        int choice;
        while (!(std::cin >> choice) || (choice < 1 || choice > 4)) {
            std::cout << "Ошибка выбора. Введите число от 1 до 4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: startGame(); break;
            case 2: configParams(); break;
            case 3: showStats(); break;
            case 4:
                std::cout << "Выход из игры.\n";
                return 0;
        }
    }
}
