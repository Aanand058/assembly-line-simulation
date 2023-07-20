
#include "Utilities.h"

using namespace std;

namespace sdds {


    char Utilities::m_delimiter;

    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }


    size_t Utilities::getFieldWidth() const
    {
        return this->m_widthField;
    }


    string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
    {

        size_t pos = str.find(m_delimiter, next_pos);
        if (pos == next_pos)
        {
            more = false;
            throw invalid_argument("Invalid pos");
        }

        string line = str.substr(next_pos, pos - next_pos);

        trim(line);

        m_widthField = max(line.length(), getFieldWidth());

        if (pos != string::npos)
        {
            next_pos = pos + 1;
            more = true;
        }
        else {
            more = false;
        }
        return line;
    }


    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }


    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}
