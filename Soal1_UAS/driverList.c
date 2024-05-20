#include "boolean.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// Deklarasi struktur node
typedef struct Node
{
    int wkwk;
    struct Node *next;
} Node;

// Fungsi untuk menampilkan isi linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d|%p -> ", node->wkwk, node->next);
        node = node->next;
    }
    printf("NULL\n");
}

// Fungsi untuk menghitung jumlah elemen dalam linked list
int countNodes(Node *node)
{
    int count = 0;
    while (node != NULL)
    {
        count++;
        node = node->next;
    }
    return count;
}

// Fungsi untuk memasukkan elemen baru pada awal linked list
Node *insertAtBeginning(Node *head, int wkwk)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->wkwk = wkwk;
    newNode->next = head;
    head = newNode;
    return head;
}

// Fungsi untuk memasukkan elemen baru pada akhir linked list
Node *insertAtEnd(Node *head, int wkwk)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->wkwk = wkwk;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Fungsi untuk memasukkan elemen baru setelah suatu elemen pada linked list
Node *insertAfter(Node *head, int key, int wkwk)
{
    Node *temp = head;
    while (temp != NULL && temp->wkwk != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Elemen dengan nilai %d tidak ditemukan dalam linked list\n", key);
        return head;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->wkwk = wkwk;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Fungsi untuk menghapus elemen pada linked list
Node *deleteNode(Node *head, int key)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL && temp->wkwk != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Elemen dengan nilai %d tidak ditemukan dalam linked list\n", key);
        return head;
    }
    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

int main()
{
    int jumlahElemenMaksimum, i, input, pilihanInsert, nilaiInsert, nilaiSetelahnya;
    Node *head = NULL;

    printf("Masukkan jumlah elemen maksimum yang akan di-insert : ");
    scanf("%d", &jumlahElemenMaksimum);

    printf("Silahkan masukkan elemen linked list dengan maksimum %d elemen dan tidak boleh angka -99\n", jumlahElemenMaksimum);
    printf("Jika nilai -99 atau sudah melebihi batas maksimum elemen, elemen tidak akan dimasukkan ke dalam linked list\n");

    for (i = 1; i <= jumlahElemenMaksimum; i++)
    {
        printf("Elemen ke-%d : ", i);
        scanf("%d", &input);
        if (input == -99 || i > jumlahElemenMaksimum)
        {
            break;
        }
        head = insertAtEnd(head, input);
    }

    printf("Isi Linked List : ");
    printList(head);
    printf("Jumlah Elemen Linked List : %d\n", countNodes(head));

    while (1)
    {
        printf("\nMENU OPERASI LINKED LIST : \n");
        printf("1. INSERT LIST \n");
        printf("2. DELETE LIST \n");
        printf("Masukkan pilihan (1/2) : ");
        scanf("%d", &input);

        if (input == 1)
        {
            printf("\nMENU INSERT LINKED LIST:\n");
            printf("11. INSERT FIRST ELEMENT\n");
            printf("12. INSERT LAST ELEMENT\n");
            printf("13. INSERT AFTER ELEMENT\n");
            printf("Masukkan pilihan insert (11/12/13) : ");
            scanf("%d", &pilihanInsert);

            switch (pilihanInsert)
            {
            case 11:
                printf("\nMasukkan elemen yang akan di-insert : ");
                scanf("%d", &nilaiInsert);
                head = insertAtBeginning(head, nilaiInsert);
                printf("Isi Linked List : ");
                printList(head);
                printf("Jumlah Elemen Linked List : %d\n", countNodes(head));
                break;
            case 12:
                printf("\nMasukkan elemen yang akan di-insert : ");
                scanf("%d", &nilaiInsert);
                head = insertAtEnd(head, nilaiInsert);
                printf("Isi Linked List : ");
                printList(head);
                printf("Jumlah Elemen Linked List : %d\n", countNodes(head));
                break;
            case 13:
                printf("\nMasukkan nilai elemen yang ingin ditambahkan setelahnya : ");
                scanf("%d", &nilaiSetelahnya);
                printf("Masukkan elemen yang akan di-insert : ");
                scanf("%d", &nilaiInsert);
                head = insertAfter(head, nilaiSetelahnya, nilaiInsert);
                printf("Isi Linked List : ");
                printList(head);
                printf("Jumlah Elemen Linked List : %d\n", countNodes(head));
                break;
            default:
                printf("\nPilihan tidak sesuai, program keluar.\n");
                exit(0);
            }
        }
        else if (input == 2)
        {
            printf("\nMasukkan nilai elemen yang ingin dihapus : ");
            scanf("%d", &nilaiInsert);
            head = deleteNode(head, nilaiInsert);
            printf("Isi Linked List : ");
            printList(head);
            printf("Jumlah Elemen Linked List : %d\n", countNodes(head));
        }
        else
        {
            printf("\nPilihan tidak sesuai, program keluar.\n");
            exit(0);
        }
    }

    return 0;
}