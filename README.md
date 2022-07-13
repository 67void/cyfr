# cyfr
### a ciphering machine

a cipher (or cypher) is an algorithm for performing encryption or decryption

---
## ciphers used:

> A 1 - Caesar

> B 2 - Rail-fence

> C 3 - Vigenere

> D 4 - Reverse Vigenere

> E 5 - Reverse Caesar

> F  6 - ASCII

> G 7 - Morse
---

## Cyfr Key Format:
```
at the  beginning of output:

xyyyyyZ

x     = A to G (which cipher used)            [A-G]
yyyyy = additional details (such as key)      []
Z     = proof of sign that its coded on cyfr  [Z]

```
---

## Cyfr Process:
> Encoding
 
    - Enter which cipher (the actual encoding process) you want to use from the list of ciphers above.
    - Enter your input.
    - Cyfr ciphers your input puts the Cyfr key at front.

> Decoding

    - Enter the text which needs to be decoded.
    - Using the Cyfr key, Cyfr automatically knows which ciphers decode.
    - Cyfr converts from input language to English and then decodes the ciphers.
    