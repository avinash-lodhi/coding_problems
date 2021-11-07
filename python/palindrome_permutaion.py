###
# Problem Description: Check if given string is a permutation of a palindrome.
###
import sys

def main():
    input_string = str(sys.argv[1]).strip().lower()
    char_count = {}
    allowed = True
    for char in input_string:
        if char == ' ':
            continue
        try:
            char_count[char] = char_count[char]-1 if char_count[char] != 0 else 1
        except KeyError as e:
            char_count[char] = 1
    print(char_count)
    for key in char_count.keys():
        if char_count[key] != 0 and not allowed:
            print("The input {0} is not a permution of a palindrome".format(input_string))
            exit(0)
        if char_count[key] != 0:
            allowed = False
    print("The input {0} is a permutaion string".format(input_string))
if __name__ == '__main__':
    main()