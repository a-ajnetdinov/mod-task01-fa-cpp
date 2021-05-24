unsigned int faStr1(const char *str)
{
    bool inWord = false;
    bool isWordContainDigit = false;
    unsigned int cnt = 0;
    while (*str) {
        if (*str != ' ' && inWord == false) {
            inWord = true;
        }
        else if (*str == ' ' && inWord == true) {
            inWord = false;
            if (!isWordContainDigit)
                cnt++;
            isWordContainDigit = false;
        }
        if (inWord && !isWordContainDigit) {
            if (isdigit(*str))
                isWordContainDigit = true;
        }
        *str++;
    }
    return cnt;
}
unsigned int faStr2(const char *str)
{
    unsigned int faStr2(const char *str) {
    bool inWord = false;
    bool isFirstLetter = false;
    bool isWordOK = true;
    unsigned int cnt = 0;
    while (*str) {
        if (*str != ' ' && inWord == false) {
            if(!isalpha(*str) || !isupper(*str))
                isWordOK = false;
            inWord = true;
            isFirstLetter = true;
        }
        else if (*str == ' ' && inWord == true) {
            inWord = false;
            if (isWordOK)
                cnt++;
            isWordOK = true;
        }
        if (inWord && isWordOK) {
            if (isFirstLetter) isFirstLetter = false;
            else if (!isalpha(*str) || isupper(*str)) {
                isWordOK = false;
            }
        }
        *str++;
    }
    return cnt;
}
unsigned int faStr3(const char *str)
{
    bool inWord = false;
    unsigned int wordCount = 0;
    unsigned int wordSumLen = 0;
    while (*str) {
        if (*str != ' ' && inWord == false) {
            inWord = true;
            wordCount++;
            wordSumLen++;
        }
        else if (*str == ' ' && inWord == true) {
            inWord = false;
        }
        else if (*str != ' ' && inWord == true) {
            wordSumLen++;
        }
        *str++;
    }
    return (unsigned int)round(wordSumLen*1.0/wordCount);
}
