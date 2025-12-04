##############################
# Dominik Łempicki (kapitan) #
##############################

dane = input().split(",")

suma = int(0)



def validowana(a):
    for i in range(1,len(a)):
        if len(a) % i == 0:
            p = a[:i]
            ok = True
            for x in range(i,len(a),i):
                if p != a[x:x+i]:
                    ok = False
                    break
            if ok:
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
print(validowana("824824824"))
