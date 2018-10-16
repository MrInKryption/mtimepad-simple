import sys

def strxor(a, b):     # xor two strings (trims the longer input)
    return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a, b)])

def random(size=16):
    return open("/dev/urandom").read(size)

def encrypt(key, msg):
    c = strxor(key, msg)
    print c.encode('hex')
    return c

def main():
    message="The "
    cipher1="4b9e17f763379cdaf7141123f09257b49f6e21dcad692bd75e0901a5862698fae762477c2dd4"
    cipher2="4b8417ec76659cddf1111739f49857b39f683cdca6756ede41141fb19c7ddffcb42f497c2d96f435aff311ec65763bccd3dfdaff1d4608cc6f0e7ba117c661e1834afec0f5d72bbe3b"
    resCipher=strxor(cipher1,cipher2)
    n=len(message)
    k=0
    split=[resCipher[i:i+n] for i in range(0, len(resCipher), n)]
    for j in split:
        if k==len(split):
            break
        print strxor(message,split[k])
        k+=1

main()
