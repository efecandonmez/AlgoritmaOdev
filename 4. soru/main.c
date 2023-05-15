#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Kuyruk oluşturma
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Kuyruğa eleman ekleme
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    printf("Eleman eklendi: %d\n", data);
}

// Kuyruktan eleman çıkarma
void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    
    Node* temp = queue->front;
    int data = temp->data;
    
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    
    free(temp);
    printf("Cikarilan eleman: %d\n", data);
}

// Kuyruğu görüntüleme
void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    
    Node* current = queue->front;
    printf("Kuyruk: ");
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    int choice, value;
    
    do {
        printf("\nLutfen asagidaki islemlerden birini seciniz:\n");
        printf("1. Ekleme\n2. Silme\n3. Goruntuleme\n4. Cikis\nSeciminiz: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Eklemek istediginiz degeri giriniz: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
                
            case 2:
                dequeue(queue);
                break;
                
            case 3:
                displayQueue(queue);
                break;
                
            case 4:
                printf("Program sonlandiriliyor.\n");
                break;
                
            default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}
