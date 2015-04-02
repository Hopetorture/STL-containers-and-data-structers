#ifndef GRAPH
#define GRAPH
#include <QVector>
#include <QString>

class Error //класс для ошибки
{
private:
    QString mess;
public:
    Error(const QString &mess) : mess(mess){}
    QString const &getMess() const
    {
        return mess;
    }
};

template <class T>
class Graph
{
    struct Vertex //вершина графа
    {
        int index;
        T value;
        Vertex()
        {
        }
        Vertex(int index, T value)
        {
            this->index = index;
            this->value = value;
        }
    };

    struct Edge //ребро графа
    {
        T weight;
        int from;
        int to;
        Edge()
        {
        }
        Edge(T weight, int from, int to)
        {
            this->weight = weight;
            this->from = from;
            this->to = to;
        }
    };

public:
    Vertex find_Value(T value);
    Graph();
    Graph(QVector<QVector<T> > adjacencyMatrix); //конструктор с матрицей смежности
    Graph(QVector<Edge> edges, QVector<Vertex> verts); //конструктор со списком вершин и ребер
    Graph(const Graph& other); //копирование
    ~Graph();
    void deleteVertex(int index); //удаление вершины (и всех ее связей)
    void addVertex(T value, QVector<int> connections, QVector<T> weights); //добавление вершины со значением value и связями connections (вектор хранит индексы смежных вершин)
    T getWeight(int index1, int index2); //получить вес ребра между вершинами (если ребра нет - вернуть -1)
    Graph<T> primaAlgorythm(); //алгоритм прима (возвращает остовное дерево)
    QVector<QVector<T> > getAdjacencyMtrix(); //получение матрицы смежности
    QVector<QVector<T> > getIncidenceMatrix(); //получение матрицы инцидентности
    QVector<int> minimumPathFinding(int from, int to); //поиск минимального пути (возвращает вектор с последовательностью индексов вершин)   
    bool isEmpty(); // проверка на пустоту
    int findValue(T value); //поиск значения и возвращение индекса

    void operator = (Graph<T>& other);


private:
    T getWeightforMatrix(int index1, int index2);
    QVector<Edge> edges;
    QVector<Vertex> verts;
};

#endif // GRAPH

