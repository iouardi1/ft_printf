#include "so_long.h"

char	**read_the_map(int fd)
{
	char	*tab;
	char	*temp;
	char	**arr;

	tab = get_next_line(fd);
	temp = NULL;
	while (tab)
	{
		temp = ft_strjoin(temp, tab);
		tab = get_next_line(fd);
	}
	arr = ft_split(temp, '\n');
	return (arr);
}
// int main()
// {
// 	char	**arr;
// 	int i;
// 	int fd = open("my_map.ber", O_RDONLY);
// 	arr = read_the_map(fd);
// 	while (arr[i])
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// }