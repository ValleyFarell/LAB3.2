#include<iostream>
#include <random>

#include"include/Person.h"
#include"include/UI.h"
#include"include/tests.h"

int main() {
    UI ui;
    ui.main();
    run_all_tests();
}