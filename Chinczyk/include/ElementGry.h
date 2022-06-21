#ifndef ELEMENTGRY_H
#define ELEMENTGRY_H

#include <iostream>
#include <string>

class ElementGry
{
    public:
        ElementGry();
        virtual void info() = 0;
        int zwrocId();
        friend std::ostream& operator<< (std::ostream& str, ElementGry &elementGry);

    protected:
        static int idCounter;
        int uid;
        virtual void info(std::ostream& str) = 0;
};

#endif // ELEMENTGRY_H
