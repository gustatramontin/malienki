#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

struct list_node_t {
	int value;
	struct list_node_t * next;

};

typedef struct list_node_t list_node ;

int get(list_node * l, int i) {
	if (i == 0 )
		return l->value;
	return get(l->next, i-1);
}

void insert(list_node * l, int value) {

	list_node * list = l;
	while (list->next != NULL) {
		list = list->next;
	}
	list_node * new_list = NEW(list_node, 1);// malloc(sizeof(list_node)); 
        new_list->value = value;
	list->next = new_list;
}

#define INSERT_MANY(list, args...) {\
    int values[] = {args}; \
    for (int i = 0; i< sizeof(values)/sizeof(int); i++) { \
        insert(list, values[i]);\
    }\
}


list_node new_list(int value) {
	list_node l = { value , NULL };
	return l;
}

void delete(list_node * list, int i) {
    if (i == 1) {
        list_node * old_node = list->next;
        list->next = list->next->next;

        free(old_node);
        return;
    }

    if (list->next == NULL) {
        return;
    }

    delete(list->next, i-1);
}


void print_list(list_node * list) {
    while (list->next != NULL) {
        printf("[ %d ] -> ", list->value);
        list = list->next;
    }
    printf("[ %d ]\n", list->value);
}


int main() {
	list_node my_list = new_list(3);

	
	insert(&my_list, 5);
	insert(&my_list, 8);

        INSERT_MANY(&my_list, 1,2,3,4);


	printf("%d\n", get(&my_list, 3));
        print_list(&my_list);
        delete(&my_list, 2);

        print_list(&my_list);
	//printf("%d", my_list.next);
}
