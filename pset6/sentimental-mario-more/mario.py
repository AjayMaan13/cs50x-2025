# TODO
height = 0

# cheking if the height is the range without any error
while (height > 8 or height < 1):
    try:
        height = int(input("Height : "))
    except:
        height = input("Height : ")


spaces = height - 1
hash = 1

for i in range(height):

    # The main line of code
    print(" " * spaces + "#" * hash + "  " + "#" * hash)
    spaces = spaces - 1
    hash = hash + 1
