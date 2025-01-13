#include "../include/Person.h"

bool Person::operator < (const Person& other) const {
    if (surname < other.surname) return 1;
    if (surname > other.surname) return 0;
    if (name < other.name) return 1;
    if (name > other.name) return 0;
    if (patronymic < other.patronymic) return 1;
    if (patronymic > other.patronymic) return 0;
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Имя: " << person.name << "\n"
       << "Фамилия: " << person.surname << "\n"
       << "Отчество: " << person.patronymic << "\n"
       << "Пол: " << person.gender << "\n"
       << "Адрес: " << person.address << "\n"
       << "Работа: " << person.job << "\n"
       << "Организация: " << person.entity << "\n"
       << "Образование: " << person.education << "\n"
       << "Вес: " << person.weight << " кг\n"
       << "Возраст: " << person.age << " лет\n";
    return os;
}

int age_cmp(const Person& first, const Person& second) {
    return first.age < second.age;
}

int fcs_cmp(const Person& first, const Person& second) {
    if (first.surname < second.surname) return 1;
    if (first.surname > second.surname) return 0;

    if (first.name < second.name) return 1;
    if (first.name > second.name) return 0;

    if (first.patronymic < second.patronymic) return 1;
    if (first.patronymic > second.patronymic) return 0;
    return 0;
}
