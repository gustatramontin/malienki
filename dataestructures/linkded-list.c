#include <stdio.h>
#include <stdlib.h>

struct ll {
	int value;
	struct ll * next;

	void (*insert)(struct ll *, int);
	int (*get)(struct ll * , int);
};

int get(struct ll * l, int i) {
	if (i == 0 )
		return l->value;
	return get(l->next, i-1);
}

void insert(struct ll * l, int value) {
	struct ll * list = l;
	while (list->next != NULL) {
		list = list->next;
	}
	struct ll * new_list = malloc(sizeof(struct ll)); 
	new_list->value = value;
	new_list->next = NULL;
	new_list->insert = &insert;
	new_list->get = &get;

	list->next = new_list;
}


struct ll new_list(int value) {
	struct ll l = { value , NULL, &insert, &get };
	return l;
}



int main() {
	struct ll my_list = new_list(3);

	
	my_list.insert(&my_list, 5);
	my_list.insert(&my_list, 8);

	printf("%d", my_list.get(&my_list, 2));
	//printf("%d", my_list.next);
}
