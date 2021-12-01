#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void bubblesort() {
    int i, j, a[50], n, temp;
    printf("\nBubble sort\n");
    printf("Enter size of array\t");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter the %d element : " , i+1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nSorted array is\t");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}

void selectionsort() {
    int i, j, a[50], n, min;
    printf("Selection sort\n");
    printf("\nEnter size of array\t");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter the %d element : " , i+1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++) {
                min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        if (i < min) {
            int temp;
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    printf("\nSorted array is\t");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}

int main() {
    //pid_t pid;
    //pid=fork
    if (fork() == 0) {
        printf("\nchild process\n");
        printf("child process id=%d\n",getpid());
        bubblesort();
    } else {
        wait(NULL);
        printf("\nparent process\n");
        printf("\nparent process id=%d\n",getppid());
        selectionsort();
    }
    return 0;
}
