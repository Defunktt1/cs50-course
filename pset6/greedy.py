import cs50

def main():
    money = getMoney()
    count = counter(money)
    print (count)

def getMoney():
    print ("O, Hai!")
    while True:
        print ("How much change is owed?")
        fMoney = cs50.get_float();
        money = round(fMoney * 100)
        if money >= 0:
            break
    return money
    
def counter(money):
    count = 0
    while money > 0:
        if money >= 25:
            money -= 25
            count += 1
        elif money >= 10:
            money -= 10
            count += 1
        elif money >= 5:
            money -= 5
            count += 1
        elif money >= 1:
            money -= 1
            count += 1
        elif money == 0:
            break
    return count

if __name__ == "__main__":
    main()