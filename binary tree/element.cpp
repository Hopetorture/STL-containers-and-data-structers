
#include "element.h"

template <class T>
Element<T>::Element(T value, Element<T> *parent, Element<T> *right, Element<T> *left)
    :value(value), parent(parent), right(right), left(left)
{
}

template <class T>
void Element<T>::print()
{
    qDebug() << value;
}

template <class T>
Element<T>* Element<T>::getLeft()
{
    return left;
}

template <class T>
Element<T>* Element<T>::getRight()
{
    return right;
}

template <class T>
Element<T>* Element<T>::getParent()
{
    return parent;
}

template <class T>
void Element<T>::setLeft(Element<T> *el)
{
    left = el;
}

template <class T>
void Element<T>::setRight(Element<T> *el)
{
    right = el;
}

template <class T>
void Element<T>::setParent(Element<T> *el)
{
    parent = el;
}

template <class T>
T Element<T>::getValue()
{
    return value;
}

template <class T>
int Element<T>::getDepth()
{
    int i = 0;
    Element* tmp = this;
    while (tmp->getParent())
    {
        tmp = tmp->getParent();
        ++i;
    }

    return i;
}
