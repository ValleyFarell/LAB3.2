#include <string>
#include <iostream>

#ifndef TYPES
#define TYPES

class Person {
public:
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string gender;
    std::string address;
    std::string job;
    std::string entity;
    std::string education;
    unsigned int weight;
    unsigned int age;

    bool operator < (const Person& other) const;
};

std::ostream& operator<<(std::ostream& os, const Person& person);
int age_cmp(const Person& first, const Person& second);
int fcs_cmp(const Person& first, const Person& second);

#endif // TYPES