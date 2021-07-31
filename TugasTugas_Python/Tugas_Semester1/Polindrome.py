x = input()
y = x[::-1]
if x==y:
    print('Polindrome')
    print(y)
else:
    print("Not Polindrome")
    print(y)

#another way
'''a[i] == a[n-i-1]'''
'''i = int(input())
for i in range(i):
    print(i)
    a = input('apa')
if (a == a[::-1]):
    print('plindrome')
else:
    print('bukan')'''


'''def reversal(sample):
    new_sample=''
    for i in sample:
        new_sample=i+new_sample
    return new_sample
str=input()
pol=reversal(str)
if str == pol:
    print('polindrome')
else:
    print('not')'''


