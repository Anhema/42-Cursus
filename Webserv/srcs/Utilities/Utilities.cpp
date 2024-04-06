#include "Utilities.hpp"

std::vector<std::string> Utils::read_dir(const string &path)
{
	DIR							*dir;
	struct dirent				*entry;
	std::vector<std::string> 	entries;

	dir = opendir(path.c_str());

	if (!dir)
		return entries;

	while ((entry = readdir(dir)) != NULL)
	{
		std::string entryName = entry->d_name;

		switch (entry->d_type) {
			case DT_REG:
//				entryType = "Regular File";
				break;
			case DT_DIR:
				entryName.push_back('/');
				break;
//			case DT_LNK:
//				entryType = "Symbolic Link";
//				break;
//				// Add more cases for other types as needed
			default:
				break;
		}
		entries.push_back(entryName);
	}

	closedir(dir);
	return entries;
}

std::string Utils::read_file(std::string file_name)
{
	std::ifstream   file(file_name.c_str());
	std::string     result;
	std::string     line;
	std::ostringstream buffer;

	if (file.fail())
	{
		std::cout << "Error opening file\n";
		file.close();
		return ("");
	}


	buffer << file.rdbuf();
	result = buffer.str();
	
	file.close();
	return (result);
}

bool	Utils::can_open_dir(std::string const &directory)
{
	DIR *dir = opendir(directory.c_str());

	if (!dir)
		return false;
	else
		closedir(dir);
	return true;
}

std::string Utils::get_extension(std::string const file_name)
{
	std::string file(file_name);
	std::vector<std::string> ext = Utils::split(file, '.');
	std::vector<std::string>::iterator ite = ext.end();
	ite -= 1;

	return (*ite);
}

bool Utils::isport(const std::string &s)
{
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++)
		if (!isdigit(*it))
			return false;

	return std::atoi(s.c_str()) <= USHRT_MAX;
}

bool Utils::can_open_file(const string &file)
{
	std::ifstream infile(file.c_str());

	if (infile.is_open())
	{
		infile.close();
		return true;
	}
	return false;
}

std::vector<std::string>    Utils::split(std::string str, std::string del) {
	std::vector<std::string> result;
	std::string line;

	char *token = std::strtok((char *) str.c_str(), del.c_str());
	do {
		result.push_back(token);
		token = std::strtok(NULL, del.c_str());
	} while (token);
//	int end = str.find(del);
//	char *
//	while (end != -1)
//	{
//		result.push_back(str.substr(0, end));
//		str.erase(str.begin(), str.begin() + end + 1);
//		end = str.find(del);
//	}
//	result.push_back(str.substr(0, end));

	return (result);
}

bool	Utils::isSet(char c, string set)
{
	for (string::iterator it = set.begin(); it != set.end(); it++)
		if (*it == c)
			return true;
	return false;
}

char *Utils::capitalize(char *s, string sep)
{
	for (size_t i = 0; i < std::strlen(s); i++)
	{
		s[i] = std::toupper(s[i]);
		while (s[++i] && !isSet(s[i], sep))
			continue;
	}
	return s;
}
void Utils::capitalize(string &s, string sep)
{
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (isSet(*it, sep))
			continue;
		std::toupper(*it);
	}
}

bool Utils::is_directory(const std::string& path)
{
	struct stat statbuf;
	if (stat(path.c_str(), &statbuf) != 0)
		return 0;
	return S_ISDIR(statbuf.st_mode);
}
std::vector<std::string> Utils::split(std::string str, char separator)
{
	std::vector<std::string>	result;
	std::stringstream 			sstream(str);
	std::string 				segment;

	while (std::getline(sstream, segment, separator))
	{
		if (!segment.empty())
			result.push_back(segment);
	}

	return result;
}

void Utils::deleteConsecutives(string &src, __unused char c)
{
	std::string result;

	result.reserve(src.size());
	for (std::string::iterator it = src.begin(); it != src.end(); it++)
	{
		if (*it == c && *(it + 1) == c)
			continue;
		else
			result.push_back(*it);
	}
	src = result;
}

int Utils::file_exists(const string &path)
{
	struct stat buffer;
	int stat_val = stat(path.c_str(), &buffer);
	if (stat_val == 0)
		return stat_val;
	switch (errno)
	{
		case ENOENT: // failed cause no exists
			return ENOENT;
		case EACCES: // failed cause acces
			return EACCES;
		default:
			return stat_val;
	}
}


std::string Utils::eraseAll(const std::string src, char c)
{
	std::string result;

	result.reserve(src.size());

	for (std::string::const_iterator it = src.begin(); it != src.end(); it++)
	{
		if (*it != c)
			result += *it;
	}
	return result;
}

bool Utils::comparePaths(const string &lhs, const string &rhs)
{
	return eraseAll(lhs, '/') == eraseAll(rhs, '/');
}
