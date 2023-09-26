
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

double closest_pair(std::vector<int> &x, std::vector<int> &y);

double dist(int a, int b, int c, int d);

int main()
{

 return 0;
}

double dist(int a, int b, int c, int d)
{
 double ds = pow(a - c, 2) + (b - d, 2);
 return sqrt(ds);
}

std::vector<int> cpy_range(int strt, int end, std::vector<int> &v)
{
 std::vector<int> cpy;
 for (int i = strt; i <= end; i++)
 {
  v.push_back(i);
 }
 return cpy;
}

std::vector<int> get_valid_points(int low, int up, std::vector<int> &x)
{
 std::vector<int> valid;
 for (int i = 0; i < x.size(); i++)
 {
  if (x[i] >= low && x[i] <= up)
  {
   valid.push_back(x[i]);
  }
 }
 return valid;
}

double min_tree(double a, double b, double c)
{
 int min = std::min(a, b);
 if (c < min)
 {
  min = c;
 }
 return min;
}

double closest_pair(std::vector<int> &x, std::vector<int> &y)
{
 int n = x.size();

 if (n == 2)
 {
  return dist(x[0], y[0], x[1], y[1]);
 }
 if (n == 3)
 {
  double a = dist(x[0], y[0], x[1], y[1]);
  double b = dist(x[0], y[0], x[2], y[2]);
  double c = dist(x[1], y[1], x[2], y[2]);
  return min_tree(a, b, c);
 }

 int mid = n / 2;
 std::vector<int> cpy_low = cpy_range(0, mid, x);
 std::vector<int> cpy_high = cpy_range(mid + 1, n, x);
 double dl = closest_pair(cpy_low, y);
 double dr = closest_pair(cpy_high, y);
 double d = std::min(dl, dr);

 std::vector<int> s = get_valid_points(x[mid] - d, x[mid] + d, x);
 // max of 7
 for (int i = 0; i < s.size(); i++)
 {
  for (int j = 0; j < 7; j++)
  {
   if (i + j < n)
   {
    double a = dist(x[i], y[i], x[i + j], y[i + j]);
    d = std::min(d, a);
   }
  }
 }
 return d;
}
