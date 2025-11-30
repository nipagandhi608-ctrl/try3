/**
 * @file main.cpp
 * @brief Main entry point for the Calculation Application.
 */
#include <iostream>
#include "Logger.h"
#include "CalculationEngine.h"

/** 
  * \mainpage This is the main entry point for the Calculation Application.
  *  It initializes the erforms calculations,
  * 
*/
int calculate_and_report() {
    // Create a logger instance
    Logger app_logger("app.log");
    app_logger.log(LOG_INFO, "Application started.");

    // Create the engine, passing the logger by reference
    CalculationEngine engine(app_logger);

    // Test a valid calculation
    double area = engine.calculate_circle_area(5.0);
    std::cout << "Area (r=5.0): " << area << std::endl;

    // Test an invalid calculation
    double invalid_area = engine.calculate_circle_area(-2.0);
    std::cout << "Area (r=-2.0): " << invalid_area << std::endl;
    
    
    app_logger.log(LOG_INFO, "Application finished.");

    return 0;
}

/**
 * @brief The main function.
 * * Calls the core logic function to run the application.
 * * \callgraph
 */
int main() {
    return calculate_and_report();
}
