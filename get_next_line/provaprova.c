
size_t	get_space(int fd)
{
	char *box;
	size_t i, count;
	size_t	n;

	n = read(fd, box, BUFFER_SIZE)
	i = 0;
	count = 0;
	box = malloc(BUFFER_SIZE + 1)
	while (n > 0)
	{
		i = 0;
		while (i < n && box[i])
		{
			if (box[i] == '\n')
				return (count);
			i++;
			count++;
		}
	}
	return (count);
}
char	*get_next_line(int fd)
{
	return (new)
}