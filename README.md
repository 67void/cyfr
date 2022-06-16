# cyfr
### a ciphering machine
---
## ciphers used:

> A - Caesar [replacing letters with offset letters]

> B - Numerical [replacing letters with numbers]

> C - Pig Latin

> D - Affine

> E - Rail-fence

> F - Vigenere

> G - Reverse Vigenere

> H - Reverse Rail-fence

> I - Reverse Affine

> J - Reverse Rail-fence

> K - Reverse Pig Latin

> L - Reverse Numerical

> M - Reverse Caesar


---
## Cyfr Key Format:
```
at the  beginning of output:

wwwxyyyyyZ

www   = output language which its ciphered in [065,010,.--]
x     = A to M (which cipher used)            [A-M]
yyyyy = additional details                    []
Z     = proof of sign that its coded on cyfr  [Z]

at end of output:

ddmmyybbxxZ

dd    = date                                  [01-31]
mm    = month                                 [JA,FE,MA,AP,MY, JU,JY,AU,OC,NO,DE]
yy    = year                                  [00-99]
bb    = day                                   [MO,TU,WE,TH,FR,SA,ST]
xx    = which cipher used            [A-M]
Z     = proof of sign that its coded on cyfr  [Z]
```
---

## Cyfr Process:
> Encoding

    - Enter which language you want output to be in [ASCII, Binary, Morse or English]
    - Enter which cipher (the actual encoding process) you want to use from the list of ciphers above
    - Enter your input
    - Cyfr first ciphers your input then converts to choosen language and puts the Cyfr key.

> Decoding

    - Enter the text which needs to be decoded
    - Using the Cyfr key, Cyfr automatically knows which ciphers and language to use decode
    - Cyfr converts from input language to English and then decodes the ciphers.
    