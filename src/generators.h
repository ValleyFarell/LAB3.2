#include <iostream>
#include <fstream>
#include <random>
#include <unistd.h>
#include "sequence/ArraySequence.h"
#include "Person.h"

#ifndef GENERATORS_H
#define GENERATORS_H

std::string gen_rand_str(const int len);
long long gen_rand_int(long long l, long long r);
ArraySequence<Person>* generate_persons(int amount);
ArraySequence<int>* generate_random_integers(int amount, int l, int r);
ArraySequence<int>* generate_increasing_integers(int amount);
ArraySequence<int>* generate_decreasing_integers(int amount);
ArraySequence<int>* generate_from_user(int amount);
ArraySequence<int>* generate_integers(int amount, int l, int r, std::string mode, int average);

#endif // GENERATORS_H
