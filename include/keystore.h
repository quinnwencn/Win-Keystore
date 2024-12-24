#include <string>
#include <filesystem>
#include <vector>
#include <optional>

namespace Crypto {

class KeyStore {
public:
    static KeyStore& getInstance() {
        static KeyStore keyStore;
        return keyStore;
    }
    
    KeyStore(const KeyStore&) = delete;
    KeyStore(KeyStore&&) = delete;
    KeyStore& operator=(const KeyStore&) = delete;
    KeyStore&& operator=(KeyStore&&) = delete;
    ~KeyStore() = default;

    using KeyId = std::string;

    std::optional<KeyId> storeKey(const std::string& alias, const std::vector<uint8_t>& key);
    std::optional<KeyId> storeKey(const std::string& alias, const uint8_t* data, uint32_t len);
    std::optional<std::vector<uint8_t>> readKey(const std::string& alias);

    bool storePassword(const std::string& site, const std::string& user, const std::string& password);
    std::optional<std::string> readPassword(const std::string& site, const std::string& user);

private:
    KeyStore() = default;

};

}