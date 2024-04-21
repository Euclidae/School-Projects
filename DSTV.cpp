/*c) Write a C+4 program to calculate a customer's bill for DSTV Eswat n ,
ere are wo
types of customers: residential and business. There are two rates for calculating DSTV
bill: one for residential Customers and one for business customers. For residential
customers, the following rates apply:
Bili processing fee:E18.50
Basic service fee:E40
Premium Channels:EIO per channel
For business customers, the following rates apply:
processing fee:E80
Basic service fee:E130 for the first IO connections, E20 for each additional
connection
Premium channels:EIOO per channel for any number of connections
Note: the program should ask the user for an account number(an integer) and customer code,
Input: the customers's account number, customer code, number of premium channels to which
the user subscribe and in the case of business customer's, number of basic service connections*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string customer_type,customer_code;
    float bill_processing, basic_service, additional_costs, io_connections_costs, total_costs;
    int account_number, premium_channel_number, basic_service_connections, IO_Connections;
    cout << "Please input your license type: residential or business: ";
    cin >> customer_type;

    cout << "\nFollowing up, input your customr account number: ";
    cin >> account_number;

    cout << "\nNow, input your customer code: ";
    cin >> customer_code;

    cout << "\nNext input the number of premium channels you have: ";
    cin >> premium_channel_number;


    if(customer_type == "residential"){
        bill_processing = 18.50;
        basic_service = 40;
        total_costs += (basic_service + bill_processing + (10*premium_channel_number));
    }
    else if(customer_type == "business"){
        cout << "\nPlease input your number of basic service connections: ";
        cin >> basic_service_connections;

        cout << "\nPlease add your number of IO connections: ";
        cin >> IO_Connections;


        bill_processing = 80;
        basic_service = 130;
        if(IO_Connections > 1){
            io_connections_costs += (IO_Connections * 20);

        }
        total_costs += (basic_service + bill_processing + (100*premium_channel_number)+ io_connections_costs);

    }
    cout << "\ncustomer " << customer_code << " is " + customer_type << " and their total expenditure is " << total_costs;
    return 0;    
}