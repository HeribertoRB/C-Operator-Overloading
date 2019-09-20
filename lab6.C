#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

class TheMatrix;

TheMatrix operator/ (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator- (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator+ (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator* (const TheMatrix& M1, const TheMatrix& M2);
ifstream& operator>> (ifstream& is, TheMatrix& myMatrix); 
ostream& operator<< (ostream& is, const TheMatrix& myMatrix);

class TheMatrix
{
  friend TheMatrix operator/ (const TheMatrix& M1, const TheMatrix& M2);
  friend TheMatrix operator- (const TheMatrix& M1, const TheMatrix& M2);
  friend TheMatrix operator+ (const TheMatrix& M1, const TheMatrix& M2);
  friend TheMatrix operator* (const TheMatrix& M1, const TheMatrix& M2);
  friend ifstream& operator>> (ifstream& is, TheMatrix& myMatrix);
  friend ostream& operator<< (ostream& is, const TheMatrix& myMatrix);

private:
  int  M[5][5];
  
public:
  TheMatrix();
  ~TheMatrix();
};

TheMatrix::~TheMatrix()
{
}

TheMatrix::TheMatrix()
{
  for (int i=0; i< 5; i++)
    for (int j=0; j<5; j++)
      M[i][j]=0;
}

ifstream& operator>> (ifstream& is, TheMatrix& myMatrix) 
{
  string fileName;
  cout << "Enter a file name -> ";
  cin >> fileName;
  is.open(fileName.data());
  for (int i=0; i< 5; i++)
    for (int j=0; j<5; j++)
      is >> myMatrix.M[i][j];
  return is;

}

ostream& operator<< (ostream& os, const TheMatrix& myMatrix) 
{
  os << "The value of x: " << endl;

  for(int i=0; i< 5; i++)
    {
      for(int j=0; j< 5; j++)
	{
	  os << setw(4) << myMatrix.M[i][j];
	}
      os << endl;
    }

  return os;
}

TheMatrix operator+ (const TheMatrix& M1, const TheMatrix& M2)
{
  TheMatrix Result;
  for (int i=0; i< 5; i++)
    for (int j=0; j<5; j++)
      Result.M[i][j] = M1.M[i][j]+M2.M[i][j];
  return Result;
}

TheMatrix  operator- (const TheMatrix& M1, const TheMatrix& M2)
{
  TheMatrix Result;
  for (int i=0; i< 5; i++)
    for (int j=0; j<5; j++)
      Result.M[i][j] = M1.M[i][j]-M2.M[i][j];
  return Result;
}

TheMatrix  operator* (const TheMatrix& M1, const TheMatrix& M2)
{
  TheMatrix Result;
  for (int i=0; i< 5; i++)
    for (int j=0; j<5; j++)
      Result.M[i][j] = M1.M[i][j]*M2.M[i][j];
  return Result;
}

TheMatrix  operator/ (const TheMatrix& M1, const TheMatrix& M2)
{
  TheMatrix Result;
  for (int i=0; i< 5; i++)
    for (int j=0; j<5; j++)
      {
	if(M2.M[i][j] == 0)
	  Result.M[i][j] = 0;
	else
	  Result.M[i][j] = M1.M[i][j]/M2.M[i][j];
      }
  return Result;
}

int main()
{
  TheMatrix A, B, AddAB, MulAB, SubAB, DivAB;
  ifstream fin1, fin2;

  fin1 >> A;
  fin2 >> B; 

  AddAB = A + B;
  SubAB = A - B;
  MulAB = A * B;
  DivAB = A / B;

  cout << A << endl;
  cout << B << endl;
  cout << AddAB << endl;
  cout << SubAB << endl;
  cout << MulAB << endl;
  cout << DivAB << endl;
  
  return 0;
}
