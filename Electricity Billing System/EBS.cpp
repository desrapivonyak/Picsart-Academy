#include <iostream>
#include "Customer.h"
#include "Consumption.h"
#include "Calculation.h"

int main()
{
    Consumption obj;
    obj.add_consumption();
    Calculation ob{};
    ob.set_per_unit();
    ob.calculate(obj);
    ob.report_to_txt(obj);
}