#!/usr/bin/python3.7

minta = int(input())
angka = 2
total = 0
while minta != total:
    prima = True
    for i in range(2, angka):
        if angka % i == 0:
            prima = False
            break
    if prima == True:
        print(angka, end='')
        total += 1
        if(total<minta):
            print("-", end='')
    angka += 1
