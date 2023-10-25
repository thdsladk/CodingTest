#include "Test3132.h"



Test3132::Test3132()
{
    IQ.resize(1001);


    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> IQ[i];
    }

    for (int i = 1; i < N; ++i) {
        int M, E;
        cin >> M >> E;
        adj[M].push_back(E);
        adj[E].push_back(M);
    }

    DFS(1, -1, IQ[1]);

    cout << endl << endl;
    for (int i = 0; i < N - 1; ++i) 
    {
        cout << NewStructure[i].first << " " << NewStructure[i].second << endl;
    }




    




}

void Test3132::DFS(int Child, int Parent, int MaxIQ)
{
    for (int elem : adj[Child]) 
    {
        if (elem != Parent) 
        {
            MaxIQ = max(MaxIQ, IQ[elem]);
            DFS(elem, Child, MaxIQ);
        }
    }
    if (IQ[Child] <= MaxIQ) {
        IQ[Child] = MaxIQ + 1;
        NewStructure.push_back({ Parent, Child });
    }
}
