#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Car{
    string model_name, manufacturer;
    int year;
    double price;
    int quantity;

};

void loadInventory(Car inventory[], int& count, string filename);
void addCar(Car inventory[], int& count);
void displayInventory(const Car inventory[], int count);
void searchByManufacturer(const Car inventory[], int count, const string& manufacturer, string outfile);
void calculateTotalValue(const Car inventory[], int count);

int main(){
    Car inventory[100];
    int count = 0;
    loadInventory(inventory, count, "inventory.txt");
    addCar(inventory, count);
    displayInventory(inventory, count);
    searchByManufacturer(inventory, count, "Honda", "report.txt");
    calculateTotalValue( inventory,count);
    return 0;
}

void loadInventory(Car inventory[], int& count, string filename){
    ifstream in_file(filename, ios::in);
    Car car;
    if(!in_file.is_open())return;
    getline(in_file,filename);
    while(in_file >> car.model_name >> car.manufacturer >> car.year >> car.price >> car.quantity){
        inventory[count] = car;
        ++count;
    }

}


void addCar(Car inventory[], int& count){
    Car car;
    std::cin >> car.model_name >> car.manufacturer >> car.year >> car.price >> car.quantity;
    if(count < 100 && count > 0) inventory[count] = car;
    else return;
}


void displayInventory(const Car inventory[], int count){
    for(int i = 0; i < count; ++i){
        cout << inventory[i].model_name<< " " << inventory[i].manufacturer << " " << inventory[i].year<< " " << inventory[i].price
        << " " << inventory[i].quantity << " "<<inventory[i].quantity * inventory[i].price <<'\n';
    }
}


void searchByManufacturer(const Car inventory[], int count, const string& manufacturer, string outfile){
    ofstream out_file(outfile, ios::out);
    for(int i = 0; i < count; ++i){
        if(inventory[i].manufacturer != manufacturer ) continue;
        else{
            out_file << inventory[i].model_name<< " " << inventory[i].manufacturer << " " << inventory[i].year<< " " << inventory[i].price
            << " " << inventory[i].quantity << "\n";
        }
    }
}


void calculateTotalValue(const Car inventory[], int count){
    double stock;
    for(int i = 0; i < count; ++i){
        stock += (inventory[i].price * inventory[i].quantity);
    }
    std::cout << "Currency : " << stock << endl;
}

