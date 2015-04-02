#ifndef ELEMENT_H
#define ELEMENT_H
#include <qDebug>

template <class T>
class Element
{
public:
    Element(T value = 0, Element<T> *parent = NULL, Element<T> *right = NULL, Element<T> *left = NULL); //конструктор
    void print(); //вывод value
    void setLeft(Element<T>* el); //установить левого сына
    void setRight(Element<T>* el); //установить правого сына
    void setParent(Element<T>* el); //установить родителя
    int getDepth(); //получение глубины остовного дерева
    T getValue(); //получение значения элемента
    Element<T>* getRight(); //получение правого сына
    Element<T>* getLeft(); //получение левого сына
    Element<T>* getParent(); //получение родителя

private:
    T value;
    Element<T>* parent;
    Element<T>* right;
    Element<T>* left;
};

#endif // ELEMENT_H
