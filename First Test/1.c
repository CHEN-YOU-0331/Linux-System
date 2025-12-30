#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define my_assert(test, message) \
    do {                         \
        if (!(test))             \
            return message;      \
    } while (0)
#define my_run_test(test)       \
    do {                        \
        char *message = test(); \
        tests_run++;            \
        if (message)            \
            return message;     \
    } while (0)

#define N 1000

static list_item_t items[N];
static list_t l;

static inline void list_insert_before(list_t *l, list_item_t *before, list_item_t *item)//inline 嵌入：編譯器會嘗試把函式的內容直接「複製並貼上」到呼叫處。
{
    // p 指向「儲存下一個節點地址」的地方
    // 一開始指向 head，因為 head 存著第一個節點的地址
    struct list_item **p;

    // 只要目前的指標所指向的內容不是 before，就繼續找下一個
    // *p 是「目前的節點地址」
    for (p = &l->head; *p != before; p = &(*p)->next);

    // 找到位置了！此時 p 指向的是「前一個節點的 next」或是「l->head」
    item->next = before; // 新節點指向 before
    *p = item;           // 讓原本指向 before 的那個位置，改指向新節點 item
}

static inline size_t list_size(const list_t *l)
{
    size_t size = 0;
    list_item_t *cur = l->head;
    while (cur) {
        size++;
        cur = cur->next;
    }
    return size;
}

static list_t *list_reset(void)
{
    for (size_t i = 0; i < N; i++) {
        items[i].value = i;
        items[i].next = NULL;
    }
    l.head = NULL;
    return &l;
}

static char *test_list(void)
{
    /* Test inserting at the beginning */
    list_reset();
    my_assert(list_size(&l) == 0, "Initial list size is expected to be zero.");
    for (size_t i = 0; i < N; i++)
        list_insert_before(&l, l.head, &items[i]);
    my_assert(list_size(&l) == N, "Final list size should be N");
    size_t k = N - 1;
    list_item_t *cur = l.head;
    while (cur) {
        my_assert(cur->value == k, "Unexpected list item value");
        k--;
        cur = cur->next;
    }

    /* Test inserting at the end */
    list_reset();
    my_assert(list_size(&l) == 0, "Initial list size is expected to be zero.");
    for (size_t i = 0; i < N; i++)
        list_insert_before(&l, NULL, &items[i]);
    my_assert(list_size(&l) == N, "Final list size should be N");
    k = 0;
    cur = l.head;
    while (cur) {
        my_assert(cur->value == k, "Unexpected list item value");
        k++;
        cur = cur->next;
    }

    /* Reset the list and insert elements in order (i.e. at the end) */
    list_reset();
    my_assert(list_size(&l) == 0, "Initial list size is expected to be zero.");
    for (size_t i = 0; i < N; i++)
        list_insert_before(&l, NULL, &items[i]);
    my_assert(list_size(&l) == N, "list size should be N");

    return NULL;
}

int tests_run = 0;

static char *test_suite(void)
{
    my_run_test(test_list);
    return NULL;
}

int main(void)
{
    printf("---=[ List tests\n");
    char *result = test_suite();
    if (result)
        printf("ERROR: %s\n", result);
    else
        printf("ALL TESTS PASSED\n");
    printf("Tests run: %d\n", tests_run);
    return !!result;
}
