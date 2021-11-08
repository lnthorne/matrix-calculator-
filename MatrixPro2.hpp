//
//  MatrixPro2.hpp
//
//
//  Created by Liam Thorne 
//

#ifndef MatrixPro2_hpp
#define MatrixPro2_hpp

#include <stdio.h>
#include <iomanip>

using namespace std;

class myMatrix{
public:
    //default constructor
    myMatrix(int n = 2);

    //copy constructor/destructer
    myMatrix(const myMatrix &m2);
    ~myMatrix();

    // accessor methods
    int getDimension() const;
    // returns the element at i,j
    int getElement(int, int) const;

    // modifier methods
    void readMatrix();
    void printMatrix()const;
    void swapElements(int, int, int, int);
    void resizeMatrix(int);
    int replaceElementAt(int, int, int);

    void makeIdentity();
    
    
    //modifier constructors
    myMatrix operator+ (int);
    myMatrix operator+ (const myMatrix &M);
    myMatrix operator- (int);
    myMatrix operator- (const myMatrix &M);
    myMatrix operator* (int);
    myMatrix operator* (const myMatrix &M);
    myMatrix& operator= (const myMatrix &M);
    
    myMatrix& operator+= (int);
    myMatrix& operator+= (const myMatrix &M);
    myMatrix& operator-= (int);
    myMatrix& operator-= (const myMatrix &M);
    myMatrix& operator*= (int);
    myMatrix& operator*= (const myMatrix &M);
    
    bool isIdentity(void);
    bool isDiagonal(void);
    bool operator> (const myMatrix &M);
    bool operator< (const myMatrix &M);    bool operator== (const myMatrix &M);
    
    //i/o stream overload
    friend ostream& operator<< (ostream& os,const myMatrix& M);//cout
    friend istream& operator>> (istream& ci, myMatrix& M);//cin
private:
    int dimension;
    int** Block; // specify where the element sits

    int** allocateMatrixMemory(int n);
    void deallocateMatrixMemory(int** M, int n);
};


#endif /* MatrixPro2_hpp */
