// 21 задание 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <vector>
#include <string>


enum class roomType {
    bedroom,      
    kitchen,     
    bathroom,     
    children,    
    livingRoom    
};


enum class buildingType {
    house,       
    garage,       
    barn,       
    bathhouse     
};


struct room {
    roomType type; 
    double area;   
};


struct Floor {
    double ceilingHeight; 
    std::vector<room> rooms;   
};


struct building {
    buildingType type;    
    double area;          
    bool hasStove;        
    std::vector< Floor > floors; 
};


struct plot {
    int number;                
    double area;              
    std::vector<building> buildings; 
};


struct settlement {
    std::vector<plot> plots; 
};

int main() {
    settlement settlementData;
    int plotCount;
    std::cout << "Enter the number of plots: " << std::endl; 
    std::cin >> plotCount;

    for (int i = 0; i < plotCount; i++) {
        std::cout << std::endl;

        plot currentPlot;
        currentPlot.number = i + 1;
        std::cout << "Plot #" << currentPlot.number << std::endl
            << "Plot area (m²): " << std::endl; 
        std::cin >> currentPlot.area;

        int buildingCount;
        std::cout << "Number of buildings on the plot: " << std::endl; 
        std::cin >> buildingCount;

        for (int j = 0; j < buildingCount; j++) {
            building b;
            int typeChoice;
            std::cout << "  Select building type (0-House, 1-Garage, 2-Barn, 3-Bathhouse): " << std::endl; 
            std::cin >> typeChoice;
            b.type = static_cast<buildingType>(typeChoice);

            std::cout << "  Building area (m²): " << std::endl; 
            std::cin >> b.area;

            if (b.type == buildingType::house || b.type == buildingType::bathhouse) {
                std::cout << "  Has stove? (1-Yes, 0-No): " << std::endl; 
                std::cin >> b.hasStove;
            }
            else {
                b.hasStove = false;
            }

            if (b.type == buildingType::house) {
                int floorCount;
                std::cout << "  Number of floors (1-3): " << std::endl; 
                std::cin >> floorCount;

                for (int f = 0; f < floorCount; f++) {
                    Floor fl;
                    std::cout << "    Floor " << f + 1 << ", ceiling height (m): " << std::endl; 
                    std::cin >> fl.ceilingHeight;

                    int roomCount;
                    std::cout << "    Number of rooms (2-4): " << std::endl; 
                    std::cin >> roomCount;

                    for (int r = 0; r < roomCount; r++) {
                        room rm;
                        int roomTypeChoice;
                        std::cout << "      Room type (0-Bedroom, 1-Kitchen, 2-Bathroom, 3-Children, 4-Living room): " << std::endl; 
                        std::cin >> roomTypeChoice;
                        rm.type = static_cast<roomType>(roomTypeChoice);

                        std::cout << "      Room area (m²): " << std::endl; 
                        std::cin >> rm.area;

                        fl.rooms.push_back(rm);
                    }
                    b.floors.push_back(fl);
                }
            }
            currentPlot.buildings.push_back(b);
        }
        settlementData.
            plots.push_back(currentPlot);
    }

    double totalArea = 0, builtArea = 0;
    for (auto& p : settlementData.plots) {
        totalArea += p.area;
        for (auto& b : p.buildings) {
            builtArea += b.area;
        }
    }
    std::cout << std::endl
        << "Built-up area is " << (builtArea / totalArea) * 100 << "% of the settlement."
        << std::endl; 

    return 0;
}


