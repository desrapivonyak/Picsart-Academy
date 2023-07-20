#include "Patient.hpp"
#include <iostream>
#include <fstream>

int main() {
    Patient* obj = new Patient();
    obj->registeration();
    obj->set_report();
    obj->report_to_txt();
    delete obj;
}