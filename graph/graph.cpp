#include "graph.h"
#include <QDebug>
#include <ctime>
#include <QVector>
#include <QtAlgorithms>

using namespace std;

template <class T>
Graph<T>::Graph():edges(0), verts(0)
{
}
template<class T>
Graph<T>::Graph(Qvector<Qvector<T> > adjecencyMatrix)
{
    for (int i = 0; i < adjecencyMatrix.size(); i++)
    {
        Vertex v(i, 0);
        verts.push_back(v);
    }
    for (int i = 0; i < adjecencyMatrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (adjecencyMatrix[i][j] != 0)
            {
                Edge edg(adjecencyMatrix[i][j], verts[i].index, verts[j].index);
                edges.push_back(edg);
            }
        }//end for j
    }//end for i

}

template <class T>
Graph<T>::Graph(QVector<Edge> edges, QVector<Vertex> verts)
{
    this->edges = edges;
    this->verts = verts;
}

template <class T>
Graph<T>::Graph(const Graph &other)
{
    edges = other.edges;
    verts = other.verts;
}

template <class T>
Graph<T>::~Graph()
{
}

template <class T>
bool Graph<T>::isEmpty()
{
    if (edges.isEmpty())
        return true;
    else
        return false;
}

template <class T>
void Graph<T>::deleteVertex(int index)
{
    bool isAvailable = false;
    for (int i = 0; i < verts.size(); i++)
    {
        if (verts[i].index == index)
        {
            isAvailable = true;
            for (int j = 0; j < edges.size(); j++)
            {
                if (edges[j].from == verts[i].index || edges[j].to == verts[i].index)
                    edges.remove(j);
            }
            verts.remove(i);
        }//end if
    }//end for
    if (!isAvailable)
        throw Error("no vertex");
}//end deleteVert


template <class T>
void Graph<T>::addVertex(T value, QVector<int> connections, QVector<T> weights)
{
  int index=verts[verts.size()-1].index+1;

Vertex vrt(index,0);
verts.push_back(vrt);
for (int i=0;i<connections.size();i++)
 {
    for(int j=0;j<verts.size();j++)

    {
       if(verts[j].index==connections[i])
       { Edge edg(weights[i],index,connections[i]);
         edges.push_back(edg);
       }
    }//end for j
 }//end for i
}//end addVert


template <class T>
T Graph<T>::getWeightforMatrix(int index1, int index2)
{
    for(int i=0;i<edges.size();i++)
    {
        if(edges[i].from==index1 && edges[i].to==index2 || edges[i].from==index2&&edges[i].to==index1)
            return edges[i].weight;
    }//end for
    return 0;

}//end getWeightforMatrix

template <class T>
QVector<QVector<T> > Graph<T>::getIncidenceMatrix()
{
    QVector<QVector<T> > Imatrix;
    QVector<T> temp;
    for(int i=0;i<verts.size();i++)
    {
        for(int j=0;j<edges.size();j++)
        {
            if (edges[j].from==verts[i].index || edges[j].to==verts[i].index)
                temp.push_back(1);
            else
                temp.push_back(0);

        }//end for j
        Imatrix.push_back(temp);
        temp.clear();
    }//end for i
}//end Get inc. matrx

template<class T>
int Graph<T>::findValue(T value)
{
    for(int i=0;i<verts.size();i++)
    {
        if(verts[i].value==value)
            return verts[i].index;
    }//end for
}//end findvalue

template<class T>
Vertex Graph<T>::findValue(T value)
{
    for(int i=0;i<verts.size();i++)
    {
        if (verts[i].value==value)
            return verts[i];
    }
    throw Error("not found");
}

template<class T>
Graph<T> Graph<T>::primaAlgorythm()
{
    QVector<QVector<T> > adjacencyMatrix=this->getAdjacencyMtrix();
    QVector<bool> used;
    used.fill(false,verts.size());
    QVector<QVector<int> > PrAdj_matrix;
    QVector<int> temp;
    temp.fill(0,adjacencyMatrix.size());
    used[0]=true;
    int P_count=1;
    while(P_count< adjacencyMatrix.size())
    {
        int min=6969;
        int jmin=0;
        int imin=0;
        for(int i=0;i<used.size();i++)
        {
            for(j=0;i<used.size();j++)
            {
                if(used[i]==true && used[j]==false && adjacencyMatrix[i][j]!=0)
                   { if(adjacencyMatrix[i][j]<min)
                    {
                        min=adjacencyMatrix[i][j];
                        imin=i;
                        jmin=j;
                    }//end if #2
                  }//end if #1
            }//end for j

        }//end for i

        PrAdj_matrix[imin][jmin]=adjacencyMatrix[imin][jmin];
        PrAdj_matrix[jmin][imin]=adjacencyMatrix[jmin][imin];
        used[jmin]=true;
        ++P_count;

    }//end while
  Graph<T> pOutput(PrAdj_matrix);
  return pOutput;



}//end Prima Alg

