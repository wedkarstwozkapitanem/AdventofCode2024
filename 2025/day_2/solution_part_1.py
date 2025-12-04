##############################
# Dominik Łempicki (kapitan) #
##############################

dane = input().split(",")

suma = int(0)


def validowana(a):
    if len(a) % 2 != 0:
        return False
    sr1 = a[:len(a)//2]
    sr2 = a[len(a)//2:]
    if sr1 == sr2:
        return True
    return False
    

for i  in dane:
    p = i.split("-")
    if len(p) != 2:
        continue

    for px in range(int(p[0]),int(p[1])+1):
        pxs = str(px)
        if validowana(pxs):
            suma += px
        
print(suma)