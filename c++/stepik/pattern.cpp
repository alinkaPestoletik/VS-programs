int pattern(char *text, char *pattern) {
    int i = 0;
    int j = 0;
    int result = 0;
    if (text == pattern || *pattern == '\0') return 0;
    while (pattern[i] != '\0') {
        if (text[j] == '\0') {
            result = -1;
            break;
        }
        if (text[j+i] == pattern[i]) {
            i++; result = j;
        }
        else { 
            j++; i = 0; 
        }
    }
    return result;
}