template<class T>
T Graph<T>::getMinimumPathLength(int from, int to)
{
    int Lenght;
    int size=verts.size();

    QVector<bool> visited[size];
    visited.fill(false);


    QVector<int> vertex_weight[size];
    vertex_weight.fill(INT_MAX);
    vertex_weight[from]=0;


    int current_index=NULL;
    for (int i=0;i<edges.size();i++)
    {
      if(edges[i].weight<0)
      throw Error("I cannot do this, Creator, I am not a Bellman-Ford algorithm");

    }
    bool t=0;
    bool f=0;
    for(int i=0;i<verts.size();i++)
    {
        if(from==verts[i])
            f=1;
        if(to==verts[i]);
           t=1;
    }
    if(t!=1&&f!=1)
        throw Error("Invalid vertexes for the search");
    else

    for(int i=0;i<size-1;i++)
    {
        int min=INT_MAX;
        for(int j=0;j<size;j++){

          if(visited[j]==false && vertex_weight[j]<=min)
          {
            min=vertex_weight[j];
            //visited[j]=true;
            current_index=j;

          }
          visited[current_index]=true;
          for (int j=0;j<edges.size();j++)
          {
              if(edges[j].from==current_index)
              {
               int vert_weight=edges[j].weight;
               int indx=edges[j].to;

                if((vert_weight+vertex_weight[current_index])<vertex_weight[indx])
                  {
                   vertex_weight[indx]=vert_weight+vertex_weight[current_index];
                   if(indx==to)
                       Lenght=vertex_weight[indx];
                       goto output; //breaks all the cycles, goes in the end of the block.
                  }



              }
          }//value update
        }//end choosing for



    }//main cycle
    if(vertex.weight[to]==INT_MAX)
        throw Error("Unexpected error");
    else

output:
    return Lenght;
}

template<class T>
T Graph<T>::getMinimumPathLength(int from, int to)
{
    int Lenght;
    int size=verts.size();

    QVector<bool> visited[size];
    visited.fill(false);


    QVector<int> vertex_weight[size];
    vertex_weight.fill(INT_MAX);
    vertex_weight[from]=0;


    int current_index=NULL;
    for (int i=0;i<edges.size();i++)
    {
      if(edges[i].weight<0)
      throw Error("I cannot do this, Creator, I am not a Bellman-Ford algorithm");

    }
    bool t=0;
    bool f=0;
    for(int i=0;i<verts.size();i++)
    {
        if(from==verts[i])
            f=1;
        if(to==verts[i]);
           t=1;
    }
    if(t!=1&&f!=1)
        throw Error("Invalid vertexes for the search");
    else

    for(int i=0;i<size-1;i++)
    {
        int min=INT_MAX;
        for(int j=0;j<size;j++){

          if(visited[j]==false && vertex_weight[j]<=min)
          {
            min=vertex_weight[j];
            //visited[j]=true;
            current_index=j;

          }
          visited[current_index]=true;
          for (int j=0;j<edges.size();j++)
          {
              if(edges[j].from==current_index)
              {
               int vert_weight=edges[j].weight;
               int indx=edges[j].to;

                if((vert_weight+vertex_weight[current_index])<vertex_weight[indx])
                  {
                   vertex_weight[indx]=vert_weight+vertex_weight[current_index];
                   if(indx==to)
                       Lenght=vertex_weight[indx];
                       goto output; //breaks all the cycles, goes in the end of the block.
                  }



              }
          }//value update
        }//end choosing for



    }//main cycle
    if(vertex.weight==INT_MAX)
        throw Error("Unexpected error");
    else

output:
    return Lenght;
}



template <class T>
void Graph<T>::operator =(Graph<T> &other)
{
    edges=other.edges;
    verts=other.verts;

}

template <class T>
Graph<T>::~Graph()
{
    qDeleteAll(verts);
    qDeleteAll(edges);
}















