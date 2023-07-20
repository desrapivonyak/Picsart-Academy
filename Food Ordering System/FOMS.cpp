#include <iostream>
#include "Restaurant.h"
#include "OrderSystem.h"

int main()
{
    std::map<std::string, int> menu;
    menu["pizza"] = 3500;
    menu["burger"] = 1750;
    menu["soup"] = 1200;
    menu["free"] = 500;
    menu["juice"] = 800;
    Restaurant obj{ "Yerevan Park", "Yerevan", menu };
    Customer customer{ "Aram", "37444720028" };
    OrderSystem order{customer};
    std::pair<std::string, int> ord = order.placeOrder(obj);
    order.report_to_console(order.bill_generation(ord.first, obj));
    order.report_to_txt(order.bill_generation(ord.first, obj));
}