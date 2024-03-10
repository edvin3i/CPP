#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	int			len = 0;
	std::string	message;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			if (i > 1)
				message += " ";
			message += argv[i];
		}
		len = message.length();
		for (int l = 0; l < len; ++l)
		{
			message[l] = std::toupper(message[l]);
		}
		std::cout << message << std::endl;
	}
	return (0);
}