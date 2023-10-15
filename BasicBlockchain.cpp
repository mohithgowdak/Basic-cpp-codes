#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

class Block {
private:
    int index;
    std::string data;
    std::string previousHash;
    std::string hash;
    time_t timestamp;

    std::string calculateHash(const std::string& data, const std::string& previousHash, const time_t& timestamp, const int& index) {
        std::stringstream ss;
        ss << data << previousHash << timestamp << index;
        std::string input = ss.str();

        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, input.c_str(), input.length());
        SHA256_Final(hash, &sha256);

        std::stringstream ss2;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss2 << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }

        return ss2.str();
    }

public:
    Block(int idx, const std::string& d, const std::string& prevHash) {
        index = idx;
        data = d;
        previousHash = prevHash;
        timestamp = time(nullptr);
        hash = calculateHash(data, previousHash, timestamp, index);
    }

    std::string getHash() const {
        return hash;
    }

    std::string getPreviousHash() const {
        return previousHash;
    }
};

class Blockchain {
private:
    std::vector<Block> chain;

public:
    Blockchain() {
        chain.emplace_back(Block(0, "Genesis Block", "0"));
    }

    void addBlock(const std::string& data) {
        int idx = chain.size();
        std::string prevHash = chain[idx - 1].getHash();
        chain.emplace_back(Block(idx, data, prevHash));
    }

    void printChain() const {
        for (const auto& block : chain) {
            std::cout << "Block Index: " << block.getIndex() << std::endl;
            std::cout << "Block Data: " << block.getData() << std::endl;
            std::cout << "Block Timestamp: " << asctime(localtime(&block.getTimestamp()));
            std::cout << "Block Hash: " << block.getHash() << std::endl;
            std::cout << "Previous Hash: " << block.getPreviousHash() << "\n" << std::endl;
        }
    }
};

int main() {
    Blockchain blockchain;
    blockchain.addBlock("Transaction Data 1");
    blockchain.addBlock("Transaction Data 2");
    blockchain.printChain();
    return 0;
}
