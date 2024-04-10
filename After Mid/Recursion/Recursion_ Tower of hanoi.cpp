#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }
    else
    {
        towerOfHanoi(n - 1, source, destination, auxiliary);
        cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
        towerOfHanoi(n - 1, auxiliary, source, destination);
    }
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
