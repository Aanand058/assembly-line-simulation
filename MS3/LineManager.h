// Name: Aanand Aman
// Seneca Student ID: 166125211
// Seneca email: aaman8@myseneca.ca
// Date of completion: 2023/04/01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <iostream>
#include "Workstation.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Utilities.h"

namespace sdds {

  
	class LineManager
	{
	
		std::vector<Workstation*> m_activeLine{};

		size_t m_cntCustomerOrder{};

		Workstation* m_firstStation{};



	public:
		// 2-argv Constructor
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);

		//stores reorder collection in the same instance variable
		void reorderStations();

		//perform one iterations of operations
		bool run(std::ostream& os);

		//Display all stations of current order
		void display(std::ostream& os)const;
	};
}
#endif 
