def extended_eucluid (m, b):
    b = b % m
    a1, a2, a3 = 1, 0, m
    b1, b2, b3 = 0, 1, b
    while 1:
        if b3 == 0:
            return "IMPOSSIBLE"
        if b3 == 1:
            return b2
        q = int(a3 / b3)
        t1, t2, t3 = a1 - q*b1, a2 - q*b2, a3 - q*b3
        a1, a2, a3 = b1, b2, b3
        b1, b2, b3 = t1, t2, t3

in1, in2 =map(int,input().split())
a = (extended_eucluid(in1, in2))
if a == "IMPOSSIBLE":
    print(a)
else:
    while a < 0:
        a = a + in1
    additive = in1 - in2
    while additive < 0:
        additive = additive + in1
    print(additive, " ", a)