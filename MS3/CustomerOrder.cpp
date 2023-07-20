
// Name: Aanand Aman
// Seneca Student ID: 166125211
// Seneca email: aaman8@myseneca.ca
// Date of completion: 2023/03/24
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder()
	{
	}

	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities uObject;

		size_t next_pos1 = 0;
		bool more1;

		m_name = uObject.extractToken(str, next_pos1, more1);
		m_product = uObject.extractToken(str, next_pos1, more1);

		for (size_t i = next_pos1; i < str.size(); i++)
		{
			if (str[i] == uObject.getDelimiter())
			{
				m_cntItem++;
			}
		}

		m_cntItem++;

		//Allocating Memory for array of pointers
		m_lstItem = new Item * [m_cntItem];
		for (size_t i = 0; i < m_cntItem; i++)
		{
			m_lstItem[i] = new Item(uObject.extractToken(str, next_pos1, more1));
		}


		if (m_widthField < uObject.getFieldWidth())
		{
			m_widthField = uObject.getFieldWidth();
		}

	}

	CustomerOrder::CustomerOrder(const CustomerOrder& toCopyFrom)
	{
		throw "Copying is not Allowed";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& toMoveFrom) noexcept
	{
		*this = std::move(toMoveFrom);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& toMoveFrom) noexcept
	{
		if (this != &toMoveFrom)
		{
			//Deleting  
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;


			//Moving 
			m_name = toMoveFrom.m_name;
			m_product = toMoveFrom.m_product;
			m_cntItem = toMoveFrom.m_cntItem;
			m_lstItem = toMoveFrom.m_lstItem;


			//Setting null the Original 
			toMoveFrom.m_product = "";
			toMoveFrom.m_lstItem = nullptr;
			toMoveFrom.m_cntItem = 0;
			toMoveFrom.m_name = "";
		}
		return *this;
	}



	bool CustomerOrder::isOrderFilled() const
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (!m_lstItem[i]->m_isFilled)
				return false;
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				if (!m_lstItem[i]->m_isFilled)
					return false;
			}
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {

		bool flag = false;
		for (size_t i = 0; i < m_cntItem && !flag; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName()&& !m_lstItem[i]->m_isFilled)
			{
				if (station.getQuantity()>0)
				{
					m_lstItem[i]->m_isFilled = true;
					flag = true;

					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();

					station.updateQuantity();


					os.width(4);
					os.setf(ios::right);
					os << "    Filled ";
					os.unsetf(ios::right);

					os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;

				}
				else
				{
					os.setf(ios::right);
					os << "    Unable to fill ";
					os.unsetf(ios::right);
					os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;

				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[";
			os.width(6);
			os.fill('0');
			os.setf(ios::right);
			os << m_lstItem[i]->m_serialNumber;

			os << "] ";

			os.fill(' ');
			os.width(m_widthField + 2);
			os.unsetf(ios::right);

			os.setf(ios::left);
			os << m_lstItem[i]->m_itemName;
			os << " - ";
			m_lstItem[i]->m_isFilled ? os << "FILLED" << endl : os << "TO BE FILLED" << endl;
		}
	}


	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}

		delete[] m_lstItem;
	}
}



