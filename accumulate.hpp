//Author - Dvir Sadon
#pragma once
#include "range.hpp"
#include <iterator>

namespace itertools 
{
    typedef struct 
    {
        template<typename T>
        T operator()(T x, T y)  
        {
            return x + y;
        }

    }defFunc;

    template <typename DA, typename FUNC = defFunc>
    class accumulate 
    {
        /* Variables */
        DA data;
        FUNC func;

        public:
            /* Constructors */
            explicit accumulate(DA x,FUNC f = defFunc()) : data(x), func(f) {}
            
            /* Iterator */
            class iterator
            {
                FUNC itef; // The function needed 
                typename DA::value_type ited;
                typename DA::iterator ite;
                typename DA::iterator itend;
                
                public:
                    explicit iterator(typename DA::iterator it, typename DA::iterator end, FUNC func) : ite(it), itend(end), itef(func) ,ited(*it)
                    {};

                    iterator& operator=(const iterator& other) 
                    {
                        if (&other != this)
                        {
                            this->ited = other.ited;
                            this->ite = other.ite;
                            this->itend = other.itend;
                            this->itef = other.itef;
                        }
                        return *this;
                    }

                    iterator& operator++()
                    {
                        ++ite;
                        if(ite != itend)
                            ited = itef(ited, *ite);
                        return *this;
                    }

                    iterator operator++(int)
                    {
                        iterator temp = *this;
                        ++(*this);
                        return temp;
                    }

                    bool operator==(const iterator& other) 
                    {
                        return (ite == other.ite);
                    }

                    bool operator!=(const iterator& other) 
                    {
                        return !(ite == other.ite);
                    }

                    auto operator*()
                    {
                        return ited;
                    }
            };

            /* Functions */
            iterator begin()
            {
                return iterator(data.begin(), data.end(), func);
            }
            
            iterator end()
            {
                return iterator(data.end(), data.end(), func);
            }
        };
};
