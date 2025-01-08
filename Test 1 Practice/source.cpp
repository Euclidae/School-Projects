#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

//Copies the fields from question itself
struct DiseaseData{
    int Disease_Code;
    std::string County;
    int Year;
    std::string Sex;
    int Count;
    size_t Population;
};
//Same here
struct DiseaseInfo{
    int Disease_Code;
    std::string Disease;
};

//Overloads the extraction operator. I am too lazy to handle multiple variables
//So I encapsulated as much as possible.
std::istream& operator >> (std::istream& is, DiseaseData& data){
    is >> data.Disease_Code >> data.County >> data.Year >> data.Sex >> data.Count >> data.Population;
    return is; 
}

//Same thing as above but this for disease info
std::istream& operator >> (std::istream& is, DiseaseInfo& data){
    is >> data.Disease_Code >> data.Disease;
    return is; 
}

//As specified by the instructions. I don't want to use char pointers due to potential future actions like string comparison
void viewCidDataByYear(std::string disease_info, std::string disease_data, std::string county, std::string sex, int year);

//as specified by instructions.
int main() {
    viewCidDataByYear("test_cid_data.txt", "test_disease_info.txt", "California", "Male", 2001);
    //System pause is not cross platform. As such, I prefer std::cin.get() [N.B I often code on linux]
    std::cin.get();
    //but if you insist on using system pause, you and want your ode to be cross platform, you can check OS
    // then set a string to what you want the command to be. Go to top and paste this
    /*#ifdef _WIN32
        #define command "pause"
        #else
        #define command "bash -c 'read -n1 -r'"
        #endif*/
    //Here, in main, type system(command);
    return 0;
}


void viewCidDataByYear(std::string disease_info, std::string disease_data, std::string county, std::string sex, int year){
    //Opens the appropriate files
    std::ifstream disease_data_stream(disease_info, std::ios::in);
    std::ifstream disease_info_stream(disease_data, std::ios::in);
    //design choice. only one container string needed cuz everything will be thrown into Struct's objects [convinient]
    std::string buffer;

    //trims the head off the file
    std::getline(disease_data_stream,buffer);

    //Create objects
    DiseaseInfo di_info;
    DiseaseData di_data;

    //Required by instructions
    int total_count = 0, total_rate = 0;

    //Defined the top part of the necessary output structure
    std::cout << "COUNTY NAME\t" << county << '\n';
    std::cout << "GENDER/SEX \t" << sex << '\n';
    std::cout << "YEAR       \t" << year << '\n';
    std::cout << std::string((50 + 13 + 13 + 4), '=') << std::endl;

    std::cout << std::left;
    std::cout << std::setw(13) << "DIS-CODE"
              << std::setw(50) << "DIS-NAME" << std::setw(13) << "COUNT"
              << std::setw(13) << "RATE" << std::endl;
     //std::string(N, 'char') has the same functionality as the proposed function writeCharLine. It's shorter to write so went with it
    //Also, just added the setw values from above to make sure the = characters endd up the same length as columns
    std::cout << std::string((50 + 13 + 13 + 4), '=') << std::endl;
    int record_count = 0;

    //iterate over disease_data_stream
    while(std::getline(disease_data_stream,buffer)){
        //horrible at naming things. d_d stands for disease_data_stream
        std::istringstream d_d_stream(buffer);
        //overloaded operator coming in clutch
        d_d_stream >> di_data;

        //As specified by instructions. All three of the inputs have to be true in order to progress
        if(di_data.County == county && di_data.Sex == sex && di_data.Year == year){
            //if true, we look a the other file. Same thing.
            //clips header off again but for other file.
            std::getline(disease_info_stream,buffer)

            while(std::getline(disease_info_stream, buffer)){
                std::istringstream d_i_stream(buffer);
                d_i_stream >> di_info;

                //Pretty straight forward I think. Messed up the math but it looks good, I suppose?
                if(di_info.Disease_Code == di_data.Disease_Code){
                              std::cout << std::left;
                              std::cout<<std::setw(13) << di_info.Disease_Code
                              << std::setw(50) << di_info.Disease << std::setw(13) << di_data.Count
                              << std::setw(13) << ((di_data.Count * 100000) / (di_data.Population)) << std::endl;

                    //convinience of structs shows itself again
                    total_count+=di_data.Count;
                    total_rate += ((di_data.Count * 100000)/(di_data.Population)); 
                    record_count++;
                }
                
            }
            //resets the disease info stream pointer to just after the columns in the text file
            //.clear() removes all error flags such as the file in question being = EOF
            disease_info_stream.clear();
            //takes pointer to the top. Should be 0 but makes no difference to be honest.  
            disease_info_stream.seekg(1);
        }
    }
    //lower half... this is where I messed up the math
    float average_count = static_cast<float>(total_count) / record_count;

    std::cout << std::string((50 + 13 + 13 + 4), '=') << std::endl;
    std::cout << std::left << "TOTAL" << std::setw(13 + 13 + 13) << std::right << total_count << std::setw(50) <<std::right << total_rate <<std::endl;
    std::cout << "NUMBER OF RECORDS(N)" << std::setw(50 + 13 + 13) << record_count << std::endl;
    std::cout << "AVERAGE COUNT" << std::setw(50 + 13 + 13) << average_count << std::endl;

    //Pretty obvious
    disease_data_stream.close();
    disease_info_stream.close();
}
//N.B Special notes for me, get better at naming things, stop forgetting toclose the file or just shove everything into a file buffer so you can close the files immediately
//N.B 2 Try it with recursion
