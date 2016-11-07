import cs50
from sys import argv

def main():
    if len(argv) != 2:
        print ("You screwed up!")
        exit(1)
    
    if str.isnumeric(argv[1]) == False:
        print ("please, put only number!")
        exit(2)
    
    key = int(argv[1])
    
    print ("plaintext: ", end="")
    inputText = cs50.get_string()
    print ("ciphertext: ", end="")
    caesar(inputText, key)
    exit(0)
    
def caesar(text, key):
    for i in range(len(text)):
        if str.isalpha(text[i]) and str.islower(text[i]):
            temp = ord(text[i]) + key
            while temp > ord('z'):
                temp = temp - ord('z') + 96
            print (chr(temp), end="")
        elif str.isalpha(text[i]) and str.isupper(text[i]):
            temp = ord(text[i]) + key
            while temp > ord('Z'):
                temp = temp - ord('Z') + 64
            print (chr(temp), end="")
        else:
            print (text[i], end="")
  
if __name__ == "__main__":
    main()
            