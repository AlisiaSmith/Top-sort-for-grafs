#include "Header.h"


list* push(list *head, elem* vertex)
{
	list *new_el = (list*)calloc(1, sizeof(list));
	new_el->value = vertex;
	
	if (head)	new_el->next = head;
		
	return new_el;
}

elem* ribs_reading(int num, int ribs, elem *graf)
{
	graf = calloc(num, sizeof(elem));
	memset(graf, 0, num);
	
	int i = 0, j = 0;
	
	for (i = 0; i < num; i++)
		graf[i].number = i + 1;

	int line[2] = { 0 };

	for(i = 0; i < ribs; i++)
	{
		for (j = 0; j < 2; j++)
			fscanf(stdin, "%d", &line[j]);
		
		if ((line[0] == 0) || (line[1] == 0)) 
			errors(BNL);
		
		verify_include(num, line[0]);
		verify_include(num, line[1]);

		graf[line[0] - 1].count = graf[line[0] - 1].count + 1;
		graf[line[0] - 1].head = push(graf[line[0] - 1].head, &graf[line[1] - 1]);
		
		line[0] = 0;
		line[1] = 0;
	}
	return graf;
}

elem* pop(list **head)
{
	if (!(*head)) return NULL;
	elem * ret = (*head)->value;
	list *tmp = *head;
	(*head) = (*head)->next;
	free(tmp);
	return ret;
}

list* dfs(elem *graf, list* head_top)
{
	if (graf->color != WHITE) return head_top;
	graf->color = GRAY;
	elem *next_gr;
	for (int i = 0; i < graf->count; i++) {
		next_gr = pop(&(graf->head));
		if (next_gr->color == GRAY)
			errors(ITS);
		if (next_gr->color == WHITE)
			head_top = dfs(next_gr, head_top);
	}
	graf->color = BLACK;
	head_top = push(head_top, graf);
	return head_top;
}

void printf_top_sort(list *head)
{
	elem *el;
	while (head)
	{
		el = pop(&head);
		fprintf(stdout, "%d ", (el->number));
	}
}

int main(void)
{
	int num = 0;
	int ribs = -1;
	elem *graf = NULL;
	list *head_top = NULL;

	fscanf(stdin, "%d", &num);
	fscanf(stdin, "%d", &ribs);

	if (ribs == -1) errors(BNL);
	
	verify_values(num, ribs);
	graf = ribs_reading(num, ribs, graf);
	for(int j = 0; j < num; j++)
		head_top = dfs(&graf[j], head_top);

	verify_sort(graf, num);
	printf_top_sort(head_top);

	return 0;
}