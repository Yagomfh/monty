#include "monty.h"

/**
  * add_dnodeint - adds a new node at the beginning of a dlistint_t list
  * @head: pointer to head node
  * @n: data to add to node
  * Return: address of the new element, or NULL if it failed
  */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		new->prev = NULL;
	}
	*head = new;
	return (new);
}
/**
  * free_dlistint - frees a dlistint_t list
  * @head: pointer to head node
  * Return: void
  */

void free_stack(stack_t *head)
{
	stack_t *current = head;

	if (head == NULL)
		return;
	while (current->next)
	{
		head = current->next;
		free(current);
		current = head;
	}
	free(current);
}
/**
  * print_dlistint - prints all the elements of a dlistint_t list
  * @h: pointer to head node
  * Return: the number of nodes
  */

size_t print_dlistint(const stack_t *h)
{
	size_t i = 0;

	if (h == NULL)
		return (0);

	while (h->next)
	{
		i++;
		printf("%d\n", h->n);
		h = h->next;
	}
	printf("%d\n", h->n);
	i++;
	return (i);
}
