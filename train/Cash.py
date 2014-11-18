class CashRegister:
    def __init__(self, loonies, toonies, fives, tens, twenties):


        self.loonies = loonies
        self.toonies = toonies
        self.fives = fives
        self.tens = tens
        self.twenties = twenties

    def __str__(self):
        return 'CashRegister:' +\
               '${0}($1x{1}, $2x{2}, $5x{3}, $10x{4}, $20x{5})'.format(
                   self.get_total(), self.loonies, self.toonies,
                   self.fives, self.tens, self.twenties)
        
    def __eq__(self, other):
        return self.get_total() == other.get_total()
    
    def get_total(self):

        return self.loonies + self.toonies * 2 + self.fives * 5 + \
               self.tens * 10 + self.twenties * 20
    
    def add(self, count, denomination):


        if denomination == 'loonies':
            self.loonies += count
        elif denomination == 'toonies':
            self.toonies += count
        elif denomination == 'fives':
            self.fives += count
        elif denomination == 'tens':
            self.tens += count
        elif denomination == 'twenties':
            self.twenties += count


    def remove(self, count, denomination):


        if denomination == 'loonies':
            self.loonies -= count
        elif denomination == 'toonies':
            self.toonies -= count
        elif denomination == 'fives':
            self.fives -= count
        elif denomination == 'tens':
            self.tens -= count
        elif denomination == 'twenties':
            self.twenties -= count


if __name__ == '__main__':
    register = CashRegister(5, 5, 5, 5, 5)
    print(register.get_total())

    register.add(3, 'toonies')
    register.remove(2, 'twenties')

    print(register.get_total())
    print(register)
    cr1 = CashRegister(1, 1, 0, 0, 0)
    cr2 = CashRegister(1, 1, 0, 0, 0)
    print(cr1 == cr2)
