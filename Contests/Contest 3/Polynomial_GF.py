import math


def addition(f, g):
    output = ""
    for i in range(8):
        output = output + str(((int(f[i])+int(g[i])) % 2))
    return '{0:{fill}2x}'.format(int(output, 2), fill='0').upper()


def multiply(f, g):
    res = 0
    calcs = []
    calcs.append(f)
    for i in range(1, 8):
        if calcs[i-1][0] == '1':
            calcs.append("{0:{fill}8b}".format(((int(calcs[i-1], 2) << 1) ^ int('00011011', 2)) & 0xff, fill='0'))
        else:
            calcs.append("{0:{fill}8b}".format((int(calcs[i-1], 2) << 1) & 0xff, fill='0'))
    for i in range(8):
        if g[i] == '1':
            res = res ^ int(calcs[7-i], 2)
    return '{0:{fill}2x}'.format(int(res), fill='0').upper()


f_x, g_x = input().split()
f_x = "{0:08b}".format(int(f_x, 16))
g_x = "{0:08b}".format(int(g_x, 16))
print(addition(f_x, g_x), " ", multiply(f_x, g_x))
