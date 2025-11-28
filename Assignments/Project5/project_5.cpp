#include <initializer_list>
#include <iostream>
#include <cassert>

/**********************************************************************************
 * README
 * ********************************************************************************
 * This starter code is a skeleton of the Set and Node classes.
 * You can modify this code to create your project_5 submission.
 * Any main() function or output will be ignoed by testing software.
 * A testing main() can be found on Learn.
 *
 * From Project 5 Specification: 2.1 Development Stratigies
 * "First, implement the node class and all of its member functions. This should be
 *  straight-forward from the course notes, as they are the sam member functions as
 *  for a linked list.
 *
 *  Second, start with a skeleton, where each member function is defined, but where
 *  the default values of the return type is returned. ..."
 *
 * The skeleton has been povided (below) for you to modify.
*/

class Set;
class Node;
std::ostream& operator<<(std::ostream& out, Set const& rhs);

/////////////////////////////
/// Set class declaration ///
/////////////////////////////
class Set {
public:
        Set(std::initializer_list<int> initial_values);
        ~Set();

        // The instructions will describe exactly what to do
        Set(Set const& orig);
        Set(Set&& orig);

        // The instructions will describe exactly what to do
        Set& operator=(Set const& orig);
        Set& operator=(Set&& orig);

        // Size operations
        bool        empty() const;
        std::size_t size()  const;

        // Clear all items out of the set
        void clear();

        // Find the value item in the set
        //  - Return the address of the node if found,
        //    and nullptr otherwise.
        Node* find(int const& item) const;

        // Insert the item into the set if it
        // is not already in the set.
        //  - Return 1 if the item is new,
        //    and 0 otherwise.
        std::size_t insert(int const& item);

        // Insert all the items in the array
        // from array[begin] to array[end - 1]
        // that are not already in the set.
        //  - Return the number of items inserted
        //    into the set.
        std::size_t insert(int         const array[],
                std::size_t const begin,
                std::size_t const end);

        // Remove the item from the set and
        // return the number of items removed.
        std::size_t erase(int const& item);

        // Move any items from 'other', whose values
        // do not appear in 'this', to 'this'
        // Leave any items that already appear
        // in 'this' and 'other' in 'other'. 
        std::size_t merge(Set& other);


        // Set operations
        Set& operator|=(Set const& other);
        Set& operator&=(Set const& other);
        Set& operator^=(Set const& other);
        Set& operator-=(Set const& other);

        Set operator|(Set const& other) const;
        Set operator&(Set const& other) const;
        Set operator^(Set const& other) const;
        Set operator-(Set const& other) const;

        // Returns 'true' if the 'other' set
        // is a subset of 'this' set; that is,
        // all entries in the 'other' set are
        // also in this set.
        bool operator<=(Set const& other) const;
        bool operator>=(Set const& other) const;
        bool operator<(Set const& other) const;
        bool operator>(Set const& other) const;

        bool operator==(Set const& other) const;
        bool operator!=(Set const& other) const;

private:
        Node* p_head_;
        std::size_t length;

        friend std::ostream& operator<<(std::ostream& out, Set const& rhs);
};


///////////////////////////////
/// Node class declaration  ///
///////////////////////////////
class Node {
public:
        Node(int new_value, Node* new_next);
        int   value() const;
        Node* next()  const;

private:
        int   value_;
        Node* next_;

        // Allow any member function in the class
        // 'Set' to access or modify the member
        // variables of any instance of this class.
        friend class Set;
};


///////////////////////////////
/// Node class Definition   ///
///////////////////////////////

// Node constructor
Node::Node(int new_value, Node* new_next) {
        this->value_ = new_value;
        this->next_ = new_next;
}

int Node::value() const {
        return this->value_;
}

Node* Node::next() const {
        return this->next_;
}


///////////////////////////////
/// Set class definition    ///
///////////////////////////////

// Initializing constructor
Set::Set(std::initializer_list<int> initial_values) {
        p_head_ = nullptr;
        length = 0;

        for (const int& value : initial_values) {
                insert(value);
        }
}


// Copy constructor
Set::Set(Set const& orig) {
        p_head_ = nullptr;
        Node* p_node = orig.p_head_;

        (*this) = orig; // Use copy assignment to copy value
}

// Move constructor
Set::Set(Set&& orig) {
        p_head_ = orig.p_head_;
        orig.p_head_ = nullptr;
        length = orig.length;
        orig.length = 0;
}

