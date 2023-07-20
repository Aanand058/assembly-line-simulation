// Name: Aanand Aman
// Seneca Student ID: 166125211
// Seneca email: aaman8@myseneca.ca
// Date of completion: 2023/03/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H


#include <iostream>
#include <string>
#include <algorithm> 



namespace sdds {

    class Utilities
    {
        //Instance Variable
        size_t m_widthField = 1;

        //Class Variable
        static char m_delimiter;


        //Trim blank spaces from front and back
        void trim(std::string& str) {
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
                return !std::isspace(ch);
                }));
            str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
                return !std::isspace(ch);
                }).base(), str.end());
        }


    public:

        //Member Functions
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

        //Class Functions
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();


       
       
    };


}
#endif 