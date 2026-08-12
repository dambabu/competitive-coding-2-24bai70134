class MyQueue:
    def __init__(self):
        self.input = []
        self.output = []

    def push(self, x):
        self.input.append(x)

    def pop(self):
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())

        return self.output.pop()

    def peek(self):
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())

        return self.output[-1]

    def empty(self):
        return not self.input and not self.output


q = MyQueue()

q.push(1)
q.push(2)

print("Peek:", q.peek())
print("Pop:", q.pop())
print("Empty:", q.empty())