// Copy assignment
Set& Set::operator=(Set const& orig) {
        if (&orig == this) {
                // if two pointers are equal, do nothing
                return *this;
        }

        clear();
        Node* p_node{ orig.p_head_ };
        for (std::size_t i{ 0 }; i < orig.size(); i++) {
                insert(p_node->value());
                p_node = p_node->next();
        }

        return *this;
}

// Move assignment
Set& Set::operator=(Set&& orig) {
        Node* p_head_ = orig.p_head_;
        orig.p_head_ = nullptr;
        length = orig.length;
        orig.length = 0;

        return *this;
}

// Destructor
Set::~Set() {
        clear();
}

// Size
std::size_t Set::size() const {
        return length;
}

// Empty
bool Set::empty() const {
        return length == 0;
}


// Clear
void Set::clear() {
        while (length != 0) {
                erase(p_head_->value());
        }
}

// Find
Node* Set::find(int const& item) const {
        Node* node = p_head_;
        for (std::size_t i{ 0 }; i < length; i++) {
                if (node->value() == item) {
                        return node;
                }
                node = node->next();
        }

        return nullptr;
}

// Insert the item into the set
std::size_t Set::insert(int const& item) {
        if (find(item)) {
                return 0;
        }
        p_head_ = new Node(item, p_head_);
        length++;
        return 1;
}

// Insert all the items in the array
std::size_t Set::insert(int         const array[],
        std::size_t const begin,
        std::size_t const end) {
        std::size_t result{ 0 };
        for (std::size_t i{ begin }; i < end; i++) {
                result += insert(array[i]);
        }
        return result;
}


// Remove the item from the set and
// return the number of items removed.
std::size_t Set::erase(int const& item) {
        Node* p_node = p_head_;
        Node* p_prev_node = nullptr;
        for (std::size_t i{ 0 }; i < length; i++) {
                if (p_node->value() != item) {
                        // Step forward
                        p_prev_node = p_node;
                        p_node = p_node->next();
                        continue;
                }
                // Connect next node to previous node
                if (p_prev_node == nullptr) {
                        p_head_ = p_node->next();
                }
                else {
                        p_prev_node->next_ = p_node->next();
                }
                // Delete node and return
                delete p_node;
                length--;
                return 1;
        }
        return 0;
}

// Move any items from 'other', whose values
// do not appear in 'this', to 'this'.
// Leave any items that already appear
// in both sets, in both sets. 
std::size_t Set::merge(Set& other) {
        std::size_t count{ 0 };
        return 0;
}

//////////////////////
/// Set operations ///
//////////////////////
Set& Set::operator|=(Set const& other) {
        return *this;
}

Set& Set::operator&=(Set const& other) {
        return *this;
}

Set& Set::operator^=(Set const& other) {
        return *this;
}

Set& Set::operator-=(Set const& other) {
        return *this;
}

Set Set::operator|(Set const& other) const {
        Set result{};
        return result;
}

Set Set::operator&(Set const& other) const {
        Set result{};
        return result;
}

Set Set::operator^(Set const& other) const {
        Set result{};
        return result;
}

Set Set::operator-(Set const& other) const {
        Set result{};
        return result;
}

// Returns 'true' if the 'other' set
// is a subset of 'this' set; that is,
// all entries in the 'other' set are
// also in this set.
bool Set::operator>=(Set const& other) const {
        return false;
}

bool Set::operator<=(Set const& other) const {
        return false;
}

bool Set::operator>(Set const& other) const {
        return false;
}

bool Set::operator<(Set const& other) const {
        return false;
}

bool Set::operator==(Set const& other) const {
        return false;
}

bool Set::operator!=(Set const& other) const {
        return false;
}


////////////////////////////////////////////
/// Supplied Code for print Set objects  ///
////////////////////////////////////////////
/// @brief Overloads the << operator allowing the print of Set objects
/// @param out The ostream to print to (e.g. std::cout <<)
/// @param rhs The Set to print (e.g. << set_A)
/// @note You do not need to edit or alter this code
std::ostream& operator<<(std::ostream& out, Set const& rhs) {
        out << "{";
        if (!rhs.empty()) {
                out << rhs.p_head_->value();
                for (Node* ptr{ rhs.p_head_->next() }; ptr != nullptr; ptr = ptr->next()) {
                        out << ", " << ptr->value();
                }
        }
        out << "}";

        return out;
}
