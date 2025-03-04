#ifndef ARRAY_BOX_HPP_
#define ARRAY_BOX_HPP_

#include <string>

template <typename T>
class ArrayBox {
    private:
        int capacity_;  // Maximum capacity of the array
        int size_;      // Current occupied spaces in the array
    
    protected:
        T* items_;      // Dynamic array to hold elements

        /**
         *  @brief Searches a subarray of `items_` for an item of the given type. 
         *      Returns the *leftmost* index of the item if it is found within 
         *      the subarray from [start, end). Return -1 if not found.
         * 
         *  @param type A const reference to a string denoting the `type` of the object to search for
         *  @param start An integer representing the start of the subarray to search
         *  @param end An integer representing the end of the subarray to search (non-inclusive)
         * 
         *  @return Either the index target in the subarray within items_ as an integer
         *          or -1, if the subarray does not contain an object of that type
         * 
         *  @note [start, end) means we look at all values from index = start, up to but 
         *  not including index = end
         *  a) If `start` is negative or >= size_
         *  b) If `end` is negative or > size_
         *  c) If `start` >= `end`
            The search is fails to execute, and -1 is returned.
        **/
        int getIndexOf(const std::string& type, int start, int end) const;

    public:
        /**
        * @brief Default constructor
        * @post Initializes capacity_ to 64 and size_ to 0. 
        *      Allocates a dynamic array for items_ of length equal to the capacity_. 
        */
        ArrayBox();

        /**
        * @brief Parameterized constructor
        * @param capacity A const reference to an integer describing the maximum capacity of the items_ array.
        *      If capacity is not positive (ie. <= 0), 64 is used instead.
        * @post size_ is initialized to 0. items_ is initialized to a dynamically allocated array of length equal to 'capacity'
        */
        ArrayBox(const int& capacity);

        /**
        * Getter for the size member
        * @return Returns the integer value stored in size_
        */
        int size() const;

        /**
        * Getter for the capacity member
        * @return Returns the integer value stored in capacity_
        */
        int capacity() const;

        /**
         * @brief Appends the parameter item to the `items_` array such that:
         *  1) There current size_ and target.size() is small enough 
         *      that the item can be added without exceeding the ArrayBox capacity_
         *  2) The target item takes up target.size() spaces at 
         *      starting at the leftmost non-occupied space
         * 
         * @param type A const reference to an item of type T, specifying the object to add
         * @return True if the add was successful. False otherwise.
         * @post Increment size_ if the item was added.
         */
        bool addItem(const T& item);

        /**
        * @brief Removes the first instance in `items_` of an object whose `getType()` equals the parameter given
        *      To maximize contiguous space available to add objects later, we shift 
        *      all elements over by the size of the object we just removed.
        *      
        *      `size_` is also decremented by the size of the object we just removed.
        * 
        *      Instead of lazy-deletion, all values that are not counted as part of the valid subarray, ie. not from indices [0, size_)
        *      are set to a default-initialized object
        * 
        *      If no object of the given type is found, nothing happens.
        *  
        * @param type A const reference to a string specifying the type of the object to remove
        *
        * @post Objects after the removed instance are shifted elements over by the size of the object we just removed
        * 
        * @return True if the remove operation was successfully performed. False otherwise.
        */
        bool remove(const std::string& type);

        /**
         * @brief Counts the number of distinct intances of the 
         *        given type within items_ from indices [0, size_)
         *        A singular instance of an object is the block of indices from [a, a + a.size())
         * 
         * @param type A const reference to a string denoting the type of the item to search for
         * @return An integer representing the number of 
         *         distinct instances of objects 
         *         whose `getType()` is equal to the parameter.
         */
        int count(const std::string& type) const;

        /**
         * @param type A const reference to a string denoting the type of the item to search for
         * @return True if items_ contains an object whose getType() equals the given parameter
         */
        bool contains(const std::string& type) const;

        // Destructor
        ~ArrayBox();
};

#include "ArrayBox.cpp"
#endif // ARRAY_BOX_HPP_