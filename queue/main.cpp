#include <QCoreApplication>
#include <QDebug>
#include <string>
#include <iostream>

template <class T>
class queue
{
 unsigned int size;
 T* array;

  public:
 queue():size(0),array(NULL){}
 ~queue()
 {
     if(array)
         delete[]array;
 }

void add_elem(T elm)
{
    T tmp[size];
    for(int i=0;i<size;++i)
    {
        tmp[i]=array[i];
    }
    delete[] array;
    size+=1;
    array=new T[size];
    for(int i=0; i<size-1;++i)
    {
        array[i]=tmp[i];
    }
    array[size-1]=elm;
}
T get_elem()
{
   if(size==0)
       throw("queue is empty");
   else{
   T result;
   T tmp[size];
   for(int i=0;i<size;++i)
   {
       tmp[i]=array[i];
   }
   result= array[0];
   delete[] array;
   size-=1;
   array=new T[size];
   for(int i=0;i<size;++i)
   {
       array[i]=tmp[i+1];
   }
   return result;
   }//end else
}//end get_elem
unsigned int get_lenght()
{
    return size;
}//end get_lenght
};//end queue class



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    queue<int> test;
    test.add_elem(12);
    test.add_elem(15);
    qDebug()<<test.get_elem();
    queue<double>dTest;
    dTest.add_elem(3.14);
    dTest.add_elem(4.25);
    dTest.add_elem(5.36);
    qDebug()<<dTest.get_elem();
    qDebug()<<dTest.get_elem();
    qDebug()<<dTest.get_elem();
    queue<std::string> str;
    str.add_elem("first");
    str.add_elem("second");
    str.add_elem("third");
    std::cout<<str.get_elem();


    return a.exec();
}
