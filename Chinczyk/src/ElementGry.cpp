#include "ElementGry.h"

int ElementGry::idCounter = 0;

ElementGry::ElementGry()
{
    uid = idCounter++;
}

std::ostream &operator<< (std::ostream& str, ElementGry &elementGry)
{
    elementGry.info(str);
    return str;
}

int ElementGry::zwrocId()
{
    return uid;
}
