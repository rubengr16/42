from sys import argv
from string import (
    ascii_uppercase,
    ascii_lowercase,
    punctuation,
    digits,
    whitespace
)


def count_chars(string: str):
    count_dict = {
        ascii_uppercase: 0,
        ascii_lowercase: 0,
        punctuation: 0,
        whitespace: 0,
        digits: 0
    }
    for char in string:
        for char_type in count_dict:
            if char in char_type:
                count_dict[char_type] += 1
                break
    return count_dict.values()


def main():
    if len(argv) == 1:
        exit(0)
    if len(argv) > 2:
        raise AssertionError("more than one argument is provided")
    uppers, lowers, puncts, spaces, digits = count_chars(argv[1])
    print(f"The text contains {len(argv[1])} characters:")
    print(f"{uppers} upper letters")
    print(f"{lowers} lower letters")
    print(f"{puncts} punctuation marks")
    print(f"{spaces} spaces")
    print(f"{digits} digits")


if __name__ == "__main__":
    main()
