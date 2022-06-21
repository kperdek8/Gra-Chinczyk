#include "ElementGry.h"

int ElementGry::idCounter = 0;

ElementGry::ElementGry()
{
    uid = idCounter++;
}

ElementGry::~ElementGry()
{

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
