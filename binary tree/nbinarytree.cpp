#include "nbinarytree.h"
#include <QtCore>


template <class T>
NBinaryTree<T>::NBinaryTree():depth(-1)
{

}

template <class T>
NBinaryTree<T>::NBinaryTree(T root):root(new Element<T>(root)),depth(0)
{

}

template <class T>
NBinaryTree<T>::NBinaryTree(const NBinaryTree &other)
{
    this->setRoot(other.getRoot()->getValue());
    for(int i=1;i<=other.getDepth();i++)
    {
        QVector<Element<T> > temp;
        temp=other.getRow(i);
        for(int j=0;j<temp.size();j++)
        {
            this->addElement(temp[j].getValue());
        }//end for#2
        temp.clear();

    }//end for

}//end constr.

template <class T>
NBinaryTree<T>::~NBinaryTree()
{
    destr(root);
}


template <class T>
Element<T> *NBinaryTree<T>::getRoot()
{
    return root;
}

template <class T>
NBinaryTree<T> NBinaryTree<T>::getRightSubTree(Element<T> *el)
{
    NBinaryTree<T> result;
    result.setRoot(el->getRight());
    return result;
}

template <class T>
void NBinaryTree<T>::setRoot(Element<T> *el)
{
    root=el;
}

template <class T>
NBinaryTree<T> NBinaryTree<T>::getLeftSubTree(Element<T> *el)
{
    NBinaryTree<T> result;
    result.setRoot(el->getLeft());
    return result;
}

template <class T>
Element<T>* NBinaryTree<T>::find_rec(Element<T>* el, T value)
{
    if(el->getValue()==value)
        return el;
    if(el->getValue()>value && el->getLeft() != NULL)
        return find_rec(el->getLeft(), value);
    if(el->getValue()<value && el->getRight()!=NULL)
        return find_rec(el->getRight(),value);

    return NULL;
}

template <class T>
Element<T>* NBinaryTree<T>::find(T value)
{
    return find_rec(root,value);
}



template <class T>
void NBinaryTree<T>::add_rec(Element<T>* el, T value)
{
    if (value < el->getValue())
    {
        if(!el->getLeft())
            el->setLeft(new Element<T>(value, el));
        else
            add_rec(el->getLeft(), value);
    }//end if
    if (value > el->getValue())
    {
        if (!el->getRight())
            el->setRight(new Element<T>(value, el));
        else
            add_rec(el->getRight(), value);
    }//end if
}

template <class T>
void NBinaryTree<T>::addElement(T value)
{
    add_rec(root, value);
}

template <class T>
void NBinaryTree<T>::destr(Element<T>* el)
{
    if (el->getLeft() != NULL)
        destr(el->getLeft());
    if (el->getRight() != NULL)
        destr(el->getRight());
    delete el;
}

template <class T>
void NBinaryTree<T>::removeElement(T value)
{
    Element<T>* tmp = find(value);
    destr(tmp);
    if (tmp>tmp->getParent())
        tmp->getParent()->setRight(NULL);
    else
        tmp->getParent()->setLeft(NULL);
}

template <class T>
int NBinaryTree<T>::getDepth()
{
    updateDepth_rec(root);
    return depth;
}


template <class T>
void NBinaryTree<T>::updateDepth_rec(Element<T> *el)
{
    if (!el->getLeft() && !el->getRight())
    {
        if (el->getDepth() > depth)
            depth = el->getDepth();
    }//end if#1
    else
    {
        if (el->getLeft())
            updateDepth_rec(el->getLeft());
        if (el->getRight())
            updateDepth_rec(el->getRight());
    }//end else
}

template <class T>
void NBinaryTree<T>::leftRotation()
{
    this->setRoot(root->getRight());
    if (root->getLeft() != NULL)
    {
        root->getParent()->setRight(root->getLeft());
        root->getLeft()->setParent(root->getParent());

        root->setLeft(root->getParent());
        root->getLeft()->setParent(root);
    }
    else
    {
        root->setLeft(root->getParent());
        root->getLeft()->setParent(root);

        root->getLeft()->setRight(NULL);
    }
    root->setParent(NULL);
}


template <class T>
void NBinaryTree<T>::rightRotation()
{
    this->setRoot(root->getLeft());
    if (root->getRight() != NULL)
    {
        root->getParent()->setLeft(root->getRight());
        root->getRight()->setParent(root->getParent());

        root->setRight(root->getParent());
        root->getRight()->setParent(root);
    }
    else
    {
        root->setRight(root->getParent());
        root->getRight()->setParent(root);

        root->getRight()->setLeft(NULL);
    }
    root->setParent(NULL);
}


template <class T>
void NBinaryTree<T>::setRoot(T value)
{
    root = new Element<T>(value);
}

template <class T>
QVector<Element<T> *> NBinaryTree<T>::getRow(int index)
{
    QVector<Element<T>*> result;
    QVector<Element<T>*> tmp;
    Element<T>* el;
    result.push_back(root);
    el = root;
    while (el->getDepth() != index)
    {
        tmp.clear();
        for (int i = 0; i < result.size(); ++i)
        {
            if (result[i])
            {
                tmp.push_back(result[i]->getLeft());
                tmp.push_back(result[i]->getRight());
            }
            else
            {
                tmp.push_back(NULL);
                tmp.push_back(NULL);
            }
        }//end for
        result = tmp;
        int j = -1;
        do
        {
            ++j;
            el = result[j];
        }
        while (!result[j]);
        //end do-while
    }//end while
    return result;
}//getRow

template <class T>
QVector<Element<T> *> NBinaryTree<T>::getRow_rec(QVector<Element<T>*> row, int rowIndex)
{
    if (row.first()->getDepth() == rowIndex)
        return row;

    QVector<Element<T>*> tmp;
    getRow_rec(tmp,rowIndex);
}



