// Name: Aanand Aman
// Seneca Student ID: 166125211
// Seneca email: aaman8@myseneca.ca
// Date of completion: 2023/03/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#ifndef SDDS_STATION_H
#define SDDS_STATION_H


#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>


namespace sdds {

    class Station
    {
        //Instance Variaables
        size_t m_id{};
        std::string m_name{};
        std::string m_desc{};
        unsigned int m_nextSerialNo{};
        unsigned int m_noOfItems{};


        //Class variables
        static size_t m_widthField;
        static size_t id_generator;

    public:

        //Default Constructor
        Station();

        //1-arg Constructor
        Station(const std::string& str);

        //Returns the name of current Stattion object
        const std::string& getItemName() const;
        
        // returns the next serial number to be used on the assembly line and increments m_serialNumber
        size_t getNextSerialNumber();

        //returns the remaining quantity of items in the Station object
        size_t getQuantity() const;

        //subtracts 1 from the available quantity; should not drop below 0.
        void updateQuantity();

        //Dsiplay Output
        void display(std::ostream& os, bool full) const;

        //Deconstructor
        ~Station();
    };


}
#endif 