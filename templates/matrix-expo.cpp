template <int mod>
class Matrix
{
private:
  vector<vector<int>> m;

public:
  Matrix(int rows, int cols)
  {
    m.resize(rows, vector<int>(cols));
  }

  void setNeutral()
  {
    for (int i = 0; i < (int)m.size(); ++i)
    {
      m[i][i] = 1;
    }
  }

  int getRows() {
    return (int)m.size();
  }

  int getCols() {
    return (int)m[0].size();
  }

  int add(int a, int b) {
    return (a + b) % mod;
  }

  int mul(int a, int b) {
    return 1LL * a * b % mod;
  }

  int getNum(int row, int col) {
    return m[row][col];
  }

  void setNum(int row, int col, int val) {
    m[row][col] = val;
  }

  Matrix operator*(const Matrix &curMatrix) {
    Matrix res(m.size(), curMatrix.m[0].size());
    for (int i = 0; i < (int)m.size(); ++i) {
      for (int j = 0; j < (int)curMatrix.m[0].size(); ++j) {
        for (int k = 0; k < (int)m[0].size(); ++k) {
          res.m[i][j] = add(res.m[i][j], mul(m[i][k], curMatrix.m[k][j]));
        }
      }
    }
    return res;
  }

  Matrix operator+(const Matrix &curMatrix) {
    Matrix res(getRows(), getCols());
    for (int i = 0; i < (int)m.size(); ++i)
    {
      for (int j = 0; j < (int)m[0].size(); ++j)
      {
        res.m[i][j] = add(m[i][j], curMatrix.m[i][j]);
      }
    }
    return res;
  }
  Matrix operator^(long long exp)
  {
    Matrix ans(getRows(), getCols()), base(getRows(), getCols());
    ans.setNeutral();
    base.m = this->m;
    while (exp > 0)
    {
      if (exp & 1)
      {
        ans = ans * base;
      }
      base = base * base;
      exp >>= 1;
    }
    return ans;
  }
};
