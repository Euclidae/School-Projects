#include <iostream>
#include <fstream>
#include <string>

#define MAX_ARRAY_SIZE 100
#define FIRST_X_ITEMS 5

std::ifstream input_stream("inventory.txt", std::ios::in);
std::ofstream output_stream("reports.txt", std::ios::out);

struct Grocery{
    std::string ID;
    std::string name;
    std::string category;
    float price;
    long long quantity;
};

void copy_contents(Grocery& tracker, Grocery& item){
    tracker.ID = item.ID;
    tracker.name = item.name;
    tracker.category = item.category;
    tracker.price = item.price;
    tracker.quantity = item.quantity;
}

std::string buffer;

int main(){
    std::getline(input_stream,buffer);
    Grocery item_list[MAX_ARRAY_SIZE];
    int counter = 0;
    double full_stock_value;
    Grocery item, tracker;

    while(input_stream >> item.ID >> item.name >> item.category >> item.price >> item.quantity){
        if(item.price > tracker.price){
            copy_contents(tracker, item);
        }

        item_list[counter] = item;
        counter++;
        full_stock_value += item.price;
    }

    output_stream << "Most Expensive Item ; " << tracker.ID << " " << tracker.name << " " << tracker.category << " " <<tracker.price << '\n';
    output_stream << "The first 5 items on the list : \n";
    for(int i = 0; i < FIRST_X_ITEMS; ++i){
        output_stream << item_list[i].ID << " " << item_list[i].name << " " << item_list[i].price * item_list[i].quantity << '\n';  
    }

    input_stream.close();
    output_stream.close();

    return 0;
}
