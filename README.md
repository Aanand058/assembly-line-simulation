# Assembly Line Simulation

A comprehensive C++ object-oriented simulation of an assembly line system with multiple workstations, customer orders, and inventory management.

![Assembly Line](assemblyline.jpg)

## 📋 Project Overview

This project implements a simulation of an assembly line with multiple stations that process customer orders. Each station holds specific stock items and fills customer orders as they move through the line. The system includes:

- **Multiple Workstations**: Each handling specific items with inventory management
- **Customer Orders**: Containing lists of items that need to be filled
- **Line Manager**: Coordinates order movement and processing across stations
- **Inventory Tracking**: Real-time stock management with serial number assignment
- **Order Status Tracking**: Complete vs incomplete order classification

## 🏗️ Architecture

The project is built using object-oriented design principles with the following key components:

### Core Classes

- **`Utilities`**: String parsing and token extraction functionality
- **`Station`**: Base class for managing station information and inventory
- **`Workstation`**: Active station on the assembly line (inherits from Station)
- **`CustomerOrder`**: Manages individual customer orders and their items
- **`LineManager`**: Orchestrates the entire assembly line operation

### Data Flow

1. **Configuration**: Stations and orders are loaded from input files
2. **Processing**: Orders move through workstations sequentially
3. **Filling**: Each station attempts to fill order items from its inventory
4. **Completion**: Orders are classified as complete or incomplete

## 🚀 Features

### Milestone 1: Foundation
- ✅ **Utilities Module**: String parsing with configurable delimiters
- ✅ **Station Module**: Inventory management with serial number generation
- ✅ **File Input Processing**: Loading station data from CSV files
- ✅ **Display Formatting**: Aligned output with configurable field widths

### Milestone 2: Order Management
- ✅ **CustomerOrder Class**: Complete order lifecycle management
- ✅ **Item Tracking**: Individual item status and serial number assignment
- ✅ **Move Semantics**: Efficient resource management with move constructors
- ✅ **Order Filling**: Station-based item fulfillment logic

### Milestone 3: Assembly Line
- ✅ **Workstation Class**: Active stations with order queues
- ✅ **LineManager**: Complete assembly line orchestration
- ✅ **Order Routing**: Automatic order movement between stations
- ✅ **Queue Management**: Pending, completed, and incomplete order queues

## 📁 Project Structure

```
assembly-line-simulation/
├── MS1/                          # Milestone 1: Foundation
│   ├── ms1.cpp                   # Main test program
│   ├── Station.h/.cpp            # Station class implementation
│   ├── Utilities.h/.cpp          # Utilities class implementation
│   └── Stations1.txt, Stations2.txt  # Input data files
├── MS2/                          # Milestone 2: Order Management
│   ├── ms2.cpp                   # Main test program
│   ├── CustomerOrder.h/.cpp      # CustomerOrder class implementation
│   ├── CustomerOrders.txt        # Order input data
│   └── [inherited from MS1]      # Station and Utilities classes
├── MS3/                          # Milestone 3: Assembly Line
│   ├── ms3.cpp                   # Main test program
│   ├── Workstation.h/.cpp        # Workstation class implementation
│   ├── LineManager.h/.cpp        # LineManager class implementation
│   ├── AssemblyLine.txt          # Assembly line configuration
│   └── [inherited from MS2]      # All previous classes
└── README.md                     # This file
```

## 🛠️ Implementation Details

### Key Design Patterns

- **Inheritance**: `Workstation` inherits from `Station`
- **Resource Management**: RAII with move semantics for `CustomerOrder`
- **Singleton-like Behavior**: Static members in `Utilities` for global configuration
- **Queue-based Processing**: FIFO order processing at each workstation

### Memory Management

- **Smart Resource Handling**: Move constructors and assignment operators
- **Dynamic Allocation**: Proper cleanup of dynamically allocated arrays
- **Exception Safety**: Strong exception guarantees where appropriate

### Data Structures

- **Vectors**: For station and order collections
- **Deques**: For order queues at workstations
- **Pointers**: For workstation linking in assembly line

## 📖 Usage

### Compilation

Each milestone can be compiled independently:

```bash
# Milestone 1
g++ -std=c++17 -o ms1 ms1.cpp Station.cpp Utilities.cpp

# Milestone 2
g++ -std=c++17 -o ms2 ms2.cpp Station.cpp Utilities.cpp CustomerOrder.cpp

# Milestone 3
g++ -std=c++17 -o ms3 ms3.cpp Station.cpp Utilities.cpp CustomerOrder.cpp Workstation.cpp LineManager.cpp
```

### Running the Simulation

```bash
# Milestone 1: Test station loading and utilities
./ms1 Stations1.txt Stations2.txt

# Milestone 2: Test order processing
./ms2 Stations1.txt Stations2.txt CustomerOrders.txt

# Milestone 3: Full assembly line simulation
./ms3 Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt
```

### Input File Formats

#### Station Files (CSV format)
```
ItemName,StartingSerial,Quantity,Description
CPU,1000,5,Central Processing Unit
GPU,2000,3,Graphics Processing Unit
```

#### Customer Orders (Pipe-delimited)
```
CustomerName|ProductName|Item1,Item2,Item3
John|Desktop|CPU,GPU,RAM
Sara|Laptop|CPU,GPU,SSD
```

#### Assembly Line Configuration
```
Workstation1|Workstation2
Workstation2|Workstation3
Workstation3|
```

## 🧪 Testing

The project includes comprehensive test programs for each milestone:

- **MS1**: Tests station creation, inventory management, and utilities
- **MS2**: Tests order processing and item filling
- **MS3**: Tests complete assembly line simulation

Sample output files are provided for validation.

## 🔧 Technical Requirements

- **C++17** or later
- **Standard Library**: Extensive use of STL containers and algorithms
- **Namespace**: All code uses `sdds` namespace
- **Exception Handling**: Comprehensive error handling throughout

## 📊 Performance Considerations

- **Efficient String Processing**: Token extraction with minimal copying
- **Move Semantics**: Reduced copying overhead for large objects
- **Queue-based Processing**: O(1) order insertion and removal
- **Memory Efficiency**: Proper resource cleanup and RAII principles

## 🎯 Learning Objectives

This project demonstrates:

- **Object-Oriented Design**: Inheritance, polymorphism, encapsulation
- **Modern C++**: Move semantics, smart pointers, STL usage
- **Resource Management**: RAII, exception safety, memory management
- **System Design**: Component interaction, data flow, state management
- **File I/O**: Parsing, validation, error handling

## 📝 Notes

- All source code uses the `sdds` namespace
- Header files contain class declarations with implementation in `.cpp` files
- Input files are provided for testing and validation
- The project follows strict C++ coding standards and best practices

## 🤝 Contributing

This is an academic project demonstrating C++ object-oriented programming concepts. The implementation follows specific requirements and design patterns as outlined in the original project specifications.

---

*This project showcases advanced C++ programming concepts including object-oriented design, modern C++ features, and system architecture principles.*
