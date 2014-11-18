def gcd(a, b):
  return a if b == 0 else gcd(b, a % b)


class F():
  def __init__(self, d=0, n=1):
    self.d = d
    self.n = n

  def add(self, other):
    self.d, self.n = self.d * other.n + self.n * other.d, \
                     self.n * other.n
    # self.reduce()


  def display(self):
    if self.n == 1:
      print self.d
    else:
      left = self.d / self.n
      up = self.d % self.n
      down = self.n
      left_len = len(str(left))
      up_len = len(str(up))
      down_len = len(str(down))
      print " " * left_len + str(up)
      print ("%d" % left) + "-" * max(up_len, down_len)
      print " " * left_len + str(down)

  def reduce(self):
    n = gcd(self.d, self.n)
    self.d /= n
    self.n /= n


def main():
  n = input()
  s = F()
  for i in range(1, n + 1):
    s.add(F(1, i))
  s.d *= n
  s.reduce()
  s.display()

main()