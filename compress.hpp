//Author - Dvir Sadon
#pragma once
#include <iterator>

namespace itertools 
{
    template <typename DA, typename DA2>
    class compress 
    {
        /* Variables */
        DA data;
        DA2 data2;

        public:
            explicit compress(DA y, DA2 y2) : data(y), data2(y2) {}
            
            /* Iterator */
            class iterator
            {
                typename DA2::iterator bite;
                typename DA::iterator ite;
                typename DA::iterator itend;

                public:
                    explicit iterator(typename DA::iterator it, typename DA::iterator end, typename DA2::iterator _bool) : ite(it), itend(end), bite(_bool) 
                    {
                        while (ite != itend && !(*bite)) 
                        {
                            ++ite;
                            ++bite;
                        }
                    };

                    iterator& operator=(const iterator& got) 
                    {
                        if (&got != this)
                            iterator(got.ite,got.itend,got._it_func);
                        return *this;
                    }

                    iterator& operator++() 
                    {
                        ++ite;
                        ++bite;
                        while (ite != itend && !(*bite))
                        {
                            ++ite;
                            ++bite;
                        }
                        return *this;
                    }

                    iterator operator++(int)
                    {
                        iterator temp = *this;
                        ++(*this);
                        return temp;
                    }

                    bool operator==(const iterator& got) 
                    {
                        return (ite == got.ite);
                    }

                    bool operator!=(const iterator& got) 
                    {
                        return !(ite == got.ite);
                    }

                    auto operator*()
                    {
                        return *ite;
                    }
            };

            /* Functions */
            iterator begin()
            {
                return iterator(data.begin(), data.end(), data2.begin());
            }
            iterator end()
            {
                return iterator(data.end(), data.end(), data2.begin());
            }
        };
};
