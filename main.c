#include <stdio.h>
#include <math.h>

float f(float p, float q, float c, float x);
int main() {
    float p, q, c, a, b, m;
    int i;
    
    printf("Enter quadratic equation [px^2 + qx + c = 0]: \n");
    printf("Enter p: ");
    scanf("%f", &p);
    printf("Enter q: ");
    scanf("%f", &q);
    printf("Enter c: ");
    scanf("%f", &c);

    printf("Enter limit interval [a, b]: ");
    scanf("%f %f", &a, &b);
    
    printf("The equation involved is f(x) = %.2fx^2 + %.2fx + %.2f on interval [%.2f, %.2f]\n", p, q, c, a, b);

    // for bolzano's thoerem:
    if(f(p, q, c, a) * f(p, q, c, b) < 0 ) {
        printf("A root lies b/w interval [%.2f, %.2f]\n", a, b);
        for(i = 0; i <= 10; i++) {
            if (f(p, q, c, m) == 0) {
                printf("Found root at m=%.2f\n", m);
                i = 41;
            }
            m = (a + b) / 2;
            printf("Iteration #%d: a=%.6f, b=%.6f, m=%.6f, f(m)=%.6f\n", i, a, b, m, f(p, q, c, m));
            
            if(f(p, q, c, m) > 0) b = m;
            if(f(p, q, c, m) < 0) a = m;
        }
        printf("\nroot = %f", m);
    } else printf("No root lies b/w interval [%.2f, %.2f]\n", a, b);
}

float f(float p, float q, float c, float x) {
    return (p * x * x) + (q * x) + c;
}