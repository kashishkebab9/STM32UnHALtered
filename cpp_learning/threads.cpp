#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void outnum( int n ) {
    static mutex m;
    lock_guard<mutex> g(m);
    cout << "[" << n << "]" << endl;
}

void printnums( int start, int n ) {
    for( int i = 0; i < n; i++ ) {
        outnum( start + i );
    }
}

int main() {
    thread t1( printnums, 0, 100 );
    thread t2( printnums, 1000, 100 );
    t1.join();
    t2.join();
}
