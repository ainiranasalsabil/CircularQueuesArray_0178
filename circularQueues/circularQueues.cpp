#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        //cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            // jika rear berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove() {
        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queues undeflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is:" << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            //jika element yang dihapus berada diposisi terakhir array,, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
    void display() {

        int FRONT_POSITION = FRONT;
        int REAR_POSITION = REAR;

        // cek apakah antrian kosong
        if (FRONT_POSITION == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElement is the queue are...\n";

        // jika FRONT <= REAR, iterasi dari FRONT hingga REAR 
        if (FRONT_POSITION <= REAR_POSITION) {
            while (FRONT_POSITION <= REAR_POSITION) {
                cout << queue_array[FRONT_POSITION] << "  ";
                FRONT_POSITION++;
            }
            cout << endl;
        }
        else //jika FRONT > REAR, iterasi dari FRONT hingga akhir array
            while (FRONT_POSITION <= max - 1) {
                cout << queue_array[FRONT_POSITION] << "  ";
            }

        