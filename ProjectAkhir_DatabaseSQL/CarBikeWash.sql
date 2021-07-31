create database CarBikeWashAkhir
use CarBikeWashAkhir

create table pegawai(
    id_pegawai varchar(3) NOT NULL PRIMARY KEY,
    nama_pegawai varchar(20) NOT NULL,
    nik_pegawai varchar(20) NOT NULL,
    notlp_pegawai varchar(12),
    gaji int
)

create table pelanggan(
    id_pelanggan varchar(3) NOT NULL PRIMARY KEY,
    nama_pelanggan varchar(20),
    plat_mobil varchar(10),
    plat_motor varchar(10),
)

create table antrianmotor(
    id_pelanggan varchar(3) FOREIGN KEY REFERENCES pelanggan(id_pelanggan),
    plat_motor varchar(10),
    harga_pelayanan int,
    status_lunas char(1)
)

create table antrianmobil(
    id_pelanggan varchar(3) FOREIGN KEY REFERENCES pelanggan(id_pelanggan),
    plat_mobil varchar(10),
    harga_pelayanan int,
    status_lunas char(1)
)

create table histori_transaksi(
    id_pelanggan varchar(3) FOREIGN KEY REFERENCES pelanggan(id_pelanggan),
    id_pegawai varchar(3) FOREIGN KEY REFERENCES pegawai(id_pegawai),
    harga_pelayanan int,
)

insert into pegawai values('AZ1', 'Bagus Saputra', '100210231300', '082113452213', 1500000)
insert into pegawai values('SX2', 'Tatang Purnomo', '100413959343', '081342123145', 1500000)
insert into pegawai values('DC3', 'Sigit Panjaitan', 100511834734, 082542312332, 1500000)

insert into pelanggan values('1A2', 'Bimo', 'B72142AZ', '')
insert into pelanggan values('7H3', 'Satria', '', 'A4183CCV')
insert into pelanggan values('9SB', 'Nino', 'BK2131AS', 'BK3843SSA')

insert into antrianmotor values('7H3', 'A4183CCV', 15000, 'N')
insert into antrianmotor values('9SB', 'BK3843SSA', 20000, 'Y')
insert into antrianmobil values('1A2', 'B72142AZ', 50000, 'Y')
insert into antrianmobil values('9SB', 'BK2131AS', 50000, 'N')

insert into histori_transaksi values('9SB', 'AZ1', 20000)
insert into histori_transaksi values('1A2', 'DC3', 50000)

SELECT * FROM histori_transaksi;

drop database CarBikeWash;