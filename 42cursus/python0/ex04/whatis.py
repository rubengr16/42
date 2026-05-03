from sys import argv

try:
    if len(argv) == 1:
        exit(0)
    if len(argv) > 2:
        raise AssertionError("more than one argument is provided")
    try:
        nb = int(argv[1])
    except ValueError:
        raise AssertionError("argument is not an integer")
    if nb % 2:
        print("I'm Odd.")
    else:
        print("I'm Even.")
except AssertionError as error:
    print(f"{error.__class__.__name__}: {error}")
