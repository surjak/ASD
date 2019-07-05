#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point
{
    int x, y;
} point;

typedef struct queue
{
    int start, end, size;
    point **elements;
} queue;

queue *new_queue(int size)
{

    queue *points = (queue *)malloc(sizeof(queue));
    points->elements = (point **)malloc(size*sizeof(point *));
    points->size = size;
    points->start = 0;
    points->end = 0;
    return points;
}

void delete_queue(queue *q)
{

    free(q->elements);
    free(q);
}

void put(queue *q, point *value)
{

    point *p = (point *)malloc(sizeof(point));
    p->x = value->x;
    p->y = value->y;
    q->elements[q->end] = p;
    q->end++;
    if (q->end == q->size)
        q->end = 0;
}

point *get(queue *q)
{

    q->start++;
    if (q->start == q->size)
    {
        q->start = 0;
        return q->elements[q->size - 1];
    }
    return q->elements[q->start - 1];
}

bool is_empty(queue *q)
{
    return (q->start == q->end);
}

void fill(int **image, int n, int x, int y, int color)
{

    queue *points = new_queue(n * n);
    point *tmp = (point *)malloc(sizeof(point));
    tmp->x = x;
    tmp->y = y;
    put(points, tmp);
    while (!is_empty(points))
    {
        tmp = get(points);
        if (image[tmp->x][tmp->y] == 0)
        {
            image[tmp->x][tmp->y] = color;
            if (tmp->x != 0)
            {
                tmp->x--;
                put(points, tmp);
                tmp->x++;
            }
            if (tmp->x != n - 1)
            {

                tmp->x++;
                put(points, tmp);
                tmp->x--;
            }
            if (tmp->y != 0)
            {

                tmp->y--;
                put(points, tmp);
                tmp->y++;
            }
            if (tmp->y != n - 1)
            {
                tmp->y++;
                put(points, tmp);
                tmp->y--;
            }
        }
    }
    delete_queue(points);
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int **image = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        image[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    int x, y, color;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &color);
        fill(image, n, x, y, color);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", image[i][j]);
        }
        printf("\n");
        free(image[i]);
    }
    free(image);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// typedef struct stack
// {
//     int *elements;
//     int top;
//     int max_size;
// } stack;

// void push(stack *s, int n)
// {
//     s->elements[s->top] = n;
//     s->top++;
// }

// int pop(stack *s)
// {
//     s->top--;
//     return s->elements[s->top];
// }

// bool is_empty(stack *s)
// {
//     return (s->top == 0);
// }

// stack *new_stack(int size)
// {
//     stack *s = (stack *)malloc(sizeof(stack));
//     s->elements = (int *)malloc(size * sizeof(int));
//     s->max_size = size;
//     s->top = 0;
//     return s;
// }

// void delete_stack(stack *s)
// {
//     free(s->elements);
//     free(s);
// }

// int main()
// {
//     int size;
//     scanf("%d", &size);

//     stack *s = new_stack(size);
//     int tmp;
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &tmp);
//         push(s, tmp);
//     }

//     while (!is_empty(s))
//         printf("%d\n", pop(s));
//     delete_stack(s);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// typedef struct stack
// {
//     int *elements;
//     int top;
//     int max_size;
// } stack;

// void push(stack *s, int n)
// {
//     s->elements[s->top] = n;
//     s->top++;
// }

// int pop(stack *s)
// {
//     s->top--;
//     return s->elements[s->top];
// }

// bool is_empty(stack *s)
// {
//     return (s->top == 0);
// }

// stack *new_stack(int size)
// {
//     stack *s = (stack *)malloc(sizeof(stack));
//     s->elements = (int *)malloc(size * sizeof(int));
//     s->max_size = size;
//     s->top = 0;
//     return s;
// }

// void delete_stack(stack *s)
// {
//     free(s->elements);
//     free(s);
// }

// typedef enum entry_type
// {
//     number,
//     add,
//     subtract,
//     multiply,
//     divide
// } entry_type;

// entry_type parse(char *raw)
// {
//     if (raw[0] == '+')
//         return add;
//     if (raw[0] == '-')
//         return subtract;
//     if (raw[0] == '*')
//         return multiply;
//     if (raw[0] == '/')
//         return divide;
//     return number;
// }

// void do_add(stack *s)
// {
//     int x = pop(s);
//     int y = pop(s);
//     push(s, x + y);
// }

// void do_subtract(stack *s)
// {
//     int x = pop(s);
//     int y = pop(s);
//     push(s, y - x);
// }

// void do_multiply(stack *s)
// {
//     int x = pop(s);
//     int y = pop(s);
//     push(s, x * y);
// }

// void do_divide(stack *s)
// {
//     int x = pop(s);
//     int y = pop(s);
//     push(s, y / x);
// }

// int read_and_calculate(int operands_count, int max_entry_size)
// {
//     stack *operands = new_stack(operands_count);
//     char *entry = malloc((max_entry_size + 1) * sizeof(char));
//     int j = 0;
//     while (j < 2 * operands_count - 1)
//     {
//         for (int i = 0; i < max_entry_size; i++)
//             entry[i] = '\0';
//         scanf("%s", entry);
//         entry_type rodzaj = parse(entry);
//         if (rodzaj == number)
//             push(operands, atoi(entry));
//         else if (rodzaj == add)
//             do_add(operands);
//         else if (rodzaj == subtract)
//             do_subtract(operands);
//         else if (rodzaj == multiply)
//             do_multiply(operands);
//         else
//             do_divide(operands);
//         j++;
//     }
//     int result = pop(operands);
//     delete_stack(operands);
//     free(entry);
//     return result;
// }

// int main()
// {
//     int operands_count, max_entry_size;
//     scanf("%d", &operands_count);
//     scanf("%d", &max_entry_size);
//     printf("%d\n", read_and_calculate(operands_count, max_entry_size));
// }
