#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Struktur untuk menyimpan data penumpang
typedef struct {
int id;
char nama[50];
char kereta[50];
} Penumpang;
// Struktur node untuk antrian
typedef struct Node {
Penumpang data;
struct Node* next;
} Node;
// Fungsi untuk menambahkan penumpang ke array (tabel)
void tambahPenumpang(Penumpang* tabel, int* jumlah, int id,
const char* nama, const char* kereta) {
tabel[*jumlah].id = id;
strcpy(tabel[*jumlah].nama, nama);
strcpy(tabel[*jumlah].kereta, kereta);
(*jumlah)++;
}
// Fungsi untuk menampilkan tabel penumpang
void tampilkanPenumpang(Penumpang* tabel, int jumlah) {
printf("ID\tNama\t\tKereta\n");
printf("-------------------------------------\n");
for (int i = 0; i < jumlah; i++) {
printf("%d\t%s\t\t%s\n", tabel[i].id,
tabel[i].nama, tabel[i].kereta);
}
}
// Fungsi untuk membuat node baru untuk antrian
Node* buatNode(Penumpang data) {
Node* nodeBaru = (Node*)malloc(sizeof(Node));
nodeBaru->data = data;
nodeBaru->next = NULL;
return nodeBaru;
}
// Fungsi untuk menambahkan penumpang ke antrian
void enqueue(Node** front, Node** rear, Penumpang data) {
Node* nodeBaru = buatNode(data);
if (*rear == NULL) {
*front = *rear = nodeBaru;
} else {
(*rear)->next = nodeBaru;
*rear = nodeBaru;
}
}
// Fungsi untuk menghapus penumpang dari antrian
Penumpang dequeue(Node** front, Node** rear) {
if (*front == NULL) {
printf("Antrian kosong!\n");
exit(EXIT_FAILURE);
}
Node* nodeHapus = *front;
Penumpang data = nodeHapus->data;
*front = (*front)->next;
if (*front == NULL) {
*rear = NULL;
}
free(nodeHapus);
return data;
}
// Fungsi untuk menampilkan antrian penumpang
void tampilkanAntrian(Node* front) {
printf("Antrian Penumpang:\n");
printf("ID\tNama\t\tKereta\n");
printf("-------------------------------------\n");
while (front != NULL) {
printf("%d\t%s\t\t%s\n", front->data.id,
front->data.nama, front->data.kereta);
front = front->next;
}
}
int main() {
Penumpang tabelPenumpang[100];
int jumlahPenumpang = 0;
// Menambahkan beberapa penumpang ke tabel
tambahPenumpang(tabelPenumpang, &jumlahPenumpang, 1,
"Budi", "Kereta A");
tambahPenumpang(tabelPenumpang, &jumlahPenumpang, 2,
"Ani", "Kereta B");
tambahPenumpang(tabelPenumpang, &jumlahPenumpang, 3,
"Siti", "Kereta C");
// Menampilkan tabel penumpang
printf("Tabel Penumpang:\n");
tampilkanPenumpang(tabelPenumpang, jumlahPenumpang);
// Membuat antrian penumpang
Node* front = NULL;
Node* rear = NULL;
// Menambahkan penumpang ke antrian
enqueue(&front, &rear, tabelPenumpang[0]);
enqueue(&front, &rear, tabelPenumpang[1]);
enqueue(&front, &rear, tabelPenumpang[2]);
// Menampilkan antrian penumpang
tampilkanAntrian(front);
// Mengeluarkan penumpang dari antrian
Penumpang penumpangKeluar = dequeue(&front, &rear);
printf("\nPenumpang keluar dari antrian:\n");
printf("%d\t%s\t\t%s\n", penumpangKeluar.id,
penumpangKeluar.nama, penumpangKeluar.kereta);
// Menampilkan antrian setelah penumpang keluar
printf("\nAntrian setelah satu penumpang keluar:\n");
tampilkanAntrian(front);
return 0;
}
