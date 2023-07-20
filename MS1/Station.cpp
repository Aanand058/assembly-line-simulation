// Name: Aanand Aman
// Seneca Student ID: 166125211
// Seneca email: aaman8@myseneca.ca
// Date of completion: 2023/03/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;


    Station::Station()
    {
    }


    Station::Station(const std::string& line) : m_id(++id_generator)
    {
        Utilities utilities;
        bool more;
        size_t next_p = 0;

        this->m_name = utilities.extractToken(line, next_p, more);

        this->m_nextSerialNo = stoi(utilities.extractToken(line, next_p, more));

        this->m_noOfItems = stoi(utilities.extractToken(line, next_p, more));

        this->m_widthField = max(utilities.getFieldWidth(), m_widthField);

        this->m_desc = utilities.extractToken(line, next_p, more);
    }


    const std::string & Station::getItemName() const
    {
        return this->m_name;
    }


    size_t Station::getNextSerialNumber()
    {
        return this->m_nextSerialNo++;
    }


    size_t Station::getQuantity() const
    {
        return this->m_noOfItems;
    }

    void Station::updateQuantity()
    {
        if (this->m_noOfItems > 0)
        {
            this->m_noOfItems--;
        }
    }


    void Station::display(ostream& os, bool full) const
    {

        os.width(3);
        os.fill('0');
        os << this->m_id << " | ";

        os.setf(ios::left);
        os.width(15);
        os.fill(' ');
        os << this->m_name << " | ";
        os.unsetf(ios::left);

        os.setf(ios::right);
        os.width(6);
        os.fill('0');
        os << this->m_nextSerialNo;
        os.unsetf(ios::right);

        if (full == true)
        {
            os << " | ";
            os.width(4);
            os.fill(' ');
            os << this->m_noOfItems << " | ";

            os.setf(ios::left);
            os << this->m_desc;
            os.unsetf(ios::left);
            os << endl;
        }
        else
        {
            os << " | " << endl;
        }
    }


    Station::~Station()
    {
    }
}