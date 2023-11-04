// ===========================================================================
// Main.cpp  // Exceptions
// ===========================================================================

#include <iostream>
#include <stdexcept>
#include <string>

namespace Exceptions {

    void dangerousFunction() {}

    void scriptSnippets()
    {
        try
        {
            dangerousFunction();
        }
        catch (std::out_of_range)
        {
            // do something because of out_of_range exception
        }
        catch (std::overflow_error)
        {
            // do something because of overflow_error exception
        }
        catch (std::invalid_argument)
        {
            // do something because of invalid_argument exception
        }
        catch (std::exception)
        {
            // an unexpected exception occurred
        }
    }
}

void testExceptions01()
{
    try
    {
        std::string str("Zeichenkette");
        std::cout << str << std::endl;

        int pos = 123;
        char ch = str.at(pos);

        size_t len = str.length();
        std::cout << "Length: " << len << std::endl;

        str.insert(123, " !!!");
        std::cout << str << std::endl;
    }
    catch (std::out_of_range ex)
    {
        // do something because of out_of_range exception
        std::cout << "std::out_of_range: " << ex.what() << std::endl;
    }
    catch (std::invalid_argument ex)
    {
        // do something because of invalid_argument exception
        std::cout << "std::invalid_argument: " << ex.what() << std::endl;
    }
    catch (std::length_error ex)
    {
        // do something because of invalid_argument exception
        std::cout << "std::length_error: " << ex.what() << std::endl;
    }
    catch (std::exception ex)
    {
        // an unexpected exception occurred
        std::cout << "std::exception: " << ex.what() << std::endl;
    }

    std::cout << "Done." << std::endl;
}

void testExceptions()
{
    using namespace Exceptions;

    testExceptions01();
}


// ===========================================================================
// End-of-File
// ===========================================================================
