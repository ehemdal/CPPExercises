// Fig. 17.11: CooperativeCancelation.cpp (JEH updated for VS2022 compile errors)
// Using a std::jthread's built-in stop_source 
// to request that the std::jthread stop executing.
#include <chrono>
#include <format>
#include <iostream>
#include <mutex>
#include <random>
#include <sstream>
#include <stop_token>
#include <string>
#include <string_view>
#include <thread>

// get current thread's ID as a string
std::string id() {
    std::ostringstream out;
    out << std::this_thread::get_id();
    return out.str();
}

int main() {
    // each printTask iterates until a stop is requested by another thread
    auto printTask{
       [&](std::stop_token token, std::string name) {
            // set up random-number generation 
            std::random_device rd;
            std::default_random_engine engine{rd()};
            std::uniform_int_distribution ints{500, 1000};

            // register a function to call when a stop is requested 
            std::stop_callback callback(token, [&]() {
               std::cout << std::format(
                  "{} told to stop by thread with id {}\n", name, id());
            });

            while (!token.stop_requested()) { // run until stop requested
               auto sleepTime{std::chrono::milliseconds{ints(engine)}};

               std::cout << std::format(
                  "{} (id: {}) going to sleep for {} ms\n",
                  name, id(), sleepTime.count());

               // put thread to sleep for sleepTime milliseconds 
               std::this_thread::sleep_for(sleepTime);

               // show that task woke up 
               std::cout << std::format("{} working.\n", name);
            }

            std::cout << std::format("{} terminating.\n", name);
         }
    };

    std::cout << std::format("MAIN (id: {}) STARTING TASKS\n", id());

    // create two jthreads that each call printTask with a string argument
    std::jthread task1{ printTask, "Task 1" };
    std::jthread task2{ printTask, "Task 2" };

    // put main thread to sleep for 2 seconds 
    std::cout << "\nMAIN GOING TO SLEEP FOR 2 SECONDS\n\n";
    std::this_thread::sleep_for(std::chrono::seconds{ 2 });

    std::cout << std::format("\nMAIN (id: {}) ENDS\n\n", id());
}



/************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and             *
 * Pearson Education, Inc. All Rights Reserved.                         *
 *                                                                      *
 * DISCLAIMER: The authors and publisher of this book have used their   *
 * best efforts in preparing the book. These efforts include the        *
 * development, research, and testing of the theories and programs      *
 * to determine their effectiveness. The authors and publisher make     *
 * no warranty of any kind, expressed or implied, with regard to these  *
 * programs or to the documentation contained in these books. The       *
 * authors and publisher shall not be liable in any event for           *
 * incidental or consequential damages in connection with, or arising   *
 * out of, the furnishing, performance, or use of these programs.       *
 ***********************************************************************/
