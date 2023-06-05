#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Student {
    std::string surname;
    float averageScore;
};

void readDataFromFile(const std::string& filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string surname;
        float averageScore;
        while (file >> surname >> averageScore) {
            students.push_back({surname, averageScore});
        }
        file.close();
    }
}

void printMenu() {
    std::cout << "=============================" << std::endl;
    std::cout << "1. Загрузить данные из файла" << std::endl;
    std::cout << "2. Вывести наибольший средний балл" << std::endl;
    std::cout << "3. Вывести наименьший средний балл" << std::endl;
    std::cout << "4. Выход" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Выберите действие: ";
}

void findMaxAverageScore(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Нет данных" << std::endl;
        return;
    }
    
    auto maxScoreStudent = std::max_element(students.begin(), students.end(),
        [](const Student& s1, const Student& s2) {
            return s1.averageScore < s2.averageScore;
        });

    std::cout << "Наибольший средний балл: " << maxScoreStudent->surname
              << " - " << maxScoreStudent->averageScore << std::endl;
}

void findMinAverageScore(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Нет данных" << std::endl;
        return;
    }
    
    auto minScoreStudent = std::min_element(students.begin(), students.end(),
        [](const Student& s1, const Student& s2) {
            return s1.averageScore < s2.averageScore;
        });

    std::cout << "Наименьший средний балл: " << minScoreStudent->surname
              << " - " << minScoreStudent->averageScore << std::endl;
}

void solveTask1() {
    std::vector<Student> students;
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;
    readDataFromFile(filename, students);

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                readDataFromFile(filename, students);
                break;
            case 2:
                findMaxAverageScore(students);
                break;
            case 3:
                findMinAverageScore(students);
                break;
            case 4:
                std::cout << "Выход из программы" << std::endl;
                break;
            default:
                std::cout << "Неверный выбор" << std::endl;
                break;
        }
    } while (choice != 4);
}

void solveTask2() {
    float a, b, c;
    std::cout << "Введите длины сторон треугольника: ";
    std::cin >> a >> b >> c;

    float cosA = (b * b + c * c - a * a) / (2 * b * c);
    float cosB = (a * a + c * c - b * b) / (2 * a * c);
    float cosC = (a * a + b * b - c * c) / (2 * a * b);

    float angleA = std::acos(cosA) * 180 / M_PI;
    float angleB = std::acos(cosB) * 180 / M_PI;
    float angleC = std::acos(cosC) * 180 / M_PI;

    float semiperimeter = (a + b + c) / 2;
    float area = std::sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));

    std::cout << "Угол A: " << angleA << "°" << std::endl;
    std::cout << "Угол B: " << angleB << "°" << std::endl;
    std::cout << "Угол C: " << angleC << "°" << std::endl;
    std::cout << "Площадь: " << area << std::endl;
}

int main() {
    int task;
    std::cout << "Выберите задачу (1 или 2): ";
    std::cin >> task;

    if (task == 1) {
        solveTask1();
    } else if (task == 2) {
        solveTask2();
    } else {
        std::cout << "Неверный выбор задачи" << std::endl;
    }

    return 0;
}