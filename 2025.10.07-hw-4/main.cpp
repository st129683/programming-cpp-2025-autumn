class StringRangeProxy {

private:
    const String& str;
    int start_index;
    
public:
    StringRangeProxy(const String& s, int i) : str(s), start_index(i) {}
    
    String operator[](int end_index) const {
        if (start_index == end_index) {
            return String("");
        }
        
        int length = end_index - start_index;
        
        char* temp = new char[length + 1];
        
        for (int k = 0; k < length; k++) {
            temp[k] = str[start_index + k];
        }
        temp[length] = '\0';
        
        String result(temp);
        delete[] temp;
        return result;
    }
};

StringRangeProxy String::operator[](int i) const {
    return StringRangeProxy(*this, i);
}
