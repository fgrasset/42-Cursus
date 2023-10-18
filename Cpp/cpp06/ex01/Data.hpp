#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	int	_x;
	int	_y;
	int	_z;

	public:
		Data();
		Data(int x, int y, int z);
		~Data();
		Data(const Data &src);
		Data	&operator=(const Data &src);
};

#endif
