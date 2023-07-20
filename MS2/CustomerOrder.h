// Name: Aanand Aman
// Seneca Student ID: 166125211
// Seneca email: aaman8@myseneca.ca
// Date of completion: 2023/03/24
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H


#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
#include "Station.h"


namespace sdds {

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};

		static size_t m_widthField;

	public:


		// Default Constructor
		CustomerOrder();

		//One- Arguement Cons
		CustomerOrder(const std::string& str);

		//Copy and Assingment 
		CustomerOrder(const CustomerOrder& toCopyFrom);
		CustomerOrder& operator=(const CustomerOrder& toCopyFrom) = delete;

		//Move Operations
		CustomerOrder(CustomerOrder&& toMoveFrom) noexcept;
		CustomerOrder& operator=(CustomerOrder&& toMoveFrom) noexcept;

		//returns true if all the items in the order have been filled; false otherwise
		bool isOrderFilled() const;

		//returns true if all items specified by itemName have been filled. If the item doesn't exist in the order, this query returns true.
		bool isItemFilled(const std::string& itemName) const;

		void fillItem(Station& station, std::ostream& os);

		void display(std::ostream& os) const;

		//Destructor
		~CustomerOrder();
	};

  
}
#endif 