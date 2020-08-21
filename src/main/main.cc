#include <iostream>
#include "src/lib/solution.h"

using namespace std;

// int main()
// {
//     BST b;
//     b.push(8);
//     b.push(3);
//     b.push(10);
//     b.push(1);
//     b.push(6);
//     b.push(14);
//     //          8
//     //     3         10
//     // 1        6         14
//     b.print();
//     b.RecursiveInorderTraveral();
//     b.NonRecursiveInorderTraveral();
// }

int main() 
{ 
    BST b;
    b.push(3); 
    b.push(2); 
    b.push(20); 
    b.push(15); 
    b.push(27); 
    // b.push(1);
    // b.push(4);

    b.print();
    cout << b.MaxDep() << endl; // output 3

    b.NonRecursiveInorderTraveral();
    // b.print();

    b.RecursiveInorderTraveral();

    // cout << b.kthSmallest(1) << endl;
    // cout << b.kthSmallest(2) << endl;
    cout << b.kthSmallest(3) << endl;
    // cout << b.kthSmallest(4) << endl;
    // cout << b.kthSmallest(5) << endl;
    


    //                     3
    //         2                   20
    //                         15      27
    //          
    // original 3 2 20 15 27
    // output   2 3 15 20 27



    return 0; 
} 

