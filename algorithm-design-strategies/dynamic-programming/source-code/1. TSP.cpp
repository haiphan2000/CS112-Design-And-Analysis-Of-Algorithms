#include <iostream>
#include <climits>
#define MAX_N 100
using namespace std;

int KiemTra[MAX_N];

struct graph
{
    int v;
    int adj[MAX_N][MAX_N];

    friend istream& operator >> (istream &, graph &);
};

int TSP(graph);

int main()
{
    graph cities;
    cin >> cities;
    cout << TSP(cities);

    return 0;
}

istream& operator >> (istream &is, graph &gr)
{
    is >> gr.v;
    for (int i = 1; i <= gr.v; i++)
        for (int j = 1; j <= gr.v; j++)
            cin >> gr.adj[i][j];
}

int TSP(graph gr)
{
    int sum = 0;
    int start = 1;
    KiemTra[start] = 1;
    for (int i = 1; i < gr.v; i++)
    {
        int temp = 0;
        int min = INT_MAX;
        for (int j = 1; j <= gr.v; j++)
        {
            if (gr.adj[start][j] > 0 && KiemTra[j] == 0)
            {
                if (gr.adj[start][j] < min)
                {
                    min = gr.adj[start][j];
                    temp = j;
                }
            }
        }
        sum = sum + min;
        start = temp;
        KiemTra[start] = 1;
    }
    sum = sum + gr.adj[start][1];
    return sum;
}
