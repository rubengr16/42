# ft_ssl
## Usage
```
usage: ft_ssl command [flags] [file/string]
```

## MD5

The algorithm takes as input a message of arbitrary length and produces as output a 128-bit "fingerprint" or "message digest" of the input.

### Terminology and Notation

* `word`: 32 bits (4 Bytes)
* `byte`: 8 bits
* Bytes are readed in `big-endian`, first leftmost bit is the most significant one.
* Words are readed in `little-endian`, first leftmost byte is the less significant one.
* `x_i`: denotes subindex i
* `x^i`: power to the i-th
* `+`: addition within the given module
* `x <<< s`: circulary bitshifting x by s times
* `not(x)`: bitwise complement
* `x v y`: x OR y
* `x XOR y`
* `xy`: x AND y

### MD5 Algorithm Description
Given a message (m) or arbitrary non-negative length (b) we want to calculate its digest.
```m_0 m_1 ... m_{b-1}```

#### Step 1. Append Padding Bits
"Padding" is perform so that the length of the message is congruent to 448 mod 512 (64b are left). The padding must be always in the range [1, 448]. It is done by adding "1" and later "0"s.

#### Step 2. Append Length
A 64b representation of b (the message length). If the length is greater than 2^64, the low order 64b are used. This 64b create 2 words with the less significant first.

At this point, the resulting message has a length of 512b, 16 words. Let message be M[0 ... N-1] be the words of the resulting message, where N is a multiple of 16.

#### Step 3. Initialize MD Buffer
A four word buffer (A, B, C, D) is used to compute the message digest. Each word is a 32b register with the following values in hex (little-endian):
```
A: 01 23 45 67
B: 89 ab cd ef
C: fe dc ba 98
D: 76 54 32 10
```

#### Step 4. Process Message in 16-Word Blocks
We first define four auxiliary functions that each take as input
three words and produce as output one word (they are evaluated bit to bit):
```
F(X,Y,Z) = XY v not(X) Z
G(X,Y,Z) = XZ v Y not(Z)
H(X,Y,Z) = X xor Y xor Z
I(X,Y,Z) = Y xor (X v not(Z))
```

In **each bit** position F acts as a conditional: if X then Y else Z.
The function F could have been defined using + instead of v since XY
and not(X)Z will never have 1's in the same bit position. It is
interesting to note that if the bits of X, Y, and Z are independent
and unbiased, the each bit of F(X,Y,Z) will be independent and
unbiased.

Similar properties apply to G, H and I which are also **bitwise parallel**. Note that the function H is the bit-wise "xor" or "parity" function of its
inputs.

This step uses a 64-element table T[1 ... 64] constructed from the
sine function. Let T[i] denote the i-th element of the table, which
is equal to the integer part of 4294967296 times abs(sin(i)), where i
is in radians (remember that i range is [1, 64]). The elements of the table are given in the appendix.

## SHA256

## Bibliography

* [The MD5 Message-Digest Algorithm](https://www.ietf.org/rfc/rfc1321.txt)
