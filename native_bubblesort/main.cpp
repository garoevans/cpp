#include <phpcpp.h>

/**
 *  Bubblesort function in C++
 *
 *  This function takes an unsorted array as input, sorts it, and returns
 *  the output. Notice that we have not really done our best to make the
 *  implementation of this function as efficient as possible - we use stl
 *  containers for example - it is simple looking plain C++ function with
 *  a lot of room for improvements.
 *
 *  @param  array       An unsorted array of integers
 *  @return array       A sorted array
 */
Php::Value native_bubblesort(Php::Parameters &params)
{
    // there is one input array, cast the PHP variable to a vector of ints
    std::vector<int> input = params[0];

    // loop through the array
    for (size_t i = 0; i < input.size(); i++)
    {
        // loop through the elements that were already processed
        for (size_t j = 1; j < input.size() - i; j++)
        {
            // move on if smaller
            if (input[j-1] <= input[j]) continue;

            // swap elements
            int temp = input[j];
            input[j] = input[j-1];
            input[j-1] = temp;
        }
    }

    // done
    return input;
}

/**
 *  Switch to C context, because the Zend-engine calls the get_module() method
 *  in C context, and not in C++ context
 */
extern "C" {

    /**
     *  When a PHP extension starts up, the Zend engine calls the get_module()
     *  function to find out which functions and classes are offered by the
     *  extension
     *
     *  @return void*   pointer to memory address holding the extension information
     */
    PHPCPP_EXPORT void *get_module()
    {
        // create an instance of the Php::Extension class
        static Php::Extension extension("bubblesort", "1.0");

        // add the bubblesort function to the extension, we also tell the
        // extension that the function receives one parameter by value, and
        // that that parameter must be an array
        extension.add("native_bubblesort", native_bubblesort, {
            Php::ByVal("input", Php::Type::Array)
        });

        // return the extension
        return extension;
    }
}
