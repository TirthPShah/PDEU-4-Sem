int main() {
    
    struct Node* first = NULL;
    struct Node* second = NULL;

    int n, value;

    printf("Enter the first number: ");
    scanf("%d", &n);

    while (n != 0) {

        value = n % 10;
        first = addNode(first, value);
        n /= 10;

    }

    printf("Enter the second number: ");
    scanf("%d", &n);

    while (n != 0) {

        value = n % 10;
        second = addNode(second, value);
        n /= 10;

    }

    printf("First number: ");
    printList(first);

    printf("Second number: ");
    printList(second);

    struct Node* result = addLists(first, second);

    printf("Result: ");
    printList(result);

    return 0;
}