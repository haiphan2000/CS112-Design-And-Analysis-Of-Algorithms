#include <iostream>
#define MAX_N 100
using namespace std;

struct graph
{
    int v;
    int adj[MAX_N][MAX_N];

    friend istream& operator >> (istream &, graph &);
};

int DuongDiNganNhat(graph, int, int);

int main()
{
    graph do_thi;
    int start;
    int finish;

    cin >> do_thi;
    cin >> start >> finish;
    cout << DuongDiNganNhat(do_thi, start, finish);

    return 0;
}

istream& operator >> (istream &is, graph &do_thi)
{
    is >> do_thi.v;
    for (int i = 1; i <= do_thi.v; i++)
        for (int j = 1; j <= do_thi.v; j++)
            is >> do_thi.adj[i][j];
    return is;
}

int DuongDiNganNhat(graph gr, int start, int finish)
{
    for (int k = 1; k <= gr.v; k++)
        for (int i = 1; i <= gr.v; i++)
            for (int j = 1; j <= gr.v; j++)
                gr.adj[i][j] = min(gr.adj[i][j], gr.adj[i][k] + gr.adj[k][j]);
    return gr.adj[start][finish];
}
