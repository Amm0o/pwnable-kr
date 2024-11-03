# How did we reach the conclusion that we need to device the hash by 5?

So we devide the hash by 5 because check_password will be the result of the sum of 5 4byte values into res var


0x21DD09EC / 5 = 0x06C5CEC8

Now if we multiply the result * 5 we see that the result does not equal the hash value we are comparing to:

0x06C5CEC8 * 5 = 0x21DD09E8

0x21DD09E8 != 0x21DD09EC 

So what we do is just use the 4 values and calculate the remainder:

0x21DD09EC - (0x06C5CEC8 * 4) = 0x06C5CECC

So now we need the 5 values we need to passinto the function to get to the hashvalue of 0x21DD09EC>
0x06C5CEC8 * 4 +  0x06C5CECC = 0x21DD09EC


# How do we actually pass this value into the program?

Since the system will interpret these bytes in reverse order we the need to flip the values from little endian to big endian:
0x06C5CEC8 = \xc8\xce\xc5\x06
0x06C5CECC = \xcc\xce\xc5\x06

> The check_password function casts the input (argv[1]) to an integer pointer (int* ip = (int*)p;), so it processes each 4-byte chunk of the input string as an integer. If we don’t flip the values before inputting them, the check_password function would interpret the values incorrectly due to the little-endian storage order.

We represent the 5 4 bytes inputs in the following format xNN because each \xNN means a single byte therefore '\xc8\xce\xc5\x06' means a 4 byte digit where each xNN is a byte.

