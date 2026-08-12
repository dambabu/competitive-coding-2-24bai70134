class MyQueue:
    def __init__(self):
        self.input = []
        self.output = []

    def transfer(self):
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())

    def push(self, x):
        self.input.append(x)

    def pop(self):
        self.transfer()
        return self.output.pop()

    def peek(self):
        self.transfer()
        return self.output[-1]

    def empty(self):
        return not self.input and not self.output


q = MyQueue()

print("Implement Queue Using Stacks")
print()

q.push(1)
q.push(2)

print("After push(1), push(2)")
print("Peek:", q.peek())
print("Pop:", q.pop())
print("Empty:", q.empty())

q.push(3)

print()
print("After push(3)")
print("Peek:", q.peek())
print("Pop:", q.pop())
print("Pop:", q.pop())
print("Empty:", q.empty())