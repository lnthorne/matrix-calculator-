//
//  MatrixPro2.cpp
//
//
//  Created by Liam Thorne
//

#include "MatrixPro2.hpp"
#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;



//default constructor
//****************************************************************
myMatrix::myMatrix(int n):dimension(n){

    Block = allocateMatrixMemory(dimension);
}


//copy constructor
//****************************************************************
myMatrix::myMatrix(const myMatrix &m2):dimension(m2.dimension){

    //Block = new int* [dimension+1];
    Block = allocateMatrixMemory(dimension);

    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            Block[i][j] = m2.Block[i][j];
        }
    }
}

//Destructor
//****************************************************************
myMatrix::~myMatrix(){
    deallocateMatrixMemory(Block, dimension);

}
//****************************************************************
int** myMatrix::allocateMatrixMemory(int n){

    int** temp;//creating tempary double ptr
    //creating newSize of elements and setting to 0
    temp = new int* [n];
    for(int i = 0; i < n; i++){
        temp[i] = new int [n];
        for(int j = 0; j < n; j++){
            temp[i][j] = 0;
        }
    }
    return temp;
}




//when called it deletes array
//****************************************************************
void myMatrix::deallocateMatrixMemory(int** M, int n){

    for(int i = 0; i < n; i++)
        delete [] M[i];

    delete M;
    M = nullptr;
}




//used to print matrix
//****************************************************************
void myMatrix::printMatrix()const{
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            cout<< setw(4) << Block[i][j];
        }
        cout<< endl;
    }
}

//****************************************************************
void myMatrix::readMatrix(void){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            cout<< "(" << i + 1 << "," << j + 1<< "):";
            cin>> Block[i][j];
        }
    }
}

//****************************************************************
void myMatrix::resizeMatrix(int newSize){
    int oldSize = dimension;
    int** temp = allocateMatrixMemory(newSize);

    //make array bigger
    if(oldSize < newSize){
        for(int i=0; i<oldSize; i++)
           for(int j=0; j<oldSize; j++)
              temp[i][j] = Block[i][j];

    }
    else{
        for(int i=0; i<newSize; i++)
           for(int j=0; j<newSize; j++)
              temp[i][j] = Block[i][j];

    }
    deallocateMatrixMemory(Block, oldSize);
    Block =  temp;
    dimension = newSize;
}


//****************************************************************
int myMatrix::getDimension() const
{
    return dimension;
}

//****************************************************************
int myMatrix::getElement(int i, int j) const{
    assert(i >= 0 && i <= dimension);
    assert(j >= 0 && j <= dimension);

    return  this->Block[i][j];
}

//****************************************************************
void myMatrix::swapElements(int i1, int j1, int i2, int j2){
    assert(i1 >= 0 && j1 >= 0 && i1 <= dimension && j1 <= dimension);
    assert(i2 >= 0 && j2 >= 0 && i2 <= dimension && j2 <= dimension);

    int temp;

    temp = Block[i1-1][j1-1];

    Block[i1-1][j1-1] = Block[i2 - 1][j2 - 1];
    Block[i2 - 1][j2 - 1] = temp;
}





//****************************************************************
int myMatrix::replaceElementAt(int i, int j, int newElem){
    assert(i > 0 && j > 0 && i <= dimension && j <= dimension);
    
    int temp;
    temp = Block[i-1][j-1];
    Block[i-1][j-1] = newElem;

    return temp;
}


//****************************************************************
void myMatrix::makeIdentity(){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(i == j)
                Block[i][j] = 1;
            else
                Block[i][j] = 0;
        }
    }
}

//****************************************************************
myMatrix& myMatrix::operator= (const myMatrix &M){
    if(dimension != M.dimension){
        deallocateMatrixMemory(Block, dimension);
        Block = allocateMatrixMemory(M.dimension);
        dimension = M.dimension;
        
        for(int i = 0; i < dimension; i++){
            for(int j = 0; j < dimension; j++){
                Block[i][j] = M.Block[i][j];
            }
        }
        return *this;
    }

    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            Block[i][j] = M.Block[i][j];
        }
    }
    return *this;
}



//add matrix
//****************************************************************
myMatrix myMatrix::operator+ (int n){
    myMatrix sum(dimension);

   for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
         sum.Block[i][j] = this->Block[i][j] + n;
        }
    }

    return sum;
}

