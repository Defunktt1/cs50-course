import cs50

def main():
    heigth = checkNumber()
    drow(heigth)
    
def checkNumber():
    while True:
        print ("heigth: ", end="")
        heigth = cs50.get_int()
        if heigth > 0 or heigth <= 23:
            break
    return heigth

def drow(heigth):
    for i in range(heigth):
        for k in range(heigth - i - 1):
            print (" ", end="")
        for j in range(i + 2):
            print ("#", end="")
        print ()
if __name__ == "__main__":
    main()
