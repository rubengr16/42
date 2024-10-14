# ft_ssl
## Usage
```
usage: ft_ssl command [flags] [file/string]
```

## MD5

The algorithm takes as input a message of arbitrary length and produces as output a 128-bit "fingerprint" or "message digest" of the input.

### Terminology and Notation

* `word`: 32 bits
* `byte`: 8 bits
* Bytes are readed in `big-endian`, first leftmost byte is the most significant one.
* `x_i`: denotes subindex i
* `x^i`: power to the i-th
* `+`: addition within the given module
* `x <<< s`: circulary bitshifting x by s times
* `not(x)`: bitwise complement
* `x v y`: x OR y
* `x XOR y`
* `xy`: x AND y

## SHA256

## Bibliography

* [The MD5 Message-Digest Algorithm](https://www.ietf.org/rfc/rfc1321.txt)
