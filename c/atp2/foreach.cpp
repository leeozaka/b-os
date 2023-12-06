#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "hello world!";
    for (auto &c : str)
        if (c == 'h' || c == 'w') c=toupper(c);
    puts(str);
    return 0;
}
