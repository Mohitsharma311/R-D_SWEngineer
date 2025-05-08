def is_automorphic(number):
    if not isinstance(number, int) or number < 0 or number > 9:
        return "Invalid input"
    
    square = number * number
    
    if square % 10 == number:
        return f"{number} is an Automorphic number."
    else:
        return f"{number} is not an Automorphic number."


try:
    num = int(input("Enter a number: "))

    result = is_automorphic(num)
    print(result)

except ValueError:
    print("Invalid input")

