###
# Problem description: Given two strings find if one is permutation of other
###
import sys

def main():
    string1 = str(sys.argv[1])
    string2 = str(sys.argv[2])
    counter = {}
    for i in string1:
        try:
            counter[i] = counter[i]+1
        except KeyError as e:
            counter[i] = 1
    for i in string2:
        try:
            counter[i] = counter[i] - 1
            if counter[i] < 0 :
                print("Strings are not permutation of each other")
                exit(0)
        except KeyError as e:
            print("Strings are not permutation of each other")
            exit(0)
    print("Strings are permutation of each other")
if __name__ == '__main__':
    main()