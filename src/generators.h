#include<iostream>
#include<fstream>
#include<random>
#include <unistd.h>

#include"sequence/ArraySequence.h"
#include"Person.h"

#ifndef GENERATORS_H
#define GENERATORS_H

std::string gen_rand_str(const int len) {
    srand((unsigned)time(NULL) * getpid());
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

long long gen_rand_int(long long l, long long r) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(l, r);
        return distr(gen);
    }

ArraySequence<Person>* generate_persons(int amount) {
    ArraySequence<Person>* persons = new ArraySequence<Person>(amount);

    int dataset_size = 20000;

    ArraySequence<std::string> names(dataset_size);
    ArraySequence<std::string> surnames(dataset_size);
    ArraySequence<std::string> patronymics(dataset_size);

    std::string line;

    std::ifstream names_in("./data/men/names.txt");
    std::ifstream surnames_in("./data/men/surnames.txt");
    std::ifstream patronymic_in("./data/men/patronymic.txt");

    if (names_in.is_open() && surnames_in.is_open() && patronymic_in.is_open())
    {
        for (int i = 0; i != dataset_size / 2; ++i) {
            std::getline(names_in, line);
            names[i] = line;
            std::getline(surnames_in, line);
            surnames[i] = line;
            std::getline(patronymic_in, line);
            patronymics[i] = line;
        }
    }

    names_in.close();
    surnames_in.close();
    patronymic_in.close();

    names_in.open("./data/women/names.txt");
    surnames_in.open("./data/women/surnames.txt");
    patronymic_in.open("./data/women/patronymic.txt");

    if (names_in.is_open() && surnames_in.is_open() && patronymic_in.is_open())
    {
        for (int i = dataset_size / 2; i != dataset_size; ++i) {
            std::getline(names_in, line);
            names[i] = line;
            std::getline(surnames_in, line);
            surnames[i] = line;
            std::getline(patronymic_in, line);
            patronymics[i] = line;
        }
    }

    for (int i = 0; i != amount; ++i) {
        if (gen_rand_int(0, 1)) {
            persons->get(i).name = names[gen_rand_int(0, dataset_size / 2)];
            persons->get(i).surname = surnames[gen_rand_int(0, dataset_size / 2)];
            persons->get(i).patronymic = patronymics[gen_rand_int(0, dataset_size / 2)];
            persons->get(i).age = gen_rand_int(0, 100);
            persons->get(i).address = gen_rand_str(20);
            persons->get(i).entity = gen_rand_str(20);
            persons->get(i).education = gen_rand_str(20);
            persons->get(i).weight = gen_rand_int(0, 100);
            persons->get(i).job = gen_rand_str(20);
            persons->get(i).gender = "MAN";
        } else {
            persons->get(i).name = names[gen_rand_int(dataset_size / 2 + 1, dataset_size - 1)];
            persons->get(i).surname = surnames[gen_rand_int(dataset_size / 2 + 1, dataset_size - 1)];
            persons->get(i).patronymic = patronymics[gen_rand_int(dataset_size / 2 + 1, dataset_size - 1)];
            persons->get(i).age = gen_rand_int(0, 100);
            persons->get(i).address = gen_rand_str(20);
            persons->get(i).entity = gen_rand_str(20);
            persons->get(i).education = gen_rand_str(20);
            persons->get(i).weight = gen_rand_int(0, 100);
            persons->get(i).job = gen_rand_str(20);
            persons->get(i).gender = "WOMAN";
        }
        
    }
    names_in.close();
    surnames_in.close();
    patronymic_in.close();
    return persons;
}

ArraySequence<int>* generate_random_integers(int amount, int l, int r) {
    ArraySequence<int>* result = new ArraySequence<int>(amount);
    for (int i = 0; i != amount; ++i) {
        result->get(i) = gen_rand_int(l, r);
    }
    return result;
}

ArraySequence<int>* generate_increasing_integers(int amount) {
    ArraySequence<int>* result = new ArraySequence<int>(amount);
    for (int i = 0; i != amount; ++i) {
        result->get(i) = i + 1;
    }
    return result;
}

ArraySequence<int>* generate_decreasing_integers(int amount) {
    ArraySequence<int>* result = new ArraySequence<int>(amount);
    for (int i = 0; i != amount; ++i) {
        result->get(i) = amount - i;
    }
    return result;
}

ArraySequence<int>* generate_from_user(int amount) {
    ArraySequence<int>* result = new ArraySequence<int>(amount);
    for (int i = 0; i != amount; ++i) {
        std::cout << "   " << i << ": ";
        int tmp;
        std::cin >> tmp;
        result->get(i) = tmp;
    }
    return result;
}

ArraySequence<int>* generate_integers(int amount, int l, int r, std::string mode, int average) {
    ArraySequence<int>* result = new ArraySequence<int>(amount);
    for (int i = 0; i != amount; ++i) {
        result->get(i) = amount - i;
    }
    return result;
}
#endif