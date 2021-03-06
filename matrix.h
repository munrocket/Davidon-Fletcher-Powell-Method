#ifndef _matrix_h_
#define _matrix_h_
struct vector;
struct covector;

//2do: message, <<, zero vector, rang, norm

void errormessage(char* from, char* errormessage);

struct matrix
{
  double** data;
  int lines, colomns;

  matrix();                                               //constructor
  ~matrix();                                              //destructor
  matrix(int, int);
  matrix(const matrix&);                                  //copy constructor

  friend void print(const matrix&);
  friend matrix init(matrix&, double, ...);                 //initialization
  friend matrix zero(int, int);                           //zero matrix(teta)
  friend matrix identity(int);                            //identity matrix(E)

  matrix& operator=(const matrix&);
  matrix& operator+=(const matrix&);
  matrix& operator-=(const matrix&);
  matrix& operator*=(double);
  matrix& operator*=(const matrix&);
  matrix& operator/=(double);
  matrix& changelines(int, int);

  friend matrix operator+(matrix, const matrix&);
  friend matrix operator-(matrix, const matrix&);
  friend matrix operator-(const matrix&);
  friend matrix operator*(matrix, double);
  friend matrix operator*(double, matrix);
  friend matrix operator*(matrix, const matrix&);
  friend matrix operator/(matrix, double);
  friend matrix transpose(const matrix&);
  friend matrix concat(const matrix&, const matrix&);    //bild expanded matrix 
                                                         // (A|B)

  friend bool nonzero(const matrix&, double);

  //in struct vector\covector
  friend vector operator*(const matrix&, const vector&);
  friend covector operator*(const covector&, const matrix&);
  friend vector operator/(const vector&, const matrix&);
};

//type vector it is matrix[n, 1]
struct vector: public matrix
{
  explicit vector(int);
  vector(const vector&);
  explicit vector(const matrix&);
  ~vector();

  int length();
  double& operator[](int);
  friend covector transpose(const vector&);
  friend vector transpose(const covector&);
  friend double sqr(const vector&);
  friend double norm(const vector&);

  friend vector operator+(const vector&, const vector&);
  friend vector operator-(const vector&, const vector&);
  friend double operator*(const covector&, const vector&);
  friend vector operator*(const matrix&, const vector&);
  friend vector operator*(double, const vector&);
  friend vector operator*(const vector&, double);
  friend vector operator/(const vector&, const matrix&);  //gauss algaritm :)
};

//type covector it is matrix[1, n]
struct covector: public matrix
{
  covector(int);
  covector(const covector&);
  explicit covector(const matrix&);
  ~covector();

  int length();
  double& operator[](int);
  friend covector transpose(const vector&);
  friend vector transpose(const covector&);
  friend double sqr(const covector&);
  friend double norm(const covector&);

  friend covector operator+(const covector&, const covector&);
  friend covector operator-(const covector&, const covector&);
  friend covector operator*(const covector&, const matrix&);
  friend covector operator*(double, const covector&);
  friend covector operator*(const covector&, double);

  friend double operator*(const covector&, const vector&);
};
#endif
