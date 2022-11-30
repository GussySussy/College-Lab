struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    struct node *end = head;

    if (end != NULL)
    {
        while (end->link != NULL)
        {
            end = end->link;
        }
        end->link = newNode;
    }
    else
    {
        head = newNode;
    }
    printf("\n--- Insertion is successful ---");