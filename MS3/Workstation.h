// Name: Aanand Aman
// Seneca Student ID: 166125211
// Seneca email: aaman8@myseneca.ca
// Date of completion: 2023/04/01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"



namespace sdds {


	// accessible outside this module's translation unit
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete; 


	//Class 

	class Workstation : public Station
	{
	

		std::deque<CustomerOrder> m_orders{};

		Workstation* m_pNextStation{};


	public:
		//1-argv Constructor
		Workstation(const std::string& sStr);

		// fills order at front of queue if there are CustomerOrders in  queue
		void fill(std::ostream& os);

		//attempts to move the order order at the front of the queue to the next station in the assembly line
		bool attemptToMoveOrder();

		// stores the address of the referenced Workstation object in the pointer to the m_pNextStation
		void setNextStation(Workstation* station = nullptr);

		//query returns the address of next Workstation
		Workstation* getNextStation() const;

		//Dsiplay Output
		void display(std::ostream& os) const;

		// moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
		Workstation& operator+=(CustomerOrder&& newOrder);


		//Object cannot be copied or moved 
		Workstation(const Workstation& toCopyFrom) = delete;
		Workstation& operator=(const Workstation& toCopyFrom) = delete;
		Workstation(Workstation&& toMoveFrom) = delete;
		Workstation& operator=(Workstation&& toMoveFrom) = delete;

	};




}
#endif 

