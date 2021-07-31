dict = {}

def averageAll():
    sumMath = sum(d['Matematika'] for d in dict.values() if d)
    sumIpa = sum(d['Ilmu Pengetahuan Alam'] for d in dict.values() if d)
    sumIng = sum(d['Bahasa Inggris'] for d in dict.values() if d)
    sumInd = sum(d['Bahasa Indonesia'] for d in dict.values() if d)

    temp = list(dict.items())

    avgAll = (sumMath + sumIpa + sumIng + sumInd)/(4*len(temp))
    avgAll = float(avgAll)
    print("Rata-Rata Nilai Seluruh Siswa Adalah =>", avgAll,'\n')

def average1(name):
    math = dict[name]['Matematika']
    ipa = dict[name]['Ilmu Pengetahuan Alam']
    ing = dict[name]['Bahasa Inggris']
    ind = dict[name]['Bahasa Indonesia']
    avg = (math + ipa + ing + ind)/4
    avg = float(avg)
    print("Rata-rata Nilai", name, "Adalah =>", avg, '\n')

def tampilNilaiAll():
    for nama, nilai in dict.items():
        print("\nNama :", nama)

        for key in nilai:
            print(key + ':', nilai[key])
    averageAll()
    return main()

def tampilNilai(namaSiswa):
    try:
        print(dict[namaSiswa])
        average1(namaSiswa)
    except KeyError:
        print("Siswa nya gk ada gaes...")
    return main()

def inputNilai():
    name = input("Nama Siswa : ")
    NMath = int(input("Nilai Matematika : "))
    NIpa = int(input("Nilai IPA : "))
    NIng = int(input("Nilai Bahasa Inggris : "))
    NInd = int(input("Nilai Bahasa Indonesia : "))
    dict[name] = {'Matematika' : NMath, 'Ilmu Pengetahuan Alam' : NIpa, 'Bahasa Inggris' : NIng, 'Bahasa Indonesia' : NInd}
    print("\nData Terisi!")
    print(dict)

    pilih = input('Ingin Melanjutkan? ( y/n (y default)) : ')
    if pilih == 'y':
        return main()
    elif pilih == 'n':
        exit()
    else:
        return main()


def main():
    print("="*33)
    print("Syaddad Aulia Rahman - 2301956903")
    print("="*33,'\n')
    print('{:=^50}'.format(""))
    print("{:^50}".format("Program Nilai UN SMA"))
    print('{:=^50}'.format(""))
    print("1. Masukkan Nilai")
    print("2. Tampilkan Nilai Semua Siswa")
    print("3. Tampilkan Nilai Siswa")
    print("4. Exit")
    pilih = input("Input Menu: ")
    if pilih == '1':
        inputNilai()
    elif pilih == '2':
        tampilNilaiAll()
    elif pilih == '3':
        nama = input("Nama Siswa : ")
        tampilNilai(nama)
    elif pilih == '4':
        exit()
    else:
        return main()

if '__main__' == __name__:
    main()