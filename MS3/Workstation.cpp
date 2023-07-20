// Name: Aanand Aman
// Seneca Student ID: 166125211
// Seneca email: aaman8@myseneca.ca
// Date of completion: 2023/04/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#include "Workstation.h"

using namespace std;

namespace sdds {

    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};

    //goes to Station Module
    Workstation::Workstation(const std::string& str) : Station(str) {}


    void Workstation::fill(std::ostream& os) {
        if (m_orders.size()) {
            m_orders.front().fillItem(*this, os);
        }
    }

    bool Workstation::attemptToMoveOrder() {
        bool flag = false;

        if (m_orders.size()) {
            if (m_orders.front().isItemFilled(getItemName()) || !getQuantity()) {

                if (m_pNextStation) {
                    *m_pNextStation += std::move(m_orders.front());

                }
                else {
                    if (m_orders.front().isOrderFilled()) {
                        g_completed.push_back(std::move(m_orders.front()));
                    }
                    else {
                        g_incomplete.push_back(std::move(m_orders.front()));
                    }
                }
                m_orders.pop_front();
                 flag = true;

            }
        }
        return flag;
    }

    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const {
        os << getItemName() << " --> ";
      
        if (getNextStation()) {
            os << getNextStation()->getItemName();
        }
        else {
            os << "End of Line";
        }

        os << endl;
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}
