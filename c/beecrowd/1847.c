#include <stdbool.h>
#include <stdio.h>

// a > b
// If the temperature decreased from the 1st to the 2nd day, but increased or remained constant from the 2nd to the 3rd, the people are happy (first figure).
// If the temperature decreased from the 1st to the 2nd day and from the 2nd to the 3rd, but decreased from the 2nd to the 3rd less than what had decreased from the 1st to the 2nd, the people are happy (fifth figure).
// If the temperature decreased from the 1st to the 2nd day and from the 2nd to the 3rd, but decreased from the 2nd to the 3rd at least what had decreased from the 1st to the 2nd, the people are sad (sixth figure).

// b>a
// If the temperature increased from the 1st to the 2nd day, but decreased or remained constant from the 2nd to the 3rd, the people are sad (second figure).
// If the temperature increased from the 1st to the 2nd day and from the 2nd to the 3rd, but increased from the 2nd to the 3rd less than what had increased from the 1st to the 2nd, the people are sad (third figure).
// If the temperature increased from the 1st to the 2nd day and from the 2nd to the 3rd, but increased from the 2nd to the 3rd at least what had increased from the 1st to the 2nd, the people are happy (fourth figure).

// b==a
// If the temperature remained constant from the 1st to the 2nd day, the people are happy if the temperature increased from the 2nd to the 3rd or sad otherwise (respectively, seventh and eighth figures).

int main() {
    bool humour;
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if ((a > b)) {
        if (c >= b)
            humour = true;
        else {
            int d = a - b;
            if ((b - c) < d)
                humour = true;
            else
                humour = false;
        }
    }

    if (b > a) {
        if (c <= b)
            humour = false;
        else {
            int d = b - a;
            if ((c - b) < d)
                humour = false;
            else
                humour = true;
        }
    }
    if (b == a) {
        if (c > b)
            humour = true;
        else
            humour = false;
    }
    printf("%s\n", humour ? ":)" : ":(");

    return 0;
}