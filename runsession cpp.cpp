#include "RunSession.h"
#include <iostream>

using namespace std;

// Inisialisasi awal saat objek dibuat
RunSession::RunSession() {
    stats = {1, 1, 300, 4, 3, 1000, 0}; 
    isRunning = true;
}

// Menampilkan papan informasi ke terminal
void RunSession::renderUI() {
    cout << "\n===============================" << endl;
    cout << "        CARD STRATEGY SIM       " << endl;
    cout << "===============================" << endl;
    cout << " Level: " << stats.level << " | Round: " << stats.round << endl;
    cout << " Target Skor  : " << stats.targetScore << endl;
    cout << " Skor Saat Ini: " << stats.currentScore << endl;
    cout << "-------------------------------" << endl;
    cout << " Sisa Hands   : " << stats.hands << endl;
    cout << " Sisa Discards: " << stats.discards << endl;
    cout << "===============================" << endl;
}

// Logika saat pemain memilih bermain kartu
void RunSession::playHand() {
    if (stats.hands > 0) {
        stats.hands--;              // Kurangi jatah jalan
        stats.currentScore += 100;  // Tambah skor tetap 100
        cout << ">> Kartu dimainkan! (+100 Skor)" << endl;
    } else {
        cout << ">> Gagal! Sisa 'Hands' kamu habis." << endl;
    }
}

// Logika saat pemain membuang kartu
void RunSession::discardHand() {
    if (stats.discards > 0) {
        stats.discards--;           // Kurangi jatah buang
        cout << ">> Kartu dibuang (Discard)." << endl;
    } else {
        cout << ">> Gagal! Sisa 'Discard' kamu habis." << endl;
    }
}

// Mengecek apakah permainan harus berakhir (Menang/Kalah)
void RunSession::updateState() {
    if (stats.currentScore >= stats.targetScore) {
        cout << "\n*** VICTORY! TARGET TERCAPAI ***" << endl;
        isRunning = false;
    } 
    else if (stats.hands <= 0) {
        cout << "\n*** DEFEAT! KAMU KEHABISAN TANGAN ***" << endl;
        isRunning = false;
    }
}

// Mengembalikan status running ke Main Loop
bool RunSession::isActive() const {
    return isRunning;
}
