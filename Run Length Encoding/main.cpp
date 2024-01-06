std::string encode(std::string src) {
    int start = 0;
    int end = 0;
    std::string encodedString;

    while (end < src.length()) {
        start = end;

        // Find the length of the current run of identical characters
        while (end < src.length() && src[end] == src[start]) {
            end++;
        }

        // Append the character and its count to the encoded string
        encodedString += src[start] + std::to_string(end - start);
    }

    return encodedString;
}
