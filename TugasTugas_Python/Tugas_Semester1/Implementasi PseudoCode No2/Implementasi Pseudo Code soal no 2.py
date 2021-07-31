print("="*33)
print("Syaddad Aulia Rahman - 2301956903")
print("="*33,"\n")

myDict={}
def newAlamat():
    f = open("pengiriman.txt","a+")

    namaPengirim = input("Nama Pengirim : ")
    namaPenerima = input("Nama Penerima : ")
    noHp = input("No HP : ")
    noHpPenerima = input("No HP Penerima: ")
    alamat = input("Alamat : ")
    alamatTujuan = input("Alamat Tujuan : ")

    dict = {'Nama': namaPengirim, 'Alamat': alamat, 'No HP': noHp,'Nama Penerima': namaPenerima, 'No HP Penerima': noHpPenerima, 'Alamat tujuan': alamatTujuan}
    f.write(str(dict))
    f.write("\n")
    f.close()

    print("Input Berhasil", flush=True)
    return main()

def hapus():
    namaPengirim = input("Nama Pengirim yang akan dihapus : ")
    namaPenerima = input("Nama Penerima yang akan dihapus : ")
    noHp = input("No HP yang akan dihapus : ")
    noHpPenerima = input("No HP Penerima yang akan dihapus : ")
    alamat = input("Alamat yang akan dihapus : ")
    alamatTujuan = input("Alamat Tujuan yang akan dihapus : ")
    with open("pengiriman.txt", 'r') as f:
        data = f.readlines()
    dict = {'Nama': namaPengirim, 'Alamat': alamat, 'No HP': noHp, 'Nama Penerima': namaPenerima, 'No HP Penerima': noHpPenerima, 'Alamat tujuan': alamatTujuan}
    str(dict)
    with open("pengiriman.txt", 'w') as f:
        for line in data:
            if line.strip("\n") != str(dict):
                f.write(line)
    f.close()
    return main()

def cetak():
    f = open("pengiriman.txt","r")
    data = f.readlines()
    for line in data:
        print(line)
    f.close()
    return main()

def edit():
    namaPengirim = input("Nama Pengirim yang akan diganti : ")
    namaPengirimbaru = input("Nama Pengirim baru : ")
    namaPenerima = input("Nama Penerima : ")
    noHp = input("No HP yang akan diganti : ")
    noHpbaru = input("No HP baru : ")
    noHpPenerima = input("No HP Penerima : ")
    alamat = input("Alamat Pengirim : ")
    alamatTujuan = input("Alamat Tujuan : ")
    with open("pengiriman.txt", 'r') as f:
        data = f.readlines()
    dict = {'Nama': namaPengirim, 'Alamat': alamat, 'No HP': noHp, 'Nama Penerima': namaPenerima,
            'No HP Penerima': noHpPenerima, 'Alamat tujuan': alamatTujuan}
    str(dict)
    with open("pengiriman.txt", 'w') as f:
        for line in data:
            if line.strip("\n") != str(dict):
                f.write(line)
    f = open("pengiriman.txt", "a+")
    dict = {'Nama': namaPengirimbaru, 'Alamat': alamat, 'No HP': noHpbaru, 'Nama Penerima': namaPenerima, 'No HP Penerima': noHpPenerima, 'Alamat tujuan': alamatTujuan}
    f.write(str(dict))
    f.write("\n")
    return main()
def main():
    print("*"*45)
    print("*"*15+'Naruto Ekspress'+"*"*15)
    print("*"*45,"\n")
    print("Menu : ")
    print("1. Tambah Alamat")
    print("2. Hapus Alamat")
    print("3. Info Pengiriman")
    print("4. Edit Pengiriman")
    pilih =  int(input("Pilih 1/2/3/4 (0 untuk Exit) : "))
    if pilih == 0:
        exit()
    elif pilih == 1:
        newAlamat()
    elif pilih == 2:
        hapus()
    elif pilih == 3:
        cetak()
    elif pilih == 4:
        edit()
    else:
        return main()
if __name__ == '__main__':
    main()