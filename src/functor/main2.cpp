#include <algorithm>
#include <vector>

using namespace std;

struct Dog
{
  Dog(int age, int weight)
    : m_age(age)
    , m_weight(weight)    
  {};
  
  bool operator<(Dog const &other) const 
  {
    return m_age < other.m_age;
  }
  
  int m_age;
  int m_weight;

};


struct SortByWeightFunctor
{
  bool operator()(Dog const & lhs, Dog const & rhs) const 
  {
    return lhs.m_weight < rhs.m_weight;
  }
};

int main() {
  vector<Dog> v = {Dog(3, 40), Dog(1, 20), Dog(5, 10), Dog(2, 30), Dog(4, 50)};

  sort(begin(v), end(v), SortByWeightFunctor());
  return 0;
}