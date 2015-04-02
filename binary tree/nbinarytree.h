#ifndef NBINARYTREE_H
#define NBINARYTREE_H
#include "element.cpp"

template<class T>
class NBinaryTree
{
public:
    NBinaryTree();
    NBinaryTree(T root);
    NBinaryTree(const NBinaryTree& other); //конструктор копирования
    ~NBinaryTree(); //деструктор
    void addElement(T value); //добавление нового элемента в дерево
    void removeElement(T value); //удаление значения элемента из дерева
    int getDepth(); //получение глубины дерева
    void setRoot(T value); //установление корня дерева
    NBinaryTree<T> getRightSubTree(Element<T>* el); //правое поддерево
    NBinaryTree<T> getLeftSubTree(Element<T>* el); //левое поддерево
    void rightRotation();  
    void leftRotation();    
    QVector<Element<T>*> getRow(int index); //вернуть ряд(слой) элементов по указанному индексу (корень - 0)
    Element<T>* find(T value); //поиск
    Element<T>* getRoot();

private:
    Element<T> *find_rec(Element<T> *el, T value);
    void destr(Element<T>* el);
    void add_rec(Element<T> *el, T value);
    void setRoot(Element<T> *el);
    QVector<Element<T>*> getRow_rec(QVector<Element<T>*> row, int rowIndex);
    void updateDepth_rec(Element<T> *el);
    Element<T>* root; //указатель на корен дерева
    int depth;
};

template <typename T>
void optimiseTree(NBinaryTree<T>* tree);

#endif // NBINARYTREE_H
