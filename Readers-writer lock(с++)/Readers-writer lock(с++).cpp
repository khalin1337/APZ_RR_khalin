#include <iostream>
#include <mutex>
#include <condition_variable>

class ReadersWriterLock {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int readers;
    bool writer;

public:
    ReadersWriterLock() : readers(0), writer(false) {}

    void lockRead() {
        std::unique_lock<std::mutex> lock(mtx);
        while (writer) {
            cv.wait(lock);
        }
        readers++;
    }

    void unlockRead() {
        std::unique_lock<std::mutex> lock(mtx);
        readers--;
        if (readers == 0) {
            cv.notify_one();
        }
    }

    void lockWrite() {
        std::unique_lock<std::mutex> lock(mtx);
        while (writer || readers > 0) {
            cv.wait(lock);
        }
        writer = true;
    }

    void unlockWrite() {
        std::unique_lock<std::mutex> lock(mtx);
        writer = false;
        cv.notify_all();
    }
};

int main() {
    ReadersWriterLock rwLock;

    // Пример использования для чтения
    rwLock.lockRead();
    std::cout << "Reading data..." << std::endl;
    // Чтение данных
    rwLock.unlockRead();

    // Пример использования для записи
    rwLock.lockWrite();
    std::cout << "Writing data..." << std::endl;
    // Запись данных
    rwLock.unlockWrite();

    return 0;
}
