//Author - Dvir Sadon
#pragma once
#include <iterator>

namespace itertools 
{
    template <typename FUNC, typename DA>
    class filterfalse 
    {
        /* Variables */
        DA data;
        FUNC func;

        public:
            /* Constructors */
            explicit filterfalse(FUNC f,DA x) : data(x), func(f) {}
            
            /* Iterator */
            class iterator
            {
                typename DA::iterator ite;
                typename DA::iterator itend;
                FUNC itefunc;

                public:
                    explicit iterator(typename DA::iterator it, typename DA::iterator end, FUNC func) : ite(it), itend(end), itefunc(func)
                    {
                        while (ite != itend && itefunc(*ite))
                            ite++;
                    }

                    iterator& operator=(const iterator& got) 
                    {
                        if (&got != this)
                            iterator(got.ite,got.itend,got.itefunc);
                        return *this;
                    }

                    iterator& operator++()
                    {
                        ++ite;
                        while (ite != itend && itefunc(*ite))
                            ++ite;
                        return *this;
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
                return iterator(data.begin(), data.end(), func);
            }
            iterator end()
            {
                return iterator(data.end(), data.end(), func);
            }
    };
};
