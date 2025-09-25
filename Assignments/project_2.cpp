#include<iostream>
#include<cassert>

void line(int n, int i)
{
  for (int j = 0; j < n-i; j++)
    std::cout << " ";
  for (int j = 0; j < 1 + i*2; j++)
    std::cout << "*";
  std::cout << std::endl;
}

void pattern(unsigned int n)
{
  for (int i = n; i > 0; i--)
  {
    line(n, i);
  }
  for (int i = 0; i <= n; i++)
  {
    line(n, i);
  }
}

unsigned int exp10(unsigned int m)
{
  unsigned int result = 1;
  for (unsigned int i = 0; i < m; i++)
    result *= 10;
  return result;
}

unsigned int exp256(unsigned int exp)
{
  unsigned int result = 1;
  for (unsigned int i = 0; i < exp; i++)
    result *= 256;
  return result; 
}

unsigned int log10(unsigned int n)
{
  for (unsigned int m = 0; m < 10; m++)
    if (exp10(m) > n)
      return m-1;
  return 11;
}

unsigned int count(unsigned int n, unsigned int bit)
{
  assert(bit == 1 || bit == 0);

  unsigned int ones_count = 0;
  while (n != 0)
  {
    ones_count += n % 2;
    n /= 2;
  }

  return bit == 1 ? ones_count : 32-ones_count;
}

unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1)
{
  assert(0 <= b0 && b0 <= 3 && 0 <= b1 && b1 <= 3);

  unsigned int bytes[4];
  for (unsigned int i = 0; i < 4; i++)
  {
    bytes[i] = n % (16*16);
    n /= (16*16);
  }
  
  unsigned int tmp = bytes[b0];
  bytes[b0] = bytes[b1];
  bytes[b1] = tmp;

  unsigned int result = 0;
  for (int i = 0; i < 4; i++)
  {
    std::cout << bytes[i] << std::endl;
    result += bytes[i] * exp256(i);
  }
  return result;
}

int main() 
{
  for (int i = 0; i < 5; i++)
  {
    pattern(i);
    std::cout<<std::endl<<std::endl;
  }
  std::cout << log10(100) << std::endl;
  std::cout << log10(1200) << std::endl;

  std::cout << count(0x03020100U, 1) << std::endl;
  std::cout <<count(0x03020100U, 0) << std::endl;

  std::cout << swap_bytes(0x03020100U, 1, 3) << std::endl;
  std::cout << 0x01020300U << std::endl;
}
