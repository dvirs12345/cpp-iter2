//Author - Dvir Sadon
#pragma once
#include <iterator>

namespace itertools
{
    class range 
    {
        public:

            /* Variables */
            int start;
            int _end;

            /* Constructors */
            range(int x, int y) : start(x), _end(y) 
            {
                if (y == x) 
                {
                    start = 0;
                    _end = 0;
                }
            }

            range(range &other) : start(other.start), _end(other._end) {}

            /* Iterator */
            class iterator
            {
                private:
                    int value_;

                    class intholder 
                    {
                        int value_;
                        public:
                            intholder(int value) : value_(value) {}

                            int operator*() 
                            {
                                return value_; 
                            }
                    };

            public:
                typedef int value_type;
                typedef std::ptrdiff_t difference_type;
                typedef int *pointer;
                typedef int &reference;
                typedef std::input_iterator_tag iterator_category;

                explicit iterator(int value) : value_(value) {}

                int operator*() const 
                { 
                    return value_; 
                }

                bool operator==(const iterator &other) const 
                { 
                    return value_ == other.value_; 
                }

                bool operator!=(const iterator &other) const 
                { 
                    return !(*this == other); 
                }

                iterator &operator++() 
                {
                    ++value_;
                    return *this;
                }

                intholder operator++(int) 
                {
                    intholder ret(value_);
                    ++*this;
                    return ret;
                }
            };

            /* Functions */
            
            iterator begin() 
            { 
                return iterator(start); 
            }

            iterator end() 
            { 
                return iterator(_end); 
            }

            typedef int	value_type;

    };

};