//add matrix
//****************************************************************
myMatrix myMatrix::operator+ (const myMatrix &M){
    assert(M.dimension == dimension);
    
    myMatrix sum(dimension);
    for(int i = 0; i < dimension; i++){
         for(int j = 0; j < dimension; j++){
             sum.Block[i][j] = Block[i][j] + M.Block[i][j];
         }
     }

    return sum;
}


//****************************************************************
myMatrix& myMatrix::operator+=(int n){
   
    myMatrix temp(*this + n);
    *this = temp;
    return *this;
}


//****************************************************************
myMatrix& myMatrix::operator+= (const myMatrix &M){
    assert(M.dimension == dimension);
    
    myMatrix temp(*this + M);
    *this = temp;
    return *this;
    
}




//subtract matrix
//****************************************************************
myMatrix myMatrix::operator- (int n){
    
    myMatrix difference(dimension);
    for(int i = 0; i < dimension; i++){
         for(int j = 0; j < dimension; j++){
             difference.Block[i][j] = this->Block[i][j] - n;
         }
     }

    return difference;
}


//Subtract matrix
//****************************************************************
myMatrix myMatrix::operator- (const myMatrix &M){
    assert(M.dimension == dimension);
    
    myMatrix difference(dimension);
    for(int i = 0; i < dimension; i++){
         for(int j = 0; j < dimension; j++){
             difference.Block[i][j] =  this->Block[i][j] - M.Block[i][j];
         }
     }

    return difference;
}


//****************************************************************
myMatrix& myMatrix::operator-=(int n){
    
    myMatrix temp(*this - n);
    *this = temp;
    return *this;
}

//****************************************************************
myMatrix& myMatrix::operator-=(const myMatrix &M){
    assert(M.dimension == dimension);
    
    myMatrix temp(*this - M);
    *this = temp;
    return *this;
}






//multiply matrix
//****************************************************************
myMatrix myMatrix::operator* (int n){
    myMatrix product(dimension);
    for(int i = 0; i < dimension; i++){
         for(int j = 0; j < dimension; j++){

             product.Block[i][j] = this->Block[i][j] * n;
             }
         }

    return product;

}

//Multiply matrix
//****************************************************************
myMatrix myMatrix::operator* (const myMatrix &M){
    assert(M.dimension == dimension);
    myMatrix product(dimension);
    for(int i = 0; i < dimension; i++){
         for(int j = 0; j < dimension; j++){
             for(int k = 0; k < dimension; k++){
                 product.Block[i][j] = this->Block[i][k] * M.Block[k][j];
             }

         }
     }

    return product;
}

//****************************************************************
myMatrix& myMatrix::operator*= (int n){
    
    myMatrix temp(*this * n);
    *this = temp;
    return *this;
}

//****************************************************************
myMatrix& myMatrix::operator*= (const myMatrix &M){
    assert(M.dimension == dimension);
    
    myMatrix temp(*this * M);
    *this = temp;
    return *this;
}

//****************************************************************
bool myMatrix::isIdentity(){
    myMatrix ID(dimension);

     ID.makeIdentity();

    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(ID.Block[i][j] != Block[i][j])
                return false;

        }
    }

    return true;
}

//****************************************************************
bool myMatrix::isDiagonal(){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(i != j){
               if(Block[i][j] != 0)
                    return false;
            }
        }
    }
    return true;

}

//isBigger
//****************************************************************
bool myMatrix::operator> (const myMatrix &M){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(!(Block[i][j] > M.Block[i][j]))
                return false;
        }
    }
    return true;
}


//isSmaller
//****************************************************************
bool myMatrix::operator< (const myMatrix &M){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(!(Block[i][j] > M.Block[i][j]))
                return true;
        }
    }
    return false;
}

//isEqual
//****************************************************************
bool myMatrix::operator== (const myMatrix &M){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(Block[i][j] != M.Block[i][j])
                return false;
        }
    }
    return true;
}





ostream& operator<< (ostream& os,const myMatrix& M){
   
    for(int i = 0; i < M.dimension; i++){
        for(int j = 0; j < M.dimension; j++){
            os << setw(4) <<  M.Block[i][j];
      
        }
        os << endl;
    }
    return os;
}



istream& operator>> (istream& ci, myMatrix& M){
    for(int i = 0; i < M.dimension; i++){
        for(int j = 0; j < M.dimension; j++){
            cout<< "(" << i + 1 << "," << j + 1<< "):";
            ci >> M.Block[i][j];
        }
    }
    return ci;
}
 
