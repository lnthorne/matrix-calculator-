//
//  main.cpp
//  
//
//  Created by Liam Thorne
//

#include <iostream>
#include "MatrixPro2.hpp"


int main() {
    int d; // matrix dimension
     myMatrix A(3); // Establish a 3 x 3 matrix
     d = A.getDimension();
     cout << "The dimensions of A are " << d << " x " << d << endl;
     cout << "We are now going to get data from standard input stream (cin).\n";
     cin >> A;
     cout << "Matrix A is: " << endl;
     cout<< A << endl;

     cout << "Resizing matrix A to 4 x 4..." << endl;
     A.resizeMatrix(4);
     cout << "Matrix A is now: " << endl;
     cout<< A << endl;

     cout << "Replacing A(4,4) with -17:" << endl;
     A.replaceElementAt(4,4,-17);
     cout << "Matrix A is now: " << endl;
     cout << A << endl;

     cout << "Resizing matrix A to 3 x 3 ..." << endl;
     A.resizeMatrix(3);
     cout << "Matrix A is now: " << endl;
     cout<< A << endl;

     cout << "Swapping A(1,1) and A(3,3): " << endl;
     cout << "CMatrixExt A is now: " << endl;
     A.swapElements(1,1,3,3);
     cout << A << endl;





    cout << "After CMatrixExt B = A + 8, B is: " << endl;
    myMatrix B = A + 8;
    cout<< B << endl;
    
    cout<< "After B += 2, B is: \n";
    B += 2;
    cout<< B << endl;

    cout << "After CMatrixExt C = A + B, C is: " << endl;
    myMatrix C = A + B;
    cout << C << endl;
    
    cout<< "After C += A, C is: \n";
    C += A;
    cout<< C << endl;

    cout << "After declaring CMatrixExt D, D = C, D is: " << endl;
    myMatrix D(3);
    cout << "The dimensions of C are " << C.getDimension() << " x " << C.getDimension() << endl;
    cout << "The dimensions of D are " << D.getDimension() << " x " << D.getDimension() << endl;
    D = C;
    cout << D << endl;
    
    cout<< "After declaring B = A = C, A is: \n";
    B = A = C;
    cout<< A << endl;
    cout<< "After declaring B = A = C, B is: \n";
    cout<< B << endl;
    
    cout << "After CMatrixExt E = A - 8, E is: " << endl;
    myMatrix E = A - 8;
    cout << E << endl;
    
    cout<< "After E -= 2, E is: \n";
    E -= 2;
    cout<< E << endl;


    cout << "After CMatrixExt F = A - B, F is: " << endl;
    myMatrix F = A - B;
    cout << F << endl;
    
    cout<< "After F -= B, F is: \n";
    F -= B;
    cout<< F << endl;


    cout << "After CMatrixExt G = A * (-3), G is: " << endl;
    myMatrix G = A * (-3);
    cout << G << endl;
    
    cout<< "After G *= -1, G is: \n";
    G *= (-1);
    cout<< G << endl;

    cout << "After CMatrixExt H = A * B, H is: " << endl;
    myMatrix H = A * B;
    cout<< H << endl;
    
    cout<< "After H *= B, H is: \n";
    H *= B;
    cout<< H << endl;



    cout << "After H.makeIdentity(), H is:" << endl;
    H.makeIdentity();
    cout << H << endl;


    if(H.isIdentity())
        cout << "H is the identity matrix" << endl;
    else
        cout << "H is not the identity matrix" << endl;

    if(H.isDiagonal())
        cout << "H is a diagonal matrix" << endl;
    else
        cout << "H is not a diagonal matrix" << endl;

    if(A.isIdentity())
        cout << "A is the identity matrix" << endl;
    else
        cout << "A is not the identity matrix" << endl;
    
    if(A.isDiagonal())
        cout << "A is a diagonal matrix" << endl;
    else
        cout << "A is not a diagonal matrix" << endl;

    cout << endl << "Now we will test isBigger, isSmaller and isEqual" << endl;

    myMatrix J(3),K(3);
    cout << "Enter values for 3 x 3 matrix J:" << endl;
    cin >> J;
    cout << endl << "CMatrixExt J is:" << endl;
    cout << J << endl;

    cout << "Enter values for 3 x 3 matrix K:" << endl;
    cin >> K;
    cout << endl << "CMatrixExt K is:" << endl;
    cout << K << endl;

    if(J > K)
        cout << "CMatrixExt J is bigger than CMatrixExt K"<< endl;
    else
        cout << "CMatrixExt J is not bigger than CMatrixExt K" << endl;

    if(J < K)
        cout << "CMatrixExt J is smaller than CMatrixExt K"<< endl;
    else
        cout << "CMatrixExt J is not smaller than CMatrixExt K" << endl;

    if(J == K)
        cout << "CMatrixExt J is equal to CMatrixExt K"<< endl;
    else
        cout << "CMatrixExt J is not equal to CMatrixExt K" << endl;

        return 0;

}
