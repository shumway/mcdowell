#include <cstdlib>
#include <iostream>
#include <string>

class CompressedString {
public:

  CompressedString(std::string& s)
  : n(s.size()), s(s) {
  }

  void Compress() {
    if (is_compressed) {
      return;
    }
    auto compressed_size = MeasureCompressedSize();
    if (compressed_size < s.size()) {
      CompressInPlace(compressed_size);
      is_compressed = true;
    }
  }

  void Inflate() {
    if (!is_compressed) {
      return;
    }
    auto iterw = s.rbegin();
    auto iterr = std::make_reverse_iterator(s.begin() + n);
    std::string multiplier = "";
    for (; iterr != s.rend(); ++iterr) {
      if (isalpha(*iterr)) {
        // Repeat previous character if we had a multiplier
        auto factor = std::strtol(multiplier.c_str(), nullptr, 0);
        for (int i = 0; i < factor; ++i) {
          *iterw++ = *iterr;
        }
        multiplier = "";
      }
      else {
       multiplier = *iterr + multiplier;
      }
    }
    is_compressed = false;
  };

  size_t GetCompressedSize() const {
    return n;
  }

private:
  size_t n;
  std::string& s;
  bool is_compressed = false;

  size_t MeasureCompressedSize() const {
    size_t compressed_size = 0u;
    int multiplier = 1;
    char prev_char = '\0';
    for (auto c: s) {
      if (c == prev_char) {
        multiplier += 1;
      } 
      else {
        if (multiplier > 1) {
          compressed_size += std::to_string(multiplier).size();
        }
        ++compressed_size;
        multiplier = 1;
        prev_char = c;
      }
    }
    if (multiplier > 1) {
      compressed_size += std::to_string(multiplier).size();
    }
    return compressed_size;
  }

  void CompressInPlace(size_t compressed_size) {
    n = compressed_size;
    auto iterr = s.begin();
    auto iterw = s.begin();
    int multiplier = 0;
    int prev_char = '\0';
    for (; iterr != s.end(); ++iterr) {
      if (*iterr == prev_char) { 
        ++multiplier;
      }
      else {
        if (multiplier > 0) { 
          *iterw++ = prev_char; 
        }
        if (multiplier > 1) { 
          auto mstring = std::to_string(multiplier);
          for (char c: mstring) {
            *iterw++ = c; 
          }
        }
        prev_char = *iterr;
        multiplier = 1;
      }
    }
    *iterw++ = prev_char; 
    if (multiplier > 1) { 
      auto mstring = std::to_string(multiplier);
      for (char c: mstring) {
        *iterw++ = c; 
      }
    }
  }
};

int main() {
  std::string test = "Non-compressible string";
  std::cout << "'" <<  test << "' -> ";
  CompressedString compressor(test);
  compressor.Compress();
  int n = compressor.GetCompressedSize();
  std::cout << "'" <<  test.substr(0, n) << "' -> ";
  compressor.Inflate();
  std::cout << "'" <<  test << "'" << std::endl;

  test = "xyyyyzzzaaabbbbbbcc";
  std::cout << "'" <<  test << "' -> ";
  CompressedString compressor2(test);
  compressor2.Compress();
  n = compressor2.GetCompressedSize();
  std::cout << "'" <<  test.substr(0, n) << "' -> ";
  compressor2.Inflate();
  std::cout << "'" <<  test << "'" << std::endl;
}
