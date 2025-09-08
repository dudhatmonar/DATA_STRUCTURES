// 3. Tower of Hanoi
// Write a recursive program to solve the Tower of Hanoi problem. The objective of the puzzle
// is to move all disks from a source rod to a destination rod using an auxiliary rod, following
// these rules:

// 1. Only one disk can be moved at a time.
// 2. A disk can only be placed on top of a larger disk or on an empty rod.
// Examples:
// Input: 2 disks
// Output: Move disk 1 from A to B
// Move disk 1 from A → B
// Move disk 2 from A → C
// Move disk 1 from B → C
// Input: 3 disks
// Output: Sequence of 7 moves showing the correct transfer
// Move disk 1 from A → C
// Move disk 2 from A → B
// Move disk 1 from C → B
// Move disk 3 from A → C
// Move disk 1 from B → A
// Move disk 2 from B → C
// Move disk 1 from A → C


#include <iostream>
using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 0) return;

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << fromRod << " -> " << toRod << endl;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "Sequence of moves:\n";
    towerOfHanoi(n, 'A', 'C', 'B');  // A = source, C = destination, B = auxiliary

    return 0;
}
