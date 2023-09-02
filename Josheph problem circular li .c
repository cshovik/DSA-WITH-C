#include <stdio.h>
#include <stdlib.h>

struct node
{
    int player_id;
    struct node *next;
};

struct node *start, *ptr, *new_node;

int main()
{
    int n, k, i, count;

    printf("Enter the number of Players: ");
    scanf("%d", &n);
    printf("Enter the value of k (Every kth player will get eliminated): ");
    scanf("%d", &k);

    start = malloc(sizeof(struct node));
    start->player_id = 1;
    ptr = start;

    for (i = 2; i <= n; i++)
    {
        new_node = malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->player_id = i;
        new_node->next = start;
        ptr = new_node;
    }

    ptr->next = start;

    while (ptr->next != ptr)
    {
        for (count = 1; count < k; count++)
        {
            ptr = ptr->next;
        }
        struct node *temp = ptr->next;
        ptr->next = temp->next;
        printf("%d deleted\n", temp->player_id);
        free(temp);
    }

    printf("The winner is player %d\n", ptr->player_id);

    free(ptr); //ptr should free to reduce memory leak at last and proper memory management

    return 0;
}
