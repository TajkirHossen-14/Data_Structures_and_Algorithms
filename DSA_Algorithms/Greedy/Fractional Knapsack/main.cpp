// Fractional Knapsack

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int Profit, Weight;

    Item(int Profit, int Weight)    // Constructor
    {
        this->Profit = Profit;
        this->Weight = Weight;
    }
};

static bool Cmp(struct Item A, struct Item B)   // Comparison function to sort Item
{
    double R1 = (double)A.Profit / (double)A.Weight;
    double R2 = (double)B.Profit / (double)B.Weight;

    return R1 > R2;
}

double FractionalKnapsack(int C, struct Item Arr[], int N)
{
    sort(Arr, Arr + N, Cmp);

    double FinalValue = 0.0;

    for (int i = 0; i < N; i++)
    {
        if (Arr[i].Weight <= C)   // If adding Item won't overflow, add it completely
        {
            C -= Arr[i].Weight;
            FinalValue += Arr[i].Profit;
        }
        else                    // If we can't add current Item, add Fractional part of it
        {
            double Fraction= ((double)C / (double)Arr[i].Weight);
            FinalValue+= Arr[i].Profit * Fraction;

            break;
        }
    }

    return FinalValue;
}

int main()
{
    int C = 50;
    Item Arr[] = { {100, 20}, {120, 30}, {60, 10} };
    int N = sizeof(Arr) / sizeof(Arr[0]);

    cout << "Maximum Value in Fractional Knapsack : " << FractionalKnapsack(C, Arr, N) << endl;

    cout << endl;

    return 0;
}
