// Name: Aanand Aman
// Seneca Student ID: 166125211
// Seneca email: aaman8@myseneca.ca
// Date of completion: 2023/04/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "LineManager.h"

using namespace std;

namespace sdds {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {


        std::ifstream inputFile(file);
        string line;

        Utilities utility;
        size_t pos = 0;
        bool more = true;

        string workstation;
        string nextWorkstation;


        if (!inputFile)
            throw "File not Found";
        else
        {
            while (!inputFile.eof())
            {
                
                getline(inputFile, line);

                utility.setDelimiter('|');

                workstation = utility.extractToken(line, pos, more);

        Workstation* c_station = nullptr;
                c_station = *std::find_if(stations.begin(), stations.end(), [&](Workstation* station)
                    {
                        return station->getItemName() == workstation;
                    }
                );

                m_activeLine.push_back(c_station);

                Workstation* n_station = nullptr;

                if (more)
                {
                    nextWorkstation = utility.extractToken(line, pos, more);
                    n_station = *std::find_if(stations.begin(), stations.end(), [&](Workstation* station)
                        {
                            return station->getItemName() == nextWorkstation;
                        }
                    );
                    c_station->setNextStation(n_station);
                }
                pos = 0;
                more = true;
            }

            Workstation* f_station = nullptr;
            for_each(stations.begin(), stations.end(), [&](Workstation* station1)
                {
                    f_station = *std::find_if(stations.begin(), stations.end(), [&](Workstation* station2)
                        {
                            return station2->getNextStation() == f_station;
                        });
                });

            m_firstStation = f_station;

        }

        inputFile.close();

        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations() {


        std::vector<Workstation*> temp;

        temp.push_back(m_firstStation);

        for (auto i = 0u; i < m_activeLine.size() - 1; i++) { 
            temp.push_back(temp[i]->getNextStation());
        }
       
        m_activeLine = temp;

    }

    bool LineManager::run(std::ostream& os) {

        static size_t count = 1;
      
        os << "Line Manager Iteration: " << count << std::endl;

        if (g_pending.size()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
            station->fill(os);
            });

        
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
            station->attemptToMoveOrder();
            });

        count++;

        return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());
    }

    void LineManager::display(std::ostream& os) const {


        for_each(m_activeLine.begin(), m_activeLine.end(), [&]( const Workstation* station) {
            station->display(os);
            });

    }
	
}

