def binsearch(lst, data):
    left = 0
    right = len(lst)-1
    found = False
    while left <= right and not found:
        tengah = (left + right)//2
        if lst[tengah] == data:
            found = True
            break
        else:
            if data < lst[tengah]:
                right = tengah - 1
            else:
                left = tengah + 1
    return found

def sequensearch(lst, data):
    for i in range(0, len(lst)):
        if lst[i] == data:
            print("Angka ditemukan pada index ke-")
            return i
        else:
            print("Not Found")



print("="*33)
print("Syaddad Aulia Rahman - 2301956903")
print("="*33,"\n")

print("Binary Search")
lst = [4, 12, 32, 55, 67, 225, 97]
x = int(input("Masukkan Angka : "))
cond = binsearch(lst, x)
if cond == False:
    print("Not Found")
else:
    print("Angka ditemukan")

print("\nSequential Search")
lst2 = [4, 12, 32, 55, 67, 225, 97]
y = int(input("Masukkan Angka : "))
seq = sequensearch(lst2, y)
print(seq)




