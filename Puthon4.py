 class Stack:
    def __init__(self):
        self.stack = []
    def push(self, item):
        self.stack.append(item)
    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else:
            return "Stack is empty!"
    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        else:
            return "Stack is empty!"
    def is_empty(self):
        return len(self.stack) == 0
    def size(self):
        return len(self.stack)
    def display(self):
        if not self.is_empty():
            return self.stack
        else:
            return "Stack is empty!"
def main():
    stack = Stack()
    
    while True:
        print("\nStack Operations:")
        print("1. Push")
        print("2. Pop")
        print("3. Peek")
        print("4. Check if Empty")
        print("5. Stack Size")
        print("6. Display Stack")
        print("7. Exit")
        
        choice = int(input("Enter your choice: "))
        
        if choice == 1:
            item = int(input("Enter item to push: "))
            stack.push(item)
            print(f"{item} pushed to stack.")
        
        elif choice == 2:
            popped_item = stack.pop()
            print(f"Popped item: {popped_item}")
        
        elif choice == 3:
            top_item = stack.peek()
            print(f"Top item: {top_item}")
        
        elif choice == 4:
            if stack.is_empty():
                print("Stack is empty.")
            else:
                print("Stack is not empty.")
        
        elif choice == 5:
            print(f"Stack size: {stack.size()}")
        
        elif choice == 6:
            print("Stack content:", stack.display())
        
        elif choice == 7:
            print("Exiting...")
            break
        
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
