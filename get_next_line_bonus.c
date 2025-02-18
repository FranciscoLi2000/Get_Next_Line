#include "get_next_line_bonus.h"

static t_list	*get_node(t_list **head, int fd)
{
	t_list	*node;

	/* Búsqueda del nodo existente */
	node = *head;
	while (node) /* Recorre la lista enlazada buscando un nodo con el fd dado */
	{
		if (node->fd == fd) /* Si lo encuentra, retorna el nodo existente */
			return (node);
		node = node->next;
	}
	/* Si el nodo no existe, reserva memoria para uno nuevo */
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	/* Inicialización del nodo:
	Asigna el fd al nodo
	Inicializa buffer a NULL (no hay datos leídos aún) 
	Inserta el nuevo nodo al principio de la lista (operación eficiente en O(1)) */
	node->fd = fd;
	node->buffer = NULL;
	node->next = *head;
	*head = node;
	return (node);
}

static void cleanup_node(t_list **head, int fd)
{
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	curr = *head;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*head = curr->next;
			free(curr->buffer);
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

char	*get_next_line_bonus(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(&head, fd);
	if (!node)
		return (NULL);
	node->buffer = read_buffer(fd, node->buffer);
	if (!node->buffer)
	{
		cleanup_node(&head, fd);
		return (NULL);
	}
	line = extract_line(node->buffer);
	node->buffer = update_buffer(node->buffer);
	if (!node->buffer)
		cleanup_node(&head, fd);
	return (line);
}